#include "queue.h"
void QueueInit(Queue* pq)//��ʼ������
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)//���ٶ���
{
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QData x)//��ӣ��Ӷ�β����һ�����ݣ�βɾ
{
	assert(pq);
/*	QNode* cur = pq->head;
	*/QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc");
	}
	newnode->data=x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		//��ֵ
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		//����tail��λ��
		pq->tail = newnode;
	}
	pq->size++;

}
void QueuePop(Queue* pq)//���ӣ��Ӷ�ͷɾ�����ݣ�ͷɾ
{
	assert(pq);
	//ͷɾ֮ǰ��Ҫ�ж��������Ƿ�Ϊ��
	assert(pq->head!=NULL);
	//�ı�ͷָ���ָ��
	
	
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
     //��headtail��ָ��һ���ǣ���headָ��Ŀռ��ͷţ���tail�ͱ��Ұָ����
	//���Ի���Ҫ�������һ����㣬��Ҫ��tail��headһ���ÿ�
	if (pq->head==NULL)//ֻ��ͷɾ������ٴ���
	{
		
		pq->tail=NULL;
	}
	pq->size--;
	//��һ����һ��ʼ�Ϳ���������������һ�����֮ǰ����������һ�����������
	//if (pq->head->next == NULL)
	//{
	//	free(pq->head);
	//	pq->head = pq->tail = NULL;
	//}
	//else
	//{
	//	//ͷɾ
	//}
	//pq->size--;
}
//�����ڱ���������Դ�Ŵ�С��
//����--���ܲ���int����--�����������һ������Ĵ�Сͨ����Ҫ��������
///��Ϊ����Ҫ���ڶ�β������
  //��ͷ�����ݣ�ʹ���������Ҫ��β
  //    �����еĸ��ֹ��ܱ�����ӣ������С����
  //    ��Ҫ��ͷλ�ú�β��λ�ã�����Ϊ�˼������ٶ���һ���ṹ�彫ͷλ����βָ���װ������
  //Ҳ�����ж�����ݾ�ʹ�ýṹ���װ��������ֻҪ�����ṹ��Ϳ����ˣ�����Ҫ��������ݹ�ȥ
bool QueueEmpty(Queue* pq)//�ж϶����Ƿ�Ϊ��----��Ҫsize������
{
	assert(pq);
	return pq->size == 0;
	//return pq->head=pq->tailk=NULL;
}
int QueueSize(Queue* pq)//��ö�����Ч���ݸ�����С
{
	assert(pq);
	return pq->size;
}

QData QueueFront(Queue* pq)//��ȡ��ͷ����
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QData QueueBack(Queue* pq)//��ȡ��β����
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

//����������˳��������