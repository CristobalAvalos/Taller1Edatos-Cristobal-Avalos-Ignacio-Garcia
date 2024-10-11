#pragma once
#include <iostream>
#include "MaterialBibliografico.h"


//**Clase libro que hereda de MaterialBibliografico
//*FechaPublicacion : Fecha de Publi
//*Resumen : Resumen xd

//** Libro(): Constructor de la clase
//**MostrarInformacion: Muestra la informacion que contiene tanto la clase como su padre */

class Libro : public MaterialBibliografico {

    protected:

    std::string fechaPublicacion;
    std::string resumen;

    public:

    Libro(std::string nombre,std::string isbn, std::string autor, std::string fechaPublicacion, std::string resumen);
    ~Libro();
    void mostrarInformacion();

};