// A C++ code to solve The Knight's Tour problem
// Uses recursion and backtracking
# include <bits/stdc++.h>
using namespace std;

int solveTKTOutil(int x, int y, int moveIndex, int sol[8][8], int xMove[], int yMove[]);

int isSafe(int x, int y, int sol[8][8]){
    if (x >= 0 && y >= 0 && x < 8 && y < 8 && sol[x][y] == -1){
        return 1;
    }else{
        return 0;
    }
}

void printSol(int sol[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << " " << setw(2) << sol[i][j] << " ";
        }
        cout << endl;
    }
}

//This function will be used to start solving the problem
int solveTKTO(){
    // Initialize a 8x8 matrix for the board that the knight can travel on
    int sol[8][8];

    //Fill the matrix with a value of chosing to be considered as empty
    for(int i = 0; i<8; i++){
        for(int j = 0; j<8; j++){
            sol[i][j] = -1;
        }
    }

    /*xMove[] and yMove[] difine the next move of the knight by considering the board as a 2d axis plane
    xMove[] is the next value for the x coordinate
    yMove[] is the next value for the y coordinate
    xMove and yMove needs to be taken as matching pairs
    */
   int xMove[] = { 2, 1, -1, -2, -2, -1, 1, 2 };
   int yMove[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

   //Knight is initially at the first block i.e. [0][0]
   sol[0][0] = 0; //marked as visited

   //Now use the utility function defined to start from 0,0 and explore all possible paths
   // Utility function will return 0 if a path was not found otherwise it will return 1
   if(solveTKTOutil(0,0,1,sol,xMove,yMove) == 0){
    cout << "Solution not found\n";
    return 0;
   }else{
    cout << "Solution found!\n";
    printSol(sol);
   }
   return 1;
}

int solveTKTOutil(int x, int y, int moveIndex, int sol[8][8], int xMove[], int yMove[]){
    int k, nextX, nextY;
    if (moveIndex == 8*8){
        return 1;
    }

    //Try all possible moves from the current index x,y
    for(k = 0; k < 8; k++){
        nextX = x + xMove[k];
        nextY = y + yMove[k];
        // We need to check whether the next planned move is possible/safe
        // For that we will use a isSafe function 
        if (isSafe(nextX, nextY, sol)){
            sol[nextX][nextY] = moveIndex;
            if (solveTKTOutil(nextX, nextY, moveIndex + 1, sol, xMove, yMove) == 1){
                return 1;
            }else{
                sol[nextX][nextY] = -1;
            }
        }
    }
    return 0;
}

//Driver Code
int main(){
    solveTKTO();
    return 0;
}
