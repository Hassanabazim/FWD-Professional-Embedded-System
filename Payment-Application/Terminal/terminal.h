/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Terminal       							*/
/****************************************************************/

#ifndef TERMINAL_H_
#define TERMINAL_H_

typedef struct ST_terminalData_t
{
    f32 transAmount;
    f32 maxTransAmount;
    u8 transactionDate[11] ;
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK, WRONG_DATE, EXPIRED_CARD,
    INVALID_AMOUNT,EXCEED_MAX_AMOUNT, INVALID_MAX_AMOUNT
}EN_terminalError_t;

EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
/**************************************************************************************
* Function Name: getTransactionDate
* Purpose      : get Transaction Date from the Machine
* Arguments    : termData* ptr -> struct ST_terminalData_t
* Return value : EN_terminalError_t local_states
***************************************************************************************/


EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData);
/***************************************************************************************
* Function Name: isCardExpired
* Purpose      : check if the card is Expired or not
* Arguments    : cardData* ->struct ST_cardData_t, termData* ->struct ST_terminalData_t
* Return value : EN_terminalError_t local_states
****************************************************************************************/


EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
/***************************************************************************************
* Function Name: getTransactionAmount
* Purpose      : get Transaction Amount to withdraw
* Arguments    : termData* ptr - > struct ST_terminalData_t
* Return value : EN_terminalError_t local_states
****************************************************************************************/


EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
/***************************************************************************************
* Function Name: isBelowMaxAmount
* Purpose      : check if the amount in the range of system Maximum
* Arguments    : termData* ptr - > struct ST_terminalData_t
* Return value : EN_terminalError_t local_states
****************************************************************************************/


EN_terminalError_t setMaxAmount(ST_terminalData_t *termData);
/***************************************************************************************
* Function Name: setMaxAmount
* Purpose      : set the max Amount of the system to Withdraw
* Arguments    : termData* ptr - > struct ST_terminalData_t
* Return value : EN_terminalError_t local_states
****************************************************************************************/

#endif
