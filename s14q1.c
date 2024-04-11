#include <stdio.h>
int main()
{
    int n, i, st, l, op;
    char fn[20],f[20];
    printf("Enter the number of block in disk :");
    scanf("%d", &n);
    FILE *fp;
    int blk[n];
    for (i = 0; i < n; i++)
        blk[i] = 1;
    while (1)
    {
        printf("\n1.Create New File : \n2.Delete : \n3.Display Disk Status : \n4.Exit :");
        printf("\nEnter the choice : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("Enter File Name :");
            scanf("%s", &fn);
            printf("Enter the number of starting blk no in disk :");
            scanf("%d", &st);
            printf("Enter the length file :");
            scanf("%d", &l);
            fp = fopen(fn, "w");
            if (st + l > n)
                printf("\n\nError....");
            else
                for (i = st; i < st + l; i++)
                    if (blk[i] == 1)
                    {
                        printf("\nFile already created.");
                        break;
                    }
            if (i = st + l)
                for (i = st; i < st + l; i++)
                {
                    blk[i] = 0;
                }
            printf("\nFile created successfully");
            break;

        case 2:
            printf("\nEnter File name to delete : ");
            scanf("%s", f);
            fclose(fp); // Close the file before attempting deletion
            if (remove(f) == 0)
                printf("\nDeleted successfully\n");
            else
                printf("\nUnable to delete the file\n");
            break;

        case 3:
            for (i = 0; i < n; i++)
                if (blk[i] == 0)
                    printf("%d ", blk[i]);
                else
                    printf("%d ", blk[i]);
            printf("\n");
            break;
            
        case 4:
            return 0;
        default:
            printf("Invalid choice.....");
        }
    }
}
