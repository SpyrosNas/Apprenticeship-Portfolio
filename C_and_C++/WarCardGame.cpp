#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <random>
#include <string>

using namespace std;

enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };

struct Card {
    Rank rank;
    Suit suit;
};

string getRankString(Rank r) {
    switch (r) {
        case Rank::ACE: return "Ace";
        case Rank::TWO: return "2";
        case Rank::THREE: return "3";
        case Rank::FOUR: return "4";
        case Rank::FIVE: return "5";
        case Rank::SIX: return "6";
        case Rank::SEVEN: return "7";
        case Rank::EIGHT: return "8";
        case Rank::NINE: return "9";
        case Rank::TEN: return "10";
        case Rank::JACK: return "Jack";
        case Rank::QUEEN: return "Queen";
        case Rank::KING: return "King";
        default: return "??";
    }
}

string getSuitString(Suit s) {
    switch (s) {
        case Suit::HEARTS: return "Hearts";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::CLUBS: return "Clubs";
        case Suit::SPADES: return "Spades";
        default: return "??";
    }
}

string getCardString(const Card& c) {
    return getRankString(c.rank) + " of " + getSuitString(c.suit);
}

int getRankValue(Rank r) {
    return (r == Rank::ACE) ? 14 : static_cast<int>(r);
}

int main() {
    // Create and shuffle deck
    vector<Card> deck;
    for (int s = 0; s < 4; s++) {
        Suit suit = static_cast<Suit>(s);
        for (int r = 1; r <= 13; r++) {
            deck.push_back(Card{static_cast<Rank>(r), suit});
        }
    }

    random_device rd;
    shuffle(deck.begin(), deck.end(), mt19937(rd()));

    // Split deck between player and computer
    deque<Card> playerDeck, computerDeck;
    for (size_t i = 0; i < deck.size(); ++i) {
        (i % 2 == 0) ? playerDeck.push_back(deck[i]) : computerDeck.push_back(deck[i]);
    }

    // Game loop
    while (!playerDeck.empty() && !computerDeck.empty()) {
        cout << "\nPress Enter to play a round...";
        cin.ignore();

        // Draw cards
        Card playerCard = playerDeck.front();
        Card computerCard = computerDeck.front();
        playerDeck.pop_front();
        computerDeck.pop_front();

        cout << "Your card: " << getCardString(playerCard) << endl;
        cout << "Computer's card: " << getCardString(computerCard) << endl;

        // Compare card values
        int playerRank = getRankValue(playerCard.rank);
        int computerRank = getRankValue(computerCard.rank);

        if (playerRank > computerRank) {
            cout << "You win this round!\n";
            playerDeck.push_back(playerCard);
            playerDeck.push_back(computerCard);
        }
        else if (computerRank > playerRank) {
            cout << "Computer wins this round!\n";
            computerDeck.push_back(computerCard);
            computerDeck.push_back(playerCard);
        }
        else {
            cout << "Tie! Both cards are discarded.\n";
        }

        cout << "Your remaining cards: " << playerDeck.size() << endl;
        cout << "Computer's remaining cards: " << computerDeck.size() << endl;
    }

    // Determine final result
    if (playerDeck.empty() && computerDeck.empty()) {
        cout << "\nGame Over! It's a draw!\n";
    }
    else if (playerDeck.empty()) {
        cout << "\nGame Over! Computer wins!\n";
    }
    else {
        cout << "\nGame Over! You win!\n";
    }

    return 0;
}