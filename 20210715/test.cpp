//根据半径计算圆的周长和面积
#include <iostream.h>
const float PI = 3.1416;        //声明常量(只读变量)PI为3.1416
float fCir_L(float);           //声明自定义函数fCir_L()的原型 
float fCir_S(float);           //声明自定义函数fCir_S()的原型  

//以下是main()函数 
main()
{
    float r, l, s;             //声明3个变量

    cout << "r=";          //显示字符串
    cin >> r;              	//键盘输入
    l = fCir_L(r);          //计算圆的周长，赋值给变量l 
    s = fCir_S(r);          //计算圆的面积，赋值给变量s 
    cout << "l=" << l;       //显示计算结果
    cout << "\ns=" << s;
}

//定义计算圆的周长的函数fCir_L()
float fCir_L(float x)
{
    float z = -1.0;         //声明局部变量
    if (x >= 0.0)          //如果参数大于0，则计算圆的周长
        z = 2 * PI * x;
    return(z);          //返回函数值 
}

//定义计算圆的面积的函数fCir_S()
float fCir_S(float x)
{
    float z = -1.0;         //声明局部变量
    if (x >= 0.0)          //如果参数大于0，则计算圆的面积
        z = PI * x * x;
    return(z);           //返回函数值 
}
/* Program: P1-2.CPP
 Written by: Hap
 Date written: 02:11:10
*/


#include <iostream.h>
void main(void)
{
    double s1, s2, s3;
    s1 = 1.5;    /* 对变量s1赋值*/
    cout << "s1=" << s1 << endl;
    /* 对变量s2赋值*/    s2 = 2.5;
    cout << "s2=" << s2 << endl;
    s3 =  /* 对变量s3赋值*/  3.5;
    cout << "s3=" << s3 << endl;

    cout << "s1+s2+s3=" << s1 + s2 + s3 << endl;        //计算并显示
    //计算并显示 cout<<"s1+s2+s3="<<s1+s2+s3<<endl; 
}
#include <iostream.h>
main()
{
    double  r = 1.0;
    cout << "r=" << r << endl;
    double l;
    l = 2 * 3.1416 * r;           //计算圆的周长，赋值给变量l
    cout << "l=" << l << endl;    //显示圆的周长	
    double s = 3.1416 * r * r;     //计算圆的面积，赋值给变量s 
    cout << "s=" << s << endl;    //显示圆的面积

    cout << "r=";            //显示提示输入的信息
    cin >> r;                 //键盘输入
    l = 2 * 3.1416 * r;           //计算圆的周长，赋值给变量l
    cout << "l=" << l << endl;    //显示圆的周长
    s = 3.1416 * r * r;
    cout << "s=" << s << endl;    //显示圆的面积
}
#include <iostream.h>    //包含iostream.h头文件
void main()
{
    //输出字符常量、变量和字符串
    char c1 = 'A';
    cout << 'W';
    cout << c1 << endl;
    cout << "This is a test." << endl;
    cout << "------------------" << endl;

    //输出整型常量、变量和表达式
    int n = 100;
    cout << 10;
    cout << n;
    cout << 2 * n << endl;   //输出整型表达式
    cout << "------------------" << endl;

    //输出浮点型常量、变量和表达式
    double pi = 3.1415926, r = 10.0, s = pi * r * r;
    cout << pi << endl;
    cout << r;
    cout << s;
    cout << 2 * r * pi << endl;      //输出浮点型表达式
    cout << "------------------" << endl;

    //一个cout可以输出多项数据
    cout << 'W' << " " << c1 << endl;
    cout << "This is a test." << endl;
    cout << "pi=" << pi << " r=" << r << " s=" << s << endl;
}