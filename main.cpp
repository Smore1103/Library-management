#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct library {
    char book_name[1000];
    char author[1000];
    int number_of_pages;
    float price;
};

int main()
{
    struct library lib[100];
    char search_the_name_of_the_book[30], author_name[30], a[50];
    int i, inp, c, j;
  
    i = j = c = inp = 0;	
    while (inp != 6) {
        printf("\n1. Enter book information");
        printf("\n2. Display list of the books");
        printf("\n3. Search a book");
        printf("\n4. Search book according to Author name");
        printf("\n5. Sort list of books by name");
        printf("\n6. Exit");
  
        printf("\nEnter one of the above: ");
        scanf("%d", &inp);
  
        switch(inp){
        case 1:	
			printf("Enter book name = ");
            scanf("%s", lib[i].book_name);
  
            printf("Enter author name = ");
            scanf("%s", lib[i].author);
  
            printf("Enter no. of pages = ");
            scanf("%d", &lib[i].number_of_pages);
  
            printf("Enter price = ");
            scanf("%f", &lib[i].price);
            c++;
            i++;
			break;
  
        case 2:		
            printf("\nThe following books have been stored: ");
            for (i=0; i < c; i++){
                printf("\nBook Name = %s", lib[i].book_name);
                
                printf("\nAuthor Name = %s", lib[i].author);
                
                printf("\nNumber of pages = %d", lib[i].number_of_pages);
                
                printf("\nPrice = Rs.%f", lib[i].price);
            }
            break;
  
        case 3:		
            printf("Enter book to search: ");
            scanf("%s", search_the_name_of_the_book);
            for (i = 0; i < c; i++){
                if (strcmp(search_the_name_of_the_book, lib[i].book_name) == 0)
                    printf(" %s is written by %s with %d number of pages priced at  Rs.%f", lib[i].book_name, lib[i].author, lib[i].number_of_pages, lib[i].price);
            }
            break;
  
        case 4:	
            printf("\nEnter book to search by author name: ");
            scanf("%s", author_name);
            for(i = 0; i < c; i++){
            	if(strcmp(author_name, lib[i].author) == 0)
            		printf("%s has been written by %s", lib[i].book_name, lib[i].author);
			}
            break;
            
        case 5:	
        	for(i = 0; i < c; i++){
				for(j = i+1; j < c; j++){
					if(strcmp(lib[i].book_name, lib[j].book_name) > 0){
            			strcpy(a, lib[i].book_name);
            			strcpy(lib[i].book_name, lib[j].book_name);
            			strcpy(lib[j].book_name, a);
        			}
      			}
   			}
   			printf("\nThe sorted order of names are:\n");
   			for(i = 0; i < c; i++){
      			printf("%s\n", lib[i].book_name);
   			}
        	
        case 6:		
        	exit(0);
        }
    }
    return 0;
}
