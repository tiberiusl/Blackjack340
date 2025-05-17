#include "klondike.h"

#include <iostream>
using namespace std;

klondike::klondike() {
    this->deck = new Deck();
    this->drawPile = new Deck();
    this->spadeFoundation = new Deck();
    this->heartFoundation = new Deck();
    this->diamondFoundation = new Deck();
    this->cloverFoundation = new Deck();
    this->tableau1 = new Deck();
    this->tableau2 = new Deck();
    this->tableau3 = new Deck();
    this->tableau4 = new Deck();
    this->tableau5 = new Deck();
    this->tableau6 = new Deck();
    this->tableau7 = new Deck();
}

klondike::~klondike() {
    delete this->deck;
    delete this->drawPile;
    delete this->spadeFoundation;
    delete this->heartFoundation;
    delete this->diamondFoundation;
    delete this->cloverFoundation;
    delete this->tableau1;
    delete this->tableau2;
    delete this->tableau3;
    delete this->tableau4;
    delete this->tableau5;
    delete this->tableau6;
    delete this->tableau7;
}

klondike::klondike(const klondike &original) {
    this->deck = new Deck(*original.deck);
    this->drawPile = new Deck(*original.drawPile);
    this->spadeFoundation = new Deck(*original.spadeFoundation);
    this->heartFoundation = new Deck(*original.heartFoundation);
    this->diamondFoundation = new Deck(*original.diamondFoundation);
    this->cloverFoundation = new Deck(*original.cloverFoundation);
    this->tableau1 = new Deck(*original.tableau1);
    this->tableau2 = new Deck(*original.tableau2);
    this->tableau3 = new Deck(*original.tableau3);
    this->tableau4 = new Deck(*original.tableau4);
    this->tableau5 = new Deck(*original.tableau5);
    this->tableau6 = new Deck(*original.tableau6);
    this->tableau7 = new Deck(*original.tableau7);
}

klondike &klondike::operator=(const klondike &original) {
    if (this == &original) return *this;
    delete this->deck;
    this->deck = new Deck(*original.deck);
    delete this->drawPile;
    this->drawPile = new Deck(*original.drawPile);
    delete this->spadeFoundation;
    this->spadeFoundation = new Deck(*original.spadeFoundation);
    delete this->heartFoundation;
    this->heartFoundation = new Deck(*original.heartFoundation);
    delete this->diamondFoundation;
    this->diamondFoundation = new Deck(*original.diamondFoundation);
    delete this->cloverFoundation;
    this->cloverFoundation = new Deck(*original.cloverFoundation);
    delete this->tableau1;
    this->tableau1 = new Deck(*original.tableau1);
    delete this->tableau2;
    this->tableau2 = new Deck(*original.tableau2);
    delete this->tableau3;
    this->tableau3 = new Deck(*original.tableau3);
    delete this->tableau4;
    this->tableau4 = new Deck(*original.tableau4);
    delete this->tableau5;
    this->tableau5 = new Deck(*original.tableau5);
    delete this->tableau6;
    this->tableau6 = new Deck(*original.tableau6);
    delete this->tableau7;
    this->tableau7 = new Deck(*original.tableau7);
    return *this;
}

void klondike::play() {
    this->startGame();
    while (true) {
        if (this->getUserMove() == EXIT_GAME) {
            break;
        }
        this->showBoard();
    }
}

void klondike::startGame() {
    this->deck->KlondikeFill();
    for (unsigned int i = 0; i < 7; ++i) {
        this->deck->shuffle();
    }
    Deck* tableaus[] = {this->tableau1, this->tableau2, this->tableau3,
        this->tableau4, this->tableau5, this->tableau6, this->tableau7};
    for (unsigned int cardCount = 1; cardCount <= 7; ++cardCount) {
        for (unsigned int tableau = cardCount - 1; tableau < 7; ++tableau) {
            this->deck->MoveLastCardTo(*tableaus[tableau]);
        }
    }
    for (unsigned int i = 0; i < 7; ++i) {
        tableaus[i]->getDeck()->getTail()->getData()->setFaceDown(false);
    }
    this->showBoard();
}

void klondike::showBoard() const {
    cout << endl;
    cout << "Draw pile: [";
    if (this->drawPile->size() > 0) {
        this->drawPile->getDeck()->getTail()->getData()->DisplayCard();
    }
    cout << "]" << endl;

    cout << "Foundations: ";
    Deck* foundations[] = {spadeFoundation, heartFoundation, diamondFoundation, cloverFoundation};
    for (int i = 0; i < 4; i++) {
        cout << "[";
        if (foundations[i]->size() > 0) {
            foundations[i]->getDeck()->getTail()->getData()->DisplayCard();
        }
        cout << "] ";
    }
    cout << endl;

    const Deck* tableaus[] = {tableau1, tableau2, tableau3, tableau4, tableau5, tableau6, tableau7};
    for (int i = 0; i < 7; i++) {
        cout << "T" << i + 1 << ": ";
        tableaus[i]->KlondikePrintDeck();
        cout << endl;
    }
    cout << endl;
}

int klondike::getUserMove() {
    cout << "Options:" << endl;
    cout << " (" << EXIT_GAME << ") Exit game" << endl;
    cout << " (" << DRAW_CARD << ") Draw a card" << endl;
    cout << " (" << MOVE_CARD << ") Move a card" << endl;
    cout << "Enter a number: ";
    int input;
    cin >> input;
    switch (input) {
        case EXIT_GAME:
            cout << "Exiting game..." << endl;
            return EXIT_GAME;
        case DRAW_CARD:
            this->drawCard();
            return DRAW_CARD;
        case MOVE_CARD:
            this->moveCard();
            return MOVE_CARD;
        default:
            cout << "Invalid input. Please try again!" << endl;
            return -1;
    }
}

void klondike::drawCard() const {
    if (this->deck->size() != 0) {
        this->deck->MoveLastCardTo(*this->drawPile);
        this->drawPile->getDeck()->getTail()->getData()->setFaceDown(false);
    } else {
        cout << "There are no cards left to draw!" << endl;
    }
}

void klondike::moveCard() {
    string sourcePile, targetPile;
    cout << "List of piles: " << endl;
    cout << " - Tableaus: T1, T2, T3, T4, T5, T6, T7" << endl;
    cout << " - Draw pile: DP" << endl;
    cout << " - Foundations: SF (spades), HF (hearts), DF (diamonds), CF (clovers)" << endl;
    cout << "Enter the pile to move a card from: ";
    cin >> sourcePile;
    while (this->getTargetDeck(sourcePile) == nullptr) {
        cout << "Invalid pile! Please enter again: ";
        cin >> sourcePile;
    }
    Deck *sourceDeck = this->getTargetDeck(sourcePile);
    cout << "Enter the pile to move a card to: ";
    cin >> targetPile;
    while (this->getTargetDeck(targetPile) == nullptr) {
        cout << "Invalid pile! Please enter again: ";
        cin >> targetPile;
    }
    Deck *targetDeck = this->getTargetDeck(targetPile);
    // FIXME check move validity
    // additional nullptr check
    if (sourceDeck == nullptr || targetDeck == nullptr) {
        cout << "Invalid move: source or target deck is nullptr!" << endl;
        return;
    }
    // additional check for empty source deck
    if (sourceDeck->size() == 0) {
        cout << "Invalid move: source deck has no card to move!" << endl;
        return;
    }
    if (this->moveCardCheck(*sourceDeck, *targetDeck)) {
        sourceDeck->MoveLastCardTo(*targetDeck);
        targetDeck->getDeck()->getTail()->getData()->setFaceDown(false);
        if (sourceDeck->size() > 0) sourceDeck->getDeck()->getTail()->getData()->setFaceDown(false);
    } else {
        cout << "Invalid move! Please try again!" << endl;
    }

}

bool klondike::moveCardCheck(Deck &source, Deck &target) const {
    const Card* sourceCard = source.getDeck()->getTail()->getData();

    // debug output
    cout << "Moving: ";
    sourceCard->DisplayCard();
    cout << " to ";
    if (target.getDeck()->size() > 0) {
        target.getDeck()->getTail()->getData()->DisplayCard();
    } else {
        cout << "empty pile";
    }
    cout << endl;

    // for empty target decks:
    if (target.getDeck()->size() == 0) {
        // empty foundations only allow aces
        if (&target == this->spadeFoundation || &target == this->heartFoundation ||
            &target == this->diamondFoundation || &target == this->cloverFoundation) {
            return (sourceCard->getVal() == 1) && (
                (&target == this->spadeFoundation && sourceCard->getSuit() == "Spade") ||
                (&target == this->heartFoundation && sourceCard->getSuit() == "Heart") ||
                (&target == this->diamondFoundation && sourceCard->getSuit() == "Diamond") ||
                (&target == this->cloverFoundation && sourceCard->getSuit() == "Clover"));
        }
        // empty tableaus only allow kings
        return sourceCard->getVal() == 13;
    }

    // for non-empty target decks:
    const Card* targetCard = target.getDeck()->getTail()->getData();
    const bool sameSuit = (sourceCard->getSuit() == targetCard->getSuit());
    const bool sameColor = (sourceCard->getColor() == targetCard->getColor());
    const bool oneRankHigher = (sourceCard->getVal() == targetCard->getVal() + 1);
    const bool oneRankLower = (sourceCard->getVal() == targetCard->getVal() - 1);


    // case 1: draw pile -> foundation
    if (&source == this->drawPile && (&target == this->spadeFoundation || &target == this->heartFoundation || &target == this->diamondFoundation || &target == this->cloverFoundation)) {
        return (sameSuit && oneRankHigher);
    }
    // case 2: draw pile -> tableau
    if (&source == this->drawPile && (&target == this->tableau1 || &target == this->tableau2 || &target == this->tableau3 || &target == this->tableau4 || &target == this->tableau5 || &target == this->tableau6 || &target == this->tableau7)) {
        return (!sameColor && oneRankLower);
    }
    // case 3: tableau -> foundation
    if ((&source == this->tableau1 || &source == this->tableau2 || &source == this->tableau3 || &source == this->tableau4 || &source == this->tableau5 || &source == this->tableau6 || &source == this->tableau7) && (&target == this->spadeFoundation || &target == this->heartFoundation || &target == this->diamondFoundation || &target == this->cloverFoundation)) {
        return (sameSuit && oneRankHigher);
    }
    // case 4: tableau -> tableau (multiple cards can be moved at once)
    if ((&source == this->tableau1 || &source == this->tableau2 || &source == this->tableau3 || &source == this->tableau4 || &source == this->tableau5 || &source == this->tableau6 || &source == this->tableau7) && (&target == this->tableau1 || &target == this->tableau2 || &target == this->tableau3 || &target == this->tableau4 || &target == this->tableau5 || &target == this->tableau6 || &target == this->tableau7)) {
        // FIXME moving multiple cards?
        return (!sameColor && oneRankLower);
    }
    // case 5: foundation -> tableau
    if ((&source == this->spadeFoundation || &source == this->heartFoundation || &source == this->diamondFoundation || &source == this->cloverFoundation) && (&target == this->tableau1 || &target == this->tableau2 || &target == this->tableau3 || &target == this->tableau4 || &target == this->tableau5 || &target == this->tableau6 || &target == this->tableau7)) {
        return (!sameColor && oneRankLower);
    }
    return false;
}

Deck *klondike::getTargetDeck(const string& initials) const {
    if (initials == "T1") {
        return tableau1;
    } else if (initials == "T2") {
        return tableau2;
    } else if (initials == "T3") {
        return tableau3;
    } else if (initials == "T4") {
        return tableau4;
    } else if (initials == "T5") {
        return tableau5;
    } else if (initials == "T6") {
        return tableau6;
    } else if (initials == "T7") {
        return tableau7;
    } else if (initials == "DP") {
        return drawPile;
    } else if (initials == "SF") {
        return spadeFoundation;
    } else if (initials == "HF") {
        return heartFoundation;
    } else if (initials == "DF") {
        return diamondFoundation;
    } else if (initials == "CF") {
        return cloverFoundation;
    } else {
        return nullptr;
    }
}