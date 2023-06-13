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

class Pelicula : public Video
{
public:
    Pelicula(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno);
    void setCalificacion(double calificacion);
    void mostrarDatos();
};

#endif