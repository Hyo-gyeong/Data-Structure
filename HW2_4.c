#include <stdio.h>
#define MAX_STRING 30
typedef char letter;
typedef int element;

typedef struct {
	letter data[MAX_STRING];
	element top;
}StackType;

void init(StackType *s)
{
	s->top = -1;
} 

void push(StackType *s, letter str[])
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		s->data[++(s->top)] = str[i];
}
int palindrome(char str[])
{
	StackType s; 
	int i;

	init(&s);
	push(&s, str);

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] != s.data[s.top--])
			return 0;
	return 1;
}
int main(void)
{
	 char word[MAX_STRING];

	 printf("Enter a word to check palindrome: ");
	 scanf("%s", word);

	 if (palindrome(word))
		printf("palindrome 입니다.\n");
	 else
		printf("palindrome 이 아닙니다.\n");
}