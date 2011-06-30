#include "escenario.h"

class partida{
	private:
		int nivel;
		escenario Escenario;
		int dificultad;
	public:
		int getNivel();
		escenario getEscenario();
		int getDificultad();
		void setNivel(int);
		void setEscenario(escenario);
		void setDificultad(int);
};

int partida::getNivel(){
	return nivel;
}

escenario partida::getEscenario(){
	return Escenario;
}

int partida::getDificultad(){
	return dificultad;
}

void partida::setNivel(int niv){
	nivel=niv;
}

void partida::setEscenario(escenario nuevo){
	Escenario.setFondo(nuevo.getFondo());
	Escenario.setID(nuevo.getID());
	Escenario.setMusica(nuevo.getMusica());
	Escenario.setScript(nuevo.getScript());
}