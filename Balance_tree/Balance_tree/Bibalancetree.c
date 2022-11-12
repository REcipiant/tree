#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "Bibalancetree.h"
#include "Ltree.h"
#define Max( a , b )	((a) > (b)? (a) : (b))
//********************************************************
//二叉平衡树的建立，所有一切的前提均基于顺序树，否则全部失效
//二叉树的平衡处理
/*
	分为四种情况：
	左子树的左边插入导致二叉树失衡
	方法：单向右旋
	右子树的右边插入导致二叉树失衡
	方法：单向左旋
	左子树的右边插入导致二叉树失衡
	方法：先单向左旋，然后单向右旋
	左子树的左边插入导致二叉树失衡
	方法：先单向右旋，然后单向左旋
*/
//************************************************************
/*
	BIBalancetree_insert_sur:二叉平衡树的创建
	@root:根节点
	@p：待插入的结点
	返回值：
			根节点指针
*/
LBtree* BIBalancetree_insert_sur(LBtree* root, LBtree* p)
{
	if (root == NULL)
	{
		return p;
	}
	if (p == NULL)
	{
		return root;
	}

	if (root->data < p->data)//右插
	{
		root->Rchild = BIBalancetree_insert_sur(root->Rchild, p);//先插入
		root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;//同时保存每个结点的高度
		
		//测试
		printf("1.root->Al = %d\n", root->Altree);
		//检查是否失衡
		if (abs(BIBalancetree_Altree(root->Lchild) - BIBalancetree_Altree(root->Rchild)) > 1)//若当前结点高度差>1,失衡
		{
			
			//printf("1.root->LH = %d,root->RH = %d\n", root->Lchild->Altree, root->Rchild->Altree);
			

			if (root->Rchild->data < p->data)//右子树右插
			{
				root = BIBalancetree_Lrotate(root);//单向左旋
			}
			else if (root->Rchild->data > p->data)//右子树左插
			{
				root = BIBalancetree_R_L_rotate(root);//先右旋，再左旋
			}
			
		}
		return root;
	}
	else if (root->data > p->data)//左插
	{
		root->Lchild = BIBalancetree_insert_sur(root->Lchild, p);
		root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;
		printf("2.root->Al = %d\n", root->Altree);
		if (abs(BIBalancetree_Altree(root->Lchild) - BIBalancetree_Altree(root->Rchild)) > 1)//若当前结点高度差>1,失衡
		{
			//
			//printf("2.root->LH = %d,root->RH = %d\n", root->Lchild->Altree, root->Rchild->Altree);
			//

			if (root->Lchild->data > p->data)//左子树的左边插入p结点
			{
				root = BIBalancetree_Rrotate(root);//单向右旋

			}
			else if (root->Lchild->data < p->data)//左子树的右边插入p结点
			{
				root = BIBalancetree_L_R_rotate(root);//先左旋，后右旋
			}
		}
		return root;
	}


	//每次增加结点后计算结点的高度
	//root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;



	return root;

}


/*
	BIBalancetree_Rrotate:单向右旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_Rrotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* newroot = root->Lchild;//对失衡的结点的左子树进行右旋，原来失衡的左子树的根节点作为树的新根
	root->Lchild = newroot->Rchild;//将新根的右子树接到旧根的左子树上
	newroot->Rchild = root;//然后由旧根充当心根的右子树

	//整棵二叉树除了新根与旧根两个结点的高度有变化，其余结点没有变化，计算高度原则，新根最后计算高度，旧根后计算
	//即：先计算子结点的高度，后计算父结点的高度，左旋类似
	root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;
	newroot->Altree = Max(BIBalancetree_Altree(newroot->Lchild), BIBalancetree_Altree(newroot->Rchild)) + 1;
	return newroot;
}

/*
	BIBalancetree_Lrotate:单向左旋
	@root:根结点
	返回值：
			新的根节点
*/

LBtree* BIBalancetree_Lrotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* newroot = root->Rchild;
	root->Rchild = newroot->Lchild;
	newroot->Lchild = root;

	root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;
	newroot->Altree = Max(BIBalancetree_Altree(newroot->Lchild), BIBalancetree_Altree(newroot->Rchild)) + 1;

	return newroot;
}


/*
	BIBalancetree_L_R_rotate:先单向左旋，然后单向右旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_L_R_rotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* pL = root->Lchild;
	root->Lchild = BIBalancetree_Lrotate(pL);
	return BIBalancetree_Rrotate(root);
}
/*
	BIBalancetree_R_L_rotate:先单向右旋，然后单向左旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_R_L_rotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* pR = root->Rchild;
	root->Rchild = BIBalancetree_Rrotate(pR);//先右旋
	return BIBalancetree_Lrotate(root);//后左旋
}

/*
	BIBalancetree_Altree:每个结点的高度
	@root：根节点
	返回值：
			结点的高度
*/
int BIBalancetree_Altree(LBtree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->Altree;
}
