#include<stdio.h>
#include<stdlib.h>

int main(){
 int temp1,temp2,temp3,temp4,i,winsize=8,noframes=8,moreframes;
 char c;
 int reciever(int);
 int simulate(int);

 temp4=0,temp1=0,temp2=0,temp3=0;


//for(i=0;i<200;i++)
//rand();
//noframes=rand()/200;

 printf("\n number of frames is %d",noframes);

 moreframes=noframes;

 while(moreframes>=0)
 {
	temp1=simulate(winsize);
	winsize-=temp1;
	temp4+=temp1;

	if(temp4 >noframes)
		temp4 = noframes;
	for(i=temp3+1;i<=temp4;i++)
		printf("\nsending frame %d",i);

	temp2=reciever(temp1);
	temp3+=temp2;

	if(temp3 > noframes)
	temp3 = noframes;
	printf("\n acknowledgement for the frames up to %d",temp3);

	moreframes-=temp2;
	temp4=temp3;

	if(winsize<=0)
		winsize=8;
	}
	printf("\n end of sliding window protocol");
	
	return 0;
}

int reciever(int temp1)
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
