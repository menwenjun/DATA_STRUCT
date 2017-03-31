#ifndef _SEARCHTREE_H_
#define _SEARCHTREE_H_

#define MAX(a, b)	(a > b ? a : b)
#define GET_HEIGHT(T)	(T == NULL ? -1 : T->height)

typedef int myType;

typedef struct treeNode 
{
	myType element;
	struct treeNode *lchild;
	struct treeNode *rchild;
	int height;
}AVLtree;

//void createTree(AVLtree **T);
void preOrder(AVLtree *T);
void inOrder(AVLtree *T);
void postOrder(AVLtree *T);
void levelOrder(AVLtree *T);
AVLtree *find(myType data, AVLtree *T);
AVLtree *findMin(AVLtree *T);
AVLtree *findMax(AVLtree *T);
AVLtree *insert(myType data, AVLtree *T);
AVLtree *erase(myType data, AVLtree *T);


#endif
