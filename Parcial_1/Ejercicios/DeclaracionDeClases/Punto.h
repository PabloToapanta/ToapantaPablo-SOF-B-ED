#ifndef PUNTO_H
#define PUNTO_H

class Punto
{
	private:
		int x;
		int y;
	public:
		//Constructor parametrizado
		Punto(int x_, int y_){
			x=x_;
			y=y_;
		}
		//Constructor sin argumentos
		Punto(){
			x=0;
			y=0;
		}
		//Const significa que el metodo no modifica ningun atributo del objeto.
		int obtenerCoordenadaX() const;
		int obtenerCoordenadaY() const;
		
		void fijarX(int valorX);
		void fijarY(int valorY);
		
		//La implementacion se realiza en el archivo .cpp
		

};

#endif
