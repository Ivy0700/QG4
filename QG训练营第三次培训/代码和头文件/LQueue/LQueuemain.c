#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"
#include "LQueue.c"

void Print(){
	printf("***************************************\n");
	printf("************链队列设计******************\n");
	printf("***************************************\n");
	printf("*           0 退出                    *\n");
	printf("*           1 初始化队列              *\n");
	printf("*           2 销毁队列                *\n");
	printf("*           3 队列是否空              *\n");
	printf("*           4 查看队头元素            *\n");
	printf("*           5 确定队列长度            *\n");
	printf("*           6 入队操作                *\n");
	printf("*           7 出队操作                *\n");
    printf("*           8 清空队列                *\n");
    printf("*           9 遍历                    *\n");
	printf("***************************************\n");
	}

int main(){
    LQueue A;
    (&A)->length = 0;
    Print();
	printf("请选择功能(一次一个)\n");
    int choice;
    int upperbound = 9;
    int lowerbound = 0;
     fflush(stdin);
    inputvalue(&choice,upperbound,lowerbound);


    while(choice){
        switch (choice)
        {
        case -1:
            printf("\n请选择功能(0表示退出):\n");
            scanf("%*[^\n]");
			inputvalue(&choice,upperbound,lowerbound);
            break;
        case 0:
            choice = 0;
			printf("已退出\n");
			break;
        case 1:
            InitLQueue(&A);
            printf("初始化成功\n");
            choice = -1;
            break;
        case 2:
            DestoryLQueue(&A);
            choice = -1;
            break;
        case 3:
            if(IsEmptyLQueue(&A)){
                printf("队列为空\n");
            }
            else{
                printf("队列不为空\n");
            }
            choice = -1;
            break;
        case 4:
            printf("\n");
            void *e = NULL;
            if(GetHeadLQueue(&A,e)!=1){
                printf("失败\n");
            }
            choice = -1;
            break;
        case 5:
            printf("队列的长度为: %d",LengthLQueue(&A));
            choice = -1;
            break;
        case 6:
            printf("请选择要输入数据的类型:\n");
            printf("1.浮点型 2.字符型 3.整型\n");
            int type1;
            int lowerbound1 = 1;
            int upperbound1 = 3;
            void* data;
            int judge = 1;
           scanf("%*[^\n]");
            inputvalue(&type1,upperbound1,lowerbound1);
             printf("请输入入列的数值\n");
            //   fflush(stdin);
            switch(type1){
                case 1:
                //scanf("%*[^\n]");
                    printf("\n");
                    double temp1;
                    double *data1 = (double*)malloc(sizeof(double));
                    scanf("%lf",&temp1);
                    if(temp1<0.01){
			judge = 0;
			printf("error\n");
                    }else{
                     *data1 = temp1;
                    data = data1;
                    type = 1;
                    }
                    break;
                case 2:
                  //scanf("%*[^\n]");
                  printf("\n");
                    char temp2;
                    char *data2 = (char*)malloc(sizeof(char));
                    printf("hello\n");
                    getchar();
                    scanf("%c",&temp2);
                    data2 = &temp2;
                    data = data2;
                    type = 2;
                    printf("%c",*(char*)data);
                    break;

                case 3:
               // scanf("%*[^\n]");
                printf("\n");
                    int *data3 = (int*)malloc(sizeof(int));
                    int temp3;
                    scanf("%d",&temp3);
                    if(temp3>1000){
			printf("错误\n");
			break;
                    }
                    *data3 = temp3;
                    data = data3;
                    type = 3;
                    break;
            }

            if(EnLQueue(&A,data) && judge ){
                printf("入列成功\n");
            }
            else{
                printf("入列失败\n");
            }
            choice = -1;
            break;
        case 7:
            if(DeLQueue(&A)){
                printf("出队成功\n");
            }
            else{
                printf("出队失败\n");
            }
            choice = -1;
            break;
        case 8:
            ClearLQueue(&A);
            printf("清空成功\n");
            choice = -1;
            break;
        case 9:
            if(TraverseLQueue(&A, LPrint))
            {
                printf("\n遍历成功\n");
            }
            else{
                printf("遍历失败\n");
            }
            choice = -1;
            break;
        default:
        printf("崩了\n");
            break;
        }

    }
     printf("已退出\n");
		system("pause");
}
