#pragma once
#ifndef __LTREE_H__
#define __LTREE_H__
//链式结构二叉树
//将二叉树的结点抽象成结构体

typedef struct LBtree
{
	//不管什么对象，都能够提取其特征，
	//如对象本身应有的属性，以及数据与
	//数据（或者对象与对象）之间的逻辑结构
	//对于数据的存储方式一般有两种：顺序存储与链式存储
	//就目前而言，所有对象与对象之间的存储方式务必归结
	//到上述两种存储结构。对于对象的抽象一般用结构体进
	//行封装，至于结构体的成员（即对象的属性）因人而异。

	//以树的结点作为对象，抽象出其属性
	//1.树的结点存储的数据元素（数据域）
	//2.树的结点的孩子变量(指针域)

	struct LBtree* Rchild;
	struct LBtree* Lchild;

	int data;
	//平衡二叉树,树的高度
	int Altree;

}LBtree;

/*
	LBitree_insert:链式二叉树的插入
	@p：插入的结点
	返回值：
			返回二叉树的root结点（指针）

*/
LBtree* LBitree_insert(LBtree* root, LBtree* p);

//递归版
LBtree* LBitree_insert_sur(LBtree* root, LBtree* p);
/*
	二叉树的遍历：先序，中序，后序遍历
	LBitree_ahead:二叉树的先序遍历（先根遍历）
	@root：根结点
	返回值
		空

*/
//递归版
void LBitree_ahead(LBtree* root);
/*
	LBitree_mid:中序遍历
	@root：根结点
	返回值
		空

*/
void LBitree_mid(LBtree* root);
/*
	LBitree_final:后序遍历
	@root：根结点
	返回值
		空

*/
void LBitree_final(LBtree* root);

/*
	LBitree_level:层次遍历
	@root：根结点
	返回值
		空

*/

void LBitree_level(LBtree* root);
/*
	LBitree_high:求二叉树的高度
	@root：二叉树的根
	返回值：
			二叉树的高度
*/

int LBitree_high(LBtree* root);
/*
	LBitree_MaxNode:二叉树的最大值的结点
	@root：根结点
	返回值：
			最大值结点指针
*/
LBtree* LBitree_MaxNode(LBtree* root);
/*
	LBitree_del:二叉树结点删除操作
	@root：根结点
	@aim：删除的目标结点
	返回值：
			root指针
*/
LBtree* LBitree_del(LBtree* root, int aim);



#endif 
