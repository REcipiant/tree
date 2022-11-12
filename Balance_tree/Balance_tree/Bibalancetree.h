#pragma once
#ifndef __BIBALANCETREE_H__
#define __BIBALANCETREE_H__
#include "Ltree.h"
/*
	BIBalancetree_insert_sur:����ƽ�����Ĵ���
	@root:���ڵ�
	@p��������Ľ��
	����ֵ��
			���ڵ�ָ��
*/
LBtree* BIBalancetree_insert_sur(LBtree* root, LBtree* p);

/*
	BIBalancetree_Rrotate:��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/
LBtree* BIBalancetree_Rrotate(LBtree* root);

/*
	BIBalancetree_Lrotate:��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/

LBtree* BIBalancetree_Lrotate(LBtree* root);

/*
	BIBalancetree_L_R_rotate:�ȵ���������Ȼ��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/
LBtree* BIBalancetree_L_R_rotate(LBtree* root);

/*
	BIBalancetree_R_L_rotate:�ȵ���������Ȼ��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/
LBtree* BIBalancetree_R_L_rotate(LBtree* root);

/*
	BIBalancetree_Altree:ÿ�����ĸ߶�
	@root�����ڵ�
	����ֵ��
			���ĸ߶�
*/
int BIBalancetree_Altree(LBtree* root);










#endif // !__BIBALANCETREE_H__

