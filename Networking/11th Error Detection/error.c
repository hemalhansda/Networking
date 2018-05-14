#include<stdio.h>
#include<string.h>

#define N strlen(g)

char t[128], cs[128], g[]="10001000000100001";

int a, e, c;

void xor() {
 for(c=1;c<N;c++) 
 	cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc() {
 for(e=0;e<N;e++) 
 	cs[e]=t[e];

 do {
   if(cs[0]=='1')	xor();

   for(c=0;c<N-1;c++) 
   	cs[c]=cs[c+1];
   cs[c]=t[e++];
 }while(e<=a+N-1);

}

int main() {
  printf("\nEnter: ");
  scanf("%s",t);
  
  printf("\nPolynomial is : %s",g);
  a=strlen(t);

 for(e=a;e<a+N-1;e++) 
 	t[e]='0';

 printf("\nModified t[u] is :  %s",t);
	crc();

 printf("\nChecksum : %s",cs);

 for(e=a;e<a+N-1;e++) 
 	t[e]=cs[e-a];
 
 printf("\nFinal Codeword is : %s",t);
 printf("\nTest Error detection please 0(yes) 1(no) ? : ");

 scanf("%d",&e);

 if(e==0) {
   printf("Position where error is to inserted : ");
   scanf("%d",&e);
 
   t[e]=(t[e]=='0')?'1':'0';
   printf("Errorneous data-> %s\n",t);
 }
	 crc();

 for (e=0;(e<N-1)&&(cs[e]!='1');e++);

 if(e<N-1) 
 	printf("Error detected.");

 else 
 	printf("No Error Detected.");

 return 0;
}


/*
Theory

It does error checking via polynomial division. In general, a bit string

bn-1bn-2bn-3…b2b1b0

As

bn-1Xn-1 + bn-2 Xn-2  + bn-3 Xn-3  + …b2 X2  + b1 X1  + b0

Ex: -

10010101110

As

X10 + X7 + X5 + X3 + X2 + X1

All computations are done in modulo 2

Algorithm:-

    Given a bit string, append 0S to the end of it (the number of 0s is the same as the degree of the generator polynomial) let B(x) be the polynomial corresponding to B.

    Divide B(x) by some agreed on polynomial G(x) (generator polynomial) and determine the remainder R(x). This division is to be done using Modulo 2 Division.

    Define T(x) = B(x) –R(x)


(T(x)/G(x) => remainder 0)

    Transmit T, the bit string corresponding to T(x).

    Let T’ represent the bit stream the receiver gets and T’(x) the associated polynomial. The receiver divides T1(x) by G(x). If there is a 0 remainder, the receiver concludes T = T’ and no error occurred otherwise, the receiver concludes an error occurred and requires a retransmission.

*/
