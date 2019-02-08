#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef int element;

typedef struct DlistNode {//doubly link�̴ϱ� llink, rlink �Ѵ� ����
	element data;
	struct DlistNode *llink;
	struct DlistNode *rlink;
} DlistNode;

typedef struct {//top�� �ּҸ� �����ϴ� ����ü ����
	DlistNode *top;
} LinkedStackType;

void init(LinkedStackType *s)//�ʱ�ȭ �ϴ� �Լ�
{
	s->top = NULL;
}

int is_empty(LinkedStackType *s)//top�� null�̸� 1�� ��ȯ�ϴ� empty Ȯ�� �Լ�
{
	return (s->top == NULL);
}

void push(LinkedStackType *s, element item)
{
	DlistNode *temp = (DlistNode *)malloc(sizeof(DlistNode));
	if (temp == NULL) {
		fprintf(stderr, "Memory allocation error\n");
		return;
	}

	else {
		if (s->top == NULL) {//ó�� ���� �����
			temp->data = item;//data�� item �����ϰ�
			s->top = temp;//top �ּҸ� ���� ���� temp �ּҷ� ����
		}
		else {//2��° ���� �����
			temp->data = item;
			s->top->rlink = temp;//������ top ����� rlink�� temp�� ����
			temp->llink = s->top;//temp�� llink�� ������ top �ּҸ� ����
			s->top = temp;//���� top�� ���ο� temp�� ����Ű���� ��
		}
	}
}

element pop(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		DlistNode *temp = s->top;//�ϴ� temp �ּҸ� �����ؼ� top�ּҸ� �����ϰ�
		int item = temp->data;//item�� ��ȯ�ϱ� ���ؼ� ������ �д�.
		s->top = s->top->llink;//�׸��� ���� top�� �� ���� ��带 ����Ű���� �Ѵ�.
		free(temp);
		return item;
	}
}

element peek(LinkedStackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->top->data;
	}
}

void main()
{
	LinkedStackType s;
	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);

	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
}
