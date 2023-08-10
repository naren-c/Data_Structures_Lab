#include<stdio.h>
#include<string.h>

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void perm(char str[],int start,int end)
{
    if(start==end)
		printf("%s, ",str);
    else
	{
        for(int i=start;i<=end;i++)
		{
            swap(str+start,str+i);
            perm(str,start+1,end);
            swap(str+start,str+i);
        }
    }
}
int main(){
    char str[50];
    printf("input : ");
    gets(str);
    printf("output : ");
    perm(str,0,strlen(str)-1);
    printf("\n");
    return 0;
}