#include<stdio.h>
#include<stdlib.h>
#include"PES2UG20CS216_H.h"

int main()
{
    list *my_list;
    init(&my_list);

    FILE *fp = fopen("input.txt","r");
    int start_row,start_col,end_row,end_col;

    fscanf(fp,"%d",&start_row);
    fscanf(fp,"%d",&start_col);
    fscanf(fp,"%d",&end_row);
    fscanf(fp,"%d",&end_col);

    char line[1000];
    int row = -1;

    while(fgets(line,1000,fp))
    {
        int col = 0;
        int index = 0;
        while(line[index]!='\0')
        {
            if(line[index] == '0')
                insert(&my_list,row,col);
            if(line[index] == ' ')
                col++;
            index++;
        }
        row++;
    }
    fclose(fp);
    find_path(&my_list,start_row,start_col,end_row,end_col);
    return 0;
}