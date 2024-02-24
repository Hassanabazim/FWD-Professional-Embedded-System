/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Server         							*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utilities/std_types.h"
#include "../Utilities/SYS_config.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

/* global static DB-Index to update Accounts Database */
static u8 DB_index;

/* transactionData DB to store all the transaction with their info */
ST_transaction_t transactionData[DB_MAX] = {0};
/* AccountData DB have all the Accounts of the Bank System */
ST_accountsDB_t accountsData[DB_MAX] =  {{60000,RUNNING,"4151500000000008"},
                                        {345.50, RUNNING,"2223000048410010"},
                                        {24000.0,BLOCKED,"4263982640269299"},
                                        {5800.0, RUNNING,"5425233430109903"},
                                        {33000.0,RUNNING,"3530111333300000"},
                                        {10000.0,BLOCKED,"2222400010000008"},
                                        {2550.80,RUNNING,"6011000991300009"},
                                        {1593.0, RUNNING,"6362970000457013"},
                                        {9875.40,BLOCKED,"4035501000000008"},
                                        {32123.0,RUNNING,"4007702835532454"}};

EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountReference)
{
    EN_serverError_t local_state = ACCOUNT_NOT_FOUND;
#if (MODULE_MODE == SERVER_TEST)
    printf("PLEASE ENTER A PAN :");
    gets(cardData->primaryAccountNumber);
#endif
    /* 1. search in the database for card's Account Number stored previously */
    for (DB_index = 0; ((DB_index < DB_MAX) && (local_state == ACCOUNT_NOT_FOUND)); DB_index++)
    {
        /* check it, if it founded store it in the account struct to validate the data*/
        if (!(strcmp(cardData->primaryAccountNumber, accountsData[DB_index].primaryAccountNumber)))
        {
            accountReference->balance = accountsData[DB_index].balance;
            accountReference->state = accountsData[DB_index].state;
            strcpy(accountReference->primaryAccountNumber, accountsData[DB_index].primaryAccountNumber);
            local_state = SERVER_OK ;
        }
        else
        {

        }
    }
    return local_state;
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountReference)
{
    EN_serverError_t local_state;
#if (MODULE_MODE == SERVER_TEST)
    printf("%d\n", accountReference->state);
#endif
    /* check if the account state from the Database is blocked or not */
    if (accountReference->state == BLOCKED)
    {
        local_state = BLOCKED_ACCOUNT;
    }
    else
    {
        local_state = SERVER_OK;
    }
    return local_state;
}

EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountReference)
{
    EN_serverError_t local_state;
#if (MODULE_MODE == SERVER_TEST)
    printf("PLEASE ENTER A Amount :");
    scanf("%f",&(termData->transAmount));
#endif
    /* check if the transAmount is bigger than Account balance in the Database */
    if ((termData->transAmount) > (accountReference->balance))
    {
        local_state = LOW_BALANCE;
    }
    else
    {
        local_state = SERVER_OK;
    }
    return  local_state;
}

EN_serverError_t saveTransaction(ST_transaction_t *transData)
{
    EN_serverError_t local_state;
    /* 1. create a static id to hold SYSTEM ID over */
    static u16 id = 1;
    /* 2. check if the sys_id not equal the value of the 1st array of transactionData */
    if (id != transactionData[id-1].transactionSequenceNumber)
    {
        /* 3. Assign DB seq Number with SYSTEM ID */
        transData->transactionSequenceNumber = id;

        /* 4. copy the Account Data transaction with seq number into TransactionData DB */
        strcpy(transactionData[id-1].cardHolderData.primaryAccountNumber, transData->cardHolderData.primaryAccountNumber);
        transactionData[id-1].transactionSequenceNumber = transData->transactionSequenceNumber;

        /* 5. check if the state is Blocked Account or Low Balance Account or Approved */
        if (transData->tranState == DECLINED_STOLEN_CARD || transData->tranState == DECLINED_INSUFFECIENT_FUND)
        {
            /*6. the transaction Amount will be the same as the Account balance, no change */
            transData->terminalData.transAmount = accountsData[DB_index-1].balance;
        }
        else if (transData->tranState == APPROVED)
        {
            /* 7. the Account balance will decreased by the transAmount and update the TransAmount*/
            accountsData[DB_index-1].balance -= transData->terminalData.transAmount;
            transData->terminalData.transAmount = accountsData[DB_index-1].balance;
        }
        else
        {

        }
        transactionData[id-1].tranState = transData->tranState;
        transactionData[id-1].terminalData.transAmount = transData->terminalData.transAmount;

#if (MODULE_MODE == SERVER_TEST)
        printf("{%s, %.2f, %d, %d}\n", transactionData[id-1].cardHolderData.primaryAccountNumber,
        transactionData[id-1].terminalData.transAmount, transactionData[id-1].tranState,
        transactionData[id-1].transactionSequenceNumber);
#endif
        /* 5. increment the SYSTEM ID */
        id ++;
        local_state =  SERVER_OK ;
    }
    else
    {
        local_state = SAVING_FAILED;
    }
    return local_state;
}

En_transState_t recieveTransactionData(ST_transaction_t *transData)
{
    EN_serverError_t local_state;
    ST_accountsDB_t *accountReference = malloc(sizeof (ST_accountsDB_t));
    /* 1. check if Card's Name in the Account DB or Not */
    if (isValidAccount(&transData->cardHolderData,accountReference)== ACCOUNT_NOT_FOUND)
    {
        local_state = FRAUD_CARD;
    }
    /* 2.check if the Account state is blocked or Not */
    else if (isBlockedAccount(accountReference)== BLOCKED_ACCOUNT)
    {
        local_state = DECLINED_STOLEN_CARD;
    }
    /* 3. check if the Amount is available in your Account Balance or Not */
    else if (isAmountAvailable(&transData->terminalData,accountReference) == LOW_BALANCE)
    {
        local_state = DECLINED_INSUFFECIENT_FUND;
    }
    /* 4. check if everything in the account has been met with DB */
    else
    {
        local_state = APPROVED;
    }
    /* 5. update the transState with the transaction received state */
    transData->tranState = local_state;
    return local_state;
}

EN_serverError_t getTransaction(u32 transactionSequenceNumber, ST_transaction_t *transData)
{
    EN_serverError_t local_state = TRANSACTION_NOT_FOUND;
    /* 1. search in TransactionData Array for operation transactionSequenceNumber */
    for (u8 i = 0; i < DB_MAX && local_state == TRANSACTION_NOT_FOUND; i++)
    {
        /* 2. if transactionSequenceNumber exits in the TransactionData, Display the updated-Account DB */
        if (transData->transactionSequenceNumber == transactionData[i].transactionSequenceNumber)
        {
            printf("{%s, %.2f, %d, %d}\n", transactionData[i].cardHolderData.primaryAccountNumber,
                transactionData[i].terminalData.transAmount,transactionData[i].tranState,
               transactionData[i].transactionSequenceNumber);
            local_state = SERVER_OK ;
        }
        else
        {

        }
    }
    return local_state;
}
