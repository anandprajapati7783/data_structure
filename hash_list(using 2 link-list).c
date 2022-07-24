#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct hash
{
	int data;
	int key;
	struct hash *next;
	struct hash *link;
};

int keyfun(int data)
{
	int key=data%10;
	return key;
}
int cntnode(int data)
{
	static int tcnt,key0cnt,key1cnt,key2cnt,key3cnt,key4cnt,key5cnt,key6cnt,key7cnt,key8cnt,key9cnt,key;
	key=data%10;
	switch(key)
	{
		case 0:key0cnt++;
		break;

		case 1:key1cnt++;
		break;

		case 2:key2cnt++;
		break;

		case 3:key3cnt++;
		break;

		case 4:key4cnt++;
		break;

		case 5:key5cnt++;
		break;

		case 6:key6cnt++;
		break;

		case 7:key7cnt++;
		break;

		case 8:key8cnt++;
		break;

		case 9:key9cnt++;
		break;


	}

	if(key==0)
		return key0cnt;
	else if(key==1)
		return key1cnt;
	else if(key==2)
		return key2cnt;
	else if(key==3)
		return key3cnt;
	else if(key==4)
		return key4cnt;
	else if(key==5)
		return key5cnt;
	else if(key==6)
		return key6cnt;
	else if(key==7)
		return key7cnt;
	else if(key==8)
		return key8cnt;
	else
		return key9cnt;
	
}

struct hash * Add(struct hash *ptr)
{
	int data,key;
	struct hash *temp=NULL,*newnode=NULL;
	struct node *sidenode=NULL,*temp1=NULL;
	temp=ptr;
	printf("Enter the data\n");
	scanf("%d",&data);
	key=keyfun(data);
	int cntm=cntnode(data);

	if(temp==NULL)
	{
		newnode=calloc(1,sizeof(struct hash));
		newnode->data=data;
		newnode->key=key;
		temp=newnode;
		return temp;
	}
	else
	{
		XYZ:if(ptr->key==key)
				{
					
				 	sidenode=calloc(1,sizeof(struct node));
				 	sidenode->data=data;
					if(ptr->next==NULL)
					{
						ptr->next=(struct hash *)sidenode;
						return temp;
					}
					else
					{
						temp1=(struct node *)ptr->next;
						while(temp1->next)
						{
							temp1=temp1->next;
						}
						temp1->next=sidenode;
						return temp;
					}

				}
				else
				{
					
					if(ptr->link==NULL)
					{
						newnode=calloc(1,sizeof(struct hash));
						newnode->data=data;
						newnode->key=key;
						ptr->link=newnode;
						return temp;
						
					}
					else
					{
						ptr=ptr->link;
						goto XYZ;
					}
				}
			}
}
int Display(struct hash *ptr)
{
	struct node *temp=NULL;
	if(ptr==NULL)
	{
		printf("No list Add more\n");
		return 0;
	}
	else
	{
	while(ptr)
		{
			temp=(struct node *)ptr;
			printf("key[%d] ",ptr->key);
			while(temp)
			{
				printf("%d->",temp->data);
				temp=temp->next;
			}
			printf("\n");
			ptr=ptr->link;
		}
	}
}
struct hash *Add_middle(struct hash *ptr)
{
	int data,key,cntm=0;;
	struct hash *newnode=NULL,*temp=NULL;
	struct node *sidenode=NULL;
	printf("Enter the data\n");
	scanf("%d",&data);
	key=keyfun(data);
	cntm=cntnode(data);
	temp=ptr;

	if(temp==NULL)
	{
		newnode=calloc(1,sizeof(struct hash));
		newnode->data=data;
		newnode->key=key;
		temp=newnode;
		return temp;
	}
	else
	{
		XYZ:if(ptr->key==key)
				{
					
				 	sidenode=calloc(1,sizeof(struct node));
				 	sidenode->data=data;
					if(ptr->next==NULL)
					{
						ptr->next=(struct hash *)sidenode;
						return temp;
					}
					else
					{
						//int cntn=(cntm%2==0)?(cntm/2):((cntm+1)/2);
						for(int i=0;i<(cntm/2)-1;i++)
						{
							ptr=ptr->next;
						}
						sidenode->next=(struct node *)ptr->next;
						ptr->next=(struct hash *)sidenode;
						return temp;
						
					}

				}
				else
				{
					
					if(ptr->link==NULL)
					{
						newnode=calloc(1,sizeof(struct hash));
						newnode->data=data;
						newnode->key=key;
						ptr->link=newnode;
						return temp;
						
					}
					else
					{
						ptr=ptr->link;
						goto XYZ;
					}
				}
			}


}

struct hash* Add_first(struct hash *ptr)
{
	int data,key,buf,buf2;;
	struct hash *temp=NULL,*newnode=NULL;
	struct node *prev=NULL,*forw=NULL,*sidenode=NULL;
	printf("Enter the data\n");
	scanf("%d",&data);
	key=keyfun(data);
	int cntm=cntnode(data);
	temp=ptr;

	if(temp==NULL)
	{
		newnode=calloc(1,sizeof(struct hash));
		newnode->data=data;
		newnode->key=key;
		temp=newnode;
		return temp;
	}
	else
	{
		XYZ:if(ptr->key==key)
		{
			sidenode=calloc(1,sizeof(struct node));
			sidenode->data=data;
			if(ptr->next==NULL)
			{
				ptr->next=(struct hash *)sidenode;
				buf=ptr->data;
				ptr->data=data;
				sidenode->data=buf;
				return temp;
			}
			else
			{
				buf2=ptr->data;
				
				prev=(struct node *)ptr->next;
				ptr->next=(struct hash *)sidenode;
				sidenode->next=(struct node *)prev;
				ptr->data=sidenode->data;
				sidenode->data=buf2;
				return temp;
			}
		
			
		}
		else
				{
					
					if(ptr->link==NULL)
					{
						newnode=calloc(1,sizeof(struct hash));
						newnode->data=data;
						newnode->key=key;
						ptr->link=newnode;
						return temp;
						
					}
					else
					{
						ptr=ptr->link;
						goto XYZ;
					}
				}
		
	}



}

struct hash *Replace_middle(struct hash *ptr)
{
	int data,key,cntm=0;
	struct node *sidenode=NULL,*TEMP=NULL,*prev=NULL;
	struct hash *temp=NULL;
	printf("Enter the data for Replace_middle\n");
	scanf("%d",&data);
	key=keyfun(data);
	cntm=cntnode(data);
	temp=ptr;
	if(cntm<=2)
	{
		printf(" Nodes are less than two Enter more node for Replace_middle\n");
		return 0;
	}
	else
	{
		XYZ:if(ptr->key==key)
				{
					
					 	sidenode=calloc(1,sizeof(struct node));
					 	sidenode->data=data;
						//int cntn=(cntm%2==0)?(cntm/2):((cntm+1)/2);
						for(int i=0;i<(cntm/2)-1;i++)
						{
							prev=(struct node *)ptr;
							ptr=ptr->next;
						}
						TEMP=(struct node *)ptr;
						sidenode->next=(struct node *)ptr->next;
						prev->next=sidenode;
						free(TEMP);
						return temp;
				}
				else if(ptr->link==NULL)
				{
					printf("Key not found try another one\n");
					return 0;
				}
				else
				{
					ptr=ptr->link;
					goto XYZ;
				}

	}
		


}

struct hash *Sort(struct hash *ptr)
{
	int key,a;
	printf("Enter the key for sort\n");
	scanf("%d",&key);
	struct node *temp1=NULL,*temp2=NULL;
	struct hash *TEMP=ptr;
ABC: if(ptr->key==key)
	{
		temp1=(struct node *)ptr;
		for(temp1;temp1!=NULL;temp1=temp1->next)
		{
			for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
			{
				if(temp2->data <temp1->data)
				{
					a=temp1->data;
					temp1->data=temp2->data;
					temp2->data=a;
				}
				
			}
		}
		return (struct hash*)TEMP;
	}
	else if(ptr->link==NULL)
	{
		printf("No link found regarding %d key\n",key);
		return ptr;;
	}
	else
	{
		ptr=ptr->link;
		goto ABC;
	}
}

struct hash * Add_ascending(struct hash *ptr)
{
	int data,key,a;
	printf("Enter the data to be  Add_ascending order\n");
	scanf("%d",&data);
	key=keyfun(data);
	int cntm=cntnode(data);
	struct node *sidenode=NULL,*prev=NULL,*temp1=NULL,*temp2=NULL,*temp3=NULL;
	struct hash *newnode=NULL,*TEMP=ptr;
	

	if(ptr==NULL)
	{
		newnode=calloc(1,sizeof(struct hash));
		newnode->data=data;
		newnode->key=key;
		ptr=newnode;
		return ptr;
	}
	else
	{
		XYZ:if(ptr->key==key)
				{
					sidenode=calloc(1,sizeof(struct node));
					sidenode->data=data;
					if(ptr->next==NULL)
					{
						ptr->next=(struct hash *)sidenode;
						if(ptr->data>sidenode->data)
						{
							int a;
							a=ptr->data;
							ptr->data=sidenode->data;
							sidenode->data=a;
						}
						return TEMP;
					}
					else
					{
						temp1=(struct node *)ptr->next;
						while(temp1->next)
						{
							temp1=temp1->next;
						}
						temp1->next=sidenode;
						temp3=(struct node *)ptr;
						for(temp3;temp3!=NULL;temp3=temp3->next)
						{
							for(temp2=temp3->next;temp2!=NULL;temp2=temp2->next)
							{
								if(temp2->data <temp3->data)
								{
									a=temp3->data;
									temp3->data=temp2->data;
									temp2->data=a;
								}
								
							}
						}

						return TEMP;
					}
					

				}
				else
				{
					
					if(ptr->link==NULL)
					{
						newnode=calloc(1,sizeof(struct hash));
						newnode->data=data;
						newnode->key=key;
						ptr->link=newnode;
						return TEMP;
						
					}
					else
					{
						ptr=ptr->link;
						goto XYZ;
					}
				}
			}
	}


struct hash * Add_descending(struct hash *ptr)
{
	int data,key,a;
	printf("Enter the data to be  Add_ascending order\n");
	scanf("%d",&data);
	key=keyfun(data);
	int cntm=cntnode(data);
	struct node *sidenode=NULL,*prev=NULL,*temp1=NULL,*temp2=NULL,*temp3=NULL;
	struct hash *newnode=NULL,*TEMP=ptr;
	

	if(ptr==NULL)
	{
		newnode=calloc(1,sizeof(struct hash));
		newnode->data=data;
		newnode->key=key;
		ptr=newnode;
		return ptr;
	}
	else
	{
		XYZ:if(ptr->key==key)
				{
					sidenode=calloc(1,sizeof(struct node));
					sidenode->data=data;
					if(ptr->next==NULL)
					{
						ptr->next=(struct hash *)sidenode;
						if(ptr->data<sidenode->data)
						{
							int a;
							a=ptr->data;
							ptr->data=sidenode->data;
							sidenode->data=a;
						}
						return TEMP;
					}
					else
					{
						temp1=(struct node *)ptr->next;
						while(temp1->next)
						{
							temp1=temp1->next;
						}
						temp1->next=sidenode;
						temp3=(struct node *)ptr;
						for(temp3;temp3!=NULL;temp3=temp3->next)
						{
							for(temp2=temp3->next;temp2!=NULL;temp2=temp2->next)
							{
								if(temp2->data >temp3->data)
								{
									a=temp3->data;
									temp3->data=temp2->data;
									temp2->data=a;
								}
								
							}
						}

						return TEMP;
					}
					

				}
				else
				{
					
					if(ptr->link==NULL)
					{
						newnode=calloc(1,sizeof(struct hash));
						newnode->data=data;
						newnode->key=key;
						ptr->link=newnode;
						return TEMP;
						
					}
					else
					{
						ptr=ptr->link;
						goto XYZ;
					}
				}
			}
	}


int main()
{
	struct hash *head=NULL;
	int choice;
	while(1)
	{
		printf("Press\t 1)Add\t 2) Display\t 3)Add_first\t4)Add_middle\t5)Replace_middle\t6)Sort\t7)Add Ascending\t 8)Add_descending\t9)Exit\n");
		printf("Enter the Choice  : ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice)
		{
			case 1:head=Add(head);
			break;

			case 2:Display(head);
			break;

			case 3:head=Add_first(head);
			break;

			case 4:head=Add_middle(head);
			break;

			case 5:head=Replace_middle(head);
			break;

			case 6:head=Sort(head);
			break;

			case 7:head=Add_ascending(head);
			break;

			case 8:head=Add_descending(head);
			break;

			case 9: exit(0);

			default : printf("Wrong choice Enter agian\n");
		}

	}
}
