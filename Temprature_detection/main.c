#include <main.h>
#include <stdio.h>

#byte lcd=0x07
#byte mlcd=0x87

#bit rs=0x06.0
#bit trs=0x86.0
#bit en=0x06.1
#bit ten=0x86.1
#bit out=0x06.4
#bit mout=0x86.4

#byte adcon0 =0x1f
#byte adcon1 =0x9f
#byte adresh =0x1e
#byte adresl =0x9e
#bit go_done =0x1f.2

void disp(unsigned int a,unsigned int b);

void main()
{
   
   long int res;
   long int temp;
   char val[10];
   mlcd=0;
   mout=0;
   trs=0;
   ten=0;
   
   adcon0=0x01;
   adcon1 =0x80;
   go_done =1;
   disp(0x0e,0);
   
   disp(0x80,0);
   disp('T',1);
   disp('e',1);
   disp('m',1);
   disp('p',1);
   disp('=',1);
   disp(0x8a,0);
   disp('*',1);
   disp('C',1);
   
   while(1)
   { 
      disp(0x86,0);
      while (go_done==1);
      go_done =1;
      res =adresl|adresh<<8;
      temp= (res*5);
      temp= temp/10.24;
      sprintf(val,"%04lu",temp);
      for (int i=0;i<5;i++)
      {
         disp(val[i],1);
      }
      disp(0x8a,0);
      disp('*',1);
      if(temp>50)
         out=1;
      else
         out=0;

   }

}

void disp(unsigned int a,unsigned int b)
{
   lcd = a;
   rs = b;
   en =1;
   delay_ms(20);
   en =0;
     
}
