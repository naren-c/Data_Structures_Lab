#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NUMMATCHES 14
typedef struct player
{
	char player_name[30];
	char team_name[20];
	char played[14];
	int runs[14];
    struct player *next;
} Player;

Player* add_player(Player* list);
void total_matches(Player* list);
void display(Player *list);
void highest_score(Player *list);

int main()
{
	Player *list = NULL;
	int ch;
	while (1) 
	{
        printf("\n\nMAIN MENU\n\n");
        printf("1. Add player details\n");
        printf("2. Display players with highest scores\n");
        printf("3. Compute number of matches played by each player\n");   
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("\nYour choice: ");
        scanf("%d", &ch);
		switch (ch)
		{
            case 1: list = add_player(list);
					display(list);  
					break;
            case 2: highest_score(list);
					break;
            case 3: total_matches(list);
					break;
            case 4: display(list);
					break;
            case 5: return 0;
            default: printf("Invalid input\n");
					 continue;
        }
    }
	return 0;
}
void total_matches(Player* list)
{
	Player *temp = list;
	int count;
    while (temp) 
	{
		count = 0;
        printf("%s \n", temp->player_name);
		for(int i=0;i<NUMMATCHES;i++)
		{
			if(temp->played[i] == 'y' || temp->played[i] == 'Y')
				count++;
		}
		printf("Matches played: %d\n",count);
        temp = temp->next;
    }
}
void highest_score(Player *list)
{
	Player *temp = list;
	char pname[14][30];
	char tname[14][30];
	char match[14];
	int scores[14];
	
	if(temp != NULL)
	{
		for(int i = 0; i < 14; i++)
		{
			strcpy(pname[i],temp->player_name);
			strcpy(tname[i],temp->team_name);
			match[i] = temp->played[i];
			scores[i] = temp->runs[i];
		}
		temp = temp->next;
	}
	
	while (temp) 
	{
		for(int j=0;j<NUMMATCHES;j++)
		{
			if(temp->played[j] == 'y' || temp->played[j] == 'Y')
			{
				if(temp->runs[j] > scores[j])
				{
					strcpy(pname[j],temp->player_name);
					strcpy(tname[j],temp->team_name);
					match[j] = temp->played[j];
					scores[j] = temp->runs[j];
				}
			}
		}
        temp = temp->next;
    }
	for(int k=0;k<NUMMATCHES;k++)
	{
		printf("Match %d: %s %d\n",k+1,pname[k],scores[k]);
	}
}

Player* add_player(Player* list)
{
    Player *temp = list;
	char p;
	int s;
    if (temp == NULL)
	{
        temp = (Player*) malloc(sizeof(Player));
        printf("Enter the player name and team ");
		scanf("%s %s",temp->player_name, temp->team_name);
		for(int i=0;i<NUMMATCHES;i++)
		{
			printf("Did the player play the match %d?",i+1);
			fflush(stdin);
			scanf("%c %d",&p, &s);
			temp->played[i] = p;
			if(p == 'y' || p == 'Y')
				temp->runs[i] = s;
			else
				temp->runs[i] = 0;
		}
        temp->next = NULL;
        list = temp;
    }
    else 
	{
        while (temp->next != NULL) 
		{
            temp = temp->next;
        }
        Player *old = temp;
        temp = (Player *) malloc(sizeof(Player));
        old->next = temp;
        printf("Enter the player name and team ");
		scanf("%s %s",temp->player_name, temp->team_name);
		for(int i=0;i<NUMMATCHES;i++)
		{
			printf("Did the player play the match %d?",i+1);
			fflush(stdin);
			scanf("%c %d",&p, &s);
			temp->played[i] = p;
			temp->runs[i] = s;
		}
        temp->next = NULL;
    }
    
    return list;
}
void display(Player *list) 
{
    Player *temp = list;

    while (temp) 
	{
        printf("%s %s\n", temp->player_name,temp->team_name);
		for(int i=0;i<NUMMATCHES;i++)
		{
			printf("Match %d: %c %d\n",i,temp->played[i], temp->runs[i]);
		}
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("NULL\n");
    }
}