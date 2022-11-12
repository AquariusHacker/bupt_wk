#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 5
#define R 2
///===========================================================================
/*
 * 定义及声明
 */
///===========================================================================
int dataGol[N][N] = {0};
int score = 0;
void copyArray(int data[N][N], int src[N][N]);
void Start(int data[N][N]);
void randB(int box[], int n);
void turn(int data[N][N], int count);
void moveL(int data[N][N]);
void del(int data[N][N]);
void delL(int data[N][N]);
void delR(int data[N][N]);
void delU(int data[N][N]);
void delD(int data[N][N]);
void Ctrl(int data[N][N]);
void Show(int data[N][N]);

///===========================================================================
/*
 * 随机数生成主函数 box + 个数
 */
///===========================================================================
void randB(int box[], int n) /// 生成n个随机数，存放在该数组中
{
    for (int i = 0; i < n; i++)
    {
        /// 改变随机数种子
        srand((unsigned int)time(NULL));
        box[i] = rand() % N; /// 对4取余可以获得[0,4)范围的随机数
    }
}
///===========================================================================
/*
 * 逆时针反转函数，对象+次数
 */
///===========================================================================
void turn(int data[N][N], int count)
{
    int matrix[N][N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix[i][j] = data[j][N - 1 - i];
        }
    }
    copyArray(data, matrix);
    if (count > 1)
        turn(data, --count);
}
///===========================================================================//
/*
 * 复制矩阵
 */
///===========================================================================//
void copyArray(int data[N][N], int src[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            data[i][j] = src[i][j];
        }
    }
}
///===========================================================================
/*
 * moveL 向左移动
 */
///===========================================================================
void moveL(int data[N][N])
{
    int i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = k = 0; j < N; j++)
        {
            if (data[i][j] != 0)
            {
                data[i][k] = data[i][j];
                k++;
            }
        }
        for (; k < N; k++)data[i][k] = 0;
    }
}
///===========================================================================
/*
 * delete 向左消除
 */
///===========================================================================
void del(int data[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            if (data[i][j] == data[i][j + 1])
            {
                data[i][j] *= 2;
                data[i][j + 1] = 0;
            }
        }
    }
}

///==========================================================================
/*
 * 对函数打包 delL delR delU delD
 */
///==========================================================================
void delL(int data[N][N])
{
    moveL(data);
    del(data);
    moveL(data);
    del(data);
    score++;
}

void delR(int data[N][N])
{
    turn(data, 2);
    delL(data);
    turn(data, 2);
}

void delU(int data[N][N])
{
    turn(data, 1);
    delL(data);
    turn(data, 3);
}

void delD(int data[N][N])
{
    turn(data, 3);
    delL(data);
    turn(data, 1);
}
///===========================================================================
/*
 * newB 新数字生成 obj + 需要生成的数
 */
///===========================================================================

void newB(int data[N][N], int num)
{
    int box[2];
    do
    {
        randB(box, 2);

    } while (data[box[0]][box[1]]);

    data[box[0]][box[1]] = num;
}

///===========================================================================
/*
 * init 初始化界面
 */
///===========================================================================

void init(int data[N][N])
{
    int box[4];
    do
    {
        randB(box, 4);
    } while (box[0] == box[2] && box[1] == box[3]);
    data[box[0]][box[1]] = 2;
    data[box[2]][box[3]] = 4;
}

///===========================================================================
/*
 * delO 清零 + 初始化
 */
///===========================================================================
void delO(int data[N][N])
{
    int src[N][N] = {0};
    copyArray(data, src);
    init(data);
}
///===========================================================================
/*
 * Ctrl 控制面板
 */
///===========================================================================

void Ctrl(int data[N][N])
{
    char on = 0;
    char null = 0;
    printf("\n\t\t\t Game 2048\n");
    printf("\t\t\t\t\tMade By GyFg\n");
    printf("|===================================================================|\n");
    printf("| A : Left | D : Right | W : Up | S : Down | Q : Quit | R : Restart |\n");
    printf("|===================================================================|\n");
    printf("Start ? [y/n]: ");
    scanf_s("%c", &on, 1);
    scanf("%c", &null);
    switch (on)
    {
    case 'Y':case 'y':printf("Initing. . .");Start(data);break;
    case 'N':case 'n':printf("you have big sity...");
    default:printf("According to requests. . .@Sha Bi!");Ctrl(data);break;
    }
}
///===========================================================================
/*
 * Show函数 呈现结果
 */
///===========================================================================

void Show(int data[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d\t", dataGol[i][j]);
        }
        printf("\n");
    }
}
///===========================================================================
/*
 * 判断输赢
 */
///==========================================================================
int WOL(int data[N][N])
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (data[i][j] == 0)return 1;
            else continue;
        }
    }
    return 0;
}
///===========================================================================
/*
 * Start 函数，开启程序
 */
///===========================================================================

void Start(int data[N][N])
{
    delO(data);
    do
    {
        if (WOL(data))
        {
            printf("\n|===================================================================\n");
            printf("| A : Left | D : Right | W : Up | S : Down | Q : Quit | R : Restart |\n");
            printf("|===================================================================|\n");
            Show(data);
            printf("\nScores : %d", score);
            printf("\nInput: ");
            char on = 0;
            char null = 0;
            scanf_s("%c", &on, 1);
            scanf("%c", &null);
            switch (on)
            {
            case 'A':case 'a':delL(data);newB(data, R);break;
            case 'D':case 'd':delR(data);newB(data, R);break;
            case 'W':case 'w':delU(data);newB(data, R);break;
            case 'S':case 's':delD(data);newB(data, R); break;
            case 'Q':case 'q':Ctrl(data);score = 0;break;
            case 'R':case 'r':delO(data);score = 0;break;
            default:printf("Please according to requests...@Little angel\n"); break;
            }
        }
        else
        {
            printf("Game over!\n");
            printf("The last score : %d", score);
            printf("\nStart again. . .\n");
            score = 0;
            Ctrl(data);
        }
    } while (1);
}

///===========================================================================
/*
 * 测试main函数
 */
///===========================================================================

int main()
{
    Ctrl(dataGol);

    return 0;
}