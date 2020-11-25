#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 256

typedef struct data{
    char str[N];
    struct data *next;
}DATA;

typedef struct list{
    DATA *data1;
    DATA *data2;
}LIST;

void init(LIST *list){
    list->data1=NULL;
    list->data2=NULL;
}

void a_del(LIST *list){
    DATA *temp1,*temp2;
    while(list->data1!=NULL){
        temp1=list->data1;
        free(list->data1);
        list->data1=temp1->next;
    }
    if (list->data1 == NULL)printf("List1 is all deleted.\n");
    while (list->data2 != NULL){
        temp2 = list->data2;
        free(list->data2);
        list->data2 = temp2->next;
    }
    if (list->data2 == NULL)printf("List2 is all deleted.\n");
}

int quit(char *str){
    int flag = 1;
    if (strcmp(str, "quit") == 0){
        printf("You input 'quit'.\n");
        flag = 0;
    }
    return flag;
}

int w_list(){
    int l_num,flag=1;
    while (flag == 1){
        flag = 0;
        printf("List1→1,List2→2:");scanf("%d", &l_num);
        if (l_num != 1 && l_num != 2){
            printf("Input '1' or '2'.\n");
            flag = 1;
        }
    }
    return l_num;
}

int s_count(DATA *data){
    DATA *head;
    int s_num=0;
    head = data;
    while (data != NULL){
        data = data->next;
        s_num++;
    }
    data = head;
    return s_num;
}

int w_insert(int s_num){
    int w_num,flag=1;
    while (flag == 1){
        flag = 0;
        printf("where:");scanf("%d", &w_num);
        if (w_num < 0 || w_num >= (s_num + 1)){
            flag = 1;
            printf("Out of size.\n");
        }
    }
    return w_num;
}

void insert(LIST *list){
    DATA *item,*data,*head,*d_temp;
    char str[N];
    int l_num,s_num, w_num,i=0;
    printf("Input data:");scanf("%s", str);
    if ((item = (DATA *)malloc(sizeof(DATA))) == NULL)printf("Cannot malloc.\n");
    strcpy(item->str,str);
    item->next=NULL;
    l_num=w_list();
    if (l_num == 1)data = list->data1;
    if (l_num == 2)data = list->data2;
    s_num = s_count(data);
    w_num = w_insert(s_num);
    if (w_num == 0){
        if (s_num != 0){
            head = data;
            data = item;
            item->next = head;
        }else data = item;
    }else{
        head = data;
        while (i != w_num - 1){
            data = data->next;
            i++;
        }
        d_temp = data->next;
        data->next = item;
        item->next = d_temp;
        data = head;
    }
    if (l_num == 1)list->data1 = data;
    if (l_num == 2)list->data2 = data;
}

int w_delete(int s_num){
    int w_num,flag=1;
    while (flag == 1){
        flag = 0;
        printf("where:");scanf("%d", &w_num);
        if (w_num < 0 || w_num >= s_num){
            flag = 1;
            printf("Out of range.\n");
        }
    }
    return w_num;
}

void delete (LIST *list){
    int l_num,s_num,w_num,i=0;
    DATA *data,*temp,*head;
    l_num = w_list();
    if (l_num == 1)data = list->data1;
    if (l_num == 2)data = list->data2;
    if(data==NULL){
        printf("No data.\n");
        return ;
    }
    s_num = s_count(data);
    w_num = w_delete(s_num);
    if(w_num==0){
        temp=data->next;
        free(data);
        data=temp;
    }else{
        head=data;
        while(i!=(w_num-1)){
            data=data->next;
            i++;
        }
        temp=data->next->next;
        free(data->next);
        data->next=temp;
        data=head;
    }
    if (l_num == 1)list->data1 = data;
    if (l_num == 2)list->data2 = data;
}

int r_div(){
    int r_num, flag = 1;
    while (flag == 1){
        flag = 0;
        printf("Which part ramain.Formar→1,Lattar→2:");scanf("%d", &r_num);
        if (r_num != 1 && r_num != 2){
            printf("Input '1' or '2'.\n");
            flag = 1;
        }
    }
    return r_num;
}

int w_div(int s_num){
    int w_num, flag = 1;
    while (flag == 1)
    {
        flag = 0;
        printf("where:");
        scanf("%d", &w_num);
        if (w_num < 0 || w_num >= (s_num + 1))
        {
            flag = 1;
            printf("Out of size.\n");
        }
    }
    return w_num;
}

void divide(LIST *list){
    DATA *data,*head,*f_data,*l_data,*r_data,*d_data;
    int l_num,s_num,w_num,r_num,i=0;
    l_num = w_list();
    if (l_num == 1)data = list->data1;
    if (l_num == 2)data = list->data2;
    if (data == NULL){
        printf("No data.\n");
        return;
    }
    s_num = s_count(data);
    w_num = w_div(s_num);
    r_num = r_div();
    if(w_num==0){
        f_data = NULL;
        l_data=data;
    }else{
        head=data;
        while(i!=(w_num-1)){
            data=data->next;
            i++;
        }
        l_data=data->next;
        data->next=NULL;
        f_data=head;
    }
    printf("r_num:%d\n", r_num);
    if(r_num==1){
        r_data=f_data;
        d_data=l_data;
    }
    if(r_num==2){
        r_data = l_data;
        d_data = f_data;
    }
    if(d_data==NULL)printf("Cannot divide.\n");
    printf("You divide these data:");
    while (d_data != NULL){
        printf("%s,", d_data->str);
        free(d_data);
        d_data = d_data->next;
    }
    if (d_data == NULL)printf("\nDivided data is all deleted.\n");
    if (l_num == 1)list->data1 = r_data;
    if (l_num == 2)list->data2 = r_data;


}

int c_connect(){
    int choice,flag=1;
    while(flag==1){
        flag=0;
        printf("List1-List2→1 or List2-List1→2:");scanf("%d", &choice);
        if(choice!=1&&choice!=2){
            printf("Input '1' or '2'.\n");
            flag=1;
        }
    }
    return choice;
}

void connect(LIST *list){
    DATA *f_data,*l_data,*head;
    int choice;
    choice=c_connect();
    if(choice==1){
        f_data=list->data1;
        l_data=list->data2;
    }
    if(choice==2){
        f_data=list->data2;
        l_data=list->data1;
    }
    if(f_data==NULL){
        f_data=l_data;
        l_data=NULL;
    }else{
        head = f_data;
        while (f_data->next != NULL)f_data = f_data->next;
        f_data->next = l_data;
        l_data = NULL;
        f_data = head;
    }
    if (choice == 1){
        list->data1=f_data;
        list->data2=l_data;
    }
    if (choice == 2){
        list->data2=f_data;
        list->data1=l_data;
    }
}

void display(LIST *list){
    printf("------------------------------------------------------------\n");
    DATA *temp1,*temp2;
    temp1=list->data1;
    temp2=list->data2;
    printf("List1:");
    if (list->data1 == NULL)printf("No data.");
    while(list->data1!=NULL){
        printf("%s,",list->data1->str);
        list->data1=list->data1->next;
    }
    printf("\n");
    printf("List2:");
    if (list->data2 == NULL)printf("No data.");
    while(list->data2!=NULL){
        printf("%s,", list->data2->str);
        list->data2 = list->data2->next;
    }
    printf("\n");
    list->data1=temp1;
    list->data2=temp2;
    printf("------------------------------------------------------------\n");
}

int main(void){
    LIST *list;
    int flag=1,choice,num,l_num,l_flag=1;
    init(list);
    while(flag==1){
        printf("insert→1,delete→2,division→3,connect→4,else→end:");scanf("%d",&choice);
        switch (choice){
            case 1:
                insert(list);
                display(list);
                break;
            case 2:
                delete(list);
                display(list);
                break;
            case 3:
                divide(list);
                display(list);
                break;
            case 4:
                connect(list);
                display(list);
                break;
            default:
                flag=0;
                break;
        }
    }
    a_del(list);
    return 0;
}
