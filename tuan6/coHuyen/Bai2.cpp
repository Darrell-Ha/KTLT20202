#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void Bai2_1(string str);
string Bai2_2(string str);
void Bai2_3();
void InputString(string str); 

int main(){
    string str ;
    system("cls");
    cout << "Nhap xau ky tu: ";
    getline(cin,str);
    cout << "\tBai 2.1: in ra xau dao nguoc ma khong lam thay doi xau cu\n";
    Bai2_1(str);
    cout << "\tBai 2.2: tao 1 xau ky tu la xau dao nguoc cua xau duoc nhap\n";
    string rts = Bai2_2(str);
    cout << "Chuoi ban dau: " << str << "\n";
    cout << "Chuoi dao nguoc duoc tao ra: " << rts << "\n"; 
    cout << "Chuoi ban dau: " << str << "\n";
    cout << "\tBai 2.3: Nhap vao 1 xau roi chuyen ngay thanh xau dao nguoc\n";
    Bai2_3();
    return 0;
}

void Bai2_1(string str){
    string rts = "";
    cout << "Chuoi ban dau: " << str << "\n";
    cout << "Chuoi dao nguoc: "; 
    for(int i = str.size(); i>-1; i--){
        cout << str[i];
    }
    cout << "\nChuoi ban dau: " << str << "\n";
}
string Bai2_2(string str){
    string rts = "";
    for(int i = str.size(); i>-1; i--){
        rts+=str[i];
    }
    return rts;
}
void Bai2_3(){
    string str2_3;
    cout << "Nhap xau: ";
    getline(cin,str2_3);
    str2_3 = Bai2_2(str2_3);
    cout << "Chuoi vua duoc nhap la: " << str2_3;
}