#include<stdio.h>
int main ()
{
	int odd = 0;
	scanf_s ( "%d", &odd );
	if (odd > 2 && ( odd % 2 ) != 0)
	{

		for (int i = 1; i <= odd; i++)
		{
			for (int j = 1; j <= odd; j++)
			{
				if (j == (odd + 1)/2 - (i - 1) || j == (odd + 1)/2 + (i - 1) || j == (odd + 1)/2 - (odd - i) || j == (odd + 1)/2 + (odd -i))
				{
					printf ( "*" );
				}
				else
				{
					printf ( "." );
				}
			}
			printf ( "\n" );
		}
	}
	else
	{
		printf ( "0" );
	}
	return 0;
}