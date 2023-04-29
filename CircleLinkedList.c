#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}Node;

Node *head=NULL,*end=NULL,*p,*q;

int ReadNumberOfNode();
int ReadInput();
void AddNode(int x);
void display(Node *head);
int ReadDeletNode();
int length(Node *head);
Node *DeletNode(int z,Node *head,Node *end);

int main(){
int number,nbrNode,value,i;
nbrNode=ReadNumberOfNode();
for(i=0;i<nbrNode;i++){
	number=ReadInput();
	AddNode(number);
}
display(head);
value=ReadDeletNode();
display(DeletNode(value,head,end));
}


int ReadNumberOfNode()
{int b;
  printf("enter the number of node: ");
  scanf("%d",&b);
  return b;
}

int ReadInput()
{int y;
  printf("enter number: ");
  scanf("%d",&y);
  return y;
}

void AddNode(int x){
  p=(Node*)malloc(sizeof(Node));
  p->data=x;
  if(end==NULL){
  	head=p;
  	end=head;
  }else{
  	q=head;
  	head=p;
  	head->next=q;
  }
  end->next=p;
}

void display(Node *head){
	p=head;
	do {
      printf("%d\n", p->data);
      p=p->next;
   } while(p!=head);
}

int ReadDeletNode()
{int a;
  printf("Enter the node to be deleted: ");
  scanf("%d",&a);
  return a;
}

int length(Node *head){
	if(head==NULL){
		printf("list is empty");
		return -1;
	}else{
		p=head;int c=0;
		do{
			p=p->next;
			c++;
		}while(p!=head);
		return c;
	}
}

Node *DeletNode(int z,Node *head,Node *end){
  p=head;int count=0;
  while(p->data!=z){
  	count++;
  	p=p->next;
  }
  if(count==0){
  	q=head;
  	head=q->next;
  	end->next=head;
  	free(q);
  }else{
  	if(count==length(head)){
  		p=head;
  		q=end;
  		while(p->next!=end){
  			p=p->next;
		}
		end=p;
		end->next=head;
		free(q);
	}else{
		q=head;
		while(q->next!=p){
			q=q->next;
		}
		q->next=p->next;
		free(p);
	}
  }
  return head;
}
