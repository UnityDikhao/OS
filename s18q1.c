#include <stdio.h>
#include<stdlib.h>
int files[10], indexBlock[50], indBlock, n,cnt=0;
char  fnm[20],f[20];
int main()
{
    FILE *fp;
    static  int sb,len;
    int t;
    int op=1;

    printf("Enter Total Block : ");
    scanf("%d",&t);
    files[t];

    for(int i=0; i<10; i++)
        files[i]=1;

    printf("Bit Vector Before Allocation \n ");
    for(int i=0; i<t; i++)
        printf("%d",files[i]);

    printf("\n");
    while(op>=1 && op<=5)
    {

      y:  printf("\n 1.Create File");
        printf("\n 2.Show bit Vector ");
        printf("\n 3.Show directory  ");
        printf("\n 4.Exit");


        printf("\n Enter option :  ");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
            printf("\nEnter File name : ");
            scanf("%s",fnm);

            fp = fopen(fnm, "w");

            if (fp == NULL) {
                printf("\nError opening the file.\n");
                return 1;
            }
            else
                printf("\n * File is created * \n ");

           x: printf("Enter the index block: ");
            scanf("%d", &indBlock);
            if (files[indBlock] != 0) {
                files[indBlock]=0;
                printf("\nEnter the number of blocks  needed for the index %d on the disk: ", indBlock);
                scanf("%d", &n);
            }
            else {
                printf("%d is already allocated\n", indBlock);
                goto x;
            }

        int flag = 0;
        cnt=0;
       

       z: printf("\nEnter block occupied by given %s File : \n ",fnm);
        for (int i=0; i<n; i++) {
            scanf("%d", &indexBlock[i]);
            cnt++;
            if (files[indexBlock[i]] == 1)
                flag++;
        }
        if (flag == n) 
        {
            for (int j=0; j<n; j++) 
            {
                files[indexBlock[j]] = 0;
            }
            printf("\n**Allocated***\n");
            printf("\nFNm\tIB\tIndex\tAlloctated\n");
            for (int k=0; k<n; k++) {
                printf("%s\t%d ----> %d\t%d\n", fnm,indBlock, indexBlock[k], files[indexBlock[k]]);
            }
            goto y;
        }
        else {
            printf(" block is already allocated\n");
            printf("Enter another blocks\n");
            goto z;
        }   
    break;
case 2 :
    printf("\n Bit Vector After  Allocation \n ");
    for(int i=0; i<t; i++)
        printf("%d",files[i]);
    printf("\n");
    break;
case 3 :
    printf("\n File Details Are : \n ");
    printf("\nF_NM\tIB\tLen\n");
    printf("%s\t%d\t%d",fnm,indBlock,cnt);
    printf("\n");
    break;
case 4 :
    exit(0);
}
if(op!=4 )
{
    printf("\nF_NM\tIB\tLen\n");
    printf("%s\t%d\t%d",fnm,indBlock,cnt);
    printf("\n");
}
}
fclose(fp);
return 0;
}
