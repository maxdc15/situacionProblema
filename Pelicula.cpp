/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Pelicula
*/

#include "Pelicula.h"

Pelicula::Pelicula(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno) : Video(ID, nombre, genero, calificacion, minutos, fechaEstreno)
{

}

void Pelicula::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}

void Pelicula::mostrarDatos()
{
    cout << "Pelicula: " << endl;
    cout << "ID: " << getID() << endl;
    cout << "Nombre: " << getNombre() << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << endl;
    cout << "Duracion: " << getMinutos() << endl;
    cout << "Fecha de estreno: " << getFechaEstreno() << endl;
    cout << endl;
}
