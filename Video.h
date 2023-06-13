/*
Autor: Maximiliano De La Cruz Lima - A01798048
Definición de Clase Video con las características que se muestran
*/

#ifndef VIDEO_H
#define VIDEO_H
#include<string>
using namespace std;

class Video
{
protected:
    string ID;
    string nombre;
    string genero;
    double calificacion;
    int minutos;
    string fechaEstreno;
public:
    Video(string ID, string nombre, string genero, double calificacion, int minutos, string fechaEstreno); // Constructor con parámetros
    string getID();
    string getNombre();
    string getGenero();
    int getCalificacion();
    int getMinutos();
    string getFechaEstreno();
    virtual void setCalificacion(double calificacion) = 0;
    virtual void mostrarDatos() = 0;
    
};
#endif