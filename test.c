#include <stdio.h> 
#include <stdlib.h> 
#include <omp.h>
#include <ctype.h> 
#include <string.h>

int extraction(char *ch)
{
    int x,y;
    int l=strlen(ch);

    #pragma omp parallel sections
    {
    
     #pragma omp section
      {
         //le 1er eniter
         for (int i=0; i<l; i++)
         {
            if(isdigit(ch[i]))
            {
              x=(ch[i]-'0')*10;
              break;
            }
         }
      }
  
      #pragma omp section
      {
        //le dernier eniter
        for (int i=l-1; i>=0; i--)
        {
          if(isdigit(ch[i]))
          {
             y=ch[i]-'0';
            break;
          }
        }
      }
    }
    return x+y;
}

int main( int argc,char *argv[]) 
{ 
  FILE *file; 
  char buffer[256]; 
  char *ch=buffer;
  int somme=0;
  
  file = fopen("doc.txt", "r");
  if (file == NULL) {
      perror("Erreur lors de l'ouverture du fichier");
      return 1;
  }
  
  //faire la somme tant que le fichier n'est pas vide
  while (fgets(buffer, sizeof(buffer), file) != NULL)
  {
    somme+=extraction(ch);
  }
  
  printf("la somme est: %d\n", somme);
  fclose(file);
  return 0;
}      
