#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

enum Operations {UP, DOWN, LEFT, RIGHT};

class Node{
    private:
        int initial_state[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        
        int goal_state[9] = {1, 2, 3,
                             4, 5, 6,
                             7, 8, 0};

        int current_state[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        int hN;
        int gN;
        int fN;
        Operations operation;

    public:
        Node(int, int setInitial[9]); //create parent
        Node(int, Operations, Node); //create children
        bool operator<(const Node &) const;
        bool operator== (const Node &);
        Node& operator=(const Node &);
        void updateState();
        bool Valid();
        int getInitial(int);
        int getgN();
        int gethN();
        void printNode();
        bool checkFinal();
};

#endif