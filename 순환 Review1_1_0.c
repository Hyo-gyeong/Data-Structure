#include <stdio.h> 
#include <string.h> 

void print_reverse(char *str, int end) 
{ 
	int i;

	for (i = end; i >= 0; i--)
		printf("%c", str[i]);
	printf("\n");
} 
int main() 
{ 
	char str[100]; 
	
	printf("Enter any string:");
	scanf("%s", str); 
	
	printf("Reversed String is: "); 
	print_reverse(str, strlen(str) - 1); // str�� ������ �ε����� �Ű������� 
	return 0; 
} 