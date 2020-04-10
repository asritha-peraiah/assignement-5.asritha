/*4.write a c program for insertion and deletion of BST*/

# include <stdio.h>
# include <malloc.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node *xchild;
	struct node *ychild;
}*root;


void find(int item,struct node **par,struct node **loc)
{
	struct node *ptr,*ptrsave;

	if(root==NULL) 
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->info) 
	{
		*loc=root;
		*par=NULL;
		return;
	}
	if(item<root->info)
		ptr=root->xchild;
	else
		ptr=root->ychild;
	ptrsave=root;

	while(ptr!=NULL)
	{
		if(item==ptr->info)
		{       *loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->info)
			ptr=ptr->xchild;
		else
			ptr=ptr->ychild;
	}
	*loc=NULL;   
	*par=ptrsave;
}

void insert(int item)
{       struct node *tmp,*parent,*location;
	find(item,&parent,&location);
	if(location!=NULL)
	{
		printf("Item already present");
		return;
	}

	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=item;
	tmp->xchild=NULL;
	tmp->ychild=NULL;

	if(parent==NULL)
		root=tmp;
	else
		if(item<parent->info)
			parent->xchild=tmp;
		else
			parent->ychild=tmp;
}


void case_a(struct node *par,struct node *loc )
{
	if(par==NULL) 
		root=NULL;
	else
		if(loc==par->xchild)
			par->xchild=NULL;
		else
			par->ychild=NULL;
}

void case_b(struct node *par,struct node *loc)
{
	struct node *child;

	/*Initialize a child*/
	if(loc->xchild!=NULL) 
		child=loc->xchild;
	else                
		child=loc->ychild;

	if(par==NULL )
		root=child;
	else
		if( loc==par->xchild)   /*item is xchild of their parent*/
			par->xchild=child;
		else                  /*item is ychild of their parent*/
			par->ychild=child;
}

void case_c(struct node *par,struct node *loc)
{
	struct node *ptr,*ptrsave,*suc,*parsuc;

	/*Find the inorder successor and its parent*/
	ptrsave=loc;
	ptr=loc->ychild;
	while(ptr->xchild!=NULL)
	{
		ptrsave=ptr;
		ptr=ptr->xchild;
	}
	suc=ptr;
	parsuc=ptrsave;

	if(suc->xchild==NULL && suc->ychild==NULL)
		case_a(parsuc,suc);
	else
		case_b(parsuc,suc);

	if(par==NULL) 
		root=suc;
	else
		if(loc==par->xchild)
			par->xchild=suc;
		else
			par->ychild=suc;

	suc->xchild=loc->xchild;
	suc->ychild=loc->ychild;
}/*End of case_c()*/
int del(int item)
{
	struct node *parent,*location;
	if(root==NULL)
	{
		printf("Tree empty");
		return 0;
	}

	find(item,&parent,&location);
	if(location==NULL)
	{
		printf("Item not present in tree");
		return 0;
	}

	if(location->xchild==NULL && location->ychild==NULL)
		case_a(parent,location);
	if(location->xchild!=NULL && location->ychild==NULL)
		case_b(parent,location);
	if(location->xchild==NULL && location->ychild!=NULL)
		case_b(parent,location);
	if(location->xchild!=NULL && location->ychild!=NULL)
		case_c(parent,location);
	free(location);
}/*End of del()*/
void display(struct node *ptr,int level)
{
	int i;
	if ( ptr!=NULL )
	{
		display(ptr->ychild, level+1);
		printf("\n");
		for (i = 0; i < level; i++)
			printf("    ");
		printf("%d", ptr->info);
		display(ptr->xchild, level+1);
	}/*End of a if*/
}/*End of the display()*/
main()
{
	int choice,num;
	root=NULL;
	while(1)
	{
		printf("\n");
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Display\n");
		printf("4.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
		case 1:
			printf("Enter a number to be a inserted : ");
			scanf("%d",&num);
			insert(num);
			break;
		case 2:
			printf("Enter a number to be a deleted : ");
			scanf("%d",&num);
			del(num);
			break;
		case 3:
			display(root,1);
			break;
		case 4:
            exit(0);
		default:
			printf("Wrong choice\n");
		}/*End of the switch */
	}/*End of the while */
}/*End of the main()*/

