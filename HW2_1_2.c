#include <stdio.h>

#define MAX_STACK_SIZE 3 
#define MAX_LETTER_SIZE 10
typedef int element;
typedef char letter;

typedef struct {
	element data[MAX_STACK_SIZE];
	letter str_data[MAX_STACK_SIZE][MAX_LETTER_SIZE];
	int top;
} StackType;

void init(StackType *s)
{
	s->top = -1; 
}

int is_empty(StackType *s)
{
	return (s->top == -1); 
}

int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE-1));
}

void push(StackType *s, element item, letter str[])
{
	int i;

	 if(is_full(s)) {
		 fprintf(stderr,"스택 포화 에러\n");
		 return;
	 }
	 else {
		s->data[++(s->top)] = item;
		for (i = 0; str[i] != '\0'; i++)
			s->str_data[s->top][i] = str[i];
		s->str_data[s->top][i] = '\0';
	 }
}

element pop(StackType *s)
{
	 if( is_empty(s) ) {
		 fprintf(stderr, "스택 공백 에러\n");
		 return;
	 }
	 else
		return s->data[(s->top)--];
}

element peek(StackType *s)
{
	 if( is_empty(s) ) {
		 fprintf(stderr, "스택 공백 에러\n");
		 return;
	 }
	 else
		return s->data[s->top];
}

void stack_print(StackType *s)
{
	int i;

	if (is_empty(s))
		printf("<empty>\n--\n");
	else {
		for (i = s->top; i >= 0; i--){
			if (i == s->top)
				printf("[%d, %s] <- top\n", s->data[i], s->str_data[i]);
			else
				printf("[%d, %s]\n", s->data[i], s->str_data[i]);
		}
		printf("--\n");
	}
}

void main()
{
	 StackType s;

	 init(&s);
	 stack_print(&s);
	 push(&s, 10, "ten");
	 stack_print(&s);
	 push(&s, 20, "twenty");
	 stack_print(&s);
	 push(&s, 30, "thirty");
	 stack_print(&s);
	 push(&s, 40, "fouty");
	 stack_print(&s);
	 pop(&s);
	 stack_print(&s);
	 push(&s, 50, "fifty");
	 stack_print(&s);
	 pop(&s);
	 stack_print(&s);
	 pop(&s);
	 stack_print(&s);
	 pop(&s);
	 stack_print(&s);
}