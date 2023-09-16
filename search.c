#include "inverted_search.h"

 void search( Wlist *head, char *word)
{
    //check list is empty or not

    if(head == NULL)
    {
	//return if head is empty
	printf("Searching failed as list was empty\n");
	return ;
    }

    //non empty ---- > traverse list
    while(head)
    {
	//compare the search word with available words
	if(!strcmp(head->word , word))
	{
	//if word is present print where is the word
	    printf("Word %s is present in %d file/s\n", word , head->file_count);

	    Ltable *Thead = head->Tlink;
	    while(Thead)
	    {
		//print the files that contains the word amnd how many times
		printf("In file : %15s%8d time/s \n" , Thead->file_name , Thead -> word_count);
		Thead = Thead->table_link;
	    }
	    //printing in new line
	    printf("\n");
	    return ;
	}
	head = head->link;
    }
	//if not fount just prompt
    printf("Search word is not found in the list\n");
}






