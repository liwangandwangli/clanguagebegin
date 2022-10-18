#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <dos.h>

#define S_FRIST_X 20
#define S_FRIST_Y 10

#define UP 11
#define DOWN 12
#define LEFT 13
#define RIGHT 14

#define START 22
#define OVER 33

//��װvc++6.0�й���ƶ�����
int mygotoxy(int x, int y)
{
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    return 0;
}

//��ӡ�ߵ�����
int s_print(int s_arr[][2], int s_len)
{
    int i = 0;
    for (i = 0; i < s_len; i++)
    {
        mygotoxy(s_arr[i][0], s_arr[i][1]);
        printf("*");
    }
}

//����ߵ�����
int s_print_clean(int s_arr[][2], int s_len)
{
    int i = 0;
    for (i = 0; i < s_len; i++)
    {
        mygotoxy(s_arr[i][0], s_arr[i][1]);
        printf(" ");
    }
}

//��ӡʳ��
int t_print(int x, int y)
{
    mygotoxy(x, y);
    printf("*");
}

//���ʳ��
int t_print_clean(int x, int y)
{
    mygotoxy(x, y);
    printf(" ");
}

int main (void)
{
    int i = 0;
    char key = 0;
    int speed = 0;
    int s_len = 0;
    int s_direction = 0;

    int t_x = 0;
    int t_y = 0;
    int t_rand = 0;
    int score = 0;
    int levels = 0;

    int game = OVER;

    int s_arr[100][2] = {{0, 0}};

    //��ӡ��Ϸ����Ϊ���1-59���߶�1-22
    for (i = 1; i <= 60; i += 2)
    {
        mygotoxy(i, 0);
        printf("-");
    }
    for (i = 1; i <= 60; i += 2)
    {
        mygotoxy(i, 23);
        printf("-");
    }
    for (i = 1; i <= 22; i++)
    {
        mygotoxy(0, i);
        printf("|");
    }
    for (i = 1; i <= 22; i++)
    {
        mygotoxy(60, i);
        printf("|");
    }

    //��ӡ��ӭ��Ϣ
    mygotoxy(63, 2);
    printf("��ӭ����̰���ߡ�");
    mygotoxy(66, 4);
    printf("w��Ϊ��");
    mygotoxy(66, 5);
    printf("s��Ϊ��");
    mygotoxy(66, 6);
    printf("a��Ϊ��");
    mygotoxy(66, 7);
    printf("d��Ϊ��");
    mygotoxy(63, 20);
    printf("���س���ʼ��Ϸ��");

    while (1)
    {
_start:
        //�ж��ؿ�
        if(20 == score && 1 == levels)
        {
            mygotoxy(30, 12);
            printf("��һ��");
            Sleep(1000);
            mygotoxy(30, 12);
            printf("      ");
            speed = 250;
            levels = 2;
        }
        else if(30 == score && 2 == levels)
        {
            mygotoxy(30, 12);
            printf("��һ��");
            Sleep(1000);
            mygotoxy(30, 12);
            printf("      ");
            speed = 125;
            levels = 3;
        }
        else if(40 == score && 3 == levels)
        {
            mygotoxy(30, 12);
            printf("��һ��");
            Sleep(1000);
            mygotoxy(30, 12);
            printf("      ");
            speed = 60;
            levels = 4;
        }
        else if(50 == score && 4 == levels)
        {
            mygotoxy(30, 12);
            printf("��һ��");
            Sleep(1000);
            mygotoxy(30, 12);
            printf("      ");
            speed = 30;
            levels = 5;
        }

        if(OVER == game)
        {
            //��ӡ��Ϸ��Ϣ
            mygotoxy(68, 21);
            printf("����");

            //����س���ʼ��Ϸ
            while(1)
            {
                key = _getch();
                fflush(stdin);

                if(13 == key)
                {
                    key = 0;
                    break;
                }
            }

            //��ʼ���ƶ��ٶȺ��ߵĳ���
            speed = 500;
            s_len = 3;

            //��ʼ���ؿ�
            levels = 1;

            //��ʼ��ʳ������
            if((t_rand = rand() % 60) != 0)
            {
                t_x = t_rand;
            }

            if((t_rand = rand() % 23) != 0)
            {
                t_y = t_rand;
            }

            //��ʼ���ߵ�����
            for (i = 0; i < s_len; i++)
            {
                s_arr[i][0] = 20 + i;
                s_arr[i][1] = 10;
            }

            //��ʼ������
            s_direction = RIGHT;

            game = START;

            //��ӡ��Ϸ��Ϣ
            mygotoxy(68, 21);
            printf("����");
        }

        //ˢ�µ÷�
        mygotoxy(66, 13);
        printf("�÷�: %d��", score);

        //ˢ�¹ؿ�
        mygotoxy(65, 11);
        printf("�ؿ�: ��%d��", levels);

        //�жϷ���
        switch (s_direction)
        {
        case UP:
        {
            //�ж��Ƿ��ϱ߽���
            if(0 == s_arr[s_len - 1][1] - 1)
            {
                game = OVER;
                score = 0;
                mygotoxy(30, 12);
                printf("Game Over!");
                Sleep(1000);
                mygotoxy(30, 12);
                printf("          ");
                continue;
            }

            //�ж��Ƿ�Ҫײ���Լ�������
            for (i = 0; i < s_len; i++)
            {
                if(s_arr[i][0] == s_arr[s_len - 1][0] && s_arr[i][1] == s_arr[s_len - 1][1] - 1)
                {
                    game = OVER;
                    score = 0;
                    mygotoxy(30, 12);
                    printf("Game Over!");
                    Sleep(1000);
                    mygotoxy(30, 12);
                    printf("          ");
                    goto _start;
                }
            }

            //�ж��Ƿ�Ե�ʳ��
            if (t_x == s_arr[s_len - 1][0] && t_y == s_arr[s_len - 1][1] - 1)
            {
                s_len++;
                s_arr[s_len - 1][0] = t_x;
                s_arr[s_len - 1][1] = t_y;

                //������ʮ��
                score += 10;

                //ˢ��ʳ������
                if((t_rand = rand() % 60) != 0)
                {
                    t_x = t_rand;
                }
                if((t_rand = rand() % 23) != 0)
                {
                    t_y = t_rand;
                }
                break;
            }
            else
            {
                //��������
                for (i = 0; i < s_len; i++)
                {
                    if(s_len - 1 == i)
                    {
                        s_arr[i][1]--;
                    }
                    else
                    {
                        s_arr[i][0] = s_arr[i + 1][0];
                        s_arr[i][1] = s_arr[i + 1][1];
                    }
                }
                break;
            }
        }
        case DOWN:
        {
            //�ж��Ƿ��±߽���
            if(23 == s_arr[s_len - 1][1] + 1)
            {
                game = OVER;
                score = 0;
                mygotoxy(30, 12);
                printf("Game Over!");
                Sleep(1000);
                mygotoxy(30, 12);
                printf("          ");
                continue;
            }

            //�ж��Ƿ�Ҫײ���Լ�������
            for (i = 0; i < s_len; i++)
            {
                if(s_arr[i][0] == s_arr[s_len - 1][0] && s_arr[i][1] == s_arr[s_len - 1][1] + 1)
                {
                    game = OVER;
                    score = 0;
                    mygotoxy(30, 12);
                    printf("Game Over!");
                    Sleep(1000);
                    mygotoxy(30, 12);
                    printf("          ");
                    goto _start;
                }
            }

            //�ж��Ƿ�Ե�ʳ��
            if (t_x == s_arr[s_len - 1][0] && t_y == s_arr[s_len - 1][1] + 1)
            {
                s_len++;
                s_arr[s_len - 1][0] = t_x;
                s_arr[s_len - 1][1] = t_y;

                //������ʮ��
                score += 10;

                //ˢ��ʳ������
                if((t_rand = rand() % 60) != 0)
                {
                    t_x = t_rand;
                }
                if((t_rand = rand() % 23) != 0)
                {
                    t_y = t_rand;
                }
                break;
            }
            else
            {
                //��������
                for (i = 0; i < s_len; i++)
                {
                    if(s_len - 1 == i)
                    {
                        s_arr[i][1]++;
                    }
                    else
                    {
                        s_arr[i][0] = s_arr[i + 1][0];
                        s_arr[i][1] = s_arr[i + 1][1];
                    }
                }
                break;
            }
        }
        case LEFT:
        {
            //�ж��Ƿ���߽���
            if(0 == s_arr[s_len - 1][0] - 1)
            {
                game = OVER;
                score = 0;
                mygotoxy(30, 12);
                printf("Game Over!");
                Sleep(1000);
                mygotoxy(30, 12);
                printf("          ");
                continue;
            }

            //�ж��Ƿ�Ҫײ���Լ�������
            for (i = 0; i < s_len; i++)
            {
                if(s_arr[i][0] == s_arr[s_len - 1][0] - 1 && s_arr[i][1] == s_arr[s_len - 1][1])
                {
                    game = OVER;
                    score = 0;
                    mygotoxy(30, 12);
                    printf("Game Over!");
                    Sleep(1000);
                    mygotoxy(30, 12);
                    printf("          ");
                    goto _start;
                }
            }

            //�ж��Ƿ�Ե�ʳ��
            if (t_x == s_arr[s_len - 1][0] - 1 && t_y == s_arr[s_len - 1][1])
            {
                s_len++;
                s_arr[s_len - 1][0] = t_x;
                s_arr[s_len - 1][1] = t_y;

                //������ʮ��
                score += 10;

                //ˢ��ʳ������
                if((t_rand = rand() % 60) != 0)
                {
                    t_x = t_rand;
                }
                if((t_rand = rand() % 23) != 0)
                {
                    t_y = t_rand;
                }
                break;
            }
            else
            {
                //��������
                for (i = 0; i < s_len; i++)
                {
                    if(s_len - 1 == i)
                    {
                        s_arr[i][0]--;
                    }
                    else
                    {
                        s_arr[i][0] = s_arr[i + 1][0];
                        s_arr[i][1] = s_arr[i + 1][1];
                    }
                }
                break;
            }
        }
        case RIGHT:
        {
            //�ж��Ƿ���߽���
            if(60 == s_arr[s_len - 1][0] + 1)
            {
                game = OVER;
                score = 0;
                mygotoxy(30, 12);
                printf("Game Over!");
                Sleep(1000);
                mygotoxy(30, 12);
                printf("          ");
                continue;
            }

            //�ж��Ƿ�Ҫײ���Լ�������
            for (i = 0; i < s_len; i++)
            {
                if(s_arr[i][0] == s_arr[s_len - 1][0] + 1 && s_arr[i][1] == s_arr[s_len - 1][1])
                {
                    game = OVER;
                    score = 0;
                    mygotoxy(30, 12);
                    printf("Game Over!");
                    Sleep(1000);
                    mygotoxy(30, 12);
                    printf("          ");
                    goto _start;
                }
            }

            //�ж��Ƿ�Ե�ʳ��
            if (t_x == s_arr[s_len - 1][0] + 1 && t_y == s_arr[s_len - 1][1])
            {
                s_len++;
                s_arr[s_len - 1][0] = t_x;
                s_arr[s_len - 1][1] = t_y;

                //������ʮ��
                score += 10;

                //ˢ��ʳ������
                if((t_rand = rand() % 60) != 0)
                {
                    t_x = t_rand;
                }
                if((t_rand = rand() % 23) != 0)
                {
                    t_y = t_rand;
                }
                break;
            }
            else
            {
                //��������
                for (i = 0; i < s_len; i++)
                {
                    if(s_len - 1 == i)
                    {
                        s_arr[i][0]++;
                    }
                    else
                    {
                        s_arr[i][0] = s_arr[i + 1][0];
                        s_arr[i][1] = s_arr[i + 1][1];
                    }
                }
                break;
            }
        }
        }

        //��ӡ�ߵ�����
        s_print(s_arr, s_len);

        //��ӡʳ��
        t_print(t_x, t_y);

        while (kbhit())
        {
            //����һ���ַ�
            key = _getch();
            fflush(stdin);

            //��������
            switch (key)
            {
            case 'w':
                if(DOWN == s_direction)
                    break;
                else
                {
                    s_direction = UP;
                    break;
                }
            case 's':
                if(UP == s_direction)
                    break;
                else
                {
                    s_direction = DOWN;
                    break;
                }
            case 'a':
                if(RIGHT == s_direction)
                    break;
                else
                {
                    s_direction = LEFT;
                    break;
                }
            case 'd':
                if(LEFT == s_direction)
                    break;
                else
                {
                    s_direction = RIGHT;
                    break;
                }
            }
        }

        //��ʱ����
        Sleep(speed);

        //����ߵ�����
        s_print_clean(s_arr, s_len);

        //���ʳ��
        t_print_clean(t_x, t_y);
    }

    return 0;
}
