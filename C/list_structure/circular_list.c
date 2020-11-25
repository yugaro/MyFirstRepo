#include<stdio.h>
#include<stdlib.h>

typedef struct list{
    int num;
    struct list *next;
}LIST;

int num_data(){
    int flag=1,num;
    while(flag==1){
        flag=0;
        printf("How many people:");scanf("%d", &num);
        if(num<=0){
            printf("Input number bigger than '0'.\n");
            flag=0;
        }
    }
    return num;
}
int k_data(){
    int k,flag=1;
    while (flag == 1){
        flag = 0;
        printf("What number:");scanf("%d", &k);
        if (k<= 0){
            printf("Input number bigger than '0'.\n");
            flag = 1;
        }
    }
    return k;
}

LIST* m_data(LIST *list,int num){
    int i;
    LIST *item,*head;
    for(i=0;i<num;i++){
        if((item=(LIST *)malloc(sizeof(LIST)))==NULL)printf("Cannot malloc.");
        item->num=i+1;

        item->next=NULL;
        if(i==0){
            list=item;
            head=item;
        }else{
            list->next=item;
            list=list->next;
        }
    }
    list->next=head;
    list=list->next;
    return list;
}

void output_data1(LIST *list,int num){
    int i=0;
    LIST *temp;
    while(i!=num){
        printf("Deleted %d:%d\n", i + 1, list->num);
        temp=list->next;
        free(list);
        list=temp;
        i++;
    }
    printf("All deleted.\n");
}

void output_data2(LIST *list,int k,int num){
    int i,j;
    LIST *temp;
    for(i=0;i<num;i++){
        j=0;
        if(i==(num-1)){
            printf("Deleted %d:%d\n", i + 1, list->num);
            free(list);
            printf("All deleted.\n");
            return ;
        }
        while(j!=(k-2)){
            list=list->next;
            j++;
        }
        temp=list->next->next;
        printf("Deleted %d:%d\n",i+1,list->next->num);
        free(list->next);
        list->next=temp;
        list=list->next;
    }
}

int main(void){
    int num,k;
    LIST *people=NULL;
    num=num_data();
    k=k_data();
    people=m_data(people,num);
    if(k==1) output_data1(people,num);
    else output_data2(people,k,num);
    return 0;
}
