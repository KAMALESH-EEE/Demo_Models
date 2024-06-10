/*
This code created by KAMALESH R for learning OOPs concepts in C++ implementing working of microController concepts 
  */

#include<iostream>

using namespace std;

class MicroChip{
	
	protected:
	int a,b;

	public:
		int Wordsize;
		int Pins;
		int Cores;
		string Name;
		MicroChip(int ws,int pin,int co,string name){
			Wordsize=ws;
			Pins=pin;
			Cores=co;
			Name=name;
			a=0;
			b=0;		
		}
		MicroChip(int ws,int pin,string name){
			Wordsize=ws;
			Pins=pin;
			Cores=1;
			Name=name;	
			a=0;
			b=0;
		}
		
		void ALU(int IS){
			
			if(IS == 1) a= a+b;
			else if(IS == 2) a= a-b;
			else if(IS == 3) a= a*b;
			else if(IS == 4) a= a/b;
		}
		
		void set_a(int A){
			a=A;
		}
		void set_b(int A){
			b=A;
		}
		int get_data(){
			return a;
		}
};

class MicroController:public MicroChip{
	protected:
	int SRAM;
	int Flash_memory;
	int GPIO;
	
	public:
		MicroController (int ws,int pin,int co,string name,int sr,int FM,int pio):MicroChip(ws,pin,co,name){
			SRAM = sr;
			Flash_memory=FM;
			GPIO=pio;
		}
		
		MicroController (int ws,int pin,string name,int sr,int FM,int pio):MicroChip(ws,pin,name){
			SRAM = sr;
			Flash_memory=FM;
			GPIO=pio;
		}
	
};

class MicroProcessor:public MicroChip{
	protected:
	int GP_reg;
	public:
		MicroProcessor (int ws,int pin,int co,string name,int reg):MicroChip(ws,pin,co,name){
			GP_reg=reg;
		}
		
		MicroProcessor (int ws,int pin,string name,int reg):MicroChip(ws,pin,name){
			GP_reg=reg;
		}
};

int main()
{
	MicroController ic=MicroController (8,40,1,"AVR",2048,32,24);
	
	cout<<ic.Name<<" is "<<ic.Wordsize<<" bit CPU \n";
	
	cout<< "It has "<<ic.Pins<<" Pin\n";
	
	ic.set_a(4);
	ic.set_b(2);
	ic.ALU(1); 		//4+2=6
	ic.set_b(3);
	ic.ALU(2); 		//6-3=3
	ic.set_b(2);
	ic.ALU(3); 		//3*2=6
	ic.set_b(3);
	ic.ALU(4); 		//6/3=2
	cout<<"Result after Execution "<<ic.get_data()<<endl;
	return 0;
}
