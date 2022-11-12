#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Ltree.h"
#include "Loopqueue.h"
/*
	LBitree_insert:��ʽ�������Ĳ���
	@p������Ľ��
	����ֵ��
			���ض�������root��㣨ָ�룩
	
*/
LBtree* LBitree_insert(LBtree* root, LBtree* p)
{
	LBtree* pk = NULL;
	LBtree* father = NULL;
	if (root == NULL)
	{
		return p;//����һ�������Ϊroot���
	}
	if (p == NULL)
	{
		return root;
	}
	pk = root;
	while (pk != NULL)
	{
		//��������˳�����У�����<��<�ң�����������
		if (pk->data < p->data)//������ڵ��dataС�ڲ����㣬��Ҫ���ص����ڵ��Rchild
		{
			father = pk;
			pk = pk->Rchild;
		}
		else if (pk->data > p->data)//������ڵ��data���ڲ����㣬��Ҫ���ص����ڵ��Lchild
		{
			father = pk;
			pk = pk->Lchild;
		}
		else//���������
		{
			return root;
		}
	}
	if (father->data < p->data)
	{
		father->Rchild = p;
	}
	else//��ȣ�С��
	{
		father->Lchild = p;
	}
	return root;
}
//�ݹ��
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
	�������ı������������򣬺������
	LBitree_ahead:������������������ȸ�������
	@root�������
	����ֵ
		��
*/
//�ݹ��
void LBitree_ahead(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		printf("%d ",root->data);//��
		LBitree_ahead(root->Lchild);//��
		LBitree_ahead(root->Rchild);//��
	}
	//return;
}

/*
	LBitree_mid:�������
	@root�������
	����ֵ
		��

*/
void LBitree_mid(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		LBitree_mid(root->Lchild);//��
		printf("%d ",root->data);//��
		LBitree_mid(root->Rchild);//��
	}
	return;
}
/*
	LBitree_final:�������
	@root�������
	����ֵ
		��

*/
void LBitree_final(LBtree* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		LBitree_final(root->Lchild);//��
		LBitree_final(root->Rchild);//��
		printf("%d ",root->data);//��
	}
	return;
}
/*
	LBitree_level:��α���
	@root�������
	����ֵ
		��

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
	LBitree_high:��������ĸ߶�
	@root���������ĸ�
	����ֵ��
			�������ĸ߶�
*/

int LBitree_high(LBtree* root)
{
	//��һ
	int high = 0;
	int high1 = 0;
	if (root == NULL)
	{
		return 0;
	}
	high = LBitree_high(root->Lchild) + 1;//���������ĸ߶�
	high1 = LBitree_high(root->Rchild) + 1;//���������ĸ߶�
	return high > high1 ? high : high1;//���ֵ��Ϊ�����ĸ߶�
	/*
		//������
		//���������ֵ�ĺ�
		#define Max(a,b) ((a) > (b))?(a):(b)

		if(root == NULL)
		{
			return 0;
		}
		//�������������������ֵ�ټ���+1��root��㣩������һ���
		return Max(LBitree_high(root->Lchild),LBitree_high(root->Rchild)) + 1;
	*/
}
/*
	LBitree_MaxNode:�����������ֵ�Ľ��
	@root�������
	����ֵ��
			���ֵ���ָ��
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
	LBitree_del:���������ɾ������
	@root�������
	@aim��ɾ����Ŀ����
	����ֵ��
			�����ָ��
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
	//ɾ��������1.���ҵ�ɾ���Ľ�㣻2.��ɾ��
	while (pk != NULL)//���������ҵ�ɾ�����
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
	//ɾ������
	if (pk == NULL)//û�ҵ�
	{
		return root;
	}
	else//�ҵ���

	{
lable:
		if (pk->Rchild == NULL && pk->Lchild == NULL)//�ն˽�㣨Ҷ�ӽ�㣩�����Һ���
		{
			if (pk == root)//����һ�������
			{
				free(pk);
				return NULL;
			}
			else
			{
				if (Fa->Lchild == pk)//�Ǹ��ڵ������
				{
					
					Fa->Lchild = NULL;
				}
				if (Fa->Rchild == pk)//�Ǹ��ڵ���Һ���
				{
					Fa->Rchild = NULL;
				}
				free(pk);
			}
			return root;
		}
		else if (pk->Lchild != NULL && pk->Rchild == NULL)//ɾ���Ľ�����м䣬��ֻ������
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
		else if (pk->Rchild != NULL && pk->Lchild == NULL)//ɾ���Ľ�����м䣬��ֻ���Һ���
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
		else//ɾ���Ľ������Һ�����������
		{
			//��һ���ҵ�Ҫɾ�������������е����ֵ�滻��ɾ������ֵ��Ȼ��ɾ�������������ֵ���
			//�������ҵ�Ҫɾ�������������е���Сֵ�滻��ɾ������ֵ��Ȼ��ɾ������������Сֵ���

			//���²��÷�һ
				max = pk;
				Fa = pk;
				pk = pk->Lchild;
				while (pk->Rchild != NULL)//�ҵ��滻��Ľ��
				{
					Fa = pk;
					pk = pk->Rchild;
				}
				max->data = pk->data;
			//ɾ��
			goto lable;
		}

	}

}