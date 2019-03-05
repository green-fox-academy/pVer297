
#include "project.h"

char* checkHand(card_t* firstHand, card_t* secondHand)
{
    sortHand(firstHand);
    sortHand(secondHand);
    win_e win = TIE;
    for (int i = 0; i < NUM_OF_CARDS; i++) {
        if (firstHand[i].cardVal > secondHand[i].cardVal) {
            win = FIRST_WIN;
            break;
        } else if (secondHand[i].cardVal > firstHand[i].cardVal) {
            win = SECOND_WIN;
            break;
        }
    }

    switch (win) {
        case FIRST_WIN: return "First wins! - (High card: 9)";
        case SECOND_WIN: return "Second wins! - (High card: 9)";
        case TIE: return "Tie";
    }
}
void sortHand(card_t* hand)
{
    //printHand(hand);
    for (int i = 0; i < NUM_OF_CARDS; i++) {
        for (int j = 0; j < NUM_OF_CARDS; j++) {
            if (hand[i].cardVal > hand[j].cardVal) {
                swapCards(&hand[i], &hand[j]);
                /*card_t temp = hand[i];

                hand[i].cardVal = hand[j].cardVal;
                hand[i].cardColor = hand[j].cardColor;

                hand[j].cardVal = temp.cardVal;
                hand[j].cardColor = temp.cardColor;*/
            }
        }
    }
    //printHand(hand);
}
void swapCards(card_t* firstCard, card_t* secondCard)
{
    card_t temp = *secondCard;

    secondCard->cardVal = firstCard->cardVal;
    secondCard->cardColor = firstCard->cardColor;

    firstCard->cardVal = temp.cardVal;
    firstCard->cardColor = temp.cardColor;
}


void printHand(card_t* hand){
    for(int i = 0; i < NUM_OF_CARDS; i++){
        printf("%d, ", hand[i].cardVal);
    }
    puts("");
}
