#include <stdio.h>
#include <mm_malloc.h>

#define SIZE 100
#define MAX 1000

typedef struct _BinNode BinNode;
struct _BinNode{
    char ch;
    BinNode * left;
    BinNode * right;
};

// 存储节点的 栈实现
typedef struct seqstack{
    BinNode* data[SIZE];
    int tag[SIZE];   //为后续遍历准备的
    int top;     //top为数组的下标
}Seqstack;

void push(Seqstack *s,BinNode* t){

    if(s->top == SIZE){
        printf("the stack is full\n");
    }else{
        s->top++;
        s->data[s->top]=t;
    }
}
BinNode* pop(Seqstack *s){
    if(s->top == -1){
        return NULL;
    }else{
        s->top--;
        return s->data[s->top+1];
    }
}

typedef struct Seqqueue{
    BinNode* data[MAX];
    int front;
    int rear;
}Seqqueue;


void enter(Seqqueue *seqqueue,BinNode * binNode){
    if(seqqueue->rear == MAX){
        printf("the queue is full!\n");
    }else{
        seqqueue->data[seqqueue->rear++] = binNode;
        seqqueue->rear++;
    }
}

BinNode* del(Seqqueue *seqqueue){
    if(seqqueue->front == seqqueue->rear){
        return NULL;
    }else{
        seqqueue->front++;
        return seqqueue->data[seqqueue->front-1];
    }
}




// 前序遍历 创建二叉树
void CreateNode(BinNode ** binNode){
    char ch;
    scanf("%c",&ch);
    if(ch=='#'){
        *binNode=NULL;
    }
    else{
        *binNode=(BinNode*)malloc(sizeof(BinNode));
        (**binNode).ch=ch;
        CreateNode(&(*binNode)->left);
        CreateNode(&(*binNode)->right);
    }
}


// 二叉树 前序 中序 后序 层次 遍历递归实现
void PreShow(BinNode *binNode){
    if(!binNode){
        return;
    }
    else{
        printf("%c",binNode->ch);
        PreShow(binNode->left);
        PreShow(binNode->right);
    }
}
void MidShow(BinNode *binNode){
    if(!binNode){
        return;
    }
    else{
        MidShow(binNode->left);
        printf("%c",binNode->ch);
        MidShow(binNode->right);
    }
}
void BackShow(BinNode *binNode){
    if(!binNode){
        return;
    }
    else{
        BackShow(binNode->left);
        BackShow(binNode->right);
        printf("%c",binNode->ch);
    }
}
void PeerShow(BinNode * binNode){
    //递归结束标志
    if(binNode==NULL){
        printf("the tree is empty");
        return;
    }
    else{
        printf("%c",binNode->ch);
        if(binNode->left){
            PeerShow(binNode->left);
        }
        if(binNode->right){
            PeerShow(binNode->right);
        }
    }
}
// 二叉树 前序 中序 后序 层次 遍历 非递归实现
void preShow(BinNode * binNode){
    Seqstack seqstack;
    seqstack.top=-1;
    if(binNode==NULL){
        printf("该树为空\n");
    }
    else{
        while (binNode||seqstack.top!=-1){
            while (binNode){
                printf("%c",binNode->ch);
                push(&seqstack,binNode);
                binNode=binNode->left;
            }
            binNode=pop(&seqstack);
            binNode=binNode->right;
        }
    }
}
void midShow(BinNode * binNode){
    Seqstack seqstack;
    seqstack.top=-1;
    if(binNode==NULL){
        printf("the tree is empty!");
    }
    else{
        while (binNode||seqstack.top!=-1){
            while (binNode){
                push(&seqstack,binNode);
                binNode=binNode->left;
            }
            binNode=pop(&seqstack);
            printf("%c",binNode->ch);
            binNode=binNode->right;
        }
    }
}
void backShow(BinNode* binNode){
    Seqstack seqstack;
    seqstack.top=-1;
    if(binNode==NULL){
        printf("the tree is empty");
    }
    else{
        while (binNode||seqstack.top!=-1){
            //走到底
            while (binNode){
                push(&seqstack,binNode);
                seqstack.tag[seqstack.top]=1; //表示第一次来
                binNode=binNode->left;
            }
            //第一次来的时候,同层向右
            if(seqstack.tag[seqstack.top]==1){
                //同层向右
                binNode=seqstack.data[seqstack.top];//上层节点
                binNode=binNode->right;//上层节点 右孩子节点

                seqstack.tag[seqstack.top]=2;//表示第二次来
            }
            else{//第二次来的时候,说明下面的已经都走完了
                while (seqstack.tag[seqstack.top]==2){//这里走完连续走完两次的 节点不止有一个
                    binNode=pop(&seqstack);
                    printf("%c",binNode->ch);
                }
                binNode=NULL;  //这样写,为以后出栈作准备
            }

        }
    }
}


int main(){

    BinNode * binNode;


    // 531##4##86#7##9##

    printf("请输入二叉树前序遍历结果:");
    CreateNode(&binNode);
//遍历的递归实现
//    printf("前序遍历结果:");
//    PreShow(binNode);
//    printf("\n中序遍历结果:");
//    MidShow(binNode);
//    printf("\n后序遍历结果:");
//    BackShow(binNode);
    printf("\n层次遍历:");
    PeerShow(binNode);

//非递归遍历实现
//    printf("先序遍历:");
//    preShow(binNode);
//    printf("\n中序遍历:");
//    midShow(binNode);
//    printf("\n后序遍历:");
//    backShow(binNode);







    return 0;
}
