#include <stdio.h>
#define MAXSIZE 100

typedef  int  DataType;
typedef  struct
{   DataType  data[MAXSIZE];
    int  top;
}SeqStack;
SeqStack  *initSeqStack(){
    SeqStack s,*q;
    q=&s;
    q->top=-1;
    return q;
}
int  empty (SeqStack *s){
    if(s->top==-1)return 1;
    else return 0;
}
void  push (SeqStack *s, DataType  x){
    s->data[++s->top]=x;
}
void  pop (SeqStack *s){
    s->top--;
}
DataType  top (SeqStack *s){
    return s->data[s->top];
}
void zhuanhuan (int a,int b,SeqStack q){
    SeqStack *s =&q;
    do{
        push(s,a%b);
        a=a/b;
    }while(a!=0);
    char ch[6]={'A','B','C','D','E','F'};
    for(;!empty(s);pop(s)){

        if(top(s)>9)printf("%c",ch[top(s)-10]);
        else printf("%d", top(s));
    }

}
int main (){
    int a,b;
    SeqStack *s=initSeqStack();
    printf("请输入数字和转换为几进制\n");
    scanf("%d %d",&a,&b);
    zhuanhuan(a,b,*s);
}