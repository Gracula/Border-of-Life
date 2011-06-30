#include <iostream>
#include<string>


class perfil{
	private:
		char nombre[100];
		int bgm;
		int se;
		unsigned long int puntuacion;
	public:
		char* getNombre();
		int getBGM();
		int getSE();
		int getPuntuacion();
		void setNombre(char []);
		void setBGM(int);
		void setSE(int);
		void setPuntuacion(int);
};

char* perfil::getNombre(){
	return nombre;
}

int perfil::getBGM(){
	return bgm;
}

int perfil::getSE(){
	return se;
}

int perfil::getPuntuacion(){
	return puntuacion;
}

void perfil::setNombre(char nuevo[]){
	strcpy(nombre,nuevo);
}

void perfil::setBGM(int nuevo){
	bgm=nuevo;
}

void perfil::setSE(int nuevo){
	se=nuevo;
}

void perfil::setPuntuacion(int nuevo){
	puntuacion=nuevo;
}