/*
This is just Demo for show case the simple working of microcontroller in C++

  */


#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

class ALU{
		public:
			bool C;			
			bool B;	
			bool Z;	
			ALU(){
				C=0;
				B=0;
			}
			
		unsigned char Excecuit(char IS,unsigned char Rd,unsigned char Rr){
			C=0;
			B=0;
			Z=0;
			int a=0;
			switch(IS)
			{
				case(1):
					a=Rd+Rr;
					Rd=(char)a;
					break;
					
				case(2):
					a=Rd-Rr;
					Rd=(char)a;
					break;
					
				case(3):
					Rd &=Rr;
					break;
					
				case(4):
					Rd |=Rr;
					break;
					
				case(5):
					Rd ^=Rr;
					break;
					
				default:
					Rd=0;	
			}
						
			C=(bool)(a>>8) &&(a>=0);
			B=(bool)(a<0);
			Z=!(Rd);
		return Rd;
	}
		unsigned char Excecuit(char IS,unsigned char Rd,unsigned char *Rr){
			C=0;
			B=0;
			Z=0;
			int a=0;
			switch(IS)
			{
				case(1):
					a=Rd+ *Rr;
					Rd=(char)a;
					break;
					
				case(2):
					a=Rd- *Rr;
					Rd=(char)a;
					break;
					
				case(3):
					Rd &= *Rr;
					break;
					
				case(4):
					Rd |= *Rr;
					break;
					
				case(5):
					Rd ^= *Rr;
					break;
					
				default:
					Rd=0;	
			}
			
			C=(bool)(a>>8) &&(a>=0);
			B=(bool)(a<0);
			Z=!(Rd);
		return Rd;
		}
		unsigned char Excecuit(char IS,unsigned char Rd){
			C=0;
			B=0;
			Z=0;
			int a=0;
			switch(IS)
			{
				case(6):
					Rd =~Rd;
					break;
					
				case(7):
					Rd =~Rd;
					Rd +=1;
					break;
					
				case(8):
					Rd +=1;
					break;
					
				case(9):
					Rd -=1;
					break;
					
				case(10):
					Rd =0xff;
					break;
					
				case(11):
					Rd =0;
					break;
					
				default:
					Rd=0;	
			}
			
			C=(bool)(a>>8) &&(a>=0);
			B=(bool)(a<0);
			Z=!(Rd);
		return Rd;
		}
		
};

class CPU{
	
	
	public:
	int PC,ws;
	char *GP_reg;	
	unsigned char* Rd,*Rr;
	unsigned char *K;
	
	unsigned char SREG;
	ALU alu;
	CPU(int ws,int n){
		alu=ALU();
		SREG=0;
		GP_reg = (char *) calloc((int)(ws/8),n);
		Rd = (unsigned char *)GP_reg;
		Rr = (unsigned char *) (GP_reg+1);
		K=	Rd;
	}
	
	void Run(){
		if(PC<=5)
			*Rd = alu.Excecuit(PC,*Rd,Rr);
		else if(PC<=10)
			*Rd = alu.Excecuit(PC-5,*Rd,K);
		else if(PC<=16)
			*Rd = alu.Excecuit(PC-5,*Rd);
		SREG=(alu.C<<3)|(alu.B<<2)|(alu.Z<<1);
	}
	
};

class MicroController{
	
	unsigned char SRAM[64][3];
	CPU cpu=CPU(8,32);
	int size;
	public:
		MicroController (int a,int b){
			size =a;
		}

	void Decoder(){
		string Mne,l,m;
		int a,b;
		do{
		cout<<"Enter Mnemonics: ";
		cin >> Mne;
		if(Mne =="MOV"){
			cin>>a;
			cin>>b;
			cpu.GP_reg[a]=cpu.GP_reg[b];
			
		}
		if(Mne =="DPTR"){
			cin>>a;
			cpu.K=(unsigned char *)cpu.GP_reg+a;
			
		}
		
		else if(Mne =="LD"){
			cin>>a;
			cin>>b;
			cpu.GP_reg[a]=b;
		}
		
		else if(Mne =="LDA"){
			cin>>a;
			*cpu.Rd=a;
			
		}
		else if(Mne =="LDB"){
			cin>>a;
			*cpu.Rr=a;
		}
		else if(Mne =="SHOW"){
		
			printf("@[%x] %d  [%d]\n",cpu.K,(int)*cpu.K,cpu.SREG);
		}
		else if(Mne =="ADD"){
			cpu.PC=1;
			cpu.Run();
		}
		else if(Mne =="SUB"){
			cpu.PC=2;
			cpu.Run();
		}
		else if(Mne =="AND"){
			cpu.PC=3;
			cpu.Run();
		}
		else if(Mne =="OR"){
			cpu.PC=4;
			cpu.Run();
		}
		else if(Mne =="XOR"){
			cpu.PC=5;
			cpu.Run();
		}
		else if(Mne =="ADDI"){
			cpu.PC=6;
			cpu.Run();
		}
		else if(Mne =="SUBI"){
			cpu.PC=7;
			cpu.Run();
		}
		else if(Mne =="ANDI"){
			cpu.PC=8;
			cpu.Run();
		}
		else if(Mne =="ORI"){
			cpu.PC=9;
			cpu.Run();
		}
		else if(Mne =="XORI"){
			cpu.PC=10;
			cpu.Run();
		}
		else if(Mne =="COM"){
			cpu.PC=11;
			cpu.Run();
		}
		else if(Mne =="NEG"){
			cpu.PC=12;
			cpu.Run();
		}
		else if(Mne =="INC"){
			cpu.PC=13;
			cpu.Run();
		}
		else if(Mne =="DEC"){
			cpu.PC=14;
			cpu.Run();
		}
		else if(Mne =="SER"){
			cpu.PC=15;
			cpu.Run();
		}
		else if(Mne =="CLR"){
			cpu.PC=16;
			cpu.Run();
		}

	} while(Mne!="ALT");
}

};

int main()
{
	MicroController SoC=MicroController (8,32);
	SoC.Decoder();	
}
