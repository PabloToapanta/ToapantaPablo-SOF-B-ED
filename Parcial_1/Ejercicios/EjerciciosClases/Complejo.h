#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
using namespace std;
class Complejo
{
	public:
	double parteReal;
	double parteImaginaria;
	
	Complejo& establecer(double real,double imaginaria){
		parteReal=real;
		parteImaginaria=imaginaria;
		return *this;
	}
	
	void imprimir(){
		if(parteImaginaria>0){
		cout<<"\n"<<parteReal<<" + "<<parteImaginaria<<" j"<<endl;	
		}else{
			cout<<"\n"<<parteReal<<" - "<<-parteImaginaria<<" j"<<endl;
		}
		
		
	}
	//Aniadir complejo a otro
	Complejo* aniadir(const Complejo& ASumar){
		parteReal+=ASumar.parteReal;
		parteImaginaria+=ASumar.parteImaginaria;
		return this;
	}
	
	Complejo* suma(const Complejo & ASumar){
		parteReal+=ASumar.parteReal;
		parteImaginaria+=ASumar.parteImaginaria;
		return this;
	}
	Complejo* resta(const Complejo & ASumar){
		parteReal-=ASumar.parteReal;
		parteImaginaria-=ASumar.parteImaginaria;
		return this;
	}
	
	Complejo* multiplicacionCompleja(const Complejo & ASumar){
		double pReal;
		double pImaginaria;
		pReal=(parteReal*ASumar.parteReal)-(parteImaginaria*ASumar.parteImaginaria);
		pImaginaria=(parteReal*ASumar.parteImaginaria)+(parteImaginaria*ASumar.parteReal);
		parteReal=pReal;
		parteImaginaria=pImaginaria;
		return this;
	}
	
	Complejo* conjugada(){
		
		parteImaginaria=-parteImaginaria;
		return this;
	}
};

#endif
