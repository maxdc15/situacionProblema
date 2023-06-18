/*
Autor: Maximiliano De La Cruz Lima
Main donde se puede probar la plataforma de streaming
*/

#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
#include "Sistema.h"

int main(int argc, char const *argv[])
{
    // Se crea un objeto de la clase Sistema para modelar la plataforma de streaming
    Sistema netflis;
    netflis.ejecutar();
    return 0;
}

// g++ *.cpp;
// g++ *.cpp; ./a
