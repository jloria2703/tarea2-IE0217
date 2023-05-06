/**
* @file exceptions.hpp
* @author Jorge Loria (jloria2703)
* @date 2023-05-02
* 
* @copyright 
Licencia MIT

Copyright (c) [2023] Tarea 2 - Grupo 2 - IE 0217 - I Ciclo 2023

Se concede aquí, sin cargo, a cualquier persona que obtenga una copia de este
software y los archivos de documentación asociados (el "Software"), para
utilizar el Software sin restricciones, incluyendo, sin limitación, los
derechos para usar, copiar, modificar, fusionar, publicar, distribuir,
sublicenciar y/o vender copias del Software, y para permitir a las personas a
quienes se les proporcione el Software que lo hagan, sujeto a las siguientes
condiciones:

El aviso de copyright anterior y este aviso de permiso se incluirán en todas
las copias o partes sustanciales del Software.

EL SOFTWARE SE PROPORCIONA "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O
IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A GARANTÍAS DE COMERCIALIZACIÓN,
IDONEIDAD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO LOS
AUTORES O TITULARES DEL COPYRIGHT SERÁN RESPONSABLES POR NINGUNA RECLAMACIÓN,
DAÑO O OTRA RESPONSABILIDAD, YA SEA EN UNA ACCIÓN CONTRACTUAL, AGRAVIO O DE
OTRO MODO, QUE SURJA DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O EL USO U
OTROS ACUERDOS EN EL SOFTWARE.
*/

#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP


#include <exception>

using namespace std;
/**
 * @brief creacion de la clase MyException 
*/
class MyException : public exception {
public:
  const char* what() const throw() {
    return "My custom exception";
  }
};

/**
 * @brief clase para el error
 * 
 */
class Error{
  public:
    /**
     * @brief al ser virtual significa que se puede sobreescribir sobre ella. "f" al ser void no retorna nada.
     * 
     */
    virtual void f(){};
};














#endif /* MY_EXCEPTION_HPP*/