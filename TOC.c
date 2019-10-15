//
//implementation of nfa

#include<stdlib.h>
#include<stdio.h>

struct state
{
	int data; //if data is 0 then it is non final state else final
	struct state *transition_a; //trasition of a
	struct state *transition_b; //transion of b
};

//function that will return us nfa
//this is implemented using structure and pointers

struct state* create_nfa()
{
	struct state *A,*B,*C,*D,*E;
	A=(struct state*) malloc(sizeof(struct state*));
	B=(struct state*) malloc(sizeof(struct state*));
	C=(struct state*) malloc(sizeof(struct state*));
	D=(struct state*) malloc(sizeof(struct state*));
	E=(struct state*) malloc(sizeof(struct state*));
	A->transition_b=B;
	A->transition_a=NULL;
	A->data=0;
	B->transition_a=C;
	B->transition_b=NULL;
	B->data=0;
	C->transition_b=D;
	C->transition_a=NULL;
	C->data=0;
	D->transition_a=E; 
	D->transition_b=NULL;
	D->data=0; //final state
	E->transition_a=NULL;
	E->transition_b=NULL;
	E->data=1;
	return A;
}

//function that shows non-deterministic state
void goout()
{
	printf("Finte Automata Gone into Non-determinstic State\n");
	exit(0);
}

int main()
{
	struct state *temp;
	temp=(struct state*)malloc(sizeof(struct state*));
	temp=create_nfa();
	printf("Enter string\n");
	char string[100];
	scanf("%s",string);
	int i=0;
	while(string[i]!='\0')
	{
		if(string[i]=='a')
		{
			if(temp->transition_a==NULL)
			goout();
			temp=temp->transition_a;
		}
		if(string[i]=='b')
		{
			if(temp->transition_b==NULL)
			goout();
			temp=temp->transition_b;
		}
		i++;
		//printf("%d\n",i);
		
	}
	if(temp->data==0)
	printf("Not accepeted\n");
	if(temp->data==1)
	printf("Accepted\n");

}


