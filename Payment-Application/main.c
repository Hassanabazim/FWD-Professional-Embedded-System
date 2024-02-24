/*****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  main           							*/
/*****************************************************************/

#include <stdio.h>
#include "Utilities/std_types.h"
#include "Utilities/SYS_config.h"
#include "Card/card.h"
#include "Terminal/terminal.h"
#include "Server/server.h"
#include "Application/app.h"


int main()
{
#if (MODULE_MODE == CARD_TEST)
    ST_cardData_t *cardData = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
    printf("%d\n",getCardHolderName(cardData));
    printf("%d\n",getCardExpiryDate(cardData));
    printf("%d\n",getCardPAN(cardData));
    printf("%d\n",isValidCardPAN(cardData));
#elif (MODULE_MODE == TERMINAL_TEST)
    ST_cardData_t *cardData = (ST_cardData_t *)malloc(sizeof(ST_cardData_t));
	ST_terminalData_t *termData = (ST_terminalData_t *)malloc(sizeof(ST_terminalData_t));
	printf("%d\n", getTransactionDate(termData));
    printf("%d\n",isCardExpired(cardData, termData));
	printf("%d\n",getTransactionAmount(termData));
	termData->maxTransAmount = 200;
    printf("%d\n",setMaxAmount(termData));
    printf("%d\n",isBelowMaxAmount(termData));
#elif(MODULE_MODE == SERVER_TEST)
    ST_cardData_t *cardData = malloc(sizeof(ST_cardData_t));
    ST_accountsDB_t *accountReference = malloc(sizeof (ST_accountsDB_t));
    ST_terminalData_t *termData = malloc(sizeof(ST_terminalData_t));
    ST_transaction_t *transData = malloc(sizeof(ST_transaction_t));
    printf("%d\n",isValidAccount(cardData, accountReference));
    /*printf("%d\n",isBlockedAccount(accountReference));
    printf("%d\n",isAmountAvailable(&termData, accountReference));
    printf("%d\n",recieveTransactionData(transData));
    printf("%d\n", saveTransaction(transData));
    printf("%d\n", getTransaction(1,transData));*/

#elif(MODULE_MODE == APP_COMPILE)
    appStart();
#else
    #error("WRONG SYSTEM OPERATION CHOICE");
#endif
}




