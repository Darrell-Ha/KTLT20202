#include <iostream>

using namespace std; 

int choice, count = 0;
bool picked[10] = {false};
int permt[10];
void PrintPermt(int count);
void Pick(int position);

int main(){
    //cout << "Nhap so n de tim hoan vi cua 1,2,3...,n: ";
    //cin >> choice;
    choice = 5;
    Pick(1);
    return 0;
}
void PrintPermt(int count){
    cout << count << ": ";
    for(int i = 1; i <= choice; i++){
        cout << permt[i] << " ";
    }
    cout << "\n";
}
void Pick(int position){
    for(int i = 1; i <= choice; i++){
        if(!picked[i]){
            permt[position] = i;
            picked[i] = true;
            if(position == choice){
                PrintPermt(++count);
            }else{
                Pick(position+1);
            }
            picked[i] = false;
        }
    }
}