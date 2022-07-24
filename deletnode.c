//************* Delete task***********

#include <stdio.h>
#include <stdlib.h>
struct del
{
	int data;
	struct del *next;
};
int count(struct del *head)
{
	int cnt=0;
	struct del *ptr=NULL,*temp=NULL;
	ptr=temp=head;
	if(ptr==NULL)
		return 0;
	else{
		while(temp)
		{
			cnt++;
			temp=temp->next;
		}
		return cnt;
	}
}

struct del *del_node_9(struct del *head)
{
	int pos,cnt=0,loop=0;
	printf("Enter the position\n");
	scanf("%d",&pos);
	cnt=count(head);
	loop=cnt-pos+1;
	struct del *ptr=head,*temp=head,*prev=NULL,*temp1=NULL;
	if(ptr==NULL)
	{
		printf("List is eampty\n");
		return 0;
	}
	else
	{
		for(int i=0;i<loop;i++)
		{
			prev=temp;
			temp=temp->next;
			
		}
		
		temp1=prev;
		free(temp1);
		return temp;
	}
}

struct del *del_node_8(struct del *head)
{
	int cnt,data,ocu,pos=0,i=0;
	int *arr=NULL;
	struct del *ptr=head,*temp=head,*temp1=head,*prev=NULL,*ford=NULL,*temp2=NULL;
	printf("Enter the data and occurrence\n");
	scanf("%d%d",&data,&ocu);
	if(ptr==NULL)
	{
		printf("There i nothing add some nodes\n");
		return 0;
	}
	else
	{
		while(temp)
		{
			arr=realloc(arr,sizeof(int));
			pos++;
			if(data==temp->data)
			{
				cnt++;
				arr[i++]=pos;
			}
			temp=temp->next;
			
			//pos++;10 20 30 10 50 10
		}
		// for(int i=0;arr[i]!='\0';i++)
		// 	printf("%d ",arr[i]);
		if(ocu>pos)
		{
			printf("the occurrence is less than given data plz enter valid occurrence\n");
			return head;
		}
		if(ocu==1)
		{
			printf("only one occurrence\n");
			return head;
		}
		else
		{
			for(int i=1;i<arr[ocu-1];i++)
		{
			prev=temp1;
			temp1=temp1->next;
			ford=temp1->next;
		}
		temp2=temp1;
		free(temp2);
		prev->next=ford;
		return head;
		}
	}
}

struct del *del_node_7(struct del *head)
{
	int pos,cnt=0;
	struct del *temp=NULL,*temp1=NULL,*ford=NULL,*prev=NULL,*ford1=NULL;
	printf("Enter the position\n");
	scanf("%d",&pos);
	cnt=count(head);
	if(pos>cnt)
	{
		printf("the position is more than list count\n");
		return head;
	}
	else if(cnt==1)
	{
		head=NULL;
		return head;
	}
	else
	{
		temp=head;
		if(head==NULL)
		{
			printf("the list is empty add some nodes\n");
			return 0;
		}

		else{
			for(int i=1;i<pos;i++)
			{
				temp=temp->next;
			}
			//printf("%d\n",temp->data);
			ford=temp->next;
			temp->next = NULL;
			free(ford);
			
		}
		return head;
	}
}
struct del *del_node_6(struct del *head)
{
	int pos,cnt,loop;
	struct del *temp=NULL,*prev=NULL,*ford=NULL,*temp1=NULL;
	printf("Entet the position to delet the node\n");
	scanf("%d",&pos);
	temp=head;
	cnt=count(head);
	if(temp==NULL)
	{
		printf("There is no data add some data first\n");
		return 0;
	}
	loop=cnt-pos+1;
	if(pos==cnt)
	{
		temp1=temp;
		head=temp->next;
		free(temp1);
		return head;
	}
	else
	{	
		for(int i=1;i<loop;i++)
		{
			prev=temp;
			temp=temp->next;
			ford=temp->next;
		}
		temp1=temp;
		free(temp1);
		prev->next=ford;
		return head;
	}		
}
struct del* del_node_5(struct del *head)
{
	int pos,cnt;
	struct del *temp=NULL,*prev=NULL,*ford=NULL,*temp1=NULL;
	printf("Entet the position to delet the node\n");
	scanf("%d",&pos);
	temp=head;
	if(temp==NULL)
	{
		printf("There is no data add some data first\n");
		return 0;
	}
	if(pos==1)
	{
		temp1=temp;
		head=temp->next;
		free(temp1);
		return head;
	}
	else
	{
		for(int i=1;i<pos;i++)
		{
			prev=temp;
			temp=temp->next;
			ford=temp->next;
		}
		temp1=temp;
		free(temp1);
		prev->next=ford;

		return head;
	}
}

struct del* del_node_4(struct del *head)
{
	struct del *ptr=NULL,*ptr1=NULL,*temp=NULL,*prev=NULL,*temp1=NULL;
	int data1,data2;
	printf("Enter the data 1 and data 2\n");
	scanf("%d%d",&data1,&data2);
	if(data1==data2)
	{
		printf("data1 and data2 is same enter diffrent data\n");
		return head;
	}

	temp=head;
	temp1=head;

	if(head==NULL)
	{

		printf("List is eampty\n");
		return 0;
	}
	else
	{
		while(temp)
		{
			//prev=temp;
			if(data1==temp->data)
				ptr=temp;
			else if(data2==temp->data)
				ptr1=temp;

			if(temp->next==NULL)
			{
				if (ptr==NULL &&ptr1==NULL){
					printf("both data not found\n");
					return temp1;
				}
				else if(ptr==NULL)
					{
						printf("data1 not found enter again\n");
						return temp1;
					}
				else if(ptr1==NULL)
				{
					printf("data2 is not found\n");
					return temp1;
				}
				
				
			}
			temp=temp->next;
		}
		head=ptr;
		ptr1->next=NULL;

	}
		return head;
}


struct del* del_node_3(struct del *head)
{
		int data;
	struct del *temp=NULL,*ptr=NULL,*ford=NULL,*prev=NULL,*temp1=NULL,*p=NULL;
	ptr=temp=head;
	printf("Enter the data");
	scanf("%d",&data);

	if(temp==NULL)
	{
		printf("there is nothing dd some data\n");
		return 0;
	}
	else
	{
	mkc:while(ptr)
		{
			if(data>ptr->data)
			{
				ford=ptr->next;
				if(prev==NULL)
				{
					ptr=ford;
					goto mkc;
				}
				else
				{	

					prev->next=ford;
					//ptr=prev;
					temp1=ptr;
				free(temp1);
				ptr=prev;
				}
				
			}
			if(prev==NULL)
				head=ptr;
			
			prev=ptr;
			
			ptr=ptr->next;


		}
		return head;
	}
}

struct del* del_node_2(struct del *head)
{
	struct del *ptr=NULL,*ptr1=NULL,*temp=NULL,*prev=NULL,*temp1=NULL;
	int data1,data2;
	printf("Enter the data 1 and data 2\n");
	scanf("%d%d",&data1,&data2);
	if(data1==data2)
	{
		printf("data1 and data2 is same enter diffrent data\n");
		return head;
	}
	temp=head;
	temp1=head;

	if(head==NULL)
	{

		printf("List is eampty\n");
		return 0;
	}
	else
	{
		while(temp)
		{
			//prev=temp;
			if(data1==temp->data)
				ptr=temp;
			else if(data2==temp->data)
				ptr1=temp;

			if(ptr==NULL)
				prev=ptr;
			else
				prev=ptr;

			if(temp->next==NULL)
			{
				if (ptr==NULL &&ptr1==NULL){
					printf("both data not found\n");
					return temp1;
				}
				else if(ptr==NULL)
					{
						printf("data1 not found enter again\n");
						return temp1;
					}
				else if(ptr1==NULL)
				{
					printf("data2 is not found\n");
					return temp1;
				}
				
				
			}
			temp=temp->next;
		}
		if(prev==ptr)
			prev->next=ptr1;
		else{
		prev->next=ptr;
		ptr->next=ptr1;
	}



		return head;
	}


}
struct del *del_node(struct del *head)
{
	int data;
	struct del *temp=NULL,*ptr=NULL,*ford=NULL,*prev=NULL,*temp1=NULL,*p=NULL;
	ptr=temp=head;
	printf("Enter the data");
	scanf("%d",&data);

	if(temp==NULL)
	{
		printf("there is nothing dd some data\n");
		return 0;
	}
	else
	{
	mkc:while(ptr)
		{
			if(data<ptr->data)
			{
				ford=ptr->next;
				if(prev==NULL)
				{
					ptr=ford;
					goto mkc;
				}
				else
				{	

					prev->next=ford;
					//ptr=prev;
					temp1=ptr;
				free(temp1);
				ptr=prev;
				}
				
			}
			if(prev==NULL)
				head=ptr;
			
			prev=ptr;
			
			ptr=ptr->next;


		}
		return head;
	}


}

struct del * Add_node(struct del *head)
{
	int data;
	struct del *newnode=NULL,*ptr=NULL,*temp=NULL;
	ptr=head;
	temp=head;
	printf("Enter the data\n");
	scanf("%d",&data);
	newnode=calloc(1,sizeof(struct del));
	newnode->data=data;
	if(ptr==NULL)
	{
		ptr=newnode;
		return ptr;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newnode;
		
	}
	return ptr;

}

void Display(struct del *head)
{
	struct del *ptr=head;
	if(ptr==NULL)
	{
		printf("there  is  nothing add some nodes\n");
	}
	else
	{
		while(ptr)
		{
			printf("[%d]->",ptr->data);
			ptr=ptr->next;
		}
	}
}
int main()
{
	struct del *head=NULL;

	int choice;
	while(1)
	{
		printf("\n");
		printf("press\t1)Add_node\t2)Display\t12)Exit\n");
		printf("press\t3)del_node all bigger than the data\n");
		printf("press\t4)del the num bitween given num\n");
		printf("press\t5)del all nodes less than given num\n");
		printf("press\t6)Del all nodes other than between given data\n");
		printf("press\t7)del node at given position\n");
		printf("press\t8)del the node at given position from end\n");
		printf("press\t9)del all nodes from at given position to beginning from end\n");
		printf("press\t10)del the node from list based on data after given occurrence\n");
		printf("press\t11)del all nodes at given position from end.\t");
		printf("\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:head=Add_node(head);
			break;

			case 2:Display(head);
			break;

			case 3:head=del_node(head);
			break;

			case 4:head=del_node_2(head);
			break;

			case 5:head=del_node_3(head);
			break;

			case 6:head=del_node_4(head);
			break;

			case 7:head=del_node_5(head);
			break;

			case 8:head=del_node_6(head);
			break;

			case 9:head=del_node_7(head);
			break;

			case 10:head=del_node_8(head);
			break;

			case 11:head=del_node_9(head);
			break;
		
			case 12:exit(0);


		}
	}
}