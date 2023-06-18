/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de Clase Video con las características que se muestran
*/ //ID,Nombre,Duración,Género,Calificación,Fecha Estreno,ID Episodio,Nombre Episodio,Temporada,Num Episodio

#ifndef VIDEO_H
#define VIDEO_H
#include<string>
#include<iostream>
using namespace std;

class Video // Clase abstracta Video
{
protected: 
    string ID; // Identificador único
    string nombre; // Nombre de la película o serie
    string genero; // Género de la película o serie
    double calificacion; // Calificación de la película o serie
    int minutos; // Duración en minutos de la película o serie
    string fechaEstreno; // Fecha de estreno de la película o serie (DD/MM/AAAA)
public:
    Video(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno); // Constructor con parámetros
    string getID(); 
    string getNombre();
    string getGenero();
    int getCalificacion();
    int getMinutos();
    string getFechaEstreno();
    virtual void setCalificacion(double calificacion) = 0; // Método virtual puro para modificar la calificación de la película o serie
    virtual void mostrarDatos() = 0; // Método virtual puro para mostrar los datos de la película o serie
    friend ostream &operator<<(ostream &output, const Video &v); // Sobrecarga del operador <<
    
};
#endif