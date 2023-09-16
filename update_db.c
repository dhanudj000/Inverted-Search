#include "inverted_search.h"

void update_database(Wlist *head[] , Flist **f_head)
{
    //prompt the user to enter new file for updation 
    char file_name[FNAME_SIZE];
    printf("Enter the file name : ");
    scanf(" %s" , file_name);

    //validate 
    //........TODO...file_list.c
	int empty = isFileEmpty(file_name);
	if(empty == FILE_NOTAVAILABLE)
	    {
		    printf("The file %s does not exist,hence not adding the file.\n",file_name);
	    }
        else if(empty == FILE_EMPTY)
	    {
		    printf("the file %s is empty. hence not adding the file.\n",file_name);
	    }
        else
	    {
		int res = to_create_list_of_files(f_head,file_name);
		if(res == SUCCESS)
		{
		    printf("the file %s is succesfully added to the data base .\n",file_name);
	   	    read_datafile(*f_head,head,file_name);
	    	}
                else if(res == REPEATATION)
  	        {
	   		 printf("The file has been reapeated so not adding to the database.\n");
 		}
   		else
   		{
	    		printf("Failure to add file to database.\n");
    		}
	    }
}



