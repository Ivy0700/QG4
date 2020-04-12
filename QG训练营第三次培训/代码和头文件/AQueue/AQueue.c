#include "AQueue.h"
#include <stdio.h>
#include <stdlib.h>

// typedef struct Aqueue
// {
//     void *data[MAXQUEUE];      //数据域
//     int front;
//     int rear;
//     size_t length;        //队列长度
// } AQueue;

// typedef enum
// {
//     FALSE=0, TRUE=1
// } Status;
// char type;
// char datatype[MAXQUEUE];
//初始化队列

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
void InitAQueue(AQueue *Q){
	Q->front = -1;
	Q->rear  = -1;
    Q->length = 0;


}


//留着一个问题，要不要一开始设个Q->data = NULL; 因为有种空指针的感觉,清空完要不要呢
void DestoryAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        printf("队列为空，无需销毁\n");
        return;
    }
    Q->rear = -1;
    Q->front = -1;
    Q->length = 0;
    printf("销毁成功\n");

}
//如果直接操作行不行呢？ 因为好像的话Q->rear 没有初始化的样子
Status IsFullAQueue(AQueue *Q){
    if(Q->front == (Q->rear + 1)% MAXQUEUE){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

Status IsEmptyAQueue( AQueue *Q){
    if(Q->front == -1 && Q->rear == -1){
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}
Status GetHeadAQueue(AQueue *Q, void *e){
          if(IsEmptyAQueue(Q)){
            return FALSE;
          }
          e = Q->data[Q->front];
          APrint(e,datatype[Q->front]);
          return TRUE;
}
int LengthAQueue(AQueue *Q){
    int count = Q->length;
    return count;
}

Status EnAQueue(AQueue *Q, void *data){
    if(IsFullAQueue(Q)){
        return FALSE;
    }
    //判断是否为空
    else if(IsEmptyAQueue(Q)){
        Q->front = 0;
         Q->rear = 0;
    }
    //不为空则rear + 1
    else {
        Q->rear = (Q->rear + 1) % MAXQUEUE;
    }
        datatype[Q->rear] = type;
        Q->length ++;
        Q->data[Q->rear] = data;
    return TRUE;
}
Status DeAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        return FALSE;
    }
    else if(Q->rear == Q->front){
        Q->rear = Q->front = -1; 
    }
    else{
        Q->front = (Q->front + 1) % MAXQUEUE;
    }
        Q->length --;
        return TRUE;
}

void ClearAQueue(AQueue *Q){
    if(IsEmptyAQueue(Q)){
        return;
    }
    Q->front = -1;
    Q->rear = -1;
    Q->length = 0;
}



Status TraverseAQueue(AQueue *Q, void (*foo)(void *q,int type)) {
	if (IsEmptyAQueue(Q)){
		return FALSE;
    }
	int i = Q->front;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		foo(Q->data[i],datatype[i]);	
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;

}


void APrint(void *q,int type) {
	if (type == 1)
		printf("%lf ", *(double *)q);
	if (type == 2)
		printf("%c ", *(char *)q);
	if (type == 3)
		printf("%d ", *(int *)q);

}


