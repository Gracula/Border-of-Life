#pragma comment( lib, "openGL32.lib" )  // Estas directivas del preprocesador
#pragma comment( lib, "glu32.lib" )		// le dicen a el enlazador (linker o 
										// linkador o ...) que incluya estas
										// librerias. Esto se puede hacer en
										// la configuracion del proyecto en el
										// Visual C++ pero esto me parece mas 
										// claro.


#include <stdio.h>
#include <windows.h>    // Fichero de inclusion para programas Windows

#include <GL/gl.h>		// Los ficheros de inclusion de OpenGL.
#include <GL/glu.h>		// Estrictamente solo es necesario el primero.
						// El segundo es de funciones utiles que se podrian
						// hacer de otra manera. No nos vamos a complicar la 
						// vida y la usaremos.

HINSTANCE IdAplicacion; // Para guardar el identificador del programa
HWND IdVentana;  // Para guardar el identificador de la ventana

HDC	DevContex;	// Device Context para conectar la ventana con OpenGL.
HGLRC OGLrc;	// Render Context para la ventana OpenGL.

int AnchoVentana = 800;	  // Lo que dice el nombre de la variable
int AltoVentana = 600;	  // Lo que dice el nombre de la variable

//--------------------------------------------------------------
// Funcion para pintar algo y que se repite continuamente. Se suele 
// llamar bucle de juego o principal.
void Pinta()
{
	// Borro el buffer de atras (BackBuffer), donde voy a pintar:
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 

	// Le digo a OpenGL que voy a pintar de este color, rojo:
	glColor3f(1,0,0);
	// Le digo a OpenGL que voy a pintar y con triangulos:
	glBegin(GL_TRIANGLES); 
	// Le digo a OpenGL el primer vertice de mi triangulo:
	glVertex3f(0,350, 0);	
	// El segundo vertice de mi triangulo:
	glVertex3f(600,350 , 0);	
	// El tercer vertice de mi triangulo:
	glVertex3f(300, 0, 0);
	glEnd();		
 
	// Con esta fucion cambio el grosor de las lineas
	// para que se vea mejor:
	glLineWidth(5); 
	// Le digo a OpenGL que voy a pintar de este color, azul:
	glColor3f(0,0,1);
	// Le digo a OpenGL que voy a pintar y con lineas:
	glBegin(GL_LINES); 
	// Linea del primer vertice al segundo:
	glVertex3f(0, 350, 0);	
	glVertex3f(600, 350, 0);	
	// Cambio de color para probar, ahora verde:
	glColor3f(0,1,0);
	// Linea del segundo vertice al tercero:
	glVertex3f(600, 350, 0);	
	glVertex3f(300, 0, 0);
	// Cambio de color de nuevo, ahora una mezcla que da amarillo:
	glColor3f(1,1,0);
	// Linea del tercer vertice al primero de nuevo:
	glVertex3f(300, 0, 0);
	glVertex3f(0, 350, 0);	
	glEnd();		

	// Ahora voy a marcar el centro
	// con un punto gordo para que se vea bien:
	glPointSize(15);
	// Y de color blanco:
    glColor3f(1,1,1);
    // Le digo a OpenGL que voy a pintar y con puntos:
	glBegin(GL_POINTS); 
	glVertex3f(300, 175, 0);	
    glEnd();

	// Cambio los bufferes de modo que presento lo que he dibujado en pantalla:
	SwapBuffers(DevContex);

}
//--------------------------------------------------------------
// Funcion para inicializar OpenGL.

void IniciaGL()
{
	// Definimos una estructura de tipo PIXELFORMATDESCRIPTOR para definir
	// las caracteristicas graficas que queremos usar (dentro de las que nos
	// permite el OpenGL de nuestra tarjeta de video) 
 	static PIXELFORMATDESCRIPTOR pfd =
	{ 				
        sizeof(PIXELFORMATDESCRIPTOR),	// Tama�o de este descriptor
        1,								// N�mero de versi�n
        PFD_DRAW_TO_WINDOW |			// El formato debe soportar ventana
        PFD_SUPPORT_OPENGL |			// El formato debe soportar OpenGL
        PFD_DOUBLEBUFFER |				// Debe soportar Doble Buffer
        PFD_TYPE_RGBA,					// Tambi�n debe soportar RGBA
        32,								// Bits por pixels seleccionados
        0,0,0,0,0,0,					// Bits de color ignorados
        0,								// Sin buffer alpha
        0,								// Shift bit ignorado
        0,								// Buffer de acumulaci�n ignorado
        0,0,0,0,						// Bits de acumulaci�n ignorados
        32,								// Z-Buffer de 32 bits
        0,								// Sin buffer de pincel (Stencil)
        0,								// Sin buffer auxiliar
        PFD_MAIN_PLANE,					// Layer de dibujo principal
        0,								// Reservado
        0,0,0,							// Layers de m�scara ignorados
	}; 	

	// Estas funciones son las que hacen que la ventana acepte el modo grafico que 
	// queremos dado el descriptor de pixel anterior. (en el que uno de los parametros
	// es que funcione con OpenGL).

	DevContex=GetDC(IdVentana);	  // Obtengo el "device context" de la ventana.
	int PixF=ChoosePixelFormat(DevContex,&pfd);	// Busco un indice de una conbinacion
												// que coincida con mis especificaciones
	SetPixelFormat(DevContex,PixF,&pfd);	// Pongo la ventana en el formato que quiero.
	// Dos funciones de OpenGL por fin (aunque sean especificas de windows).
	OGLrc=wglCreateContext(DevContex);	// Indico a OpenGL que la ventana esta disponible para el.
	wglMakeCurrent(DevContex,OGLrc);	// Le digo a OpenGL que nuestra ventana es donde tiene 
										// que dibujar a partir de ahora.
	// A partir de ahora podemos considerar OpenGL inicializado. 
	// Aun nos queda decirle los parametros del modo en que dibujar, aunque eso se puede,
	// y de hecho se hace continuamente, cambiar durante el programa.
	// Ahora pondremos algunos parametro puramente de OpenGL de inicio.
	glClearDepth(1.0f);			// Profundidad del buffer de profundidad. Hace que lo que esta 
								// mas cerca se vea (dibuje) encima de lo que esta mas lejos.
	glDepthFunc(GL_LEQUAL);		// Comparacion del buffer de profundidad.  
	glEnable(GL_DEPTH_TEST);	// Habilita test de profundidad. A partir de ahora, lo que 
								// esta mas cerca se pinta encima.
	glClearColor(0,0,0,1.0f);	// Color del fondo. Color con el que se borra la pantalla, o la
								// ventana donde pintamos. Cuando usemos la funcion glClear.
	glShadeModel(GL_SMOOTH);    // Renderizado suave. Cuanta mejor calidad mas lento. Nosotros
								// tenemos un ordenador reciente(+ o -) y queremos que se vea bien.
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);   // Calidad buena de perspectiva.
	
	//Definimos un rectangulo (programacion windows)
	RECT rect; 
	// Extraemos el area cliente de nuestra ventana en rect.
	GetClientRect(IdVentana, &rect); 
	// Usamos rect (el area cliente o espacio util dentro de los bordes de nuestra ventana)
	// para definir los limites del espacio que va a usar OpenGL para dibujar (viewport).
	// asi ajustamos nuestra ventana y OpenGL.
	glViewport(rect.left,rect.top,rect.right,rect.bottom);  
							// Le dice a OpenGL el tama�o en el que va a pintar en pixels.
							// Coincidira, en principio, con el tama�o de nuestra ventana y
							// empezando por 0,0 (la esquina de nuestra ventana).


	// Decimos a OpenGL que el tipo de perspectiva que usamos es ortogonal, y que
	// las coordenadas a usar seran en el eje x de 0 al ancho del area cliente de la
	// ventana y en el eje y de 0 al alto del area cliente.
	// El eje de coordenadas sera la esquina superior izquierda del area cliente de la
	// ventana. La profundidad visible sera entra -1 y 1 (si ponemos 0 como profundidad
	// se veran nuestros dibujos, vamos a usar solo 2 dimensiones).
	glOrtho(0,rect.right,rect.bottom,0,-1,1); 
	
	// Definimos una cadena de caracteres para poner en el titulo de nuestra ventana
	// el tama�o del area cliente (a mi me gusta saber el tama�o de mi ventana de dibujo)
	char cad[50]; // 50 seran suficientes caracteres.
	// Relleno mi cadena con lo que voy a poner en la ventana.
	sprintf(cad,"USW %i x %i",rect.right,rect.bottom);
	// Modifico el titulo de mi ventana.
	SetWindowTextA(IdVentana,cad);



	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);	// Borramos la ventana con el color antes establecido
														// (en realidad solo el backbuffer (la pantalla oculta
														// donde en realidad estamos pintando)
														// y borramos tambien el buffer de profundidad
	SwapBuffers(DevContex);		// Le digo a nuestro espacio de dibujo que cambie "muy rapido" el buffer de 
								// dibujo por el de visualizacion y viceversa (suichear en Espanglish)






} // Fin IniciaGL


//------------------------------------------------------------------									  
// Funcion para controlar lo que ocurre en la ventana segun los eventos
// que vienen de Windows. Mas tarde se asocia a la ventana que crearemos.
// De momento solo interceptamos la tecla ESC para poder salir del 
// programa cuando queramos y el evento de destruccion de ventana con el
// que terminamos la aplicacion
LRESULT FAR PASCAL ProcesaMensajes(HWND Ventana, UINT Mensaje,
     						WPARAM wParam, LPARAM lParam)
{




	switch(Mensaje) // Seg�n el mensaje recibido
	{
	case WM_KEYDOWN: // Caso de mensaje de pulsaci�n de una tecla
		switch(wParam) // y segun el contenido de la variable wParam 
		{
		case VK_ESCAPE: // ESC causa la salida del programa
			// Funcion para enviar mensaje de cerrado a la ventana
			// y despues de la aplicacion
			PostMessage(Ventana, WM_CLOSE, 0, 0); 
			break;
		} 
		break;
	case WM_DESTROY:	// Mensaje de destrucci�n de la ventana (provocado por
						// nosotros al pulsar ESC o cerrar la ventana.
		PostQuitMessage(0); // Funcion para salir del programa
		break;
	} 
	// Efectuar el proceso por defecto del mensaje (si viene cualquier mensaje
	// que no hemos usado, querremos que haga lo que suele hacer)
	return DefWindowProc(Ventana, Mensaje, wParam, lParam);
} // fin ProcesaMansajes


//------------------------------------------------------------------
// Funcion para crear la ventana de nuestro programa, que asociaremos
// al OpenGL para pintar en ella
void CreaVentana(int nCmdShow)
{
	WNDCLASSEX ClaseVentana; // Declaramos un tipo de ventana, el nuestro.

	
    ZeroMemory(&ClaseVentana, sizeof(WNDCLASSEX));

    ClaseVentana.cbSize = sizeof(WNDCLASSEX);

	//Definimos nuestro tipo de ventana...
	ClaseVentana.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; // Se redibujara si 
		// cambia el tama�o de la ventana horizontal y verticalmente, y un solo
		// DC (device context) para cada ventana (para cuando empezemos con OpenGL)
	ClaseVentana.lpfnWndProc = ProcesaMensajes;	 //La definimos antes para contolar
		// los mansajes como los del teclado 
	ClaseVentana.cbClsExtra = 0; //Sin memoria extra para la clase
	ClaseVentana.cbWndExtra = 0; //Sin memoria extra para la ventana
	ClaseVentana.hInstance = IdAplicacion; // Identificador del programa para asociar
		// esta ventana con este programa.
	ClaseVentana.hIcon = NULL; // De momento pasamos de icono
	ClaseVentana.hCursor = LoadCursor(NULL, IDC_ARROW); // Flecha normal de raton
	//ClaseVentana.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // Por ahora lo ponemos blanco
	ClaseVentana.lpszMenuName = NULL; // Pasamos de menu
	ClaseVentana.lpszClassName = L"BorderOfLife"; // Nombre de la clase (la "L" antes de la cadena es
												// por que solo admite cadenas de caracteres 
												// unicode -LPCWSTR o TCHAR- y con la "L" se convierte).

	RegisterClassEx(&ClaseVentana); // Registramos nuestro tipo de ventana

	IdVentana = CreateWindowEx( // Funcion que crea la ventana. Guardamos el identificativo.
			NULL,	// estilo extendido de ventana
			L"BorderOfLife",		// Nombre de la clase puesto antes (la "L" antes para convertir a UNICODE)
			L"Border Of life",    // Titulo que aparecera en la ventana.
			WS_EX_TOPMOST | WS_POPUP,	// Parametros de como sera la ventana
														// se pueden combinar varios. 
			0,       // Posicion Horizontal. 
			0,       // Posicion Vertical. 
			AnchoVentana,       // Ancho de la ventana. 
			AltoVentana,		// Alto de la ventana. 
			(HWND) NULL,		// No depende de otra ventana.
			(HMENU) NULL,       // No le damos un menu diferente al de la clase (que es ninguno).
			IdAplicacion,       // Identificador del programa al que pertenece la ventana. Al
								// empezar lo guardamos en una variable para usarlo despues.
			(LPVOID) NULL  );   // Puntero a "no se que" datos (pasamos del tema, es para 
								// aplicaciones MIDI).

	DEVMODE dv;

	EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dv);
	SetWindowLong(IdVentana,GWL_STYLE,WS_POPUP);
	SetWindowPos(	IdVentana,HWND_TOP, 
		0, 0,
		dv.dmPelsWidth, dv.dmPelsHeight, 
		SWP_FRAMECHANGED  );


	dv.dmPelsWidth=800;
	dv.dmPelsHeight=600;
	dv.dmBitsPerPel=16;
	dv.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;
	ChangeDisplaySettings(&dv,CDS_FULLSCREEN);
	

	ShowWindow(IdVentana, nCmdShow); // Mostramos nuestra ventana.
	SetWindowPos(IdVentana,HWND_TOP, 0,0,800,600,SWP_FRAMECHANGED);
	UpdateWindow(IdVentana);  // La actualizo para que muestre lo que tenga que mostrar (ahora nada).
} // Fin CreaVentana


//------------------------------------------------------------------
// Funcion principal de un programa Windows (como main en C normal, aqui WinMain)
// el prorama empieza a ejecutarse a partir de esta funcion.
int PASCAL WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpszCmdLine, int nCmdShow) 
{ 
	UNREFERENCED_PARAMETER(lpszCmdLine);  // Para que no moleste al compilar, no lo usamos.
	IdAplicacion = hInstance;   // Guardo el identificador del programa, luego lo usamos.
	
	CreaVentana(nCmdShow); // Funcion que crea la ventana. Definida mas arriba.
	IniciaGL(); // Funcion para inicializar OpenGL. Definida mas arriba.

	

	// Este es el bucle habitual de windows que se esta ejecutando continuamente hasta que recibe 
	// el mensaje de acabar (ya lo hemos preparado en la funcion "ProcesaMensajes" asociada a 
	// la ventana, tambien asociada a este programa atraves de su identificativo).
	MSG Mensaje; // Varible para contener los mensajes que van llegando.
	while(TRUE) // Se ejecuta continuamente.
		{		
		Pinta(); // Funcion que pinta algo y se repite continuamente al estar aqui.
			
		if(PeekMessage(&Mensaje, NULL, 0, 0, PM_NOREMOVE))	// Exploramos la cola de mensajes.
			{// proces�ndolos adecuadamente
			if(!GetMessage(&Mensaje, NULL, 0, 0)) return (int)Mensaje.wParam; // En este caso terminamos.
			TranslateMessage(&Mensaje);
			DispatchMessage(&Mensaje);
			}
		else WaitMessage();	// en caso contrario esperamos un mensaje
		}

} // fin WinMain
//------------------------------------------------------------------