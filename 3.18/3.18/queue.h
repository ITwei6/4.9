#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//���õ�������ʵ�ֶ���
typedef int QData;
typedef struct QNode
{
	struct QNode* next;
	int data;
}QNode;
//��Ϊ���е����ݽṹ������Ҫ��β�������Ҫ����������ˣ����鷳�����������ٷ�װ���ṹ�彫������ݱ��һ��
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
void QueueInit(Queue *pq);//��ʼ������
void QueueDestroy(Queue *pq);//���ٶ���
void QueuePush(Queue*pq ,QData x);//��ӣ��Ӷ�β����һ�����ݣ�βɾ
void QueuePop(Queue *pq);//���ӣ��Ӷ�ͷɾ�����ݣ�ͷɾ
bool QueueEmpty(Queue *pq);//�ж϶����Ƿ�Ϊ��
int QueueSize(Queue*pq);//��ö�����Ч���ݸ�����С
QData QueueFront(Queue*pq);//��ȡ��ͷ����
QData QueueBack(Queue*pq);//��ȡ��β����