#include"PES2UG20CS216_H.h"

void initlist(LIST* p)
{
    p->head=NULL;
}
void initlistm(LISTM* p)
{
    p->head=NULL;
}
NODE* getnode(int ele,int r,int c)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->value = ele;
	temp->link= NULL;
	temp->row_position = r;
    	temp->column_postion = c;
	return temp;
}
NODEM* getnodem(int r,int c)
{
	NODEM* temp = (NODEM*)malloc(sizeof(NODEM));
	temp->rlink= NULL;
	temp->llink= NULL;
	temp->row_position = r;
    	temp->column_postion = c;
	return temp;
}
void create_sparsematrix(LIST* spm, int ele,int row, int column)
{
	
	NODE* temp, *pres;
    pres=spm->head;
	temp = getnode(ele,row,column);
	
	if (spm->head == NULL)
	{
		spm->head=temp;
	}
	else
	{
		while (pres->link != NULL)
			pres = pres->link;
        pres->link=temp;
	}
}
void create(LISTM* spm,int row, int column)
{
	
	NODEM* temp =getnodem(row,column);
    NODEM* pres=spm->head;
	if(pres==NULL)
	{
		spm->head=temp;
	}
	else if (pres->rlink == NULL)
	{
		temp->llink=pres;
        pres->rlink=temp;
		
	}
	else
	{
		while (pres->rlink != NULL)
			pres = pres->rlink;
    	temp->llink=pres;
        pres->rlink=temp;                
	}
}
void read(LIST* spm)
{
	FILE *ptr;
	ptr = fopen("input.txt","r");
	if(ptr == NULL)
   	{
      printf("Error!");   
      exit(1);             
   	}
	fscanf(ptr,"%d%d%d%d",&sr,&sc,&er,&ec);
	for (int i = 0; i < er+1; i++)
{
    for (int j = 0; j < ec+1; j++)
    {
        char c;
        if (fscanf(ptr, " %c", &c) != 1)
            printf("…report read failure and exit…");
        else if (isdigit((unsigned char)c))
            sparse_matrix[i][j] = c - '0';
        else
            sparse_matrix[i][j] = 0;
    }
}
	for (int i = 0; i < er+1; i++)
	{
		for (int j = 0; j < ec+1; j++)
		{
			
			if (sparse_matrix[i][j]!=0)
			{
				create_sparsematrix(spm, 1, i, j);
			}
			
		}
		
	}
	fclose(ptr);
}
void delete_key(LISTM* p,int r,int c)
{
        NODEM *pres = p->head;
        
        if(p->head==NULL)
                printf("Empty list\n");
        else
        {
                while(pres!=NULL)
                {
                        if(pres->row_position==r && pres->column_postion==c)
                        {
                                NODEM *temp = pres->rlink;
                                if (pres==p->head)
                                {
                                        p->head=pres->rlink;
                                        pres->rlink=NULL;
                                        free(pres);

                                }
                                else if(pres->rlink==NULL)
                                {
                                        pres->llink->rlink = NULL;
                                        pres->llink=NULL;
                                        free(pres);
                                }
                                else
                                {
                                        pres->llink->rlink = pres->rlink;
                                        pres->rlink->llink = pres->llink;
                                        pres->llink=NULL;
                                        pres->rlink=NULL;
                                        free(pres);
                                }
                                pres = temp;
                        }
                        else
                                pres = pres->rlink;
                }
                
        }
}
void movement(LIST* spm,LISTM* move)
{
	int posr=0,posc=0;
	create(move,0,0);
	NODEM* m=move->head;
	NODE* t=spm->head;
	while (posr<(er+1) && posc<(ec+1))
	{
		if (posr==t->row_position && (posc+1)==t->column_postion)
		{
			posr=posr+1;
			while (t->row_position!=posr)
			{
				t=t->link;	
			}
			while (t->column_postion<posc)
			{
				t=t->link;
			}
			if((t->row_position==posr)&&(t->column_postion==posc))
			{
				m=m->llink;
				delete_key(move,posr-1,posc);
				posc=m->column_postion-1;
				
			}
			else
			{
				posc=posc-1;
			}
		}
		else if ((posc+1)==ec && posr!=t->row_position)
		{
			posr=posr+1;
			while (t->row_position!=posr)
			{
				t=t->link;
			}
			while (t->column_postion<posc)
			{
				t=t->link;
			}
			posc=t->column_postion-1;
		}	
		posc=posc+1;
		create(move,posr,posc);
		m=move->head;
		while (m->rlink!=NULL)
		{
			m=m->rlink;
		}	
		if (posr==er && posc==ec)
		{
			display(move);
			break;
		}
	}
	if (posr>er && posc>ec)
	{
		FILE* ptr = fopen("output.txt","w");
		fprintf(ptr,"%d",-1);
   		fclose(ptr);
	}
	
}
void display(LISTM* spm)
{
	NODEM *pres = spm->head;
	FILE* ptr = fopen("output.txt","w");
	while(pres != NULL)
	{
		fprintf(ptr,"%d %d\n",pres->row_position,pres->column_postion);
		pres = pres->rlink;
	}
	fclose(ptr);
}
