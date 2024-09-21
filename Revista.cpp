#include "Revista.h"

Revista::Revista(std::string nombre, std::string isbn, std::string autor, std::string numeroEdicion, std::string mesPublicacion) : MaterialBibliografico(nombre,isbn,autor) {

    this->numeroEdicion=numeroEdicion;
    this->mesPublicacion=mesPublicacion;

}

Revista::~Revista(){

    std::cout<<"Se ha elimnado la revista '"<<this->nombre<<"'"<<std::endl;

}

void Revista::mostrarInformacion(){

    std::cout<<"Estado: "<<this->estado<<"\nNombre: "<<this->nombre<<"\nisbn: "<<this->isbn<<"\nAutor: "<<this->autor<<"\nEdición: "<<this->numeroEdicion<<"\nMes de Publicación: "<<this->mesPublicacion<<std::endl;

}