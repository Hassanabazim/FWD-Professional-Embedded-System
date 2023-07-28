/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Server         							*/
/****************************************************************/

#ifndef SERVER_H_
#define SERVER_H

#define DB_MAX  255

typedef enum En_transState_t
{
    APPROVED, DECLINED_INSUFFECIENT_FUND,
    DECLINED_STOLEN_CARD, FRAUD_CARD,
    INTERNAL_SERVER_ERROR
}En_transState_t;

typedef enum EN_serverError_t
{
    SERVER_OK, SAVING_FAILED,
    TRANSACTION_NOT_FOUND,
    ACCOUNT_NOT_FOUND,
    LOW_BALANCE, BLOCKED_ACCOUNT
}EN_serverError_t;

typedef enum EN_accountState_t
{
    RUNNING, BLOCKED
}EN_accountState_t;

typedef struct ST_transaction_t
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    En_transState_t tranState;
    u32 transactionSequenceNumber;
}ST_transaction_t;

typedef struct ST_accountsDB_t
{
    f32 balance;
    EN_accountState_t state;
    u8 primaryAccountNumber[20];
}
ST_accountsDB_t;


EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t *accountReference);
/**************************************************************************************
* Function Name: isValidAccount
* Purpose      : check if the Card's PAN into the Account DB
* Arguments    : cardData* ptr->ST_cardData_t, accountReference* ptr->ST_accountsDB_t
* Return value : EN_serverError_t local_states
***************************************************************************************/


EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountReference);
/**************************************************************************************
* Function Name: isBlockedAccount
* Purpose      : check if the Card's PAN state into the Account DB Blocked or Not
* Arguments    : accountReference* ptr -> ST_accountsDB_t
* Return value : EN_serverError_t local_states
***************************************************************************************/


EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t *accountReference);
/**************************************************************************************
* Function Name: isAmountAvailable
* Purpose      : check if the Card's PAN Balance into the AccountDB enough or Not
* Arguments    : transDate*ptr->ST_transaction_t,accountReference* ptr->ST_accountsDB_t
* Return value : EN_serverError_t local_states
***************************************************************************************/


EN_serverError_t saveTransaction(ST_transaction_t *transDate);
/**************************************************************************************
* Function Name: saveTransaction
* Purpose      : save Transactions into the TransactionData with unique TranSeqNumber
* Arguments    : transDate*ptr->ST_transaction_t,accountReference* ptr->ST_accountsDB_t
* Return value : EN_serverError_t local_states
***************************************************************************************/

En_transState_t recieveTransactionData(ST_transaction_t *transData);
/**************************************************************************************
* Function Name: recieveTransactionData
* Purpose      : receieve TransactionData and Validate it with Server States
* Arguments    : transData* ptr -> struct ST_transaction_t
* Return value : EN_serverError_t local_states
***************************************************************************************/


EN_serverError_t getTransaction(u32 transactionSequenceNumber, ST_transaction_t *transData);
/**************************************************************************************
* Function Name: getTransaction
* Purpose      : getTransaction with the unique TransactionSeqNumber
* Arguments    : transactionSequenceNumber,transData* ptr -> struct ST_transaction_t
* Return value : EN_serverError_t local_states
***************************************************************************************/


#endif // SERVER_H_
