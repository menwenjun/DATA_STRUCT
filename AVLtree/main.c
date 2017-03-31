#include <stdio.h>
#include <stdlib.h>
#include "AVLtree.h"
#include "queue.h"


int main(void)
{
	AVLtree *t = NULL;

	//createTree(&t);
	t = insert(5, t);
	t = insert(2, t);
	t = insert(1, t);
	t = insert(4, t);
	t = insert(3, t);
	t = insert(8, t);
	t = insert(6, t);
	t = insert(7, t);

	printf("层次遍历\n");
	levelOrder(t);
	printf("\n先根序\n");
	preOrder(t);
	printf("\n中根序\n");
	inOrder(t);
	printf("\n后根序\n");
	postOrder(t);
	printf("\nfind min:%d\n", (findMin(t))->element);
	printf("find max:%d\n", (findMax(t))->element);
	printf("find 6: %d\n", (find(6, t))->element);
	t = erase(6, t);
	printf("删除6，层次遍历\n");
	levelOrder(t);
	t = erase(2, t);
	printf("\n删除2，层次遍历\n");
	levelOrder(t);


	return 0;
}
