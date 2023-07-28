/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Application  							*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utilities/std_types.h"
#include "../Utilities/SYS_config.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "app.h"

void appStart(void)
{
    /* 1. create the Interface Display for user experience */
    printf("********************************************************\n");
    printf("      PROFESSIONAL EMBEDDED SYSTEM NANODEGREE FWD       \n");
    printf("      Author : HASSAN ABDELAZIM ABDELSALAM ELSAYED      \n");
    printf("********************************************************\n");
    printf("1-    CARD NAME ONLY CHAR, NO DIGITS OR SPECIAL CHAR    \n");
    printf("2-    CARD PAN ONLY DIGITS, NO CHARACTERS               \n");
    printf("3-    CARD EXPAIRY DATE IN FORMAT (MM/YY)               \n");
    printf("4-    THE MAX.AMOUNT PER TRANSACTION IS 50,000 EGP      \n");
    printf("********************************************************\n");
    printf("        PLEASE CHOOSE FROM THE FOLLOWING OPTIONS        \n");
    printf("********************************************************\n");
    printf("1:START\n2:FREE\n3:EXIT\n");

    ST_transaction_t *transData = (ST_transaction_t*)malloc(sizeof(ST_transaction_t));
    /* 2. set the Max transaction Amount of the system */
    transData->terminalData.maxTransAmount = 50000.00;
    int choice;
    u8 seqNum = 0;
    do{
        /* 3. choose the operation as stand {start, free, exit} */
        printf("*************************************************\n");
        printf("ENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch(choice)
        {
        /* 4. start the application by state machine of the system (1st priority) by card Module
        then terminal module and server module, if the system stop any state the system will stop
        the ideal test case will pass all the states and output the transaction Database */
        case START:
        if (getCardHolderName(&transData->cardHolderData) == WRONG_NAME)
        {
            printf("PLEASE ENTER THE CORRECT NAME ! \n");
            break;
        }
        else if (getCardPAN(&transData->cardHolderData) == WRONG_PAN)
        {
            printf("PLEASE ENTER THE CORRECT CARD NUMBER ! \n");
            break;
        }
        else if (isValidCardPAN(&transData->cardHolderData) == INVALID_CARD)
        {
            printf("PLEASE ENTER A VALID CARD NUMBER ! \n");
            break;
        }
        else if (getCardExpiryDate(&transData->cardHolderData) == WRONG_EXP_DATE)
        {
            printf("PLEASE ENTER THE CORRECT EXP DATA ! \n");
            break;
        }
        else if (getTransactionDate(&transData->terminalData) != TERMINAL_OK)
        {
            printf("THE TRANSCATION DATE IS INCORRECT ! \n");
            break;
        }
        else if (isCardExpired(&transData->cardHolderData,&transData->terminalData) == EXPIRED_CARD)
        {
            printf("YOUR CARD IS EXPIRED ! \n");
            break;
        }
        else if (setMaxAmount(&transData->terminalData) == INVALID_MAX_AMOUNT)
        {
            printf("PLEASE ENTER A VALID MAX AMOUNT ! \n");
            break;
        }
        else if (getTransactionAmount(&transData->terminalData) == INVALID_AMOUNT)
        {
            printf("PLEASE ENTER THE CORRECT AMOUNT ! \n");
            break;
        }
        else if (isBelowMaxAmount(&transData->terminalData) == EXCEED_MAX_AMOUNT)
        {
            printf("PLEASE ENTER AN AMOUNT BELOW MAX_AMOUNT ! \n");
            break;
        }
        else if (recieveTransactionData(transData) == FRAUD_CARD)
        {
            printf("YOUR ACCOUNT NUMBER IS NOT FOUND ! \n");
            break;
        }
        else if (recieveTransactionData(transData) == DECLINED_STOLEN_CARD)
        {
            printf("YOUR ACCOUNT IS BLOCKED ! \n");
        }
        else if (recieveTransactionData(transData) == DECLINED_INSUFFECIENT_FUND)
        {
            printf("YOUR ACCOUNT BALANCE IS EXCECCED ! \n");
        }
        if (saveTransaction(transData) == SAVING_FAILED)
        {
            printf("CONNECTION HAS LOST PLEASE TRY AGAIN ! \n");
        }

        getTransaction(seqNum, transData);
        break;

        case FREE:
        /* 5. free the Memory dynamic allocation */
        free(transData);
        printf("The Memory Allocation has been free\n");
        break;

        case EXIT:
        /* 6. Exit the operation and break the system */
        break;

        default:
        /* 7. check if user entered wrong choice, return error statement*/
        printf("INVALID CHOICE, PLEASE TRY AGAIN !\n");
        break;
        }
    }while (choice != EXIT);
}
