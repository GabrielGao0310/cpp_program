#include <iostream>
#include<opencv2/opencv.hpp>//引入头文件

using namespace std;
using namespace cv;//命名空间

//opencv机器视觉库 提供了很多功能给我们使用，都是以函数的形式提供的，学会如何使用函数

int main(int argc, char *argv[])
{

    //1.显示1张图片
    Mat image = imread("d:/test.png");
    imshow("1",image);

    //2.图片转换成hsv格式
    Mat hsv;
    cvtColor(image,hsv,COLOR_BGR2HSV);
    imshow("2",hsv);

    //3.截取颜色空间范围  抠蓝色  抠出来模板 呈白色的模板  不在hsv范围内 呈黑色
    Mat mask;//抠出了背景图的模板
    inRange(hsv,Scalar(100,43,46),Scalar(124,255,255),mask);
    imshow("3",mask);

    //4.其实我们需要抠的是人像，取反操作
    bitwise_not(mask,mask);
    imshow("4",mask);//此时的mask就是人像抠图模板了

    //5.生成一张红色背景图   大小、 类型参考 image原始图片   :: 调用Mat里面的成员函数 zeros（）
    Mat redBack = Mat::zeros(image.size(),image.type());//zeros() 创建矩阵，像素都为0
    redBack = Scalar(40,40,200);//BGR  蓝绿红
    imshow("5",redBack);

    //6.图片实现拷贝操作
    image.copyTo(redBack,mask);
    imshow("6",redBack);

    waitKey(0);//当参数为0的时候，表示等待用户按下任意键

    return 0;//程序正常结束
}

/*

    //1.显示一张图片   imread读取一张图片
    Mat img = imread("d:/niu0.jpg");//Mat（容器对象）类型的变量img   \n \t
    imshow("title",img);//显示一张图片

    //2.图片转模糊处理  -①车牌识别 人脸识别....
    Mat blurImg;
    blur(img,blurImg,Size(50,50));//模糊处理函数  Size(横向模糊尺寸，纵向模糊尺寸)
    imshow("blur",blurImg);

    //3.图片转灰色处理
    Mat grayImg;
    cvtColor(img,grayImg,COLOR_BGR2GRAY);//颜色处理函数
    imshow("gray",grayImg);

    //4.图片做二值化处理
    Mat threImg;
    threshold(grayImg,threImg,100,255,THRESH_BINARY);//二值化处理
    imshow("thre",threImg);

*/






