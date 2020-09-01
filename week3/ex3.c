#include<stdio.h>
#include <stdlib.h>
struct Element{
    int isLast;
    struct Element *next;
    int value;
};
void print_node(struct Element *list){//This function print all elements of linked list
    struct Element * iterator =list;
    if (iterator->isLast!=1){
        iterator =iterator->next;
        while(iterator->isLast!=1){
            printf("%d ",iterator->value);
            iterator=iterator->next;
        }
        printf("%d ",iterator->value);
        printf("\n");
    }
    else{
        printf("There are no elements in linked list \n");
    }

}

void insert_node_by_value(struct Element *list,int prev_elem ,int element){
    //This function insert element after given prev_elem of Linked list
    struct Element * iterator =list;
    while(iterator->isLast!=1 &iterator->value!=prev_elem){
        iterator=iterator->next;
    }
    if (iterator->value==prev_elem){
        struct Element * new_elem=malloc(sizeof(struct Element));
        new_elem->value=element;
        new_elem->isLast=iterator->isLast;
        new_elem->next=iterator->next;

        iterator->isLast=0;
        iterator->next=new_elem;
    }else{
        printf("There is no node %d in list \n",prev_elem);
    }
}

void insert_node_to_position(struct Element *list,int position ,int element){
    //This function insert element to the position position
    struct Element * iterator =list;
    int i=0;
    while(iterator->isLast!=1 &i<position){
        iterator=iterator->next;
        i++;
    }
    if (position==i){
        struct Element * new_elem=malloc(sizeof(struct Element));
        new_elem->value=element;
        new_elem->isLast=iterator->isLast;
        new_elem->next=iterator->next;

        iterator->isLast=0;
        iterator->next=new_elem;
    }else{
        printf("Number of nodes is less then %d \n",position);
    }
}

void delete_node(struct Element *list,int element){
    //This function delete node with value that equals to element.
    struct Element * iterator =list;
    while(iterator->next->isLast!=1&iterator->next->value!=element) {
        iterator=iterator->next;
    }
    if (iterator->next->value==element){
        struct Element * prev=iterator;
        struct Element * current=iterator->next;
        prev->isLast=current->isLast;
        prev->next=current->next;
        free(current);
    }else{
        printf("There is no node %d in list \n",element);
    }
}
void delete_node_from_position(struct Element *list,int position){
    //This element remove element at position position
    struct Element * iterator =list;
    int i=0;
    while(iterator->next->isLast!=1&i<position) {
        iterator=iterator->next;
        i++;
    }
    if (i==position){
        struct Element * prev=iterator;
        struct Element * current=iterator->next;
        prev->isLast=current->isLast;
        prev->next=current->next;
        free(current);
    }else{
        printf("Number of nodes is less then %d\n",position);
    }
}
int main(){
    struct Element * head=malloc(sizeof(struct Element));
    head->isLast=1;
    print_node(head);
    insert_node_to_position(head,0,2);
    insert_node_to_position(head,1,3);
    insert_node_to_position(head,0,1);
    insert_node_to_position(head,3,4);
    print_node(head);
    insert_node_by_value(head,3,10);
    insert_node_by_value(head,2,11);
    insert_node_by_value(head,1,12);
    print_node(head);
    delete_node(head,2);
    delete_node_from_position(head,0);
    delete_node_from_position(head,26);
    delete_node(head,3);
    delete_node_from_position(head,3);
    print_node(head);
}