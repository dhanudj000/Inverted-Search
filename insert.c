#include "inverted_search.h"

extern char* fname;
int insert_at_last(Wlist **head, data_t *data)
{
    //create node 
    Wlist *new = malloc(sizeof(Wlist));

    //error
    if(new == NULL)
	return FAILURE;

    //update the new word list node
    new->file_count = 1;
    strcpy(new->word,data);
    new->Tlink = NULL;
    new->link = NULL;

    // call fun() to update link table
    update_link_table(&new);
    //Check WList empty or not

    if(*head == NULL)
    {
	//if empty update head
	    *head = new;
	return SUCCESS;
    }

    //if non empty traverse and create

    Wlist *temp = *head;

    //traverse through WList

    while(temp->link)
    {
	temp = temp->link;
    }
    temp->link = new;
    //update temp link and return success
    return SUCCESS;
}

int update_link_table(Wlist **head)
{
    //Ltable node creation

    Ltable *new = malloc(sizeof(Ltable));

    //error check

    if(new == NULL)
	return FAILURE;

    //update new ltable with new file name
    new->word_count = 1;
    strcpy(new->file_name,fname);
    new->table_link = NULL; 
	//link the table with head->table link
    (*head)->Tlink = new;
    return SUCCESS;
}
