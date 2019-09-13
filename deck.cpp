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
    int remaining;

    void swap(int a, int b);
    std::string card(int cardValue);
    int cardValue(std::string card);

    public:
    Deck();
    ~Deck();

    void init();
    void shuffle();
    std::string draw();
};

Deck::Deck(void)
{
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
    std::string card = SUITS[suit];

    switch (value)
    {
        case 1:
            card += "A";
            break;
        case 11:
            card += "J";
            break;
        case 12:
            card += "Q";
            break;
        case 13:
            card += "K";
            break;
        default:
            card += std::to_string(value);
            break;
    }

    return card;
    return "";
}

std::string Deck::draw()
{
    if (remaining == 0)
    {
        return "";
    }

    remaining--;
    std::string cardStr = card(DECK[remaining]);

    return cardStr;
}

void Deck::init()
{
    delete[] DECK;
    DECK = new int[DECK_SIZE];

    for (int i = 0; i < DECK_SIZE; i++)
    {
        DECK[i] = i;
    }

    remaining = DECK_SIZE;
}

void Deck::shuffle()
{
    srand(time(NULL));
    for (int i = 0; i < remaining; i++)
    {
        int j = rand() % (i+1);

        if (j != i)
        {
            swap(i, j);
        }
    }
}