#include <stdio.h>
#include <ctype.h>

int stack[20]; 
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    if (top == -1)
        return -1;  
    else
        return stack[top--];
}

void Evalpostfix(char postfix[]) {
    int val, A, B;
    char ch;
    for (int i = 0; postfix[i] != '\0'; i++) { 
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');  // Convert char to int
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            A = pop();
            B = pop();
            switch (ch) {
                case '*': val = B * A; break;
                case '/': val = B / A; break;
                case '+': val = B + A; break;
                case '-': val = B - A; break;
                default: printf("Error\n"); return;
            }
            push(val);
        }
    }
    printf("\nResult of Expression Evaluation: %d\n", pop());
}

int main() {
    char postfix[100];
    printf("\nEnter the Expression: ");
    scanf("%s", postfix);
    Evalpostfix(postfix);
    return 0;
}
