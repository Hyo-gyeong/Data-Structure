#include <stdio.h> 
#include <string.h> 

void reverse_string(char *str, int s, int e) 
{ 
	char tmp = str[e];
	
	if (e > s){
		str[e] = str[s];
		str[s] = tmp;
		reverse_string(str, s+1, e-1);
	}
	//������
	/* if (s >= e) return;
	
	str[s]�� str[e]�� �ٲٰ� ��͸� �θ���*/
} 
int main() 
{ 
	char str[100]; 
	
	printf("Enter any string:"); 
	scanf("%s", str); 
	
	reverse_string(str, 0, strlen(str) - 1); 
	printf("\nReversed String is: %s", str); 
	return 0; 
} 