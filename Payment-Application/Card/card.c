/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Card           							*/
/****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Utilities/std_types.h"
#include "../Utilities/SYS_config.h"
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    EN_cardError_t local_state;
    u8 nameLen, name;
    /* 1. Ask user to enter his card's Name */
    printf("Enter THE NAME OF THE CARD: ");
    fflush(stdin);
    /* 2. get the card's name from the user */
    gets(cardData->cardHolderName);
#if (MODULE_MODE == CARD_TEST)
    printf("%s\n",cardData->cardHolderName);
#endif
    nameLen = strlen(cardData->cardHolderName);
    /* 3. check if card name bet [20-25] char and not Empty */
    if ((nameLen >= 20)&&(nameLen <=25)&&(nameLen != '\0'))
    {
        local_state = CARD_OK;
    }
    else
    {
        local_state = WRONG_NAME;
    }
    return local_state;
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    EN_cardError_t local_state;
    u8 expLen ;
    /* 1. Ask user to enter his card's EXP Date */
    printf("Enter Card Expiry Date: ");
    fflush(stdin);
    /* 2. get the card's EXP Date from the user */
    gets(cardData->cardExpirationDate);
#if (MODULE_MODE == CARD_TEST)
    printf("%s\n",cardData->cardExpirationDate);
#endif
    expLen = strlen(cardData->cardExpirationDate) ;
    /* 3. check if card EXP Date in 'MM/YY' */
    if ((expLen == 5) && (cardData->cardExpirationDate[2])== '/')
    {
        local_state = CARD_OK;
    }
    else
    {
        local_state = WRONG_EXP_DATE;
    }
    return local_state;
}

EN_cardError_t getCardPAN (ST_cardData_t *cardData)
{
    EN_cardError_t local_state;
    u8 numLen;
    /* 1. Ask user to enter his card's PAN */
    printf("Enter Card Account Number : ");
    fflush(stdin);
    /* 2. get the card's PAN from the user */
    gets(cardData->primaryAccountNumber);
#if (MODULE_MODE == CARD_TEST)
    printf("%s\n",cardData->primaryAccountNumber);
#endif
    numLen = strlen(cardData->primaryAccountNumber);
    /* 3. check if card PAN bet [16-19] char and not Empty */
    if ((numLen  >= 16) && (numLen <= 19)&&(numLen != '\0'))
    {
        local_state = CARD_OK;
    }
    else
    {
        local_state = WRONG_PAN;
    }
    return local_state;
}

EN_cardError_t isValidCardPAN(ST_cardData_t *cardData)
{
    EN_cardError_t local_state;
    u8 cardLen = strlen(cardData->primaryAccountNumber);
    u16 odd_sum = 0, even_sum = 0;

    /* 1. start even from the start to the end with 2-step */
    for (u8 i = 0; i < cardLen;  i += 2)
    {
        /* 2. convert PAN from characters to numbers and multiply with 2 */
        u8 product = (cardData->primaryAccountNumber[i]-'0') *2 ;
        /* 3. check if the number has two digits */
        if (product >= 10)
        {
            /* 4. get the first and second digit and add them */
            u8 d_first = product / 10;
            u8 d_secnd = product % 10;
            product = d_first + d_secnd ;

        }
        even_sum +=  product;
    }
#if (MODULE_MODE == CARD_TEST)
    printf("%d\n",even_sum);
#endif

    /* 5. start odd from the start+1 to the end with 2-step */
    for (u8 j = 1; j<cardLen; j+=2)
    {
    /* 6. convert PAN from characters to numbers and add them all */
      odd_sum += (cardData->primaryAccountNumber[j]-'0');
    }
#if (MODULE_MODE == CARD_TEST)
    printf("%d\n",odd_sum);
#endif
    /*7. check if the odd and even sum division equals to zero */
    if ((odd_sum + even_sum) % 10 == 0)
    {
        local_state = CARD_OK ;
    }
    else
    {
        local_state =  INVALID_CARD;
    }
    return local_state;
}
