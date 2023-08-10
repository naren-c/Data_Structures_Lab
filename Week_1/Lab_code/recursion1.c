#include<stdio.h>

int find(char str[],char sub[])
{
    if(*str=='\0'&&*sub!='\0')
		return 0;
    if(*sub=='\0') 
		return 1;
    if(*str!=*sub) 
		return find(str+1,sub);
    if(*str==*sub) 
		return find(str+1,sub+1);
}
int main()
{
    char str[50],sub[50];
    printf("string : ");
    gets(str);
    printf("substring : ");
    gets(sub);
    if(find(str,sub))
		printf("output : True\n");
    else 
		printf("output : False\n");
    return 0;
}