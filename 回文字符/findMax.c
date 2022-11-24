#include <stdio.h>

int findMax(const int C[], const int N, int *max);

int main()
{
    int c[100]={10, 20, 30, 20, 10};
    int max = 0;
    int id=findMax(c, 10, &max);
    printf("%d,%d", id, max);
    return 0;
}

// 输入参数：
// C：输入数字数组
// N：输入数字数组长度
// max：返回的最大值
// 返回值：返回最大值所在数组中位置

int findMax(const int C[], const int N, int *max)
{
    int i = 0, id = 0;

    for (; i < N; i++)

        if (*(C + i) > *max){*max = *(C + i);id = i;} 
        
    return id;
}