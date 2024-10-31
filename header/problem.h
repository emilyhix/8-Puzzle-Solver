#ifndef PROBLEM_H
#define PROBLEM_h

class Problem {
    private:
        int initial_state[9];
        int goal_state[9] = {1, 2, 3,
                             4, 5, 6,
                             7, 8, 0};
    public:
        Problem(int inital_Input[9]) {
            initial_state [0] = inital_Input[0];
            initial_state [1] = inital_Input[1];
            initial_state [2] = inital_Input[2];
            initial_state [3] = inital_Input[3];
            initial_state [4] = inital_Input[4];
            initial_state [5] = inital_Input[5];
            initial_state [6] = inital_Input[6];
            initial_state [7] = inital_Input[7];
            initial_state [8] = inital_Input[8];
        }                 
};

#endif