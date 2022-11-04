#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 4<->5<->65<->3<->45

struct doublelink{
	int data;
	struct doublelink *next;
	struct doublelink *prev;
};

struct doublelink * finsert(struct doublelink * start,int data){
	struct doublelink *new = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->next = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->prev = (struct doublelink *)malloc(sizeof(struct doublelink));
	struct doublelink *ptr = start;
	while(ptr->next != NULL) ptr = ptr->next;
	new->data = data;
	new->next = start;
	new->prev = ptr;
	ptr->next = new;
	start->prev = new;
	start = new;
	return start;
}

struct doublelink * ainsert(struct doublelink * start,int af,int data){
	struct doublelink *new = (struct doublelink *)malloc(sizeof(struct doublelink));
	struct doublelink *temp = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->next = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->prev = (struct doublelink *)malloc(sizeof(struct doublelink));
	struct doublelink *ptr= start;
	while(ptr->data != af) ptr = ptr->next;
	temp = ptr->next;
	new->data = data;
	new->next = temp;
	new->prev =ptr;
	ptr->next = new;
	return start;
}

struct doublelink * binsert(struct doublelink * start,int af,int data){
	struct doublelink *new = (struct doublelink *)malloc(sizeof(struct doublelink));
	struct doublelink *temp = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->next = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->prev = (struct doublelink *)malloc(sizeof(struct doublelink));
	struct doublelink *ptr= start;
	while(ptr->next->data != af) ptr = ptr->next;
	temp = ptr->next;
	new->data = data;
	new->next = temp;
	new->prev =ptr;
	ptr->next = new;
	return start;
}

struct doublelink *rinsert(struct doublelink *start,int data){
	struct doublelink *new = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->next = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->prev = (struct doublelink *)malloc(sizeof(struct doublelink));
	new->data = data;
	struct doublelink *ptr = start;
	while(ptr->next != NULL) ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	new->next =start;
	start->prev = new;
	return start;
}

struct doublelink * fdelete(struct doublelink * start){
	struct doublelink *ptr= start;
	start = start->next;
	start->prev = NULL;
	free(ptr);
	return start;
}
struct doublelink * rdelete(struct doublelink * start){
	struct doublelink *ptr= start;
	struct doublelink *pre= start;
	while(ptr != NULL){
	pre = ptr;
	 ptr = ptr->next;
	 }
	pre->next = NULL;
	free(ptr);
	return start;
}

struct doublelink * delete(struct doublelink * start,int data){
	struct doublelink *ptr= start;
	struct doublelink *pre= start;
	while(ptr->data != data){
	pre = ptr;
	 ptr = ptr->next;
	 }
	pre->next = ptr->next;
	ptr->next->prev = pre->next;
	free(ptr);
	return start;
}

void print(struct doublelink * start){
	struct doublelink *ptr= start;
	while(ptr->next != NULL){
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	 }
	 printf("%d\n",ptr->data);

}

int main(){
 	struct doublelink *list = (struct doublelink *)malloc(sizeof(struct doublelink));
	list->next =NULL;
	list->prev =NULL;
	list->data=12;
	list = finsert(list,1001);
	list = rinsert(list,23);
	list = rinsert(list,78);
	list = finsert(list,10);
	list = finsert(list,45);
	//list = fdelete(list);
	list = rdelete(list);
	print(list);

return 0;
}
