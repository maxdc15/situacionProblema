/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Video
*/

#include "Video.h"

// Constructor 
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

double Video::getCalificacion()
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

// Sobrecarga del operador <<
ostream &operator<<(ostream &output, const Video *v)
{
    output << "ID: " << v->ID << endl;
    output << "Nombre: " << v->nombre << endl;
    output << "Genero: " << v->genero << endl;
    output << "Calificacion: " << v->calificacion << endl;
    output << "Duracion: " << v->minutos << endl;
    output << "Fecha de estreno: " << v->fechaEstreno << endl;
    return output;
}
