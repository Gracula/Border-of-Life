class balas{
	private:
		int tipo;
		int hitbox;
		int tama�o;
		int x;
		int y;
		int velocidad;
	public:
		balas(int,int,int,int,int,int);
		balas(balas &);
		int getTipo();
		int getHitbox();
		int getTama�o();
		int getX();
		int getY();
		int getVelocidad();
		void setTipo(int);
		void setHitbox(int);
		void setTama�o(int);
		void setX(int);
		void setY(int);
		void setVelocidad(int);
		~balas();
};

balas::balas(int type,int hit,int tam,int x1,int y1,int vel){
	tipo=type;
	hitbox=hit;
	tama�o=tam;
	x=x1;
	y=y1;
	velocidad=vel;
}

balas::balas(balas &b){
	tipo=b.getTipo();
	hitbox=b.getHitbox();
	tama�o=b.getTama�o();
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

int balas::getTama�o(){
	return tama�o;
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

void balas::setTama�o(int tam){
	tama�o=tam;
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