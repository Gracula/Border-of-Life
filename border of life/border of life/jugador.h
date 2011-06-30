#include<iostream>
using namespace std;

class jugador{
	private:
		int x;
		int y;
		int tipo_disparo;
		char nombre[100];
		int power;
		int bombas;
		int vidas;
	public:
		int getX();
		int getY();
		int getDisparo();
		int getPower();
		int getBombas();
		int getVidas();
		void setX(int);
		void setY(int);
		void setDisparo(int);
		void setPower(int);
		void setBombas(int);
		void setVidas(int);
};

int jugador::getX(){
	return x;
}

int jugador::getY(){
	return y;
}

int jugador::getDisparo (){
	return tipo_disparo;
}

int jugador::getPower (){
	return power;
}

int jugador::getBombas (){
	return bombas ;
}

int jugador::getVidas(){
	return vidas;
}

void jugador::setX (int X){
	x=X;
}

void jugador::setY (int Y){
	y=Y;
}

void jugador::setDisparo (int disparo){
	tipo_disparo=disparo;
}

void jugador::setPower (int pow){
	power=pow;
}

void jugador::setBombas (int bomb){
	bombas=bomb;
}
void jugador::setVidas(int vid){
	vidas=vid;
}