class personaje{
	private:
		int id_personaje;
		int tipo_disparo;
		int nivel_ataque;
		int velocidad;
	public:
		int getID();
		int getDisparo();
		int getNivelAtaque();
		int getVelocidad();
		void setID(int);
		void setDisparo(int);
		void setNivelAtaque(int);
		void setVelocidad();
};

int personaje::getID(){
	return id_personaje;
}

int personaje::getDisparo(){
	return tipo_disparo;
}

int personaje::getNivelAtaque(){
	return nivel_ataque;
}

void personaje::setDisparo(int disp){
	tipo_disparo=disp;
}

void personaje::setID(int id){
	id_personaje=id;
}

void personaje::setNivelAtaque(int ataque){
	nivel_ataque=ataque;
}

int personaje::getVelocidad(){
	return velocidad;
}