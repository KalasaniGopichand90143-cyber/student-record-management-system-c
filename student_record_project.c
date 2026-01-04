#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int id;
    char name[40];
    int marks;
    struct node *next;
};
int count=0;
struct node *head =NULL,*temp;
void load_file(){
    FILE *fp;
    int id,marks;
    char name[40];
    fp=fopen("Students.txt","r");
    if(fp==NULL){
        printf("file doesn't exist ! \n");
        return;
    }
    else{
        while(fscanf(fp,"%d %s %d",&id,name, &marks)!=EOF){
            struct node *prevoiusnode=(struct node*)malloc(sizeof(struct node));
            prevoiusnode->next=NULL;
            prevoiusnode->id=id;
            strcpy(prevoiusnode->name,name);            
            prevoiusnode->marks=marks;
            if(head==NULL){
            head=temp=prevoiusnode;
            count++;
            }
            else{
                temp->next=prevoiusnode;
                temp=prevoiusnode;
                count++;
            }

        }
    }
    
    fclose(fp);

}
void create_studentnode(){
    int n,i;
    printf("Enter how many student to be entered in record :");
    scanf("%d",&n);
    for(i=0; i<n; i++){
    struct node *studentnode=(struct node*)malloc(sizeof(struct node));
    studentnode->next=NULL;
    printf("\nEnter the student details :\n\n");
    printf("enter the student id :");
    scanf("%d",&studentnode->id);
    printf("enter the student name :");
    scanf("%s",studentnode->name);
    printf("enter the student marks :");
    scanf("%d",&studentnode->marks);
    if(head==NULL){
        head=temp=studentnode;
        count++;
    }
    else{
        temp->next=studentnode;
        temp=studentnode;
        count++;
    }
}
}

void display_studentdetails(){
    if(head==NULL){
        printf("Student record is empty :");
    
    }
    else{
        temp=head;
        printf("\n\n _Student detailes are \n");
        while(temp!=NULL){
            
            printf("%d \t ",temp->id);
            printf("%s \t ",temp->name);
            printf("%d \t ",temp->marks);

            temp=temp->next;
            printf("\n");
        }
    }
}

void insert_studentnode(){
    struct node* insertnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the student record :\n");
    printf("enter the student id :");
    scanf("%d",&insertnode->id);
    printf("enter the student name :");
    scanf("%s",insertnode->name);
    printf("enter the student marks :");
    scanf("%d",&insertnode->marks);
    insertnode->next=NULL;
    if(head==NULL){
        head=insertnode;
        count++;
    }
    else{
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=insertnode;
    count++;
    }
}

void delete_studentnode(){
    int pos,i=1;
    struct node* nextnode;
    printf("enter the position to delete the student record :");
    scanf("%d",&pos);
    if(pos>count || pos<1){
        printf("invaild position to delete !");
    }

    else if(head==NULL){
        printf("Student record is empty \n");
    }
    else if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
        count--;
    }
    else{
        temp=head;
        while(i<pos-1 && temp->next!=NULL){
            temp=temp->next;
            i++;
        }
        nextnode=temp->next;
        temp->next=nextnode->next;
        free(nextnode);
        count--;


    }

}


void search(){
    int tar;
    bool tar_found=false;
    int st_id,st_marks;
    char st_name[40];
    printf("\nenter the student id to find :");
    scanf("%d",&tar);

    if(head==NULL){
    printf("Student record is empty ");
 }
 else{
    temp=head;
    while(temp!=NULL){
        if(tar==temp->id){
            tar_found=true;
            st_id=temp->id;
            strcpy(st_name,temp->name);
            st_marks=temp->marks;
            break;
        }
        else{
            temp=temp->next;
        }
    }
 if(tar_found){
    printf("id is found \n");
            printf("%d \t ",st_id);
            printf("%s \t ",st_name);
            printf("%d \t ",st_marks);
    
 }
 else{
    printf("student record not found ");
 }
}
}

void save_file(){
    FILE *fp=fopen("Students.txt","w");
    if(fp==NULL){
        printf("File is not opening!");
        return;
    }
    else{
        temp=head;
        while(temp!=NULL){
           fprintf(fp,"%d \t %s \t %d\n",temp->id,temp->name,temp->marks);
           temp=temp->next;
        }
   }
   fclose(fp);
}

int main(){
    int choice=0;
    load_file();
    while(1){
        printf("\n\n_____STUDENTS RECORD MANAGEMENT SYSTEM____\n");
        printf("1.For entering students records \n");
        printf("2.For displaying student details \n");
        printf("3.For inserting new student details \n");
        printf("4.For deleting a student details \n");
        printf("5.For searchin a student details \n");
        printf("6.For exit\n");
        printf("Enter the choice :");
        scanf("%d",&choice);


        switch(choice){
            case 1:create_studentnode();break;
            case 2:display_studentdetails();break;
            case 3:insert_studentnode();break;
            case 4:delete_studentnode();break;
            case 5:search();break;
            case 6: save_file();exit(0);
            default:printf("invalid choice !");
        }

    }    
    return 0;
}    