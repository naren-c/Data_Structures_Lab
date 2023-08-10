#include<stdio.h>
#include<conio.h>


void hanoi(int n, char rodFrom, char rodMiddle, char rodTo);

int main()
{
	int n;
	printf("Enter the number of disks in tower of Hanoi");
	scanf("%d",&n);
	if(n>=1)
		hanoi(n, 'A', 'B', 'C');
    else
		printf("Tower of Hanoi is empty");
	return 0;
}
void hanoi(int n, char rodFrom, char rodMiddle, char rodTo)
{
    if(n==1)
	{
        printf("Disk 1 moved from %c to %c \n",rodFrom,rodTo);
        return;
    }
    hanoi(n-1,rodFrom,rodTo,rodMiddle);
    printf("Disk %d moved from %c to %c \n",n,rodFrom,rodTo);
    hanoi(n-1,rodMiddle,rodFrom,rodTo);
 
}
