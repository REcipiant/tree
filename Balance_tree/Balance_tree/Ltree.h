#pragma once
#ifndef __LTREE_H__
#define __LTREE_H__
//��ʽ�ṹ������
//���������Ľ�����ɽṹ��

typedef struct LBtree
{
	//����ʲô���󣬶��ܹ���ȡ��������
	//�������Ӧ�е����ԣ��Լ�������
	//���ݣ����߶��������֮����߼��ṹ
	//�������ݵĴ洢��ʽһ�������֣�˳��洢����ʽ�洢
	//��Ŀǰ���ԣ����ж��������֮��Ĵ洢��ʽ��ع��
	//���������ִ洢�ṹ�����ڶ���ĳ���һ���ýṹ���
	//�з�װ�����ڽṹ��ĳ�Ա������������ԣ����˶��졣

	//�����Ľ����Ϊ���󣬳����������
	//1.���Ľ��洢������Ԫ�أ�������
	//2.���Ľ��ĺ��ӱ���(ָ����)

	struct LBtree* Rchild;
	struct LBtree* Lchild;

	int data;
	//ƽ�������,���ĸ߶�
	int Altree;

}LBtree;

/*
	LBitree_insert:��ʽ�������Ĳ���
	@p������Ľ��
	����ֵ��
			���ض�������root��㣨ָ�룩

*/
LBtree* LBitree_insert(LBtree* root, LBtree* p);

//�ݹ��
LBtree* LBitree_insert_sur(LBtree* root, LBtree* p);
/*
	�������ı������������򣬺������
	LBitree_ahead:������������������ȸ�������
	@root�������
	����ֵ
		��

*/
//�ݹ��
void LBitree_ahead(LBtree* root);
/*
	LBitree_mid:�������
	@root�������
	����ֵ
		��

*/
void LBitree_mid(LBtree* root);
/*
	LBitree_final:�������
	@root�������
	����ֵ
		��

*/
void LBitree_final(LBtree* root);

/*
	LBitree_level:��α���
	@root�������
	����ֵ
		��

*/

void LBitree_level(LBtree* root);
/*
	LBitree_high:��������ĸ߶�
	@root���������ĸ�
	����ֵ��
			�������ĸ߶�
*/

int LBitree_high(LBtree* root);
/*
	LBitree_MaxNode:�����������ֵ�Ľ��
	@root�������
	����ֵ��
			���ֵ���ָ��
*/
LBtree* LBitree_MaxNode(LBtree* root);
/*
	LBitree_del:���������ɾ������
	@root�������
	@aim��ɾ����Ŀ����
	����ֵ��
			rootָ��
*/
LBtree* LBitree_del(LBtree* root, int aim);



#endif 
