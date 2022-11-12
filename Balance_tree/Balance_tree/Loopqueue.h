#pragma once
#ifndef __LOOPQUEUE_H__
#define __LOOPQUEUE_H__

typedef void* Elemtype;
//ѭ�����е�ʵ�֣�˳��洢
typedef struct Lqueue
{
	Elemtype* data;//˳��洢��ָ��һ�������Ŀռ�

	int maxlen;//���������ռ�Ĵ�С������ֵ��Ԫ�ظ���������malloc���õ�

	int rear;//��β��ʶ�����ڼ���������Ԫ�أ�����Ԫ�ز��������
	int front;//���ױ�ʶ�����ڳ����У���ɾ�������е�Ԫ��
	int avail;//���ÿ�λ�������ж϶����ǿն��л���������

}Lqueue;

/*
	LQ_Init:��ʼ��һ�����еĽṹ��
	@maxlen:��Ҫ���ٵĿռ��С
	����ֵ��
			���нṹ��ָ��
*/
Lqueue* LQ_Init(int maxlen);

/*
	LQ_Destroy�����ٶ���
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			0���ɹ�
*/
int LQ_Destroy(Lqueue* LQ);

/*
	LQ_Clear:��ն���Ԫ��
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			0���ɹ�
*/
int LQ_Clear(Lqueue* LQ);

/*
	LQ_isempty:�ж϶����Ƿ�Ϊ��
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
		-1��ʧ��
		0��empty
		1:Not empty
*/
int LQ_isempty(Lqueue* LQ);

/*
	LQ_len:���г���
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			���������г���
*/
int LQ_len(Lqueue* LQ);
/*
	LQ_input:���
	@LQ��ָ����еĽṹ��ָ��
	@Data:���Ԫ��
	����ֵ��
		��
*/
int LQ_input(Lqueue* LQ, Elemtype Data);
/*
	LQ_out:����
	@LQ��ָ����еĽṹ��ָ��
	@p�������������
	����ֵ��
		��
*/
int LQ_out(Lqueue* LQ, Elemtype* p);






















#endif