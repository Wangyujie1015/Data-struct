//���ݰ뾶����Բ���ܳ������
#include <iostream.h>
const float PI = 3.1416;        //��������(ֻ������)PIΪ3.1416
float fCir_L(float);           //�����Զ��庯��fCir_L()��ԭ�� 
float fCir_S(float);           //�����Զ��庯��fCir_S()��ԭ��  

//������main()���� 
main()
{
    float r, l, s;             //����3������

    cout << "r=";          //��ʾ�ַ���
    cin >> r;              	//��������
    l = fCir_L(r);          //����Բ���ܳ�����ֵ������l 
    s = fCir_S(r);          //����Բ���������ֵ������s 
    cout << "l=" << l;       //��ʾ������
    cout << "\ns=" << s;
}

//�������Բ���ܳ��ĺ���fCir_L()
float fCir_L(float x)
{
    float z = -1.0;         //�����ֲ�����
    if (x >= 0.0)          //�����������0�������Բ���ܳ�
        z = 2 * PI * x;
    return(z);          //���غ���ֵ 
}

//�������Բ������ĺ���fCir_S()
float fCir_S(float x)
{
    float z = -1.0;         //�����ֲ�����
    if (x >= 0.0)          //�����������0�������Բ�����
        z = PI * x * x;
    return(z);           //���غ���ֵ 
}
/* Program: P1-2.CPP
 Written by: Hap
 Date written: 02:11:10
*/


#include <iostream.h>
void main(void)
{
    double s1, s2, s3;
    s1 = 1.5;    /* �Ա���s1��ֵ*/
    cout << "s1=" << s1 << endl;
    /* �Ա���s2��ֵ*/    s2 = 2.5;
    cout << "s2=" << s2 << endl;
    s3 =  /* �Ա���s3��ֵ*/  3.5;
    cout << "s3=" << s3 << endl;

    cout << "s1+s2+s3=" << s1 + s2 + s3 << endl;        //���㲢��ʾ
    //���㲢��ʾ cout<<"s1+s2+s3="<<s1+s2+s3<<endl; 
}
#include <iostream.h>
main()
{
    double  r = 1.0;
    cout << "r=" << r << endl;
    double l;
    l = 2 * 3.1416 * r;           //����Բ���ܳ�����ֵ������l
    cout << "l=" << l << endl;    //��ʾԲ���ܳ�	
    double s = 3.1416 * r * r;     //����Բ���������ֵ������s 
    cout << "s=" << s << endl;    //��ʾԲ�����

    cout << "r=";            //��ʾ��ʾ�������Ϣ
    cin >> r;                 //��������
    l = 2 * 3.1416 * r;           //����Բ���ܳ�����ֵ������l
    cout << "l=" << l << endl;    //��ʾԲ���ܳ�
    s = 3.1416 * r * r;
    cout << "s=" << s << endl;    //��ʾԲ�����
}
#include <iostream.h>    //����iostream.hͷ�ļ�
void main()
{
    //����ַ��������������ַ���
    char c1 = 'A';
    cout << 'W';
    cout << c1 << endl;
    cout << "This is a test." << endl;
    cout << "------------------" << endl;

    //������ͳ����������ͱ��ʽ
    int n = 100;
    cout << 10;
    cout << n;
    cout << 2 * n << endl;   //������ͱ��ʽ
    cout << "------------------" << endl;

    //��������ͳ����������ͱ��ʽ
    double pi = 3.1415926, r = 10.0, s = pi * r * r;
    cout << pi << endl;
    cout << r;
    cout << s;
    cout << 2 * r * pi << endl;      //��������ͱ��ʽ
    cout << "------------------" << endl;

    //һ��cout���������������
    cout << 'W' << " " << c1 << endl;
    cout << "This is a test." << endl;
    cout << "pi=" << pi << " r=" << r << " s=" << s << endl;
}