#include <iostream>
#include <string>
using namespace std;
int main(){
    char name1[50];
    string name;

    ////// Run///
    cout<<"Ban la?: ";
    cin.getline(name1,sizeof(name1));           ///// cin.getline đi với char[]
    getline(cin, name);                         ///// getline(cin,"string") 
    cout<<"Chao "<<name1<<", bay gio moi ban "<<name<<" den voi the gioi lap trinh";
    return 0;
}