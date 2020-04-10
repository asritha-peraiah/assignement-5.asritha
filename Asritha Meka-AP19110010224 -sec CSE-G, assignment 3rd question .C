/*write a c program to implement queue using two stacks*/

#include <stdio.h>
#include <stdlib.h>
#define max 500


struct stack{
	int ar[max],n;   /*maximum element is mentioned as n*/
};

struct stack a1, a2; 

void push(struct stack *s, int data){
	if(s->n == max-1){
		printf("obverflw..aborting\n");
		return;
	}
	s->n++;
	s->ar[s->n] = data;
}

int pop(struct stack *s){
	if(s->n == -1){
		return -1;
	}
	int res = s->ar[s->n];
	s->n--;
	return res;
}

void enqueue(int data){
	if(a2.n == -1){
		push(&a1,data);
		return;
	}
	while(a2.n!= -1){
		int ele = pop(&a2);
		push(&a1,ele);   /*push the element a1 from given data*/
	}
	push(&a1,data);

}

int dequeue(){
    if(a1.n == -1 && a2.n == -1){
        return -1;
    }
    if(a1.n == -1){
        return pop(&a2);       /* pop the elememt a2*/
    }
    while(a1.n != -1){
        int ele = pop(&a1);
        push(&a2,ele);
    }
    return pop(&a2);
}
int main(){
    a1.n= -1;
    a2.n = -1;
    int ans, data;
    while(1){
        printf("MENU\n1.Enter the element\n 2.Delete the element\n 3.then exit");
        scanf("%d",&ans);
        switch(ans){
            case 1: {
                printf("enter a data");
                scanf("%d",&data);
                enqueue(data);
                break;
            }
            case 2:{
                data = dequeue();
                if(data == -1) printf("overflow");
                else printf("%d deleted",data);
                break;
            }
            case 3:
            exit(0);break;
        }
    }
	return 0;
}