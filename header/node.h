#ifndef NODE_H
#define NODE_H
#include <cmath>
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
        double hN;
        double gN;
        int goal_matrix[3][3] = {1 ,2 ,3,
                                  4, 5, 6,
                                  7, 8, 0};
        Operations operation;

    public:
        Node(int, int setInitial[9]); //create initial node
        Node(int, Operations, Node); //create children
        bool operator<(const Node &) const; //overloading operators for prio queue
        bool operator>(const Node &) const;
        bool operator== (const Node &);
        Node& operator=(const Node &);
        void updateState(int); //updates the locations of the #s on the board and the h(n) value
        bool Valid(); //checks location of 0 and determines which moves are valid
        int getInitial(int); //returns inital board
        int getgN(); //returns g(n)/depth/cost per move
        double gethN(); //returns h(n)
        int getGoalMatrix(int, int); //returns the goal state in matrix form
        void printNode(); //prints specified node to terminal
        bool checkFinal(); //checks if current node == goal node
        int AStarMTHeuristic(int board[9]); //calculates h(n) for A* misplaced tile
        double AStarEDHeuristic(int board[9]); //calculates h(n) for A* euclidean distance
};

#endif