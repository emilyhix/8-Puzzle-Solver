#include "..\header\printMenu.h"

void printMenu() {
    int puzzleChoice = 0;
    int algorithmChoice = 0;
    int initialTile[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int input;

    cout << "Welcome to ehix001-sphim001 8 puzzle solver." << endl;
    cout << "Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle." << endl;
    cin >> puzzleChoice;

    if (puzzleChoice == 1) {
        // default puzzle
        initialTile [0] = 1;
        initialTile [1] = 0;
        initialTile [2] = 3;
        initialTile [3] = 4;
        initialTile [4] = 2;
        initialTile [5] = 6;
        initialTile [6] = 7;
        initialTile [7] = 5;
        initialTile [8] = 8;

        // OUTPUT USER INPUT
        // for (int i = 0; i < 9; ++i) {
        //     cout << initialTile[i] << " ";
        // }
        cout << endl;
    }
    else if (puzzleChoice == 2) {
        // user puzzle
        cout << "Enter your puzzle, use a zero to represent the blank" << endl;
        cout << "Enter the first row, use a space or tabs between numbers" << endl;
        for (int i = 0; i < 3; i++) {
            cin >> input;
            initialTile[i] = input;
        }
        cout << "Enter the second row, use space or tabs between numbers" << endl;
        for (int i = 0; i < 3; i++) {
            cin >> input;
            initialTile[i+3] = input;
        }
        cout << "Enter the third row, use space or tabs between numbers" << endl;
        for (int i = 0; i < 3; i++) {
            cin >> input;
            initialTile[i+6] = input;
        }
        cout << endl;
        // OUTPUT USER INPUT
        // for (int i = 0; i < 9; ++i) {
        //     cout << initialTile[i] << " ";
        // }
    }

    while(algorithmChoice == 0){
        
        cout << "Enter your choice of algorithm" << endl;
        cout << "1) Uniform Cost Search" << endl;
        cout << "2) A* with the Misplaced Tile heuristic." << endl;
        cout << "3) A* with the Euclidean distance heuristic." << endl << endl;
        cin >> algorithmChoice;

        if(algorithmChoice == 1 || algorithmChoice == 2 || algorithmChoice == 3){
            Node parent(algorithmChoice, initialTile);
            (Search(algorithmChoice, parent)).printNode();
        }
        else{
            cout << "Enter your choice of algorithm" << endl;
            cout << "1) Uniform Cost Search" << endl;
            cout << "2) A* with the Misplaced Tile heuristic." << endl;
            cout << "3) A* with the Euclidean distance heuristic." << endl << endl;
        }
    }    
    return;
}