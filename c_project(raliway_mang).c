
#include <stdio.h>
#include <stdlib.h>

typedef struct Railway_Management{
    int train_no;
    int capacity;
    int arrival_time;
    int departure_time;
    char from[15];
    char to[15];
    struct Railway_Management *next;
}node;
node*head=NULL;

void create(node**head){
    node*new,*p;
    int n;//no of train data to enter
    printf("enter the no of train data to enter\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    new=(node*)malloc(sizeof(node));
    printf("enter the train no\n");
    scanf("%d",&(new->train_no));
    printf("enter the train capacity\n");
    scanf("%d",&(new->capacity));
    printf("enter the arrival time of the train\n");
    scanf("%d",&(new->arrival_time)); 
    printf("enter the departure  time of the train\n");
    scanf("%d",&(new->departure_time));
    printf("enter the place of the train will start\n");
    scanf("%s",(new->from));
    printf("enter the last station of train\n");
    scanf("%s",(new->to)); 
    new->next=NULL;
    
    if(*head==NULL){
        *head=new;
    }
    else{
        p=*head;
        while(p->next!=NULL){
            p=p->next;
        }
        p->next=new;
    }
    
}
}
void insert(node**head){
    node*temp,*p,*q;
    int n;
    temp=(node*)malloc(sizeof(node));
    printf("enter the train no\n");
    scanf("%d",&(temp->train_no));
    printf("enter the train capacity\n");
    scanf("%d",&(temp->capacity));
    printf("enter the arrival time of the train\n");
    scanf("%d",&(temp->arrival_time)); 
    printf("enter the departure  time of the train\n");
    scanf("%d",&(temp->departure_time));
    printf("enter the place of the train will start\n");
    scanf("%s",(temp->from));
    printf("enter the last station of train\n");
    scanf("%s",(temp->to)); 
    temp->next=NULL;
    
   
    
    if(*head==NULL){
        *head=temp;
        temp->next=NULL;
    }
    else{
         printf("enter the no of train before you want to insert the new train data\n");
    scanf("%d",&n);
        p=*head;
        if(p->train_no==n){
            temp->next=p;
            *head=temp;
        }
        else {
            while((p!=NULL)&&(p->train_no!=n)){
                q=p;
                p=p->next;
            }
        if(p==NULL){
            q->next=temp;
            temp->next=NULL;
           }
        else if(p->train_no==n){
            q->next=temp;
            temp->next=p;
          }
        else{
           printf("invalid data\n");
         }
       }
    }
}

void delete(node**head){
     node*temp,*p,*q;
    int n;
    printf("enter the data of node you want to delete node\n");
    scanf("%d",&n);


    if(*head==NULL){
        printf("no data\n");
    }
    else{
        p=*head;
       
        if(p->train_no==n){
            *head=p->next;
            free(p);
        }
        else {
            while((p!=NULL)&&(p->train_no!=n)){
                q=p;
                p=p->next;
            }
        if(p==NULL){
            printf("empty linkinglist");
           }
        else if(p->train_no==n){
            q->next=p->next;
            free(p);
          }
        else{
           printf("invalid data\n");
         }
       }
    }
}

void print(node*head){
    node*p=head;
    
    if(head==NULL){
        printf("\nempty list\n");
    }
    else {
        while(p!=NULL){
        printf("Train_No=%d\n",p->train_no);
        printf("Train capacity=%d\n",p->capacity);
        printf("Train arrival time=%d\n",p->arrival_time);
        printf("Train departure time=%d\n",p->departure_time);
        printf("Train start place=%s\n",p->from);
        printf("Train last station=%s\n",p->to);
        
        p=p->next;
    }
        printf("       these are the all details of trains       \n");
        
    }
    
}

void spcprint(node*head){
    node*p=head;
     if(head==NULL){
        printf("\nempty list\n");
    }
    else {
        int t_no;
    printf("enter the train no\n");
    scanf("%d",&t_no);
        while(p!=NULL){

        if(p->train_no==t_no)
        {
        printf("Train_No=%d\n",p->train_no);
        printf("Train capacity=%d\n",p->capacity);
        printf("Train arrival time=%d\n",p->arrival_time);
        printf("Train departure time=%d\n",p->departure_time);
        printf("Train start place=%s\n",p->from);
        printf("Train last station=%s\n",p->to);
        }
        else if(p->next==NULL){
            printf("no match found\n");
        }
        p=p->next;
    }
        printf("        above is the detail according to the entry      \n");
        
    }
    
}



int main() {
        int n,b;
    node*HEAD=NULL;
while(1){
printf("\nEnter the Choice\n1->Enter train details\n2->Show details of all train\n3->Insert the data\n4->delete the data \n5->exit\n6->to get the details of specific train\n");
scanf("%d",&b);
  
  switch (b){
  case 1:
    create(&HEAD);
    break;
        
 
 case 2:
    print(HEAD);
    break;
        
 case 3:
    insert(&HEAD);
    break;
  
 case 4:
     delete(&HEAD);
     break;
 
  case 5:
         printf("Thank You");
         exit(0);
         break;
  case 6:
       spcprint(HEAD);
       break;
      
  default:
      printf("enter valid details");
      break;
       
}
}
 return 0;
}