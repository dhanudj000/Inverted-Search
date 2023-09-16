#include "inverted_search.h"
extern char *fname;
void create_database(Flist *f_head, Wlist *head[])
 {
     //traverse through the file linked list

     while(f_head)
     {
	 //read file from file linked list and create data base
	 read_datafile(f_head , head , f_head ->file_name);
	 //traverse through the head for next files
	 f_head = f_head->link;
     }
 }

//read the contents 
Wlist * read_datafile(Flist *file, Wlist *head[], char *filename)
{	
    //open the file in read mode

    FILE *fptr = fopen(filename , "r");

    fname = filename;
    int flag=1;
    //declare an array to store the words

    char word[WORD_SIZE];

    while(fscanf(fptr , "%s" , word) != EOF)
    {
	//index

	int index = tolower(word[0]) %97 ;

	//other than alphabets

	if(!(index >=0 && index <= 25))
	    index = 26;

	//check words are repeated or not

	if(head[index] != NULL)
	{
	    Wlist *temp = head[index];

	    //compare words at each node with new word

	    while(temp)
	    {
		    flag =1;
		if(!strcmp(temp->word , word))
		{
	    //update word count is same words are not repeated
		    update_word_count(&temp,filename);
		    flag = 0;
		    break;
		}
		temp = temp->link;
	    }

	}
	if(flag == 1)
	{
	    //if words are not repeated
	    insert_at_last(&head[index] , word);
	}
    }
}

int update_word_count(Wlist ** head, char * file_name)
{
    //................TODO..............
    //check the filename  whether they are same
	Ltable *temp = NULL,*check = (*head)->Tlink;
    while(check)
    {
	    temp = check;
    //if filenames are same , increment word_count
    if(!strcmp(check->file_name,file_name))
	 {
    //incrementing word count if file names are same
	 	check->word_count++;
		return 1;
	 }
    check = check->table_link;
    }
    //if filenames are different , increment file_count , create Ltable
	(*head)->file_count++;
	Ltable *new = malloc(sizeof(Ltable));
    //assigning values to Ltable
	new->word_count++;
	new->table_link = NULL;
	strcpy(new->file_name,file_name);
	if(temp == NULL)
		(*head)->Tlink = new;
	else
		temp->table_link = new;
	return 1;
}


