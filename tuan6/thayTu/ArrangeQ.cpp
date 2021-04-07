#include <iostream>
#include <iomanip>

#define sizeTable 8
using namespace std;

int col[sizeTable];
bool diagNE_SW[2*sizeTable-1];
bool diagNW_SE[2*sizeTable-1];
bool row[sizeTable];
int countSolution = 0;

void PrintTable(int count); //
void SetQueen(int colTab);
void SetupTable(int colTab, int position, bool value);
bool Check(int colTab, int position);

int main(){
    SetQueen(0);
    return 0;
}
void PrintTable(int count){//
    cout << "\tDap an thu " << count <<": \n";
    cout << "\t=============================\n";
    for(int i = 0; i < sizeTable; i++){
        cout << "\t" <<setw(8);
        for(int j = 0; j < sizeTable; j++){
            if (j == col[i]){
                cout << "Q ";
            }else{
                cout << "_ ";
            }
        }
        cout << "\n";
    }
    cout << "\t=============================\n\n";
}
void SetupTable(int colTab, int position, bool value){
    row[position] = value;
    diagNE_SW[colTab + position] = value;
    diagNW_SE[position - colTab + sizeTable-1] = value;
    if(value){
        col[colTab] = position;
    }else{
        col[colTab] = 0;
    }
}
bool Check(int colTab, int position){
    if(row[position] || diagNE_SW[colTab+position] || diagNW_SE[position - colTab + sizeTable-1]){
        return false;
    }else{
        return true;
    }
}

//
void SetQueen(int colTab){ 
    if (colTab == sizeTable){
        PrintTable(++countSolution);
        return;
    }  
    for(int position = 0; position < sizeTable; position++){    
        if(Check(colTab, position)){ ///
            SetupTable(colTab, position, true);
            SetQueen(colTab+1);
            SetupTable(colTab, position, false);
        }
    }
}
