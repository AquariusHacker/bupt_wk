#include<stdio.h>
int main()
{

    int m[10];
    int n[5][2];
    char c1[10]="test";
    char c2[] = "test";
    char t1[10]={'t', 'e', 's', 't'};
    char t2[] = {'t', 'e', 's', 't'};

    printf("%d\n%d\n%d\n%d\n%d\n%d",sizeof(m) ,sizeof(n) ,sizeof(c1) ,sizeof(c2) ,sizeof(t1) ,sizeof(t2) );

    return 0;
}