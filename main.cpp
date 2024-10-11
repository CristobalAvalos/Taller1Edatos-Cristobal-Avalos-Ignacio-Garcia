#include <iostream>
#include <fstream>
#include <string>
#include "MaterialBibliografico.h"
#include "Libro.h"
#include "Usuario.h"
#include "Revista.h"

using namespace std;
//** ListarMaterial(Lista[]: MaterialBibliografico) : tipo void, muestra la informacion de la biblioteca, todos los libros y revistas */
void listarMaterial(MaterialBibliografico* lista[]){

    for(int i = 0;i<100;i++){

       if(lista[i]!=nullptr){lista[i]->mostrarInformacion();}

    }
}

//** LimpiarMemoria(Lista1:MaterialBibliografico*, Lista2:Usuario*): Limpia la memoria al finalizar el programa o al asignar ciertos datos, etc. para manejo de punteros */
void limpiarMemoria(MaterialBibliografico* lista[], Usuario* lista2[]){

    for(int i =0;i<100;i++){

        if(lista[i] != nullptr){delete lista[i];}
        if(lista2[i] != nullptr){delete lista2[i];}

    }

}
//**agregarMaterial(nombre: string, isbn: string, autor: string, extra1: string, extra2: string, lor: string, lista[]: MaterialBibliografico*):void, Sirve para crear los objetos
//del material bibliografico 
//*Parametros:
//extra1: Depende de si es libro o revista
//extra2: Depende si es libro o revista
//Lista: La lista donde se agrega el nuevo objeto. */

void agregarMaterial(string nombre,string isbn,string autor,string extra1,string extra2,int lor, MaterialBibliografico* lista[]){

    MaterialBibliografico* material;

    if(lor==1){

        material = new Libro(nombre,isbn,autor,extra1,extra2);

    } else {

        material = new Revista(nombre,isbn,autor,extra1,extra2);

    }

    for(int i = 0;i<100;i++){

        if (lista[i]==nullptr){

            lista[i]=material;
            return;

        }


    }

}

//**buscarMaterial(info:String,lista): Void, Sirve para el menu, buscar un material en especifico, mostrar su info y mostrar que no existe en caso de que sea asi.*/

void buscarMaterial(string info, MaterialBibliografico* lista[]){


    MaterialBibliografico* material;
    bool existe = false;
    for(int i=0;i<100;i++){

        material = lista[i];
        
        if (material != nullptr){
        
            if (material->getNombre() == info || material->getAutor() == info){
        
                material->mostrarInformacion();
                existe = true;
            }
        }
    }

    if (existe == false){
    
        cout<< "No existe en el sistema."<<endl;
    }
}

//**crearUsuario(nombre:string, id:string, lista[]:Usuario*): Void, metodo para crear las instancias de Usuarios, comprobando si existe o no, agregandolo a la lista de usuarios. */

void crearUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;
    for (int i = 0;i<100;i++){

        if (lista[i]==nullptr){

            usuario = new Usuario(nombre,id);
            
            lista[i]=usuario;

            cout<<"Creado con exito."<<endl;

            return;

        }else if (lista[i]->getNombre() == nombre && lista[i]->getId() == id){ 

            cout<<"No se puede crear, ya existe. "<<endl;
            return;
        }
    }

}
//**datosUsuario(nombre: string, id: string, lista[]:Usuario*): Void, metodo para mostrar los datos del usuario con sus articulos en propiedad, en caso de no existir tambien da aviso. */

void datosUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;


    for (int i=0;i<100;i++){
        

        usuario = lista[i];


        if (usuario != nullptr){
            if (usuario->getNombre() == nombre && usuario->getId() == id){
                
                usuario = lista[i];
                cout<<"El usuario es: "<<usuario->getNombre()<<" De ID: "<<usuario->getId()<<"\nArtículos en propiedad: \n"<<endl;

                usuario->mostrarMaterialesPrestados();
                return;
            
            }
        }
    }
    
    if (usuario == nullptr){
    
        cout<<"No existe. "<<endl;
    }

}

//**buscarUsuario(nombre: string, id: string, lista[]:Usuario*): Usuario*, metodo para buscar un usuario en la lista de este, devuelve la instancia para poder ser trabajada. */

Usuario* buscarUsuario(string nombre, string id, Usuario* lista[]){

    Usuario* usuario;


    for (int i=0;i<100;i++){
    

        usuario = lista[i];

        if (usuario != nullptr){

            if (usuario->getNombre() == nombre && usuario->getId() == id){
               
                return usuario;

            }
            
        }
    }
    return nullptr;
}

//**encontrarMaterial(info:string, lista[]: MaterialBibliografico*): MaterialBibliografico*. Metodo para buscar un material en la lista de este, devuelve la instancia para poder ser trabajada. */

MaterialBibliografico* encontrarMaterial(string info, MaterialBibliografico*lista[]){

    MaterialBibliografico* material;
    
    for(int i=0;i<100;i++){

        material = lista[i];
        
        if (material != nullptr){
        
            if (material->getNombre() == info || material->getAutor() == info){
        
                return material;

            }
        }
    }

    return nullptr;

}
//**asignarMaterial(titulo:string, usuario:Usuario*, lista[]:MaterialBibliografico*): void, Metodo para asignar un materialBibliografico a un usuario en concreto, cambiando el estado del 
//material y la lista del usuario, comprobando si el material esta disponible o existe. */
void asignarMaterial(string titulo, Usuario* usuario, MaterialBibliografico* lista[]){

    MaterialBibliografico* material = encontrarMaterial(titulo,lista);

    if(material==nullptr){
        
        cout<<"No existe el material"<<endl;
        return;
    }

    else if(material->getEstado()=="Disponible"){

        usuario->prestarMaterial(material);

    } else {

        cout<<"Material no disponible para prestamo"<<endl;

    }

}

//**devolverMaterial(titulo:String, usuario:Usuario*, lista[]:MaterialBibliografico*):void, Metodo para que un usuario pueda devolver un material en especifico, comprobando si el material existe. */

void devolverMaterial(string titulo, Usuario* usuario, MaterialBibliografico* lista[]){

    MaterialBibliografico* material = encontrarMaterial(titulo,lista);

    if(material==nullptr){

        cout<<"No existe el material"<<endl;
        return;
    }else {
    
        usuario->devolverMaterial(material);
    }

}

//**contarEspacios(lista[]: MaterialBibliografico*, maximo: int): int, Se usa para contar los espacios usados en la lista de materialBibliografico para poder ser guardados en un archivo*/

int contarEspacios(MaterialBibliografico* lista[],int maximo){

    int contador = 0;

    for(int i = 0;i<maximo;i++){

        if(lista[i] != nullptr){

            contador++;

        }

    }

    return contador;

}

//**contarEspacios(lista[]: Usuario*): int, Se usa para contar los espacios usados en la lista de Usuario para poder ser guardados en un archivo*/

int contarEspacios(Usuario* lista[]){

    int contador = 0;

    for(int i = 0;i<100;i++){

        if(lista[i] != nullptr){

            contador++;

        }

    }

    return contador;

}

//**guardarDatos(biblioteca[]: MaterialBibliografico* ,usuarios[]: Usuario*): void, utilizado para guardar los datos de los usuarios y el material en el archivo respaldo.txt donde primero guarda
// los archivos de biblioteca y despues guarda los del usuario. */

void guardarDatos(MaterialBibliografico* biblioteca[], Usuario* usuarios[]){

    fstream archivo("respaldo.txt");

    int material = contarEspacios(biblioteca,100);
    int cantUsuarios = contarEspacios(usuarios);

    archivo<<material<<endl;

    for(int i = 0; i<100;i++){

        if(biblioteca[i]!=nullptr){

        
            archivo<<biblioteca[i]->getTipo()<<endl;
            archivo<<biblioteca[i]->getNombre()<<endl;
            archivo<<biblioteca[i]->getIsbn()<<endl;
            archivo<<biblioteca[i]->getAutor()<<endl;
            archivo<<biblioteca[i]->getExtra1()<<endl;
            archivo<<biblioteca[i]->getExtra2()<<endl;

            

        }

    }

    archivo<<cantUsuarios<<endl;

    for(int i = 0; i<100;i++){

        if(usuarios[i]!=nullptr){

            archivo<<usuarios[i]->getNombre()<<endl;
            archivo<<usuarios[i]->getId()<<endl;

            int prestados = contarEspacios(usuarios[i]->getMaterial(),5);

            archivo<<prestados<<endl;

            MaterialBibliografico** materialPrestado; 
            materialPrestado = usuarios[i]->getMaterial(); 

            for(int j = 0;j<5;j++){

                if(materialPrestado[j]!=nullptr){

                    archivo<<materialPrestado[j]->getTipo()<<endl;
                    archivo<<materialPrestado[j]->getNombre()<<endl;
                    archivo<<materialPrestado[j]->getIsbn()<<endl;
                    archivo<<materialPrestado[j]->getAutor()<<endl;
                    archivo<<materialPrestado[j]->getExtra1()<<endl;
                    archivo<<materialPrestado[j]->getExtra2()<<endl;


                }

            }

        }

    }

    archivo.close();

}

//**cargarDatos(biblioteca: MaterialBibliografico**, Usuario** usuarios): void, Metodo utilizado para cargar los datos del archivo respaldo.txt en el sistema, creando el material bibliografico y
// usuarios correspondientes */

void cargarDatos(MaterialBibliografico** biblioteca, Usuario** usuarios){

    limpiarMemoria(biblioteca, usuarios);


    ifstream archivo("respaldo.txt");

    string linea;

    getline(archivo,linea);


    int cantMaterial = stoi(linea);

    for(int i = 0; i<cantMaterial; i++){

        getline(archivo,linea);

        string tipo = linea;

        getline(archivo,linea);

        string nombre = linea;

        getline(archivo,linea);

        string isbn = linea;

        getline(archivo,linea);

        string autor = linea;

        getline(archivo,linea);

        string extra1 = linea;

        getline(archivo,linea);

        string extra2 = linea;

        int lor = 0;

        if(tipo=="Libro"){lor++;}

        agregarMaterial(nombre, isbn, autor, extra1, extra2, lor,biblioteca);

    }

    getline(archivo,linea);

    int cantUsuarios = stoi(linea);

    for(int i = 0; i<cantUsuarios;i++){

        getline(archivo,linea);

        string nombre = linea;

        getline(archivo,linea);
        
        string id = linea;

        getline(archivo,linea);

        crearUsuario(nombre,id,usuarios);

        Usuario* usuario = buscarUsuario(nombre,id,usuarios);

        cantMaterial = stoi(linea);

        for(int j = 0; j<cantMaterial;j++){

            getline(archivo,linea);

            string tipo = linea;

            getline(archivo,linea);

            string nombreMaterial = linea;

            getline(archivo,linea);

            string isbn = linea;

            getline(archivo,linea);

            string autor = linea;

            getline(archivo,linea);

            string extra1 = linea;

            getline(archivo,linea);

            string extra2 = linea;

            asignarMaterial(nombreMaterial, usuario, biblioteca);

        }



    }

}

int main(){

    MaterialBibliografico* biblioteca[100] = {nullptr};
    Usuario* usuarios[100] = {nullptr};

    int opcion = 10;
    int lor;
    int opcionInterior = 10;
    cout<<biblioteca[0]<<endl;

    //menu:
    
    while(opcion!=0){

        cout<<"Introduce la opcion: \n1.- Agregar material a la biblioteca\n2.- Mostrar informacion\n3.- Buscar Material\n4.- Prestar y Devolver el material\n5.-Gestion de Usuarios\n6.-Guardar estado de biblioteca y Usuarios "<<endl;

        cin>>opcion;
        
        if(opcion==1){

            cout<<"¿Que desea agregar=\n1.-Libro\n2.-Revista"<<endl;
            
            cin>>lor;

            cin.ignore();

            if(lor==1){

                cout<<"Ingrese el nombre"<<endl;

                string nombre;

                getline(cin,nombre);

                cout<<"Ingrese el isbn"<<endl;

                string isbn;

                getline(cin,isbn);

                cout<<"Ingrese el autor"<<endl;

                string autor;

                getline(cin,autor);

                cout<<"Ingrese la fecha de publicación"<<endl;

                string fechaDePublicacion;

                getline(cin,fechaDePublicacion);

                cout<<"Ingrese el resumen"<<endl;

                string resumen;

                getline(cin,resumen);

                agregarMaterial(nombre,isbn,autor,fechaDePublicacion,resumen,lor, biblioteca);


            } else if(lor==2){

                cout<<"Ingrese el nombre"<<endl;

                string nombre;

                getline(cin,nombre);

                cout<<"Ingrese el isbn"<<endl;

                string isbn;

                getline(cin,isbn);

                cout<<"Ingrese el autor"<<endl;

                string autor;

                getline(cin,autor);

                cout<<"Ingrese el numero de edición"<<endl;

                string numeroEdicion;

                getline(cin,numeroEdicion);

                cout<<"Ingrese el mes de publicacion"<<endl;

                string mesPublicacion;

                getline(cin,mesPublicacion);

                agregarMaterial(nombre,isbn,autor,numeroEdicion,mesPublicacion,lor, biblioteca);

            }
            
            cout<<"Agregado con exito"<<endl;

        } else if(opcion==2){

            cin.ignore();

            listarMaterial(biblioteca);

        } else if(opcion==3){

            cout<<"¿Como quieres buscar?\n1.-Por Titulo\n2.-Por Autor"<<endl;
            cin>>opcionInterior;
          
            cin.ignore();

                if(opcionInterior==1){

                    string titulo;
                    cout<<"Ingrese el Titulo: "<<endl;
                    getline(cin,titulo);

                    buscarMaterial(titulo,biblioteca);

                }

                else if(opcionInterior==2){
                
                
                    string autor;
                    cout<<"Ingrese el nombre del Autor: "<<endl;
                    getline(cin,autor);

                    buscarMaterial(autor,biblioteca);
                }

        } else if(opcion==4){
        
        
            cout<<"Ingresa tu nombre: "<<endl;
            string nombre;
            cin.ignore();
            getline(cin,nombre);
            cout<<"Ingresa tu id: "<<endl;
            string id;
            getline(cin,id);

            if (buscarUsuario(nombre,id,usuarios) == nullptr){
            
                cout<<"El usuario no existe, registrelo por favor. "<<endl;

            }else{
            
                cout<<"Desea pedir prestado (1) o devolver (2)"<<endl;

                Usuario* usuario = buscarUsuario(nombre,id,usuarios);
                int opcionPrestamo = 0;
                cin>>opcionPrestamo;
                
                cin.ignore();


                if (opcionPrestamo == 1){
                
                    cout<<"Ingrese el titulo de lo que desea."<<endl;
                    string titulo;

                    getline(cin,titulo);
                    
                    asignarMaterial(titulo,usuario,biblioteca);


                }else if (opcionPrestamo == 2){
                
                    cout<<"Ingrese el titulo del titulo que desea devolver."<<endl;
                    string titulo;

                    getline(cin,titulo);

                    devolverMaterial(titulo,usuario,biblioteca);



                }


            }
        
        }else if(opcion==5){
    
            cout<<"Que deseas, Crear usuario (1), Buscar un usuario (2),  eliminar un usuario (3)"<<endl;
            int opcionUsuario = 10;
            cin.ignore();
            cin>>opcionUsuario;

            if (opcionUsuario == 1) {
        
                cout<<"Ingresa tu nombre: "<<endl;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                cout<<"ID: "<<endl;
                string id;
                getline(cin,id);
                crearUsuario(nombre,id,usuarios);

            }else if (opcionUsuario == 2){
            
            
                cout<<"Ingresa el nombre"<<endl;
                string nombre;
                cin.ignore();
                getline(cin,nombre);
                cout<<"ID del usuario que deseas buscar: "<<endl;
                string id;
                getline(cin,id);

                datosUsuario(nombre,id,usuarios);
            }
        } else if (opcion==6){

            int opcion6 = 0;
            cin.ignore();

            cout<<"¿Que desea?\n1.-Guardar el estado de la biblioteca\n2.-Cargar el estado de la biblioteca"<<endl;
            
            cin>>opcion6;

            if(opcion6==1){

                guardarDatos(biblioteca, usuarios);

            } else {
                
                cargarDatos(biblioteca,usuarios);

            }


        }
    
    }

    limpiarMemoria(biblioteca, usuarios);

    return 0;
}
