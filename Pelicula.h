/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de Clase Pelicula 
*/ // ID,Nombre Pelicula/Serie,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"
#include<iostream>
#include<string>
using namespace std;

class Pelicula : public Video // Clase Pelicula hereda de la clase Video
{
public:
    Pelicula(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno); // Constructor con parámetros
    void setCalificacion(double calificacion); // Método para modificar la calificación de la película (sobreescribe el método virtual puro de la clase Video)
    void mostrarDatos(); // Método para mostrar los datos de la película (sobreescribe el método virtual puro de la clase Video)
    friend ostream &operator<<(ostream &output, const Pelicula *p); // Sobrecarga del operador <<
};

#endif