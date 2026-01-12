#include <stdio.h>

int main() {
    int ch;
    char x;
    int i, j;
    int a[2][2];
    int b[2][2];
    int c[2][2]; 
    int d[2][2]; 
    int e[2][2];
    int f[2][2];
    int A[2][2];
    int B[2][2];

    do {
        printf("1. Create two 2x2 matrices\n");
        printf("2. Display two matrices\n");
        printf("3. Addition\n");
        printf("4.substraction\n");
        printf("5.multiplication\n");
        printf("6.division\n");
        printf("7.transpose od matrix:\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter values for matrix 1:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        scanf("%d", &a[i][j]);
                    }
                }

                printf("Enter values for matrix 2:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        scanf("%d", &b[i][j]);
                    }
                }
                break;

            case 2:
                printf("Displaying 1st matrix:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", a[i][j]);
                    }
                    printf("\n");
                }

                printf("Displaying 2nd matrix:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", b[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3:
                
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] + b[i][j];
                    }
                }

                printf("Sum of matrices:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

                case 4:
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] - b[i][j];
                    }
                }

                printf("Subtraction of matrices:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

                case 5:
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] * b[i][j];

                    }
                }

                printf("multiplication of matrices:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

                case 6:

                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        c[i][j] = a[i][j] / b[i][j];
                    }
                }

                printf("Division of matrices:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", c[i][j]);
                    }
                    printf("\n");
                }
                break;

                case 7:

                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        A[j][i]=a[i][j];
                    }
                }
                 printf("transpose of matrix a:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", A[i][j]);
                    }
                    printf("\n");
                }

                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        B[j][i]=b[i][j];
                    }
                }

                printf("transpose of matrix b:\n");
                for (i = 0; i < 2; i++) {
                    for (j = 0; j < 2; j++) {
                        printf("%d ", B[i][j]);
                    }
                    printf("\n");
                }

            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &x);  
    } while (x == 'y' || x == 'Y');

    return 0;
}
