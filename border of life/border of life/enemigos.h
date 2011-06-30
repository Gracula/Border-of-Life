#include<iostream>
using namespace std;

class enemigos{
	private:
		int x;
		int y;
		int resistencia;
		int vida;
		int tipo;
		int hitbox;
	public:
		enemigos(int,int,int,int,int,int);
		int getX();
		int getY();
		int getResistencia();
		int getVida();
		int getTipo();
		int getHitbox();
		void setX(int);
		void setY(int);
		void setResistencia(int);
		void setVida(int);
		void setTipo(int);
		void setHitbox(int);
};

enemigos::enemigos(int a,int b,int c,int d,int e,int f){
	setX(a);
	setY(b);
	setResistencia(c);
	setVida(d);
	setTipo(e);
	setHitbox(f);
}

int enemigos::getX(){
	return x;
}

int enemigos::getY(){
	return y;
}

int enemigos::getResistencia(){
	return resistencia;
}

int enemigos::getVida(){
	return vida;
}

int enemigos::getTipo(){
	return tipo;
}

void enemigos::setX(int X){
	x=X;
}

void enemigos::setY(int X){
	y=X;
}

void enemigos::setResistencia(int X){
	resistencia=X;
}

void enemigos::setResistencia(int X){
	resistencia=X;
}

void enemigos::setVida(int X){
	vida=X;
}

void enemigos::setTipo(int X){
	tipo=X;
}

int enemigos::getHitbox(){
	return hitbox;
}

void enemigos::setHitbox(int h){
	hitbox=h;
}