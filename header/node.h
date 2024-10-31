#ifndef NODE_H
#define NODE_H

enum Operations {UP, DOWN, LEFT, RIGHT};
#include <iostream>
using namespace std;

class Node{
    private:
        int initial_state[9];
        int goal_state[9] = {1, 2, 3,
                             4, 5, 6,
                             7, 8, 0};
        int current_state[9];
        int hN;
        int gN;
        Operations operation;

    public:
        Node(int, int setInitial[9]); //create parent
        Node(int, Operations, Node); //create children
        void updateState();
        bool Valid();
        int getInitial(int);
        int getgN();
        int gethN();
        void printNode();
        bool checkFinal();
};

#endif