#include <stdio.h>
#include <stdlib.h>
//#include "Link_list-1"

/*
	README:
		This is utilty lib for linklist
		Requirments:
			-gcc compiler
		Handbook:
			This link list has data for int but you can change it
			initList:	Initilizes the link list
			insertList:	Gets your list and data and insert the data to your link list
			merge:		Merges your link lists
			
			



*/


struct linkedList{
	int data;
	struct linkedList *next;

};
void initList(struct linkedList *l,int d)
{
	l->data = d;
	l->next = (struct linkedList*)malloc(sizeof(struct linkedList));
	l->next = NULL;
	


}
void insertList(struct linkedList *l,int data)
{
	if(l->next == NULL)
	{
		l->next = (struct linkedList*)malloc(sizeof(struct linkedList));
		initList(l->next,data);
		//printf("%d\n",l->n->data);
		return;
	} 
	else insertList(l->next,data);


}

struct *linkedList merge(struct linkedList *merged,struct linkedList *l1,struct linkedList *l2,struct linkedList *l3){
	int e =0;
	while(l1->next != NULL){
		if(e==0) initList(merged,l1->data);
		else{
		insertList(merged,l1->data);
		}
		e++;
		l = l->next;
	} 
	while(l2->next != NULL){
		insertList(merged,l2->data);
	
	}
	while(l3->next != NULL){
		insertList(merged,l3->data);
	
	}





}

int main(){
	struct linkedList merged;
	struct linkedList *mergeP = (struct linkedList*)malloc(sizeof(struct linkedList));
	mergeP = &merged;


	struct linkedList root1;
	struct linkedList *rootP1 = (struct linkedList*)malloc(sizeof(struct linkedList));
	rootP1 = &root1;
	
	struct linkedList root2;
	struct linkedList *rootP2 = (struct linkedList*)malloc(sizeof(struct linkedList));
	rootP2 = &root2;
	
	struct linkedList root3;
	struct linkedList *rootP3 = (struct linkedList*)malloc(sizeof(struct linkedList));
	rootP3 = &root3;
	
	initList(rootP1,5);
	insertList(rootP1,924);
	insertList(rootP1,9);
	insertList(rootP1,8);
	
	initList(rootP2,5);
	insertList(rootP2,78);
	insertList(rootP2,56);
	
	initList(rootP3,5);
	insertList(rootP3,74);
	insertList(rootP3,12);
	insertList(rootP3,89);
	
	merge(mergeP,rootP1,rootP2,rootP3);
	
	printList(merge);
	
	
	
	
	/*
	
	
	
	printf("-------------\n");
	sortingListSmaller(rootP);
	//deleteList(rootP,924);
	printList(rootP);
		sortingListGreater(rootP);
		printf("-------------\n");
		printList(rootP);

	/*printf("%d\n",searchList(rootP,9));
	printf("%d\n",searchList(rootP,924));*/


return 0;
}
