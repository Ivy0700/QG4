#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LQueue.h"

// typedef struct node
// {
//     void *data;                   //数据域指针
//     struct node *next;            //指向当前结点的下一结点
// } Node;

// typedef struct Lqueue
// {
//     Node *front;                   //队头
//     Node *rear;                    //队尾
//     size_t length;            //队列长度
// } LQueue;

// typedef enum
// {
//     FALSE=0, TRUE=1
// } Status;
// char type;					
// char datatype[30];

void inputvalue(int *element,int upperbound,int lowerbound){
		int number;
		scanf("%d",&number);
		while(number < lowerbound||number > upperbound){
			fflush(stdin);	//避免输入char型导致无限循环
			printf("ERROR,请输入正确的数字\n");
			scanf("%d",&number);
		}
		*element = number;
		printf("输入成功\n");
	}
void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
    Q->length = 0;
	return;
}

void DestoryLQueue(LQueue *Q){
    if(IsEmptyLQueue(Q)){
        printf("队列为空，无需销毁\n");
        return;
    }
    ClearLQueue(Q);
    free(Q->front);
    free(Q->rear);
    printf("销毁成功\n");
}

Status IsEmptyLQueue(LQueue *Q){
    if(Q->rear == Q->front){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

Status GetHeadLQueue(LQueue *Q, void *e){
    if(IsEmptyLQueue(Q)){
        return FALSE;
    }
    // memcpy(e,Q->front->next->data,sizeof(Q->front->next->data));
    e = Q->front->next->data;
    printf("成功得到顶元素为:  ");
    //printf("%d\n",datatype[head]);
    //printf("%c",*(char*)e);
    LPrint(e, datatype[head]);
    return TRUE;
}


int LengthLQueue(LQueue *Q){
    return Q->length;
}


Status EnLQueue(LQueue *Q, void *data){
    Node* p = (Node*)malloc(sizeof(Node));
    if(NULL == p){
        return FALSE;
    }
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
    Q->length ++;
    end = (end + 1) % MAXQUEUE;
    datatype[end] = type;
    //printf("%c",*(char*)data);
    return TRUE;
}

Status DeLQueue(LQueue *Q){
    if(IsEmptyLQueue(Q)){
        return FALSE;
    }
    Node* p = (Node*)malloc(sizeof(Node));
    p = Q->front->next;
    Q->front->next = p->next;
    if(p->next == NULL){
        Q->rear = Q->front;
    }
    free(p);
    Q->length --;
    head = (head + 1 ) % MAXQUEUE;
    return TRUE;
}

void ClearLQueue(LQueue *Q){
    if(IsEmptyLQueue(Q)){
        printf("队列已为空\n");
        return;
    }
    Node *temp1,*temp2;
    Q->rear = Q->front;
    temp1 = Q->front->next;
    head = end = 0;
    while(temp1!=NULL){
        temp2 = temp1;
        temp1 = temp1->next;
        free(temp2);
    }
    free(temp1);
    Q->length = 0;

}

Status TraverseLQueue(LQueue *Q, void (*foo)(void *q,int type)){
    if(IsEmptyLQueue(Q)){
        return FALSE;
    }
    Node* temp = Q->front->next;
    int i = head;
    while(temp!=NULL){
        foo(temp->data,datatype[i]);
        temp = temp->next;
        i++;
    }
    return TRUE;
}

void LPrint(void *q,int type) {

	if (type == 1)
		printf("%lf  ", *(double *)q);
	if (type == 2)
		printf("%c  ", *(char *)q);
	if (type == 3)
		printf("%d  ", *(int *)q);

}