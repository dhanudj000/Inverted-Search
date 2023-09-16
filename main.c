/*
 * NAME		:KONIREDDY DHANUNJAYA REDDY
 * DATE		:11-09-2023
 * TITLE	:INVERTED SEARCH
 * DESCRIPTION	:THE FILE DATA IS ARRANGED IN HASH TABLE SUCH THATEVERY WORD IS ARRANGED IN THAT SPECIFIC INDEX
 */
#include "inverted_search.h"

char *fname;
int main(int argc , char *argv[])
{
	system ("clear");
	Wlist *head[27] = {NULL};
    //validate CLA
    if(argc <= 1)
    {
	printf("Enter the valid no. arguments\n");
	printf("Usage : ./Slist.exe  f1.txt f2.txt...\n");
	return 0;
    }
    //create the file linked list 
    //declare file head
    Flist *f_head = NULL;
    //validate the file
    file_validation_n_file_list(&f_head , argv);
    if(f_head == NULL)
    {
	//return if file list is null
	printf("No file are available in the file linked list\n");
	printf("Hence the process terminated\n");
	return 1;
    }
    Flist *temp = f_head;
    while(temp)
    {
    //printing the files that are read from file list
	    printf("%s -> ",temp->file_name);
	    temp = temp->link;
    }
    printf("NULL\n");
    int opt;
    char ch;
    //declaring variables to select a option
    while(1)
    {
	//prompt the user for the option
	printf("Select your choice among following options:\n1. Create DATABASE\n2. Display Database\n3. Update DATABASE\n4. Search\n5. Save Database\nEnter your choice : ");
	scanf("%d",&opt);
	switch(opt)
	{
    //create database 
		case 1:create_database(f_head ,head);break;
    //display database
		case 2:display_database(head);break;
    //upadate database
		case 3:update_database(head , &f_head);break;
    //search database
		case 4:char word[WORD_SIZE];
    printf("Enter the word to search\n");
    scanf("%s" , word);
    search(head[tolower(word[0])%97]  , word);break;
    //save database
		case 5:save_database(head);break;
    //invalid otion
		default :printf("Invalid option");
	}
    //prompt the user to continue the program or not
back :  printf("Do you want to continue Y/N?\nOption-->");
	scanf(" %c",&ch);
	if(ch== 'n' || ch=='N')
		exit(1);
	else if(ch!='y'&&ch!='Y')
	{
	//go back if option is not selected correctly
		printf("Please select valid option...\n");
		goto back;
	}
    }
}






























































