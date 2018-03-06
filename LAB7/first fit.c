//variable size-first fit algorithm

#include<stdio.h>

#define max 100

int main()
{
    int nb,np,i,temp,j,flag,fragi=0,fragx = 0;

    printf("enter total number of blocks\n");
    scanf("%d",&nb);

    int b[nb+1]; //to store size of blockes
    int ff[nb+1]; //to store number of each block

    printf("enter size of each block\n");
    for(i=1;i<=nb;i++)
    {
        scanf("%d",&b[i]);
        ff[i]=i;
    }

    printf("enter total number of processes\n");
    scanf("%d",&np);


    int p[np+1],flagn[np+1];
    printf("enter size of each process\n");
    for(i=1;i<=np;i++)
    {
        scanf("%d",&p[i]);
    }

    //check for each process
    printf("\n\nProcess_No\tProcess_Size\tBlock_No\tBlock_Size\tFragment\n");

    int x=1;
    for(i=1;i<=np;i++)
    {
        flag=1;
        for(j=x;j<=nb;j++)
        {
            if(p[i]<=b[j])
            {
               flagn[j] = 1;
               printf("%-15d\t%-15d\t%-15d\t%-15d\t",i, p[i],ff[j],b[j]);
               b[j] = b[j]-p[i];  //remaining memory in block
               fragi = fragi + b[j]; //which is internal fragmentation
               printf("%-15d\n",b[j]);
               break;
            }
            else
            {
              flagn[j]=0;
              x = 1;
              flag++;
            }
        }
        if(flag > nb)
		printf("%-15d\t%-15d\t%-15s\t%-15s\t%-15s\n",i, p[i],"WAIT...","WAIT...","WAIT...");
    }

    printf("Internal Fragmentation = %d",fragi );
	for (j= 1; j <=nb ; j++)
    {
		if (flagn[j] != 1)
		{
         fragx = fragx + b[j];
		}
	}
	printf("\nExternal Fragmentation = %d\n",fragx);

	return 0;
}
