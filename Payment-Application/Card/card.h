/****************************************************************/
/* Author 			:  Hassan Abdelazim Abdelsalam				*/
/* Origin Data 		:  22/3/2023 				   	 			*/
/* Version 			:  1.0.0							 		*/
/* Module			:  Card           							*/
/****************************************************************/

#ifndef CARD_H_
#define CARD_H_


typedef struct ST_cardData_t
{
    u8 cardHolderName[25];
    u8 primaryAccountNumber[20];
    u8 cardExpirationDate[6];
} ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK, WRONG_NAME, WRONG_EXP_DATE, WRONG_PAN, INVALID_CARD
}EN_cardError_t;


EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
/************************************************************************
* Function Name: getCardHolderName
* Purpose      : get card holder's name
* Arguments    : cardData* ptr - > struct ST_cardData_t
* Return value : EN_cardError_t local_states
*************************************************************************/


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
/************************************************************************
* Function Name: getCardExpiryDate
* Purpose      : get card holder's ExpiryDate
* Arguments    : cardData* ptr - > struct ST_cardData_t
* Return value : EN_cardError_t local_states
*************************************************************************/


EN_cardError_t getCardPAN(ST_cardData_t *cardData);
/************************************************************************
* Function Name: getCardPAN
* Purpose      : get card holder's Account Number
* Arguments    : cardData* ptr - > struct ST_cardData_t
* Return value : EN_cardError_t local_states
*************************************************************************/


EN_cardError_t isValidCardPAN(ST_cardData_t *cardData);
/************************************************************************
* Function Name: isValidCardPAN
* Purpose      : check card holder's PAN valid or Not
* Arguments    : cardData* ptr - > struct ST_cardData_t
* Return value : EN_cardError_t local_states
*************************************************************************/


#endif // card
