#include <stdio.h>

int main()
{
    int cm;
    scanf("%d", &cm);
    int foot = cm/30.48; // m/100.0/0.3048 用/做整除从而得到整数部分
    // 用总数减去整数部分就得到了小数部分inch/12,再乘以12就得到了inch.
    int inch = (cm/30.48-foot)*12; 
    printf("%d %d", foot, inch);
    return 0;
}
