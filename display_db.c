#include "inverted_search.h"

void display_database( Wlist *head[] )
{
	//print the heading
    printf("%8s%20s%20s%20s%20s\n","[index]","[word]","file_count file/s","File: File_name","word_count");

    for(int i = 0 ; i < 27 ; i++)
    {
	if(head[i] != NULL)
	{
	//iterate until the index reaches 27
	    print_word_count(head[i]);
	}
    }
}

int print_word_count(Wlist *head)
{
    //traveser through WList

    while(head != NULL)
    {
	//printing index word and file count
	printf("%5d%23s%8d file/s :" , tolower(head->word[0])%97 , head->word , head->file_count);
	Ltable *Thead = head->Tlink;

	//traverse through table link of word
	while(Thead)
	{
	//printing file name and word count
	    printf("%11s:%15s%15d " ,"File", Thead->file_name , Thead->word_count);
	    Thead = Thead->table_link;
	}
	//printing next line and updating head
	printf("\n");
	head= head->link;
    }
}





