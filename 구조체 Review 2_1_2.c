#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int midterm;
	int final;
}Score;

void printScore(Score *p)
{
	printf("�߰���� ������ %d\n", p->midterm );
	printf("�б⸻��� ������ %d\n", p->final );
}
Score* biggerScore(Score *p1, Score *p2)
{
	if (p1->midterm + p1->final > p2->midterm + p2->final)
		return p1;
	else
		return p2;
}
Score* totalScore(Score *p1, Score *p2)
{
	Score *tmp;

	tmp = (Score *)malloc(sizeof(Score));

	tmp->midterm = p1->midterm + p2->midterm;
	tmp->final = p1->final + p2->final;

	return tmp;
}
Score* createScore(int m, int f) 
{
	Score *tmp;

	tmp = (Score *)malloc(sizeof(Score));

	tmp->midterm = m;
	tmp->final = f;

	return tmp;
}
int main(void)
{
	Score s1, s2;
	Score *p3;

	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);

	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));

	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));

	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3); 
}