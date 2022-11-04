#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct circlelink{
	int data;
	struct circlelink *next;
};

struct circlelink * finsert(struct circlelink * start,int data){
	struct circlelink *new = (struct circlelink *)malloc(sizeof(struct circlelink));
	new->next = (struct circlelink *)malloc(sizeof(struct circlelink));
	new->data = data;
	struct circlelink *ptr = start;
	while(ptr->next != start) ptr = ptr->next;
	ptr->next = new;
	new->next = start;
	start = new;
	return start;
}

struct circlelink *rinsert(struct circlelink *start,int data){
	struct circlelink *new = (struct circlelink *)malloc(sizeof(struct circlelink));
	new->next = (struct circlelink *)malloc(sizeof(struct circlelink));
	new->data = data;
	struct circlelink *ptr = start;
	while(ptr->next != start) ptr = ptr->next;
	ptr->next = new;
	new->next = start;
	return start;
}

struct circlelink * fdelete(struct circlelink * start){
	struct circlelink *ptr= start;
	struct circlelink *ptr2= start;
	while(ptr->next != start) ptr = ptr->next;
	start = start->next;
	ptr->next = start;
	free(ptr2);
	return start;
}
struct circlelink * rdelete(struct circlelink * start){
	struct circlelink *ptr= start;
	struct circlelink *pre= start;
	while(ptr->next != start){
	pre = ptr;
	 ptr = ptr->next;
	 }
	pre->next = start;
	free(ptr);
	return start;
}

void print(struct circlelink * start){
	struct circlelink *ptr= start;
	while(ptr->next != start){
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	 }
	 printf("%d\n",ptr->data);

}

int main(){
 	struct circlelink *list = (struct circlelink *)malloc(sizeof(struct circlelink));
	list->next =list;
	list->data=12;
	list = rinsert(list,23);
	list = rinsert(list,78);
	list = finsert(list,1001); 
	list = rinsert(list,48);
	list = rinsert(list,98);
	list = finsert(list,11);
	list = fdelete(list);
	list = fdelete(list);
	list = rdelete(list);
	print(list);

return 0;
}
