#include <iostream>
#include <iomanip>

#define sizeTableMAX 20

using namespace std;


int countStep = 0;
int tableProbl[sizeTableMAX][sizeTableMAX] ;
int horseMove_X[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int horseMove_Y[8] = {-1, 1, -2, 2, -2, 2, -1, 1}; 
int sizeOfProbl;
void PrintTable();
void MoveHorse(int x, int y);

int main(){
    int beginX, beginY;
    cout << "Set up size of problem: ";
    cin >> sizeOfProbl;
    cout << "Put the horse to the first place X: ";
    cin >> beginX;
    cout << "Put the horse to the first place Y: ";
    cin >> beginY;
    MoveHorse(beginX, beginY);
    cout << "No Solution";
    return 0;
}

void PrintTable(){
    for(int i = 0; i < sizeOfProbl; i++){
        cout << "\t";
        for(int j = 0; j < sizeOfProbl; j++){
            cout << setw(5) << left <<tableProbl[i][j];
        }
        cout << "\n";
    }
}
void MoveHorse(int x, int y){
    ++countStep;
    tableProbl[x][y] = countStep;
    for(int i = 0; i < 8; i++){
        if(countStep == sizeOfProbl*sizeOfProbl){
            cout << "Solution with each step marked in the table: \n";
            PrintTable();
            exit(0);
        }
        int newX = x + horseMove_X[i];
        int newY = y + horseMove_Y[i];
        if(newX > -1 && newX < sizeOfProbl && newY > -1 && newY < sizeOfProbl && tableProbl[newX][newY]==0){
            MoveHorse(newX, newY);
        }
    }
    --countStep;
    tableProbl[x][y] = 0;
}