/***
 * Sau khi tìm hiểu từ nhiều nguồn như StackOverFlows,...
 * Ý tưởng của bạn An Việt Trung là hiệu quả nhất
 * Chương trình của bạn còn có thêm chức năng resize ảnh theo nhu cầu
 * !!!!!!!!!!!!!!!----------Bài code dưới đây không có chức năng đó---------!!!!!!!!!!!
 * 
 * GITHUB của bạn:
 * https://github.com/anviettrung/HUST-Adv-Programming-2020.2/tree/master/Week3
 * 
 * Bài tập tham khảo từ bài của bạn An Việt Trung
 * ở đây đã cố định fixed width của pic là 400
 * ý tưởng của bạn: 
 *             - sử dụng stb_image.h chứa những hàm
 *                  + stbi_load(ảnh, chiều rộng(x), chiều cao ảnh, thông số biểu thị số bit màu của ảnh, 3- cố định để in ASCII)
 *                      =>>>> thu được "imgArr" là một mảng gồm các giá trị từ 0-255 (tương ứng 0= đen ----255= trắng)
 *             - sử dụng stdint.h để sử dụng những kiểu dữ liệu cụ thể số bit cho integer (cố định 8 bit)
 *             - (grayscale) với bộ màu RGB tương ứng, 
 *                      thực hiện lấy trung bình rgb/3 để thu được giá trị trong dải màu XÁM trong RGB
 *             - ô pixel với độ grayscale tương ứng, 
 *                      hàm grayScale_toIntensity(grayscale) sẽ cho một kí tự ASCII phù hợp trong char* brightness (kí tự có độ dày tăng dần)
 *             - sau khi có được pixel, thực hiện in ra từng dòng theo chiều rộng của ảnh (x), kết thúc dòng thêm "\n" để xuống dòng
 *             - in file ra testImg.txt
 *             - BONUS: Khi ấn CRTL+A bôi đen thì kết hợp màu xám vs màu xanh sẽ khiến mắt người tự động điền nốt những ô màu:))
 * 
 *  @@@@@ Một lần nữa cảm ơn bạn An Việt Trung vì ý tưởng + code thông minh này @@@@@
***/
#include <iostream>
#include <fstream>
#include <stdint.h>
#include <cmath>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

const char* brightness = " .,-~:;=!*#$@";
const int   brightnessLeng = 12;
struct pixel{
    uint8_t r,g,b;
    uint8_t grayscale;
};

pixel getPixel_byRGB(uint8_t* imgArr, int x, int y, int w){
    pixel pix;
    pix.r=imgArr[3*(y*w+x)];
    pix.g=imgArr[3*(y*w+x)+1];
    pix.b=imgArr[3*(y*w+x)+2];
    pix.grayscale=(pix.r+pix.g+pix.b)/3;

    return pix;
}
char grayScale_toIntensity(uint8_t grayscale){
    float intensity=(grayscale/255.0f)*brightnessLeng;
    return brightness[(int)round(intensity)];
}
string printImage(uint8_t* imgArr, int w, int h){
    pixel pix;
    string lineText;
    int new_h=(float)400/w * h/2.0f;
    float w_ratio=(float)w/400;
    float h_ratio=(float)h/new_h;
    for (int y=0; y<new_h; y++){
        for(int x=0; x<400; x++){
            int cord_x=(int)round(x*w_ratio);
            int cord_y=(int)round(y*h_ratio);
            pix=getPixel_byRGB(imgArr,cord_x,cord_y,w);
            lineText+=grayScale_toIntensity(pix.grayscale);
        }
        lineText+="\n";
    }
    return lineText;
}
int main(){
    int width,height,bpp;
    uint8_t* image;
    string fileName="sami.png";
    fstream f,fileimg;
    f.open(fileName,ios::in);
    fileimg.open("testImg.txt",ios::out|ios::app);
    if(f.is_open()){
        image=stbi_load(fileName.c_str(), &width, &height, &bpp,3);
        fileimg<<printImage(image,width,height);
        stbi_image_free(image);
    }else{
        cout<<"File not found!!\n";
    }
    fileimg.close();
    f.close();
    return 0;
}



