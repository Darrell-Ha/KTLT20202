#include <iostream>
#include <math.h>
#include <iomanip>

#define ld long double
using namespace std;

ld eps;
int count=0;

ld f(ld x){                                 // insert hàm cần khảo sát vào đây
    return sin(x)+cos(x)+1;
}       
bool signOfPulp (ld(*f)(ld), ld pulp1, ld pulp2);   // Đánh giá khoảng ly nghiệm f(a).f(b)<0? + thử dùng con trỏ hàm
ld BisecMethod_recur(ld pulp1, ld pulp2);           // PP chia đôi dạng đệ quy  =>> để lấy ngay lập tức kết quả
void BisecMethod_simple(ld pulp1, ld pulp2);        // PP chia đôi dùng While   =>> để diễn giải quá trình tìm nghiệm


int main(){
    ld a,b;
    cout << "Nhap khoang (a,b) va sai so epsilon: ";
    cin >> a >> b >> eps;
    if(!signOfPulp(f, a, b)){
        cout << fixed << setprecision(-log10(eps));
        ld x = BisecMethod_recur(a,b); 
        cout << "Nghiem can tim la: " << x ;
        cout << "\nThu khao sat nghiem bang phuong phap Chia doi:";
        BisecMethod_simple(a,b);
    }else{
        cout << "Khoang phan ly nghiem ko thoa man f(a).f(b)<0!\n";
    }
    return 0;
}

bool signOfPulp (ld(*f)(ld), ld pulp1, ld pulp2){
    return f(pulp1)*f(pulp2)>0;
}
ld BisecMethod_recur(ld pulp1, ld pulp2){
    ld mid = (pulp1+pulp2)/2;
    if(f(mid) == 0 || pulp2-pulp1 <= 2*eps){
        return mid;
    }else{
        if(signOfPulp(f, pulp1, mid)){
            return BisecMethod_recur(mid, pulp2);
        }else{
            return BisecMethod_recur(pulp1, mid);
        }
    }
}
void BisecMethod_simple(ld pulp1, ld pulp2){
    while(pulp2-pulp1 > 2*eps){
        ld mid = (pulp1+pulp2)/2;
        cout <<"\n" << ++count << ".f(" << mid <<")= " <<f(mid);
        if(f(mid)==0){
            break;
        }
        if(signOfPulp(f, mid, pulp1)){
            pulp1 = mid;
        }else{
            pulp2 = mid;
        }
    }
}