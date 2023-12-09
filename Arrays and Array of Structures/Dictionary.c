#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct word
{
 char word[20];
 char meaning[50];
}w[100];

int main()
{
 char wd[20];
 int i,j, input, count;
 i = input = count = 0;
 while (input != 7)
 {
 printf("\n\n**###### DICTIONARY #####**\n");
 printf("\n1. Add a word with its meaning\n");
 printf("2. Display all the words and their meaning\n");
 printf("3. Search by word\n");
 printf("4. Search by meaning\n");
 printf("5. Total no of words\n");
 printf("6. Delete given word and its meaning\n");
 printf("7. Exit");
 printf("\n\nEnter one of the above: ");
 scanf("%d", &input);
 switch (input)
 {
  case 1:
     fflush(stdin);
     printf("Enter the word = ");
     gets(w[i].word);
     printf("Enter its meaning = ");
     gets(w[i].meaning);
     count++;
     i++;
     break;

  case 2:
     printf("You have entered the following information:\n");
     for (i = 0; i < count; i++)
     {
      printf("Word = %s", w[i].word);
      printf("\tMeaning = %s\n", w[i].meaning);
     }
     break;

  case 3:
     printf("Enter the word to search: ");
     scanf("%s",wd);
     for (i = 0; i < count; i++)
     {
      if (strcmp(wd, w[i].word) == 0)
      printf("Word: %s  Meaning: %s", w[i].word, w[i].meaning);
     }
     break;

  case 4:
     fflush(stdin);
     printf("Enter the meaning to search: ");
     gets(wd);
     for (i = 0; i < count; i++)
     {
      if (strcmp(wd, w[i].meaning) == 0)
      printf("Word: %s  Meaning: %s", w[i].word, w[i].meaning);
     }
     break;

  case 5:
     printf("\nTotal no of words : %d", count);
     break;

  case 6:
     printf("Enter a word to delete: ");
     scanf("%s",wd);
     for (i = 0; i < count; i++)
     {
      if(strcmp(wd, w[i].word) == 0)
        {
         for(j=i;j<count;j++)
         {
          w[j] = w[j+1];
         }
         printf("Word and its meaning is deleted");
         count--;
        }
     }
     break;

  case 7:
     printf("\nProgram ended");
     exit(0);
  }
 }
 return 0;
}
