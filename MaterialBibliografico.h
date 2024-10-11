#pragma once
#include <iostream>

//Clase MaterialBibliografico 
//Metodos:

//MaterialBibliografico(nombre:String, isbn: String, autor: String): constructor
//virtual ~MaterialBibliografico();
//Getters

class MaterialBibliografico { 

    protected:

        std::string tipo;
        std::string nombre;
        std::string isbn;
        std::string autor;
        std::string estado = "Disponible";
        std::string extra1;
        std::string extra2;
        

    public:
    
        MaterialBibliografico(std::string nombre, std::string isbn, std::string autor); //const
        virtual ~MaterialBibliografico(); //dest
        virtual void mostrarInformacion(); //Muestra la info del objeto.
        void actualizarEstado(); //Actualiza el estado del material cuando está prestado o no.
        
        std::string getTipo();
        std::string getNombre();
        std::string getIsbn();
        std::string getAutor();
        std::string getEstado();
        std::string getExtra1();
        std::string getExtra2();

};