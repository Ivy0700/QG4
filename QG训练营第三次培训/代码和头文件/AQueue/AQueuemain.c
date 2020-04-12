#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "AQueue.c"

void Print(){
	printf("*************************************\n");
	printf("*************队列设计*****************\n");
	printf("*************************************\n");
	printf("*           0 退出                    *\n");
	printf("*           1 初始化队列              *\n");
	printf("*           2 销毁队列                *\n");
	printf("*           3 队列是否满              *\n");
	printf("*           4 队列是否为空            *\n");
	printf("*           5 查看队头元素            *\n");
	printf("*           6 确定队列长度            *\n");
	printf("*           7 入队操作                *\n");
	printf("*           8 出队操作                *\n");
    printf("*           9 清空队列                *\n");
    printf("*           10 遍历                   *\n");
	printf("*************************************\n");
	}

int main(){
    AQueue A;
    Print();
	printf("请选择功能(一次一个)\n");
    int choice;
    int upperbound = 10;
    int lowerbound = 0;
    inputvalue(&choice,upperbound,lowerbound);

        
    while(choice){
        switch (choice)
        {
        case -1:
            printf("\n请选择功能(0表示退出):\n");
			inputvalue(&choice,upperbound,lowerbound);
            break;
        case 0:
            choice = 0;
			printf("已退出\n");
            choice = -1;
			break;
        case 1:
            InitAQueue(&A);
            printf("初始化成功\n");
            choice = -1;
            break;
        case 2:
            DestoryAQueue(&A);
            choice = -1;
            break;
        case 3:
            if(IsFullAQueue(&A)){
                printf("队列已满\n");
            }
            else{
                printf("队列未满\n");
            }
            choice = -1;
            break;
        case 4:
            if(IsEmptyAQueue(&A)){
                printf("队列为空\n");
            }
            else{
                printf("队列不为空\n");
            }
            choice = -1;
            break;
        case 5:
            printf("\n");
            fflush(stdin);
            void *e = NULL;
            if(GetHeadAQueue(&A,e)==1){
             printf("成功得到顶元素\n");
            }
            else{
                printf("失败\n");
            }
            choice = -1;
            break;
        case 6:
            printf("队列的长度为: %d",LengthAQueue(&A));
            choice = -1;
            break;
        case 7:
            printf("请选择要输入数据的类型:\n");
            printf("1.浮点型 2.字符型 3.整型\n");
            int type1;
            int lowerbound1 = 1;
            int upperbound1 = 3;
            
            void* data;
            inputvalue(&type1,upperbound1,lowerbound1);
            fflush(stdin);
             printf("请输入入列的数值\n");
            switch(type1){
                case 1:
                    printf("\n");
                    double temp1;
                    double *data1 = (double*)malloc(sizeof(double));
                    scanf("%lf",&temp1);
                     *data1 = temp1;
                    data = data1;
                    type = 1;
                    break;
                
                case 2:
                    printf("\n");
                    char temp2;
                    char *data2 = (char*)malloc(sizeof(char));
                    temp2 = getchar();
                    data2 = &temp2;
                    data = data2;
                    type = 2;
                    printf("%c",*(char*)data);
                    break;
                
                case 3:
                printf("\n");
                    int *data3 = (int*)malloc(sizeof(int));
                    int temp3;
                    scanf("%d",&temp3);
                    *data3 = temp3;
                    data = data3;
                    type = 3;
                    break;
            }

            if(EnAQueue(&A,data)){
                printf("入列成功\n");
            }
            else{
                printf("入列失败\n");
            }
            choice = -1;
            break;
        case 8:
            if(DeAQueue(&A)){
                printf("出队成功\n");
            }
            else{
                printf("出队失败\n");
            }
            choice = -1;
            break;
        case 9:
            ClearAQueue(&A);
            printf("清空成功\n");
            choice = -1;
            break;
        case 10:
            if(TraverseAQueue(&A, APrint))
            {
                printf("遍历成功\n");
            }
            else{
                printf("遍历失败\n");
            }
            choice = -1;
            break;
        default:
            break;
        }

    }
     printf("已退出\n");
			system("pause");
}
