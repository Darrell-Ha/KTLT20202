#include <iostream>

using namespace std;

void Hanoi(int quant, long *times, char begin, char end, char mid);

int main(){
    int n;
    long times = 0;
    cout << "Nhap so dia can sap xep theo bai toan \"Thap Ha Noi\": ";
    cin >> n;
    cout << "Voi " << n << " dia tren, can xep tung dia mot nhu sau: \n";
    Hanoi(n, &times, 'A', 'B', 'C');
    return 0;
}
void Hanoi(int n, long *times, char begin, char end, char mid){
    if(n == 1){
        cout << ++(*times) << "\t" << begin << " |=======> " << end <<"\n";
        return;
    }
    Hanoi(n-1,times,begin,mid,end);
    Hanoi(1,times,begin,end,mid);
    Hanoi(n-1,times,mid,end,begin);
}
