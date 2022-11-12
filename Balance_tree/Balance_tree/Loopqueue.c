#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "Loopqueue.h"

/*
	LQ_Init:��ʼ��һ�����еĽṹ��
	@maxlen:��Ҫ���ٵĿռ��С
	����ֵ��
			���нṹ��ָ��
*/
Lqueue* LQ_Init(int maxlen)
{
	Lqueue* LQ = malloc(sizeof(*LQ));
	if (LQ == NULL)
	{
		return NULL;
	}
	LQ->data = malloc(sizeof(Elemtype) * maxlen);
	if (LQ->data == NULL)
	{
		perror("Init>>>LQ->data False");
		exit(1);
	}
	LQ->avail = maxlen;
	LQ->front = 0;
	LQ->rear = 0;
	LQ->maxlen = maxlen;
	return LQ;
}

/*
	LQ_Destroy�����ٶ���
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			0���ɹ�
*/
int LQ_Destroy(Lqueue* LQ)
{
	if (LQ == NULL)
	{
		return -1;
	}
	LQ->avail = 0;
	LQ->front = 0;
	LQ->rear = 0;
	free(LQ->data);
	free(LQ);
	return 0;
}
/*
	LQ_Clear:��ն���Ԫ��
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			0���ɹ�
*/
int LQ_Clear(Lqueue* LQ)
{
	if (LQ == NULL)
	{
		return -1;
	}
	LQ->front = 0;
	LQ->rear = 0;
	LQ->avail = 0;
	return 0;
}
/*
	LQ_isempty:�ж϶����Ƿ�Ϊ��
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
		-1��ʧ��
		0��empty
		1:Not empty
*/
int LQ_isempty(Lqueue* LQ)
{
	if (LQ == NULL)
	{
		return -1;
	}
	if (LQ->avail == LQ->maxlen)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
/*
	LQ_len:���г���
	@LQ��ָ����еĽṹ��ָ��
	����ֵ��
			-1��ʧ��
			���������г���
*/
int LQ_len(Lqueue* LQ)
{
	if (LQ == NULL)
	{
		return -1;
	}
	
	return (LQ->maxlen - LQ->avail);
}

/*
	LQ_input:���
	@LQ��ָ����еĽṹ��ָ��
	@Data:���Ԫ��
	����ֵ��
		-1: ��������
		0:�ɹ�

*/
int LQ_input(Lqueue* LQ, Elemtype Data)
{

	if (LQ == NULL || LQ->avail == 0)
	{
		//printf("Full or Error\n");
		return -1;
	}
	LQ->data[LQ->rear] = Data;
	LQ->rear++;
	LQ->rear = LQ->rear % LQ->maxlen;
	LQ->avail--;
	return 0;
}

/*
	LQ_out:����
	@LQ��ָ����еĽṹ��ָ��
	@p�������������
	����ֵ��
		-1: �����ջ�Ѿ�Ϊ��
		0:�ɹ�
*/
int LQ_out(Lqueue* LQ, Elemtype* p)
{
	if (LQ == NULL || LQ->avail == LQ->maxlen)
	{
		//printf("%d ", *p);
		//printf("Empty or Error\n");
		return -1;
	}
	*p = LQ->data[LQ->front];
	LQ->front++;
	LQ->front = LQ->front % LQ->maxlen;
	LQ->avail++;
	//����
	//printf("%d ", *(int*)p);

	return 0;
}



