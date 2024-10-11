#include "Revista.h"

Revista::Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroEdicion, std::string mesPublicacion) : MaterialBibliografico(nombre,isbn,autor) {


    tipo = "Revista";
    this->numeroEdicion=numeroEdicion;
    this->mesPublicacion=mesPublicacion;

    extra1 = numeroEdicion;
    extra2 = mesPublicacion;

}

Revista::~Revista(){

    std::cout<<"Se ha elimnado la revista '"<<this->nombre<<"'"<<std::endl;

}

void Revista::mostrarInformacion(){

    std::cout<<"Estado: "<<this->estado<<"\nNombre: "<<this->nombre<<"\nisbn: "<<this->isbn<<"\nAutor: "<<this->autor<<"\nEdicion: "<<this->numeroEdicion<<"\nMes de Publicacion: "<<this->mesPublicacion<<std::endl;

}