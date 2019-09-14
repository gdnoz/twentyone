#include <iostream>
#include "deck.cpp"

using namespace std;

void drawCards(string* cards, Deck* deck)
{
    for (int i = 0; i < 21; i++)
    {
        cards[i] = deck->draw();
    }
}

void dealCards(string* cards)
{
    cout << "#1\t#2\t#3\n\n";

    for (int i = 0; i < 21; i++)
    {
        cout << cards[i];

        if (i % 3 == 2)
        {
            cout << '\n';
        }
        else
        {
            cout << '\t';
        }
    }
}

int getSelection(string msg)
{
    int selection;

    cout << "\n" << msg << ": ";
    cin >> selection;
    cout << '\n';

    return selection;
}

void collectCards(string* cards, int selection)
{
    string tmp[21];

    copy(cards, cards+21, tmp);

    for (int i = 0, k = 0; i < 3; i++)
    {
        // This is where the magic happens
        for (int j = (selection + i + 1) % 3; j < 21; j+=3, k++)
        {
            cards[k] = tmp[j];
        }
    }
}

void playRound(string* cards, string msg)
{
    dealCards(cards);
    int selection = getSelection(msg);
    collectCards(cards, selection);
}

int main(int argc, char** argv)
{
    Deck* deck = new Deck();
    string* cards = new string[21];
    deck->shuffle();
    drawCards(cards, deck);

    for (int i = 0; i < 3; i++)
    {
        playRound(cards, i == 0 ?
            "Please pick a card and enter its column (1-3)" :
            "Enter the column containing your card");
    }

    cout << "Your card is " << cards[10] << "!\n";

    return 0;
}