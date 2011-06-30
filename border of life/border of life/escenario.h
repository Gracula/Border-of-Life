#include<string>
class escenario{
	private:
		char fondo[100];
		char musica[100];
		char script[100];
		int id_escenario;
	public:
		char* getFondo();
		char* getMusica();
		char* getScript();
		int getID();
		void setFondo(char []);
		void setMusica(char []);
		void setScript(char []);
		void setID(int);
};

char* escenario::getFondo(){
	return fondo;
}

char* escenario::getMusica(){
	return musica;
}

char* escenario::getScript(){
	return script;
}

int escenario::getID(){
	return id_escenario;
}

void escenario::setFondo(char nuevo[]){
	strcpy(fondo,nuevo);
}

void escenario::setMusica(char nuevo[]){
	strcpy(musica,nuevo);
}

void escenario::setScript(char nuevo[]){
	strcpy(script,nuevo);
}

void escenario::setID(int id){
	id_escenario=id;
}