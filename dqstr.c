#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct DQueue
{
	char **arr;
	int f;
	int r;
	int s;
}dq_t, *dq_pt;

void init(dq_pt q)
{
	q->arr = (char**)calloc(SIZE, sizeof(char*));
	q->f=q->r=-1;
	q->s=0;
}

int isFull(dq_t q)
{
	if(q.s == SIZE-1)
		return 1;
	return 0;
}

int isEmpty(dq_pt q)
{
	if(q->s == 0)
		return 1;
	return 0;
}

void insRight(dq_pt q, char *str)
{
	if(q->r == SIZE-1)
		printf("RIGHT END OVERFLOW!\n");

	else
	{
		if (isEmpty(&q) == 1)
			q->f = q->r = 0;
		else
			q->r += 1;

		q->s += 1;

		*(q->arr + q->r) = str;
	}
}

void insLeft(dq_pt q, char *str)
{
    printf("insert left\n");
	if(isEmpty(&q)==0 && q->f==0)
		printf("LEFT END OVERFLOW!\n");

	else
	{
	    printf("not empty");
		if (isEmpty(&q) == 1)
			q->f = q->r = 0;
		else
			(q->f) -= 1;

		(q->s) += 1;

		(q->arr) = str;

	}
}

char * delLeft(dq_pt q)
{
	char* str;
	if(isEmpty(&q) == 1)
	{
		printf("Underflow!\n");
		return '\0';
	}

	else
	{
		str = (q->arr);// + q->f);
		q->f += 1;
		q->s -= 1;
		return str;
	}
}

void disp(dq_pt q)
{
	if (!isEmpty(q)) {
		printf("\n | Current Queue (f = %d, r = %d, c = %d) : \n", q->f, q->r, q->s);
		int i;
		for (i = q->f; i <= q->r; ++i)
			printf("\t\t%d | %s", i,  *(q->arr + i));
		//printf("\t\t%d | %s", i,  *(q.arr + i));
		printf("\n\n");
	}
}

int main()
{
	dq_pt q;
	q = (dq_pt)malloc(sizeof(dq_t));
	init(q);

	int c = 1;
	char* str = (char*)malloc(sizeof(char*));
	while(c==1 || c==2 || c==3 || c==4)
	{
		printf("1.Insert Left\n2.Insert Right\n3.Delete\n4.Display\n5.Exit");
		printf("\nEnter your choice:");
		scanf("%d", &c);

		if(c==5)
			break;
		if(c==1)
		{
			printf("Enter string:\n");
			scanf("%s", str);
			insLeft(&q,str);
		}
		if(c==2)
		{
			printf("Enter string:\n");
			scanf("%s", str);
			insRight(&q,str);
		}
		if(c==3)
		{
			printf("Deleting...\n");
			str = delLeft(q);
			if( str != '\0')
				printf("Removed string: %s\n", str);
		}
		if(c==4)
		{
			printf("Displaying...\n");
			disp(&q);
		}
	}
	return 0;
}
