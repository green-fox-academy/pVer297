#ifndef TEMPLATE_PROJECT_H
#define TEMPLATE_PROJECT_H

#define NUM_OF_CARDS 5

#include <mem.h>
#include <stdio.h>

typedef enum{
    FIRST_WIN,
    SECOND_WIN,
    TIE
} win_e;

typedef enum
{
    _2 = 2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _T,
    _J,
    _Q,
    _K,
    _A
} card_value;

typedef enum {
    C,
    D,
    H,
    S
} card_color;

typedef struct {
    card_value cardVal;
    card_color cardColor;
} card_t;

char* checkHand(card_t* firstHand, card_t* secondHand);
void sortHand(card_t* hand);
void swapCards(card_t* firstCard, card_t* secondCard);
void printHand(card_t* hand);
#endif
