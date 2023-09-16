#include "inverted_search.h"

 void save_database( Wlist *head[])
{
    //prompt the use to enter the file name for saving the database
    char file_name[FNAME_SIZE];

    printf("Enter the file name\n");
    //read the file name
    scanf("%s" , file_name);

    //open file 

    FILE *fptr = fopen(file_name , "w");
    fprintf(fptr,"%8s%20s%20s%20s%20s\n","[index]","[word]","[file_count]","[file_name]","[word_count]");
    for(int i = 0 ; i < 27; i++)
    {
	//check if node is not empty
	if(head[i] != NULL)
	{
	//traverse through the hash table
    	    write_database(head[i] , fptr);
	}
    }
    //prompt tye success
    printf("Database saved successfully\n");
}

void write_database(Wlist *head, FILE* databasefile)
{
	//traverse through the head
    while(head!=NULL)
    {
		//write the data into the file
	    fprintf(databasefile,"%5d%23s%15d",tolower(head->word[0]%97),head->word,head->file_count);
	    Ltable *Thead= head->Tlink; 
	    while(Thead)
	    {
		    //traverse through ltable and write to file
		    fprintf(databasefile,"%11s:%15s%15d","File",Thead->file_name,Thead->word_count);
		    Thead = Thead->table_link;
	    }
	    //write in new line
	    fprintf(databasefile,"\n");
	    head = head->link;
    }
}




















