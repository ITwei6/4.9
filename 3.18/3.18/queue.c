#include "queue.h"
void QueueInit(Queue* pq)//初始化队列
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueueDestroy(Queue* pq)//销毁队列
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
void QueuePush(Queue* pq, QData x)//入队，从队尾插入一个数据，尾删
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
		//赋值
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		//更新tail的位置
		pq->tail = newnode;
	}
	pq->size++;

}
void QueuePop(Queue* pq)//出队，从队头删除数据，头删
{
	assert(pq);
	//头删之前需要判断链队列是否为空
	assert(pq->head!=NULL);
	//改变头指针的指向
	
	
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
     //当headtail都指向一起是，把head指向的空间释放，那tail就变成野指针了
	//所以还需要考虑最后一个结点，需要将tail和head一起置空
	if (pq->head==NULL)//只管头删，最后再处理。
	{
		
		pq->tail=NULL;
	}
	pq->size--;
	//另一种是一开始就考虑两种情况，最后一个结点之前的情况和最后一个结点的情况。
	//if (pq->head->next == NULL)
	//{
	//	free(pq->head);
	//	pq->head = pq->tail = NULL;
	//}
	//else
	//{
	//	//头删
	//}
	//pq->size--;
}
//链表哨兵卫里面可以存放大小吗？
//不能--可能不是int类型--如果我们像求一个链表的大小通常需要遍历链表
///因为队列要求在队尾入数据
  //队头出数据，使用链表就需要找尾
  //    而队列的各种功能比如入队，计算大小，等
  //    需要传头位置和尾部位置，所以为了简化我们再定义一个结构体将头位置与尾指针分装起来，
  //也就是有多个数据就使用结构体分装起来，那只要传个结构体就可以了，不需要传多个数据过去
bool QueueEmpty(Queue* pq)//判断队列是否为空----主要size的作用
{
	assert(pq);
	return pq->size == 0;
	//return pq->head=pq->tailk=NULL;
}
int QueueSize(Queue* pq)//获得队列有效数据个数大小
{
	assert(pq);
	return pq->size;
}

QData QueueFront(Queue* pq)//获取队头数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QData QueueBack(Queue* pq)//获取队尾数据
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

//柔性数组与顺序表的区别