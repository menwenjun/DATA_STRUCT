#include <stdio.h>
#include <stdlib.h>
#include "searchtree.h"
#include "queue.h"


searchTree *find(myType data, searchTree *T)
{
	if(T == NULL) 
		return NULL;
	if(data < T->element)
		return find(data, T->lchild);
	else if(data > T->element)
		return find(data, T->rchild);
	else 
		return T;
}

searchTree *findMin(searchTree *T)
{
	if(T == NULL) 
		return NULL;
	else if(T->lchild == NULL)
		return T;
	else 
		return findMin(T->lchild);
}
searchTree *findMax(searchTree *T)
{
	if(T != NULL) 
		while(T->rchild != NULL)
			T = T->rchild;
	return T;
	
}
searchTree *insert(myType data, searchTree *T)
{
	if(T == NULL) {
		T = (searchTree *)malloc(sizeof(struct treeNode));
		T->element = data;
		T->lchild = NULL;
		T->rchild = NULL;
	} else if (data < T->element) {
		T->lchild = insert(data, T->lchild);	
	} else if (data > T->element) {
		T->rchild = insert(data, T->rchild);	
	}

	return T;
}
searchTree *erase(myType data, searchTree *T)
{
	searchTree *tmpNode;

	if(T == NULL) {
		printf("NOT FOUNT\n");
	} else if (data < T->element) {
		T->lchild = erase(data, T->lchild);	
	} else if (data > T->element) {
		T->rchild = erase(data, T->rchild);
	} else if (T->lchild && T->rchild){
		//found element to delete, two children
		tmpNode = findMin(T->rchild);//将右子树中的最小值代替该点
		T->element = tmpNode->element;
		T->rchild = erase(T->element, T->rchild);
	} else {
		//one or zero children
		tmpNode = T;	
		if(T->lchild == NULL)
			T = T->rchild;
		else if(T->rchild == NULL)
			T = T->lchild;
		free(tmpNode);
	}	

	return T;
}

void levelOrder(searchTree *T)
{
	QUEUE *q = createQueue(100);

	while(T != NULL) {
		printf("%d ", T->element);	
		if(T->lchild != NULL) 
			enQueue(T->lchild, q);	
		if(T->rchild != NULL)
			enQueue(T->rchild, q);
	
		if(!isEmpty(q))
			T = frontAndDequeue(q);
		else
			T = NULL;
	}

	disposeQueue(q);
}

void preOrder(searchTree *T)
{
	if(T != NULL) {
		printf("%d ", T->element);	
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(searchTree *T)
{
	if(T != NULL) {
		inOrder(T->lchild);	
		printf("%d ", T->element);	
		inOrder(T->rchild);
	}
}
void postOrder(searchTree *T)
{
	if(T != NULL) {
		postOrder(T->lchild);	
		postOrder(T->rchild);
		printf("%d ", T->element);	
	}
}

void createTree(searchTree **T)
{
	myType data;
	scanf("%d", &data);

	if(data == -1) {
		*T = NULL;
	} else {
		*T = (searchTree *)malloc(sizeof(struct treeNode));	
		(*T)->element = data;
		printf("请输入%d的左孩子节点：", data);
		createTree(&((*T)->lchild));
		printf("请输入%d的右孩子节点：", data);
		createTree(&((*T)->rchild));
	}
}
