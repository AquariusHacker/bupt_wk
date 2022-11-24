#include <stdio.h>

int Palindrome ( const char c[], const int N );

int main()
{
    char c[100]="Able was I ere I saw Elba";
    printf("%d", Palindrome(c, 100));
    return 0;
}

// c 是一个输入句子的数组
// N 是数组的最大长度
// 返回值：
// 1：是回文
// 0：不是回文


// 注意
// 1、判断过程中忽略字符的大小写（a和A等价）
// 2、判断过程中忽略非大小写字母符号（如标点符号、空格等）

// 一错
// int Palindrome ( const char c[], const int N )
// {

//     int len = 0;
//     // 获取有效长度
//     while (*(c+len) != 0) len++;
//     char* p = c+len -1;
//     for (int i = 0; i < (len - 1)/2; i++)
//     {
        
//         if ((*c + 32 - 'a')%32 == (*p + 32 - 'a')%32)
//         {
//             c++;
//             p--;
//         }
//         else if (*p < 'A'||*p > 'Z' && *p < 'a'|| *p < 'a'&& *p > 'Z'||*p > 'z')
//         {
//             p--;
//         }
//         else if (*c < 'A'||*c > 'Z' && *c < 'a'|| *c < 'a'&& *c > 'Z'||*c > 'z')
//         {
//             c++;
//         }
//         else return 0;
//     }
//     return 1;
// }

// 一错
// int Palindrome ( const char c[], const int N )
// {

//     int len = 0;
//     while (*(c+len) != 0) len++;
//     int l = 0;
//     int p = len - 1;
//     for (int i = 0; i < (len - 1)/2; i++)
//     {
        
//         if ((c[l] + 32 - 'a')%32 == (c[p] + 32 - 'a')%32)
//         {
//             l++;
//             p--;
//         }
//         else if (c[p] < 'A'||(c[p] > 'Z' && c[p] < 'a')|| (c[p] < 'a'&& c[p] > 'Z')||c[p] > 'z')
//         {
//             p--;
//         }
//         else if (c[l] < 'A'||(c[l] > 'Z' && c[l] < 'a')|| (c[l] < 'a'&& c[l] > 'Z')||c[l] > 'z')
//         {
//             l++;
//         }
//         else return 0;
//     }
//     return 1;
// }
// 一错
// int Palindrome ( const char c[], const int N )
// {

//     int len = 0;
//     while (*(c+len) != 0) len++;
//     int l = 0;
//     int p = len - 1;
//     while (l < p)
//     {     
//         if (((c[p] >='a' && c[p] <= 'z') || (c[p] >='A' && c[p] <= 'Z')) && ((c[l] >='a' && c[l] <= 'z' )||( c[l] >='A' && c[l] <= 'Z')) )
//         {
//             if ((c[l] + 32 - 'a')%32 == (c[p] + 32 - 'a')%32)
//             {
//                 l++;
//                 p--;
//             }
//         }
//         else if (c[p] < 'A'||(c[p] > 'Z' && c[p] < 'a')|| (c[p] < 'a'&& c[p] > 'Z')||c[p] > 'z')
//         {
//             p--;
//         }
//         else if (c[l] < 'A'||(c[l] > 'Z' && c[l] < 'a')|| (c[l] < 'a'&& c[l] > 'Z')||c[l] > 'z')
//         {
//             l++;
//         }
//         else return 0;

//     }
//     return 1;
// }

// 全对
// int Palindrome ( const char c[], const int N ){
//     char *p = c;
// 	int len = 0;
//     while (*(c+len) != 0) len++;
// 	char *q = p + len;
// 	while ((p<q)&&p != q)
// 	{
// 		if ((p<=q)&&(((*p) >= 65 && (*p <= 90)) || ((*p) >= 97 && ((*p) <= 122)) || ((*p) >= 48 && (*p) <= 57))
// 			&& (((*q) >= 65 && (*q <= 90)) || ((*q) >= 97 && ((*q) <= 122)) || ((*q) >= 48 && (*q) <= 57)))
// 		{
// 			int ret = (*p) - (*q);
// 			if (ret != 0 && ret != 32&&ret!=-32)
// 			{
// 				return 0;
// 			}
// 			else
// 			{
// 				p++;
// 				q--;
// 			}
// 		}
// 		if (!(((*p) >= 65 && (*p <= 90)) || ((*p) >= 97 && ((*p) <= 122)) || ((*p) >= 48 && (*p) <= 57)))
// 		{
// 			p++;
// 		}
// 		if (!(((*q) >= 65 && (*q <= 90)) || ((*q) >= 97 && ((*q) <= 122)) || ((*q) >= 48 && (*q) <= 57)))
// 		{
// 			q--;
// 		}
// 	}
// 	return 1;
// }
// 全对
int Palindrome ( const char c[], const int N ){
    char *p = c;
	int len = 0;
    while (*(c+len) != 0) len++;
	char *q = p + len;
	while (p<q)
	{
		if ((p<=q)&&(((*p) >= 65 && (*p <= 90)) || ((*p) >= 97 && ((*p) <= 122)))
			&& (((*q) >= 65 && (*q <= 90)) || ((*q) >= 97 && ((*q) <= 122))))
		{
			int ret = (*p) - (*q);
			if (ret != 0 && ret != 32&&ret!=-32) return 0;
			else{p++;q--;}
		}
		if (!(((*p) >= 65 && (*p <= 90)) || ((*p) >= 97 && ((*p) <= 122)) ))
			p++;
		if (!(((*q) >= 65 && (*q <= 90)) || ((*q) >= 97 && ((*q) <= 122)) ))
			q--;
	}
	return 1;
}

