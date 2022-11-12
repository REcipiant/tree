#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Ltree.h"
#include "Bibalancetree.h"
int main()
{
	LBtree* root = NULL;
	LBtree* p = NULL;
	int num;
	while (1)
	{
		scanf("%d", &num);
		if (num == 0)
		{
			break;
		}
		p = malloc(sizeof(*p));
		if (p == NULL)
		{
			perror("Main malloc");
			exit(1);
		}
		p->data = num;
		p->Lchild = NULL;
		p->Rchild = NULL;
		p->Altree = 1;

		//root = LBitree_insert_sur(root,p);
		root = BIBalancetree_insert_sur(root,p);
	}//5 3 2 6 4 7 8 9 0
	//1 2 3 4 5 6 7 8 0
	printf("\nahead:");
	LBitree_ahead(root);
	printf("\nMid:");
	LBitree_mid(root);
	printf("\nfal:");
	LBitree_final(root);

	return 0;
}