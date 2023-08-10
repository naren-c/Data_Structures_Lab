#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char SRN[15];
    char Name[50];
    int Sem;
    int Marks[5];
}*stu;
struct subjects
{
    char sub[5];
}sbjcodes[5]={"A1","B1","C1","D1","E1"};
int main()
{
    int n;
    printf("Enter the number of students:");
    scanf("%d",&n);fflush(stdin);
    stu=(struct student*)malloc(n*sizeof(struct student));
    for(int i=0;i<n;i++)
	{
        printf("Enter SRN of student %d:",i+1);
        gets(stu[i].SRN);
        printf("Enter Name of student %d:",i+1);
        gets(stu[i].Name);
        printf("Enter Sem of student %d:",i+1);
        scanf("%d",&stu[i].Sem);
        for(int j=0;j<5;j++)
		{
            printf("Enter marks obtained in subject %s:",sbjcodes[j].sub);
            scanf("%d",&stu[i].Marks[j]);
        }
        fflush(stdin);
    }
    printf("\n");
    for(int i=0;i<5;i++)
	{
        int average=0;
        for(int j=0;j<n;j++)
		{
            average+=stu[j].Marks[i];
        }
        average/=n;
        printf("Average marks scored in %s is:%d\n",sbjcodes[i].sub,average);
    }
    struct student temp;
    for(int i=0;i<n-1;i++)
	{
        for(int j=0;j<n-i-1;j++)
		{
            if(strcmp(stu[j].SRN,stu[j+1].SRN)>0)
			{
                temp=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=temp;
            }
        }
    }
    printf("\nStudents sorted based on SRN:\n\n");
    for(int i=0;i<n;i++)
	{
        printf("Name:%s\nSRN:%s\n\n",stu[i].Name,stu[i].SRN);
    }
    free(stu);
    stu=NULL;
    return 0;
}