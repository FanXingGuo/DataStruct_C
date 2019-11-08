//
// Created by 范兴国 on 2019-10-28.
//

#ifndef DSC_STACK_CHAR_H
#define DSC_STACK_CHAR_H

#endif //DSC_STACK_CHAR_H



#define SN 20
#define DataType char

typedef struct{
    DataType data[SN];
    int top;
}Stack_char;


void initStack_char(Stack_char *ST){
    ST->top=-1;
}

void Push_char(Stack_char *ST,DataType x){
    if(ST->top>=SN-1){
        printf("OverFlow");
    }
    else{
        ST->data[++ST->top]=x;
    }
}

void Pop_char(Stack_char *ST,DataType *x){
    if(ST->top==-1){
        printf("UnderFlow");
    }
    else{
        *x=ST->data[ST->top--];
    }
}
DataType Top_char(Stack_char *ST){
    if(ST->top==-1){
        printf("UnderFlow");
        return NULL;
    }
    else{
        return ST->data[ST->top];
    }
}
int Sempty_char(Stack_char* St){
    if(St->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
