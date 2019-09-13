#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

class Deck
{
    private:
    const static int DECK_SIZE = 52;
    const std::string SUITS[4] = {"♥", "♠", "♦", "♣"};
    int* DECK;

    void swap(int a, int b);
    std::string card(int cardValue);

    public:
    int remaining;

    Deck();
    ~Deck();
    void init();
    void shuffle();
    std::string draw();
};

Deck::Deck(void)
{
    DECK = new int[DECK_SIZE];
    init();
}

Deck::~Deck(void)
{
    delete[] DECK;
}

void Deck::swap(int a, int b)
{
    int tmp = DECK[a];
    DECK[a] = DECK[b];
    DECK[b] = tmp;
}

std::string Deck::card(int cardValue)
{
    int suit = cardValue % 4;
    int value = cardValue / 4 + 1;

    std::string displayValue = SUITS[suit];

    switch (value)
    {
        case 1:
            displayValue += "A";
            break;
        case 11:
            displayValue += "J";
            break;
        case 12:
            displayValue += "Q";
            break;
        case 13:
            displayValue += "K";
            break;
        default:
            displayValue += std::to_string(value);
            break;
    }

    return displayValue;
}

std::string Deck::draw()
{
    std::string cardStr = card(*DECK);

    if (remaining == 0)
    {
        return "";
    }

    DECK++;
    remaining--;

    return cardStr;
}

void Deck::init()
{
    for (int i = 0; i < DECK_SIZE; i++)
    {
        DECK[i] = i;
    }

    remaining = DECK_SIZE;
}

void Deck::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int j = rand() % (i+1);

        if (j != i)
        {
            swap(i, j);
        }
    }
}