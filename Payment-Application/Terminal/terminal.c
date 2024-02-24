/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Terminal       							*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../Utilities/std_types.h"
#include "../Utilities/SYS_config.h"
#include "../Card/card.h"
#include "terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    /* 1. get the current date from time.h library */
    time_t t = time(NULL);
    struct tm current = *localtime (&t);
    /* 2. get the day, month, year from struct object */
    u8 day = current.tm_mday;
    u8 month = current.tm_mon + 1;
    u16 year = current.tm_year + 1900;
    /* 3. store the date into transactionDate array within order */
    termData->transactionDate[0] = (day/10)+'0';
    termData->transactionDate[1] = (day%10)+'0';
    termData->transactionDate[2] = '/';
    termData->transactionDate[3] = (month/10)+'0';
    termData->transactionDate[4] = (month%10)+'0';
    termData->transactionDate[5] = '/';
    termData->transactionDate[6] = (year/1000)+'0';
    termData->transactionDate[7] = ((year/100)%10)+'0';
    termData->transactionDate[8] = ((year/10)%10)+'0';
    termData->transactionDate[9] = (year%10)+'0';
    termData->transactionDate[10]= '\0';
#if (MODULE_MODE  ==  TERMINAL_TEST)
    printf ("%s\n", termData->transactionDate);
#endif
    return TERMINAL_OK;
}

EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t *termData)
{
    EN_terminalError_t local_state;
#if (MODULE_MODE  ==  TERMINAL_TEST)
    printf("PLEASE ENTER THE EXP DATA:");
    gets(cardData->cardExpirationDate);
#endif
    /* 1. get current month,year and compare it with card's EXP DATE */
    u16 current_month = (termData->transactionDate[3] - '0')*10  + (termData->transactionDate[4] - '0');
    u16 current_year = (termData->transactionDate[8] - '0')*10  + (termData->transactionDate[9] - '0');
    u16 card_month = (cardData->cardExpirationDate[0] - '0')*10 +(cardData->cardExpirationDate[1] - '0');
    u16 card_year = (cardData->cardExpirationDate[3] - '0')*10+(cardData->cardExpirationDate[4] - '0');
#if (MODULE_MODE  ==  TERMINAL_TEST)
    printf("%d -- %d ------- %d -- %d\n",current_month, current_year, card_month, card_year);
#endif
    /* 2. check if the card year is bigger than current year (first priority) */
    if (card_year > current_year)
    {
        local_state = TERMINAL_OK;
    }

    /* 3. check if the card year is equal to current year (second priority) */
    else if (card_year == current_year)
    {
        /* 4. check if the card month is bigger than current month */
        if (card_month > current_month)
        {
            local_state = TERMINAL_OK;
        }
        else
        {
            local_state = EXPIRED_CARD;
        }
    }
    /* 5. check if the card year is less than current year (third priority)*/
    else
    {
        local_state = EXPIRED_CARD;
    }
    return local_state;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t local_state ;
    /* 1. Ask the user to enter transaction amount */
    printf("Enter your transaction amount: ");
    /* 2. Get the transaction amount from the user */
    scanf("%f", &(termData->transAmount));
#if (MODULE_MODE  ==  TERMINAL_TEST)
    printf ("%f\n", termData->transAmount);
#endif
    /*  3. check if transaction amount above 0 */
    if ((termData->transAmount) > 0)
    {
        local_state = TERMINAL_OK ;
    }
    else
    {
        local_state = INVALID_AMOUNT ;
    }
    return local_state;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t local_state ;
#if (MODULE_MODE  ==  TERMINAL_TEST)
    printf ("%f\n", termData->transAmount);
#endif
    /* check if the transAmount is less or equal to the max-Amount */
    if ((termData->transAmount) <= (termData->maxTransAmount))
    {
        local_state = TERMINAL_OK ;
    }
    else
    {
        local_state = EXCEED_MAX_AMOUNT;
    }
    return local_state;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t local_state ;
    /* check if the max transAmount is Above 0 */
    if((termData->maxTransAmount) > 0)
    {
          local_state = TERMINAL_OK;
    }
    else
    {
        local_state = INVALID_MAX_AMOUNT;
    }
    return local_state;
}
