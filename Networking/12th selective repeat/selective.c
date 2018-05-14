#include<stdio.h>
#include<stdlib.h>

int main()
{
	int temp1,temp2,temp3,temp4,temp5,i,winsize=8,noframes,moreframes;
	char c;
	int reciever(int);
	int simulate(int);
	int nack(int);

	temp4=0,temp1=0,temp2=0,temp3=0,temp5 = 0;

	for(i=0;i<200;i++)
		rand();

	noframes=rand()/200;
	printf("\n number of frames is %d",noframes);

	moreframes=noframes;

	while(moreframes>=0)
	{
		temp1=simulate(winsize);
		winsize-=temp1;
		temp4+=temp1;

		if(temp4 >noframes)
			temp4 = noframes;
		for(i=noframes - moreframes;i<=temp4;i++)
			printf("\nsending frame %d",i);

	temp2=reciever(temp1);
	temp3+=temp2;
	if(temp3 > noframes)
		temp3 = noframes;
	temp2 = nack(temp1);
	temp5+=temp2;
	if (temp5 !=0)
	{
		printf("\n No acknowledgement for the frame %d",temp5);

		for(i=1;i<temp5;i++)
		;
		printf("\n Retransmitting frame %d",temp5);
	exit(0);
	}
	moreframes-=temp1;
	if(winsize<=0)
		winsize=8;
	}
	printf("\n end of sliding window protocol Selective Reject");
	exit(0);
	
	return 0;
}

int reciever(int temp1)
{
	int i;
	for(i=1;i<100;i++)
		rand();

	i=rand()%temp1;
	return i;
exit(0);
}

int nack(int temp1)
{
	int i;
	for(i=1;i<100;i++)
		rand();

	i=rand()%temp1;
	return i;
}

int simulate(int winsize)
{
	int temp1,i;
	for(i=1;i<50;i++)
		temp1=rand();
	if(temp1==0)
		temp1=simulate(winsize);
	i = temp1%winsize;
	if(i==0)
		return winsize;
	else
		return temp1%winsize;
}

