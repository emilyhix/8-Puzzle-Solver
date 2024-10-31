#include <iostream>
using namespace std;

void printMenu() {
    int puzzleChoice = 0;
    int algorithmChoice = 0;

    cout << "Welcome to ehix001-sphim001 8 puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> puzzleChoice;
    cout << "Enter your puzzle, use a zero to represent the blank" << endl;
    cout << "Enter the first row, use a space or tabs between numbers" << endl;
    cout << "Enter the second row, use space or tabs between numbers" << endl;
    cout << "Enter the third row, use space or tabs between numbers" << endl;
    cout << endl;
    cout << "Enter your choice of algorithm" << endl;
    cout << "Uniform Cost Search" << endl;
    cout << "A* with the Misplaced Tile heuristic." << endl;
    cout << "A* with the Euclidean distance heuristic." << endl << endl;
    cin >> algorithmChoice;
    return;
}