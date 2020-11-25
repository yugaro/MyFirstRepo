#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256

typedef struct data{
    int num;
    struct data* next;
}DATA;

typedef struct list{
    DATA* head;
    DATA* tail;
}LIST;

void init(LIST *list){
    list->head=NULL;
    list->tail=NULL;
}

int quit(char *str){
    int flag = 1;
    if (strcmp(str, "quit") == 0){
        printf("You input 'quit'.\n");
        flag = 0;
    }
    return flag;
}

void a_del(LIST *list){
    LIST *temp;
    while(list->head!=NULL){
        temp->head=list->head;
        free(list->head);
        list->head=temp->head->next;
    }
    if (list->head == NULL)printf("all deleted\n");
}

void push(LIST *list,int num){
    DATA *item;
    item=(DATA *)malloc(sizeof(DATA));
    if(item==NULL)printf("cannot malloc\n");
    item->num=num;
    item->next=NULL;
    if((list->head==NULL)&&(list->tail==NULL)){
        list->head=item;
        list->tail=item;
    }else{
        list->tail->next=item;
        list->tail=item;
    }
}

int pop(LIST *list){
    int num;
    LIST *temp;
    DATA *d_temp;
    d_temp=list->head;
    if ((list->head == NULL) && (list->tail == NULL))return num=-1;
    if(list->head==list->tail){
        num=list->tail->num;
        free(list->tail);
        list->head=NULL;
        list->tail=NULL;
        return num;
    }
    while(list->head->next!=list->tail)list->head=list->head->next;
    num = list->tail->num;
    free(list->tail);
    list->tail=list->head;
    list->tail->next=NULL;
    list->head = d_temp;
    return num;
}

void display(LIST *list){
    DATA *d_temp;
    if(list->head==NULL)printf("No number.");
    d_temp=list->head;
    while(list->head!=NULL){
        printf("%d,",list->head->num);
        list->head=list->head->next;
    }
    list->head=d_temp;
    printf("\n");
}

int main(void){
    char s_num[N];
    int num;
    LIST *list;
    init(list);
    while(1){
        printf("push number:");scanf("%s",s_num);
        if(quit(s_num)==0)break;
        if(strcmp(s_num,".")==0){
            num=pop(list);
            if(num==-1)printf("No number.\n");
            else printf("pop number:%d\n",num);
        }else if (strcmp(s_num, "d") == 0)display(list);
        else push(list, atoi(s_num));
    }
    a_del(list);
    return 0;
}
