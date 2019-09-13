#include <iostream>
#include "deck.cpp"

using namespace std;

int main(int argc, char** argv)
{
    Deck* deck = new Deck();
    deck->shuffle();

    for (int i = 0; i < 21; i++)
    {
        cout << "Card " << i << ": " << deck->draw() << '\n';
    }

    return 0;
}