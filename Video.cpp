/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Video
*/

#include "Video.h"

Video::Video(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno)
{
    this->ID = ID;
    this->nombre = nombre;
    this->genero = genero;
    this->calificacion = calificacion;
    this->minutos = minutos;
    this->fechaEstreno = fechaEstreno;
}

string Video::getID()
{
    return ID;
}

string Video::getNombre()
{
    return nombre;
}

string Video::getGenero()
{
    return genero;
}

int Video::getCalificacion()
{
    return calificacion;
}

int Video::getMinutos()
{
    return minutos;
}

string Video::getFechaEstreno()
{
    return fechaEstreno;
}
