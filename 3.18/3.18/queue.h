#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//利用单链表来实现队列
typedef int QData;
typedef struct QNode
{
	struct QNode* next;
	int data;
}QNode;
//因为队列的数据结构操作需要找尾，这就需要传多个参数了，很麻烦，所以我们再分装个结构体将多个数据变成一个
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
void QueueInit(Queue *pq);//初始化队列
void QueueDestroy(Queue *pq);//销毁队列
void QueuePush(Queue*pq ,QData x);//入队，从队尾插入一个数据，尾删
void QueuePop(Queue *pq);//出队，从队头删除数据，头删
bool QueueEmpty(Queue *pq);//判断队列是否为空
int QueueSize(Queue*pq);//获得队列有效数据个数大小
QData QueueFront(Queue*pq);//获取队头数据
QData QueueBack(Queue*pq);//获取队尾数据