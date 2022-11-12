#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Ltree.h"
#include "Loopqueue.h"
/*
	LBitree_insert:链式二叉树的插入
	@p：插入的结点
	返回值：
			返回二叉树的root结点（指针）
	
*/
LBtree* LBitree_insert(LBtree* root, LBtree* p)
{
	LBtree* pk = NULL;
	LBtree* father = NULL;
	if (root == NULL)
	{
		return p;//将第一个结点作为root结点
	}
	if (p == NULL)
	{
		return root;
	}
	pk = root;
	while (pk != NULL)
	{
		//二叉树的顺序排列，即左<根<右（包括子树）
		if (pk->data < p->data)//如果父节点的data小于插入结点，则要挂载到父节点的Rchild
		{
			father = pk;
			pk = pk->Rchild;
		}
		else if (pk->data > p->data)//如果父节点的data大于插入结点，则要挂载到父节点的Lchild
		{
			father = pk;
			pk = pk->Lchild;
		}
		else//不考虑相等
		{
			return root;
		}
	}
	if (father->data < p->data)
	{
		father->Rchild = p;
	}
	else//相等，小于
	{
		father->Lchild = p;
	}
	return root;
}
//递归版
LBtree* LBitree_insert_sur(LBtree* root, LBtree* p)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (p == NULL);
	{
		return root;
	}

	if (root->data < p->data)
	{
		root->Rchild = LBitree_insert_sur(root->Rchild, p);
	}
	else
	{
		root->Lchild = LBitree_insert_sur(root->Lchild, p);
	}
	return root;
}
/*
	二叉树的遍历：先序，中序，后序遍历
	LBitree_ahead:二叉树的先序遍历（先根遍历）
	@root：根结点
	返回值
		空
*/
//递归版
void LBitree_ahead(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);//根
		LBitree_ahead(root->Lchild);//左
		LBitree_ahead(root->Rchild);//右
	}
	//return;
}

/*
	LBitree_mid:中序遍历
	@root：根结点
	返回值
		空

*/
void LBitree_mid(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		LBitree_mid(root->Lchild);//左
		printf("%d ",root->data);//根
		LBitree_mid(root->Rchild);//右
	}
	return;
}
/*
	LBitree_final:后序遍历
	@root：根结点
	返回值
		空

*/
void LBitree_final(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		LBitree_final(root->Lchild);//左
		LBitree_final(root->Rchild);//右
		printf("%d ",root->data);//根
	}
	return;
}
/*
	LBitree_level:层次遍历
	@root：根结点
	返回值
		空

*/

void LBitree_level(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	Lqueue* LQ = LQ_Init(1024);
	LQ_input(LQ,root);
	while (LQ_isempty(LQ) != 0)
	{
		Elemtype p;
		LQ_out(LQ, &p);

		printf("%d ",((LBtree* )p)->data);

		if (((LBtree*)p)->Lchild != NULL)
		{
			LQ_input(LQ, ((LBtree*)p)->Lchild);
		}
		if (((LBtree*)p)->Rchild != NULL)
		{
			LQ_input(LQ, ((LBtree*)p)->Rchild);
		}
	}

	LQ_Destroy(LQ);
	return;
}
/*
	LBitree_high:求二叉树的高度
	@root：二叉树的根
	返回值：
			二叉树的高度
*/

int LBitree_high(LBtree* root)
{
	//法一
	int high = 0;
	int high1 = 0;
	if (root == NULL)
	{
		return 0;
	}
	high = LBitree_high(root->Lchild) + 1;//求左子树的高度
	high1 = LBitree_high(root->Rchild) + 1;//求右子树的高度
	return high > high1 ? high : high1;//最大值即为，树的高度
	/*
		//法二：
		//定义求最大值的宏
		#define Max(a,b) ((a) > (b))?(a):(b)

		if(root == NULL)
		{
			return 0;
		}
		//即左子树与右子树最大值再加上+1（root结点），跟法一差不多
		return Max(LBitree_high(root->Lchild),LBitree_high(root->Rchild)) + 1;
	*/
}
/*
	LBitree_MaxNode:二叉树的最大值的结点
	@root：根结点
	返回值：
			最大值结点指针
*/
LBtree* LBitree_MaxNode(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->Rchild == NULL)
	{
		return root;
	}
	else
	{
		root = LBitree_MaxNode(root->Rchild);
	}
}

/*
	LBitree_del:二叉树结点删除操作
	@root：根结点
	@aim：删除的目标结点
	返回值：
			根结点指针
*/
LBtree* LBitree_del(LBtree* root, int aim)
{
	LBtree* pk = NULL;
	LBtree* Fa = NULL;
	LBtree* max = NULL;
	if (root == NULL)
	{

		return NULL;
	}
	pk = root;
	//删除操作：1.先找到删除的结点；2.再删除
	while (pk != NULL)//遍历树，找到删除结点
	{
		if (pk->data < aim)
		{
			Fa = pk;
			pk = pk->Rchild;
		}
		else if(pk->data > aim)
		{
			Fa = pk;
			pk = pk->Lchild;
		}
		else
		{
			break;
		}
	}
	//删除操作
	if (pk == NULL)//没找到
	{
		return root;
	}
	else//找到了

	{
lable:
		if (pk->Rchild == NULL && pk->Lchild == NULL)//终端结点（叶子结点）无左右孩子
		{
			if (pk == root)//仅有一个根结点
			{
				free(pk);
				return NULL;
			}
			else
			{
				if (Fa->Lchild == pk)//是父节点的左孩子
				{
					
					Fa->Lchild = NULL;
				}
				if (Fa->Rchild == pk)//是父节点的右孩子
				{
					Fa->Rchild = NULL;
				}
				free(pk);
			}
			return root;
		}
		else if (pk->Lchild != NULL && pk->Rchild == NULL)//删除的结点在中间，且只有左孩子
		{
			if (pk == root)
			{
				root = pk->Lchild;
				pk->Lchild = NULL;
				free(pk);
			}
			else
			{
				if (Fa->Rchild == pk)
				{
					Fa->Rchild = pk->Lchild;
				}
				if (Fa->Lchild == pk)
				{
					Fa->Lchild = pk->Lchild;
				}
				pk->Lchild = NULL;
				free(pk);
			}
			return root;
		}
		else if (pk->Rchild != NULL && pk->Lchild == NULL)//删除的结点在中间，且只有右孩子
		{
			if (Fa == NULL)
			{
				root = pk->Rchild;
				pk->Rchild = NULL;
				free(pk);
			}
			else
			{
				if (Fa->Rchild == pk)
				{
					Fa->Rchild = pk->Rchild;
				}
				if (Fa->Lchild == pk)
				{
					Fa->Lchild = pk->Rchild;
				}
				pk->Rchild = NULL;
				free(pk);
			}
			return root;
		}
		else//删除的结点既有右孩子又有左孩子
		{
			//法一：找到要删除结点的左子树中的最大值替换该删除结点的值，然后删除左子树的最大值结点
			//法二：找到要删除结点的右子树中的最小值替换该删除结点的值，然后删除右子树的最小值结点

			//以下采用法一
				max = pk;
				Fa = pk;
				pk = pk->Lchild;
				while (pk->Rchild != NULL)//找到替换后的结点
				{
					Fa = pk;
					pk = pk->Rchild;
				}
				max->data = pk->data;
			//删除
			goto lable;
		}

	}

}