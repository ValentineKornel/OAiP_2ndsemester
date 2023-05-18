#pragma once

struct Stack
{
	int data;
	Stack* head;
	Stack* next;
};

struct Stack1
{
	char letter;
	Stack1* head;
	Stack1* next;
};

struct Stack2
{
	int data;
	Stack2* head;
	Stack2* next;
};

void dop1(Stack1* myStk1);
void dop2(Stack2* myStk2);
