#include <iostream>
#include <string>

using namespace std;

struct DiemHp{
    int maHP;
    float diem;
    
};

struct Sinhvien{
    string name;
    int mssv;

    DiemHp* bangdiem;
    Sinhvien* next;
};

