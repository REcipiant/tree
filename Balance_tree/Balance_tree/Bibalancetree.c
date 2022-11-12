#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include "Bibalancetree.h"
#include "Ltree.h"
#define Max( a , b )	((a) > (b)? (a) : (b))
//********************************************************
//����ƽ�����Ľ���������һ�е�ǰ�������˳����������ȫ��ʧЧ
//��������ƽ�⴦��
/*
	��Ϊ���������
	����������߲��뵼�¶�����ʧ��
	��������������
	���������ұ߲��뵼�¶�����ʧ��
	��������������
	���������ұ߲��뵼�¶�����ʧ��
	�������ȵ���������Ȼ��������
	����������߲��뵼�¶�����ʧ��
	�������ȵ���������Ȼ��������
*/
//************************************************************
/*
	BIBalancetree_insert_sur:����ƽ�����Ĵ���
	@root:���ڵ�
	@p��������Ľ��
	����ֵ��
			���ڵ�ָ��
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

	if (root->data < p->data)//�Ҳ�
	{
		root->Rchild = BIBalancetree_insert_sur(root->Rchild, p);//�Ȳ���
		root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;//ͬʱ����ÿ�����ĸ߶�
		
		//����
		printf("1.root->Al = %d\n", root->Altree);
		//����Ƿ�ʧ��
		if (abs(BIBalancetree_Altree(root->Lchild) - BIBalancetree_Altree(root->Rchild)) > 1)//����ǰ���߶Ȳ�>1,ʧ��
		{
			
			//printf("1.root->LH = %d,root->RH = %d\n", root->Lchild->Altree, root->Rchild->Altree);
			

			if (root->Rchild->data < p->data)//�������Ҳ�
			{
				root = BIBalancetree_Lrotate(root);//��������
			}
			else if (root->Rchild->data > p->data)//���������
			{
				root = BIBalancetree_R_L_rotate(root);//��������������
			}
			
		}
		return root;
	}
	else if (root->data > p->data)//���
	{
		root->Lchild = BIBalancetree_insert_sur(root->Lchild, p);
		root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;
		printf("2.root->Al = %d\n", root->Altree);
		if (abs(BIBalancetree_Altree(root->Lchild) - BIBalancetree_Altree(root->Rchild)) > 1)//����ǰ���߶Ȳ�>1,ʧ��
		{
			//
			//printf("2.root->LH = %d,root->RH = %d\n", root->Lchild->Altree, root->Rchild->Altree);
			//

			if (root->Lchild->data > p->data)//����������߲���p���
			{
				root = BIBalancetree_Rrotate(root);//��������

			}
			else if (root->Lchild->data < p->data)//���������ұ߲���p���
			{
				root = BIBalancetree_L_R_rotate(root);//��������������
			}
		}
		return root;
	}


	//ÿ�����ӽ��������ĸ߶�
	//root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;



	return root;

}


/*
	BIBalancetree_Rrotate:��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/
LBtree* BIBalancetree_Rrotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* newroot = root->Lchild;//��ʧ��Ľ�������������������ԭ��ʧ����������ĸ��ڵ���Ϊ�����¸�
	root->Lchild = newroot->Rchild;//���¸����������ӵ��ɸ�����������
	newroot->Rchild = root;//Ȼ���ɾɸ��䵱�ĸ���������

	//���ö����������¸���ɸ��������ĸ߶��б仯��������û�б仯������߶�ԭ���¸�������߶ȣ��ɸ������
	//�����ȼ����ӽ��ĸ߶ȣ�����㸸���ĸ߶ȣ���������
	root->Altree = Max(BIBalancetree_Altree(root->Lchild), BIBalancetree_Altree(root->Rchild)) + 1;
	newroot->Altree = Max(BIBalancetree_Altree(newroot->Lchild), BIBalancetree_Altree(newroot->Rchild)) + 1;
	return newroot;
}

/*
	BIBalancetree_Lrotate:��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
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
	BIBalancetree_L_R_rotate:�ȵ���������Ȼ��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
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
	BIBalancetree_R_L_rotate:�ȵ���������Ȼ��������
	@root:�����
	����ֵ��
			�µĸ��ڵ�
*/
LBtree* BIBalancetree_R_L_rotate(LBtree* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	LBtree* pR = root->Rchild;
	root->Rchild = BIBalancetree_Rrotate(pR);//������
	return BIBalancetree_Lrotate(root);//������
}

/*
	BIBalancetree_Altree:ÿ�����ĸ߶�
	@root�����ڵ�
	����ֵ��
			���ĸ߶�
*/
int BIBalancetree_Altree(LBtree* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->Altree;
}
