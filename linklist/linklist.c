#include <stdio.h>
#include <stdlib.h>

typedef int mytype;

typedef struct link_node{
	mytype data;	
	struct link_node *pnext;
}PNODE;

PNODE *init_node(PNODE *phead, mytype val);
PNODE *add_node_back(PNODE *phead, mytype val);
PNODE *add_node_pre(PNODE *phead, mytype val);
PNODE *insert_node_back(PNODE *phead, mytype val, mytype key);
PNODE *insert_node_pre(PNODE *phead, mytype val, mytype key);
PNODE *search_node(PNODE *phead, mytype key);
PNODE *delete_node(PNODE *phead, mytype key);
PNODE *change_node(PNODE *phead, mytype val, mytype key);
void destory_linklist(PNODE *phead);
void show_linklist(PNODE *phead);
void revshow_linklist(PNODE *phead);
void bubblesort_linklist(PNODE *phead);
void quicksort_linklist(PNODE *phead, PNODE *ptail);
PNODE *divide_two_Qsort(PNODE *phead, PNODE *ptail);
int getlistlen(PNODE *phead);
int getlistlen_recursion(PNODE *phead);
PNODE *invert_linklist(PNODE *phead);
PNODE *invert_linklist_recursion(PNODE *phead);
PNODE *merge_linklist(PNODE *phead1, PNODE *phead2);
PNODE *merge_linklist_recursion(PNODE *phead1, PNODE *phead2);
PNODE *find_midnode(PNODE *phead);
int is_circularlinklist(PNODE *phead);

int is_circularlinklist(PNODE *phead)
{
	if(phead == NULL || phead->pnext == NULL){
		return 0;	
	}
	PNODE *p1 = phead;
	PNODE *p2 = phead;
	while(p1 != NULL && p2 != NULL){
		p2 = p2->pnext;	
		if(p1 == p2)
			return 1;
		p2 = p2->pnext;
		p1 = p1->pnext;
	}
	return 0;
}

PNODE *find_midnode(PNODE *phead)
{
	if(phead == NULL || phead->pnext == NULL){
		return phead;
	}

	PNODE *p1 = phead;
	PNODE *p2 = phead;
	while(p2->pnext != NULL){
		p1 = p1->pnext;//p1走一步
		p2 = p2->pnext;
		if(p2->pnext != NULL){
			p2 = p2->pnext;//p2走两步
		}
	}
	return p1;
}

PNODE *merge_linklist_recursion(PNODE *phead1, PNODE *phead2)
{
	if(phead1 == NULL){
		return phead2;	
	}else if(phead2 == NULL){
		return phead1;	
	}	
	PNODE *phead = NULL;
	if(phead1->data < phead2->data){
		phead = phead1;
		phead->pnext = merge_linklist_recursion(phead1->pnext, phead2);
	}else{
		phead = phead2;
		phead->pnext = merge_linklist_recursion(phead1, phead2->pnext);
	}
	return phead;
}


PNODE *merge_linklist(PNODE *phead1, PNODE *phead2)
{
	if(phead1 == NULL){
		return phead2;	
	}else if(phead2 == NULL){
		return phead1;
	}
	
	PNODE *phead = NULL;

	if(phead1->data < phead2->data){
		phead = phead1;
		phead1 = phead1->pnext;
	}else{
		phead = phead2;	
		phead2 = phead2->pnext;
	}//让phead找到最小的头节点

	PNODE *pcur = phead;//要比较节点(phead1 或 phead2)的上一个节点
	while(phead1 != NULL && phead2 != NULL){
		if(phead1->data < phead2->data){
			pcur->pnext = phead1;
			pcur = phead1;
			phead1 = phead1->pnext;
		}else{
			pcur->pnext = phead2;	
			pcur = phead2;
			phead2 = phead2->pnext;
		}	
	}

	pcur->pnext = ((phead1 == NULL) ? phead2 : phead1);

	return phead;
}

PNODE *invert_linklist_recursion(PNODE *phead)
{
	if(phead == NULL || phead->pnext == NULL){
		return phead;	
	}else{
		PNODE *p = phead;//保存头节点
		PNODE *q = p->pnext;//保存下一个节点
		phead = invert_linklist_recursion(q);//递归到最后一个几点,返回转置后链表的地址
		q->pnext = p;//让后面的节点指向前一个节点
		p->pnext = NULL;//每次递归返回都赋值为空，最后一次返回将转置后的节点的pnext赋值为空
		return phead;
	}
}

PNODE *invert_linklist(PNODE *phead)
{
	if(phead == NULL || phead->pnext == NULL){
		return phead;
	}else{
		PNODE *p = phead;
		PNODE *q = NULL;
		PNODE *r = NULL;
		while(p != NULL){
			q = p->pnext;//保存下一个节点
			p->pnext = r;//让该节点指向上一个节点
			r = p;//上一个节点走到当前节点
			p = q;//当前节点走到下一个节点
		}
		return r;
	}
}

int getlistlen_recursion(PNODE *phead)
{
	if(phead == NULL)
		return 0;
	else
		return 1+getlistlen_recursion(phead->pnext);
}

int getlistlen(PNODE *phead)
{
	int n = 0;

	while(phead != NULL){
		n++;
		phead = phead->pnext;
	}

	return n;
}

void destory_linklist(PNODE *phead)
{
	PNODE *ptmp;	
	while(phead != NULL){
		ptmp = phead;
		phead = phead->pnext;
		free(ptmp);
		ptmp = NULL;
	}
}

PNODE *divide_two_Qsort(PNODE *phead, PNODE *ptail)
{
	int key = phead->data;
	PNODE *p = phead;
	PNODE *q = phead->pnext;
	
	while(q != ptail){
		if(q->data < key){
			p = p->pnext;
			int tmp;
			tmp = p->data;
			p->data = q->data;
			q->data = tmp;
		}	
		q = q->pnext;
	}
	int tmp = p->data;
	p->data = phead->data;
	phead->data = tmp;

	return p;
}

void quicksort_linklist(PNODE *phead, PNODE *ptail)
{
	if(phead != ptail){
		PNODE *pmid = divide_two_Qsort(phead, ptail);	
		quicksort_linklist(phead, pmid);
		quicksort_linklist(pmid->pnext, ptail);
	}
}

void bubblesort_linklist(PNODE *phead)
{
	PNODE *p, *q;
	mytype tmp;
	
	for(p = phead; p != NULL; p=p->pnext){
		for(q = phead; q != NULL; q=q->pnext){
			if(p->data < q->data){
				tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}	
		}	
	}
}

PNODE *change_node(PNODE *phead, mytype val, mytype key)
{
	PNODE *ptmp = search_node(phead, key);
	if(ptmp != NULL){
		ptmp->data = val;		
		return phead;
	}
	return NULL;
}

PNODE *delete_node(PNODE *phead, mytype key)
{
	PNODE *ptmp1 = phead;
	PNODE *ptmp2 = phead;
	PNODE *ptmp;

	if(phead == NULL){
		printf("delete failed: linklist is tempty!\n");	
		return NULL;
	}else{
		while(ptmp1->data != key && ptmp1->pnext != NULL){
			ptmp2 = ptmp1;
			ptmp1 = ptmp1->pnext;
		}
		if(ptmp1->data == key){
			ptmp = ptmp1;
			ptmp2->pnext = ptmp1->pnext;
			free(ptmp1);
			ptmp1 = NULL;
			return (ptmp == phead ? ptmp2->pnext : phead);
		}
		if(ptmp1->pnext == NULL){
			printf("delete failed: key not found!!\n");
			return phead;
		}
	}
}

PNODE *search_node(PNODE *phead, mytype key)
{
	PNODE *ptmp = phead;	

	if(phead == NULL){
		printf("search failed: linklist is empty!\n");
		return NULL;
	}else{
		while(ptmp->data != key && ptmp->pnext != NULL)
			ptmp = ptmp->pnext;
		if(ptmp->data == key){
			return ptmp;	
		}
		if(ptmp->pnext == NULL){
			printf("key not found!!!\n");	
			return NULL;
		}
	}
}


PNODE *insert_node_pre(PNODE *phead, mytype val, mytype key)
{
	PNODE *pnode = init_node(pnode, val);	
	PNODE *ptmp = phead;

	if(phead == NULL){
		return pnode;	
	}else if(phead->data == key){
		pnode->pnext = phead;
		return pnode;
	}else{
		while(ptmp->pnext != NULL && ptmp->pnext->data != key) 	
			ptmp = ptmp->pnext;
		if(ptmp->pnext == NULL){
			printf("insert fail:key not found!!!\n");
			free(pnode);
			pnode = NULL;
			return phead;
		}
		if(ptmp->pnext->data == key){
			pnode->pnext = ptmp->pnext;	
			ptmp->pnext = pnode;
			return phead;
		}
	}
}

PNODE *insert_node_back(PNODE *phead, mytype val, mytype key)
{
	PNODE *pnode = init_node(pnode, val);
	PNODE *ptmp = phead;

	if(phead == NULL){
		return pnode;
	}else{
		while(ptmp->data != key && ptmp->pnext != NULL){
			ptmp = ptmp->pnext;	
		}	
		if(ptmp == NULL){
			printf("insert fail:key not found!!!\n");
			free(pnode);
			pnode = NULL;
			return phead;
		}
		if(ptmp->data == key){
			pnode->pnext = ptmp->pnext;
			ptmp->pnext = pnode;
			return phead;
		}
	}
}

PNODE *add_node_pre(PNODE *phead, mytype val)
{
	PNODE *pnode = init_node(pnode, val);	
	PNODE *ptmp = phead;

	if(phead == NULL){
		return pnode;	
	}else{
		phead = pnode;
		pnode->pnext = ptmp;
		return phead;
	}
}


void show_linklist(PNODE *phead)
{
	if(phead == NULL){
		return;	
	}else{
		printf("%d\t", phead->data);	
		show_linklist(phead->pnext);
	}
}

void revshow_linklist(PNODE *phead)
{
	if(phead == NULL){
		return;	
	}else{
		revshow_linklist(phead->pnext);	
		printf("%d\t", phead->data);
	}
}

PNODE *init_node(PNODE *phead, mytype val)
{
	phead = (PNODE *)malloc(sizeof(PNODE));
	phead->data = val;
	phead->pnext = NULL;

	return phead;
}

PNODE *add_node(PNODE *phead, mytype val)
{
	PNODE *pnode = init_node(pnode, val);	
	PNODE *ptmp = phead;

	if(phead == NULL){
		return pnode;	
	}else{
		while(ptmp->pnext != NULL)	
			ptmp = ptmp->pnext;
		ptmp->pnext = pnode;
		return phead;
	}
}

int main2()
{
	PNODE *phead1 = NULL;	
	phead1 = add_node(phead1, 10);
	phead1 = add_node(phead1, 16);
	phead1 = add_node(phead1, 18);
	phead1 = add_node(phead1, 28);
	phead1 = add_node(phead1, 38);

	PNODE *phead2 = NULL;	
	phead2 = add_node(phead2, 1);
	phead2 = add_node(phead2, 13);
	phead2 = add_node(phead2, 15);
	phead2 = add_node(phead2, 19);
	phead2 = add_node(phead2, 43);
	phead2 = add_node(phead2, 73);

	PNODE *phead = merge_linklist_recursion(phead1, phead2);
	show_linklist(phead);
	printf("%d\n", (find_midnode(phead))->data);
	destory_linklist(phead);
	return 0;
}

int main()
{
	PNODE *phead = NULL;	
	PNODE *pfind;
	phead = add_node(phead, 102);
	phead = add_node(phead, 102);
	phead = add_node(phead, 102);
	phead = add_node(phead, 102);
	phead = add_node(phead, 102);
	phead = add_node(phead, 11);
	phead = add_node(phead, 122);
	phead = add_node(phead, 1);
	phead = add_node(phead, 213);
	phead = add_node(phead, 123);
	PNODE *p;
	for(p = phead; p->pnext != NULL; p = p->pnext)
		;
	p->pnext = phead;

//	phead = insert_node_pre(phead, 100, 10);
//	pfind = search_node(phead, 13);
//	printf("%d\n", pfind->data);
//	phead = delete_node(phead, 3);
//	phead = change_node(phead, 100, 2);
//	show_linklist(phead);
//	bubblesort_linklist(phead);
//	quicksort_linklist(phead, NULL);
//	printf("%d\n", getlistlen_recursion(phead));
//	show_linklist(phead);
	printf("\n");
	printf("%d\n", is_circularlinklist(phead));
//	phead = invert_linklist_recursion(phead);
//	show_linklist(phead);
	printf("\n");

//	destory_linklist(phead);
	return 0;
}
