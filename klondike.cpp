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
// copy constructor
// copy assignment operator
void klondike::play() {
    this->startGame();
    while (true) {
        if (this->userMove() == 3) {
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
    Deck* tableaus[] = {this->tableau1, this->tableau2, this->tableau3, this->tableau4, this->tableau5, this->tableau6, this->tableau7};
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
}
int klondike::userMove() {
    cout << "Options:" << endl;
    cout << "1.) Draw card from draw pile" << endl;
    cout << "2.) Move card" << endl;
    cout << "3.) Exit game" << endl;
    cout << "Enter a number: ";
    int input;
    cin >> input;
    switch (input) {
        case 1:
            if (this->deck->size() != 0) {
                this->deck->MoveLastCardTo(*this->drawPile);
                this->drawPile->getDeck()->getTail()->getData()->setFaceDown(false);
            } else {
                cout << "There are no cards left in the deck!" << endl;
            }
            return 1;
        case 2:
            cout << "Enter source pile: ";
            // FIXME working on it
            return 2;
        case 3:
            cout << "Exiting game..." << endl;
            return 3;
        default:
            cout << "Invalid input. Please try again!" << endl;
            return -1;
    }
}
bool klondike::moveCardCheck(Deck &source, Deck &target) const {

}
Deck *klondike::getTargetDeck(const std::string& initials) const {
    switch (initials) {
        case "T1": return tableau1;
        case "T2": return tableau2;
        case "T3": return tableau3;
        case "T4": return tableau4;
        case "T5": return tableau5;
        case "T6": return tableau6;
        case "T7": return tableau7;
        case "DP": return drawPile;
        case "SF": return spadeFoundation;
        case "HF": return heartFoundation;
        case "DF": return diamondFoundation;
        case "CF": return cloverFoundation;
        default: return nullptr;
    }
}
