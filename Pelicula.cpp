/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de métodos de la clase Pelicula
*/

#include "Pelicula.h"

// Constructor
Pelicula::Pelicula(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno) : Video(ID, nombre, genero, calificacion, minutos, fechaEstreno)
{

}

// Método para modificar la calificación de la película (sobreescribe el método virtual puro de la clase Video)
void Pelicula::setCalificacion(double calificacion)
{
    this->calificacion = calificacion;
}

// Método para mostrar los datos de la película (sobreescribe el método virtual puro de la clase Video)
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

// Sobrecarga del operador << para mostrar los datos de la película 
ostream &operator<<(ostream &output, const Pelicula *p)
{
    output << "ID: " << p->ID << endl;
    output << "Nombre: " << p->nombre << endl;
    output << "Genero: " << p->genero << endl;
    output << "Calificacion: " << p->calificacion << endl;
    output << "Duracion: " << p->minutos << endl;
    output << "Fecha de estreno: " << p->fechaEstreno << endl;
    return output;
}
