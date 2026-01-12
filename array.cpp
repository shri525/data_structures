#include <stdio.h>

int main()
{
    int a[5];
    int i;
    int ch;
    char x;
    int max;
    int min;
    int index;
    do
    {
        printf("menu\n");
        printf("1. array cration\n");
        printf("2.display array\n");
        printf("3.maximun number in the array:\n");
        printf("4.minmun number in the array:\n");
        printf("5. array indexing\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);


       switch(ch)
       {

        case 1:
        printf("Enter 5 elements:\n");

        for(i = 0; i < 5; i++)
         {
        scanf("%d", &a[i]);
         }

         break;

        case 2:
         printf("\nArray elements are:\n");

         for(i = 0; i < 5; i++)
        {
        printf("%d ", a[i]);
         }

        break;

        case 3:
          max = a[0];
            for(i = 1; i < 5; i++)
                if(a[i] > max)
                     max = a[i];
            printf("Maximum is: = %d", max);
               
            break;

        case 4:
          min = a[0];
             for(i = 1; i < 5; i++)
                 if(a[i] < min)
                   min = a[i];
            printf("Minimum number = %d", min);
               
            break;    

        case 5:
                printf("Enter index (0 to 4): ");
                scanf("%d", &index);

                if(index >= 0 && index < 5)
                    printf("Element at index %d = %d", index, a[index]);
                else
                    printf("Invalid Index!");
                break; 

        default:
                printf("Invalid choice!");
       }
    printf("Do you want to continue (y/n)? ");
    scanf(" %c", &x);  
    } while (x == 'y' || x == 'Y');

}
