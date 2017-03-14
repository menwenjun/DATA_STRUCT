#ifndef _stack_h_
#define _stack_h_

#define EmptyTOS	-1
#define MinStackSize	5

typedef int elementType;

typedef struct stackRecord
{
	int capacity;//容量
	int stackTop;//栈顶
	elementType *array;
}STACK;

int isEmpty(STACK *s); 	//判空
int isFull(STACK *s);	//判满
STACK *createStack(int maxElements);	//栈的创建
void disposeStack(STACK *s);		//栈的释放
void makeEmpty(STACK *s);		//创建空栈
void push(elementType element, STACK *s);//入栈
elementType top(STACK *s);		//返回栈顶元素
void pop(STACK *s);			//出栈
elementType topAndTop(STACK *s);	//出栈并返回栈顶元素

#endif
