#include<stdio.h>
#include<stdlib.h>

#define size 200

int main()
{
	int i,j;
	int noframes,x,x1=10,x2;
	
	printf("Enter the number of frames:");
	scanf("%d",&noframes);

	for(i=0;i<size;i++)
			rand();
//noframes=rand()/200;
	i=1;
	j=1;
	
	noframes = noframes / 8;
	
	printf("\n number of frames is %d",noframes);

	while(noframes>0)
	{
		printf("\nsending frame %d",i);
		srand(x1++);
		x = rand()%10;
		if(x%2 == 0)
			{
				for (x2=1; x2<2; x2++)
				{
				   printf("\nwaiting for %d seconds\n", x2);
				   sleep(x2);
				}
		printf("\nsending frame %d",i);
			srand(x1++);
			x = rand()%10;
			}
		
		printf("\nack for frame %d",j);
		
		noframes-=1;
		i++;
		j++;
	}
	printf("\n end of stop and wait protocol \n");
	exit(0);
	
	return 0;
}
