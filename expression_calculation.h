//
// Created by 范兴国 on 2019-10-28.
//

#ifndef DSC_EXPRESSION_CALCULATION_H
#define DSC_EXPRESSION_CALCULATION_H

#endif //DSC_EXPRESSION_CALCULATION_H


/*比较两个运算符的优先级
 *a，b中存放待比较的运算符
 *'>'表示a>b
 *'0'表示不可能出现的比较
*/

char Precede(char a, char b) {
    int i, j;
    char pre[][7] = {
            /*运算符之间的优先级制作成一张表格*/
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '<', '<', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'>', '>', '>', '>', '<', '>', '>'},
            {'<', '<', '<', '<', '<', '=', '0'},
            {'>', '>', '>', '>', '0', '>', '>'},
            {'<', '<', '<', '<', '<', '0', '='}};
    switch (a) {
        case '+':
            i = 0;
            break;
        case '-':
            i = 1;
            break;
        case '*':
            i = 2;
            break;
        case '/':
            i = 3;
            break;
        case '(':
            i = 4;
            break;
        case ')':
            i = 5;
            break;
        case '#':
            i = 6;
            break;
    }
    switch (b) {
        case '+':
            j = 0;
            break;
        case '-':
            j = 1;
            break;
        case '*':
            j = 2;
            break;
        case '/':
            j = 3;
            break;
        case '(':
            j = 4;
            break;
        case ')':
            j = 5;
            break;
        case '#':
            j = 6;
            break;
    }
    return pre[i][j];
}


// 计算弹出的两个操作数与弹出栈顶运算符的值
float Operate(float a,  float b,char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return -1;
    }
}



//判断是否为运算符,若是 返回0-6 运算符 所在行数 , 若否 返回-1

int In(char c) {
    switch (c) {
        case '+':
            return 0;
        case '-':
            return 1;
        case '*':
            return 2;
        case '/':
            return 3;
        case '(':
            return 4;
        case ')':
            return 5;
        case '#':
            return 6;
        default:
            return -1;
    }
}
