#include <stdio.h>

int main()
{
    int cm;
    scanf("%d", &cm);
    int foot = cm/30.48; // m/100.0/0.3048 ��/�������Ӷ��õ���������
    // ��������ȥ�������־͵õ���С������inch/12,�ٳ���12�͵õ���inch.
    int inch = (cm/30.48-foot)*12; 
    printf("%d %d", foot, inch);
    return 0;
}
