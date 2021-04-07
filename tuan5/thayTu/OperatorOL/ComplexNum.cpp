#include <iostream>
#include <cstdlib>
#include <ctime>
#define Mac_randomIN(a,b) (rand()%(b-a+1))+a
using namespace std;

class ComplexNum {
    private:
        float real, img;
    public:
        friend float scalar(ComplexNum a, ComplexNum b){
            return a.real*b.real+a.img*b.img;
        }
        ComplexNum inverseNum(){
            ComplexNum inverse;
            inverse.real = this->real;
            inverse.img = - this->img;
            return inverse;
        } 
        ComplexNum(float real = 0, float img = 0){
            this->img = img;
            this->real = real;
        }
        friend ComplexNum operator + (ComplexNum a, ComplexNum b){
            ComplexNum sum;
            sum.real = a.real + b.real;
            sum.img = a.img + b.img;
            return sum;
        }
        friend ComplexNum operator - (ComplexNum a, ComplexNum b){
            ComplexNum subtract;
            subtract.real = a.real - b.real;
            subtract.img = a.img - b.img;
            return subtract;
        }
        friend ComplexNum operator * (ComplexNum a, ComplexNum b){
            ComplexNum product;
            product.real = a.real * b.real - a.img * b.img;
            product.img = a.real * b.img + a.img * b.real;
            return product;
        }
        friend ComplexNum operator /(ComplexNum a, ComplexNum b){
            ComplexNum result;
            if(b.real == 0 && b.img ==0){
                cout << "Error!!! \n";
            }else{
                float scalarB = scalar(b,b);
                result.real = scalar(a,b) / scalar(b,b);
                result.img = (a.img * b.real - a.real * b.img)/scalarB;
            }
            return result;
        }
        friend ostream &operator<<(ostream &os, ComplexNum num){
            if(num.img < 0){
                os << num.real << " - " << -num.img << "i";
            }else if (num.img == 0){
                os << num.real;
            }else{
                os << num.real << " + " << num.img << "i";
            }
            return os;
        }
};

int main(){
    srand(time(NULL));
    /// phần thực và ảo có giá trị nằm trong (-20,20)
    ComplexNum num1 = ComplexNum(Mac_randomIN(-20,20),Mac_randomIN(-20,20));
    ComplexNum num2 = ComplexNum(Mac_randomIN(-20,20),Mac_randomIN(-20,20));

    cout << "a = " << num1 << "\n";
    cout << "b = " << num2 << "\n";
    cout << "a + b = " << num1 + num2 << "\n";
    cout << "a - b = " << num1 - num2 << "\n";
    cout << "a * b = " << num1 * num2 << "\n";
    cout << "a / b = " << num1 / num2 << "\n";
}