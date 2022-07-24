#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
int cnt=0;
struct mos 
{
	int data;
	struct mos *link;
};

struct mos *hash[SIZE]={NULL},*ptr=NULL;


int hashkey(int data)
{
	int key= data%SIZE;
	return key;
}

void Add_first()
{
	int num,key;
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL,*temp;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	//newnode->link=NULL;

	if(hash[key]==NULL)
	{
		hash[key]=newnode;
	}
	else
	{
		temp=hash[key];
		ptr=newnode;
		ptr->link=temp;
		hash[key]=ptr;
	}
}


void Search()
{
	int num,key;
	scanf("%d",&num);
	key=hashkey(num);
	if(hash[key]==NULL)
		printf("Data Not Found\n");
	else
	{
		ptr=hash[key];
		for(ptr;ptr!=NULL;ptr=ptr->link)
		{
			if(ptr->data=num)
			{
				printf("Data Found \n");
				break;
			}
			if(ptr==NULL)
				printf("Not Found\n");
		}
	}
}

void sort()
{
	int i,j,a;
	printf("Enter the index for sort\n");
	scanf("%d",&i);
	struct mos *temp1=NULL,*temp2=NULL;
	for(temp1=hash[i];temp1!=NULL;temp1=temp1->link)
	{
		for(temp2=temp1->link;temp2!=NULL;temp2=temp2->link)
			{
				if(temp2->data <temp1->data)
				{
					a=temp1->data;
					temp1->data=temp2->data;
					temp2->data=a;
				}
			}
	}
		
}


void Add_last()/////////////////////////////------------------------------
{
	int num,key;
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	newnode->link=NULL;
	
	ptr=hash[key];
	if(ptr==NULL)
		hash[key]=newnode;
	else
	{
		while(ptr->link!=NULL)
		{
			ptr=ptr->link;
		}
		ptr->link=newnode;
	}
}
void Add_middle()
{
	int num,key,pos=0;
	printf("Enter The Data\n");
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL,*temp=NULL,*sp=NULL,*fp=NULL;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	if(hash[key]==NULL)
		hash[key]=newnode;
	else
	{
		 int count=(cnt%2==0)?(cnt/2):((cnt+1)/2);
                temp=hash[key];
                for(int i=0;i<count-1;i++)
                {
                        temp=temp->link;
                }
                newnode->link=temp->link;
                temp->link=newnode;

    }
        		
}

void Replace_middle()
{
	int num,key;
	printf("Enter The Data\n");
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL,*temp=NULL,*temp1=NULL,*prev=NULL;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	if(hash[key]==NULL)
		{
			printf("No Nodes at %d index Add nodes\n",key);
		}
	else
	{
		 int count=(cnt%2==0)?(cnt/2):((cnt+1)/2);
                temp=hash[key];
                for(int i=0;i<count-1;i++)
                {
                	prev=temp;
                    temp=temp->link;
                }
                temp1=temp;
                newnode->link=temp->link;
                free(temp1);
                prev->link=newnode;

    }

}

void Display()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("\nEntries at the index %d\n",i);
		if(hash[i]==NULL)
			printf("No data at index %d\n",i);
		else
		{
			for(ptr=hash[i];ptr!=NULL;ptr=ptr->link)
				printf("%d->",ptr->data);
		}
	}
}

void Add_ascending()
{
	int key,num;
	printf("Enter The Data\n");
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL,*temp=NULL,*prev=NULL;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	newnode->link=NULL;
	ptr=hash[key];

	if(ptr==NULL || newnode->data < ptr->data)
	{
		newnode->link=ptr;
		ptr=newnode;
		hash[key]=ptr;
	}
	else
	{
		prev=ptr;
			temp=ptr->link;
			while(temp && newnode->data > temp->data)
			{
				prev=temp;
				temp=temp->link;
			}
			prev->link=newnode;
			newnode->link=temp;
	}
}

void Add_decending()
{
int key,num;
	printf("Enter The Data\n");
	scanf("%d",&num);
	key=hashkey(num);
	struct mos *newnode=NULL,*temp=NULL,*prev=NULL;
	newnode=calloc(1,sizeof(struct mos));
	newnode->data=num;
	newnode->link=NULL;
	ptr=hash[key];

	if(ptr==NULL || newnode->data > ptr->data)
	{
		newnode->link=ptr;
		ptr=newnode;
		hash[key]=ptr;
	}
	else
	{
		prev=ptr;
			temp=ptr->link;
			while(temp && newnode->data < temp->data)
			{
				prev=temp;
				temp=temp->link;
			}
			prev->link=newnode;
			newnode->link=temp;
	}
}


int main()
{
	int choice;

	while(1)
	{

	printf("\nPress\t1)Add_first\t2)Add_last\t3) Search\t4)Display\t5)Sort\t6)Add Middle\t7)Add_ascending\t8)Replace_middle\t9)Add_decending\t10)Exit \n");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1: printf("Enter The Data \n");
		cnt++;
		Add_first();
		
		break;

		case 2: printf("Enter The Data \n");
		cnt++;
		Add_last();
		printf("%d\n",cnt);
		break;

		case 3:printf("Enter The Data For Search\n");
		Search();
		break;

		case 4:Display();
		break;

		case 5:sort();
		break;

		case 6:Add_middle();
		cnt++;
		break;

		case 7:Add_ascending();
		cnt++;
		break;

		case 8:Replace_middle();
		break;

		case 9:Add_decending();
		cnt++;
		break;


		case 10:exit(0);


	}
	}
}
