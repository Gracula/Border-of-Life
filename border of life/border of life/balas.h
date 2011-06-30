class balas{
	private:
		int tipo;
		int hitbox;
		int tamaño;
		int x;
		int y;
		int velocidad;
	public:
		balas(int,int,int,int,int,int);
		balas(balas &);
		int getTipo();
		int getHitbox();
		int getTamaño();
		int getX();
		int getY();
		int getVelocidad();
		void setTipo(int);
		void setHitbox(int);
		void setTamaño(int);
		void setX(int);
		void setY(int);
		void setVelocidad(int);
		~balas();
};

balas::balas(int type,int hit,int tam,int x1,int y1,int vel){
	tipo=type;
	hitbox=hit;
	tamaño=tam;
	x=x1;
	y=y1;
	velocidad=vel;
}

balas::balas(balas &b){
	tipo=b.getTipo();
	hitbox=b.getHitbox();
	tamaño=b.getTamaño();
	x=b.getX();
	y=b.getY();
	velocidad=b.getVelocidad();
}

int balas::getTipo(){
	return tipo;
}

int balas::getHitbox(){
	return hitbox;
}

int balas::getTamaño(){
	return tamaño;
}

int balas::getX(){
	return x;
}

int balas::getY(){
	return y;
}

void balas::setTipo(int tip){
	tipo=tip;
}

void balas::setHitbox(int hit){
	hitbox=hit;
}

void balas::setTamaño(int tam){
	tamaño=tam;
}

void balas::setX(int X){
	x=X;
}

void balas::setY(int Y){
	y=Y;
}

int balas::getVelocidad(){
	return velocidad;
}

void balas::setVelocidad(int v){
	velocidad=v;
}