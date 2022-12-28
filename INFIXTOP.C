#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char data){
	if(top == MAX-1){printf("Stack is full\n");}
	else{
		stack[++top] = data;
	}
}
char pop(){
	if(top == -1){printf("Stack is empty");}
	else{
		return stack[top--];
	}
	return ' ';
}

char top_ele(){
	if(top == -1){printf("Stack is empty");}
	else{
		return stack[top];
	}
	return ' ';
}

int precedence(char ch){
	if(ch == '+' || ch == '-'){return 1;}
	else if(ch == '*' || ch == '/'){return 2;}
	else{return 0;}
}

char* infix_to_postfix(char infix[], char postfix[]){
	int i = 0, j = 0;
	while(infix[i] != '\0'){
		if(infix[i] == '('){
			push(infix[i]);
			i++;
		}
		else if(infix[i] == ')'){
			while(stack[top] != '('){
				postfix[j] = pop();
				j++;
			}
			pop();
			i++;
		}
		else if(isdigit(infix[i]) || isalpha(infix[i])){
			postfix[j] = infix[i];
			i++;
			j++;
		}
		else if(infix[i] == '+' || infix[i] == '-'){
			while(stack[top] != '(' && precedence(stack[top]) >= precedence(infix[i])){
				postfix[j] = pop();
				j++;
			}
			push(infix[i]);
			i++;
		}
		else{
			push(infix[i]);
            i++;
		}
	}
	while(top != -1){
		postfix[j] = pop();
		j++;
	}
	postfix[j] = '\0';
	return postfix;
}

int main(){
	char postfix[50];
	//clrscr();
	printf("%s", infix_to_postfix("(A+(B-C)*D)", postfix));
	//printf("%s", postfix);
	return 0;
}
