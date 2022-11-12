#pragma once
#ifndef __BIBALANCETREE_H__
#define __BIBALANCETREE_H__
#include "Ltree.h"
/*
	BIBalancetree_insert_sur:二叉平衡树的创建
	@root:根节点
	@p：待插入的结点
	返回值：
			根节点指针
*/
LBtree* BIBalancetree_insert_sur(LBtree* root, LBtree* p);

/*
	BIBalancetree_Rrotate:单向右旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_Rrotate(LBtree* root);

/*
	BIBalancetree_Lrotate:单向左旋
	@root:根结点
	返回值：
			新的根节点
*/

LBtree* BIBalancetree_Lrotate(LBtree* root);

/*
	BIBalancetree_L_R_rotate:先单向左旋，然后单向右旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_L_R_rotate(LBtree* root);

/*
	BIBalancetree_R_L_rotate:先单向右旋，然后单向左旋
	@root:根结点
	返回值：
			新的根节点
*/
LBtree* BIBalancetree_R_L_rotate(LBtree* root);

/*
	BIBalancetree_Altree:每个结点的高度
	@root：根节点
	返回值：
			结点的高度
*/
int BIBalancetree_Altree(LBtree* root);










#endif // !__BIBALANCETREE_H__

