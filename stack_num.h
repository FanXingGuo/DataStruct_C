//
// Created by 范兴国 on 2019-10-28.
//

#include <stdlib.h>
#ifndef DSC_STACK_NUM_H
#define DSC_STACK_NUM_H

#endif //DSC_STACK_NUM_H

#define SN 20
#define DataType float

typedef struct{
    DataType data[SN];
    int top;
}Stack_float;


void initStack_float(Stack_float *ST){
    ST->top=-1;
}

void Push_float(Stack_float *ST,DataType x){
    if(ST->top>=SN-1){
        printf("OverFlow");
    }
    else{
        ST->data[++ST->top]=x;
    }
}

void Pop_num(Stack_float *ST,DataType *x){
    if(ST->top==-1){
        printf("UnderFlow");
    }
    else{
        *x=ST->data[ST->top--];
    }
}
DataType Top_float(Stack_float *ST){
    if(ST->top==-1){
        printf("UnderFlow");
        exit(0);
    }
    else{
        return ST->data[ST->top];
    }
}
int Sempty_float(Stack_float* St){
    if(St->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}