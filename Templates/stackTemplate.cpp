/**
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

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>
/**
 * @brief se crea un template
 */
template<typename T>
/**
 * @brief se crea la clase Stack
 * 
 */
class Stack {
private:
  /**
   * @brief se declara la variable data que es un vector de tipo T
   * 
   */
  std::vector<T> data_;

public:
  /**
   * @brief funcion que agrega un nuevo elemento al tope del stack
   * 
   * @param value parametro value es de tipo template, es decir puede recibir cualquier tipo de dato
   */
  void push(T value) {
    data_.push_back(value);
  }
  /**
   * @brief funcion que elimina el elemento que se encuentra en el tope 
   */
  T pop() {
    /**
     * @brief Se genera un condicional en dado caso que se vacie el contenedor data_. para que no genere un error
     */
    if (data_.empty()) {
      throw std::out_of_range("Stack is empty");
    }
    /**
     * @brief se le asigna el ultimo elemento de data_. a value
     * 
     */
    T value = data_.back();
    /**
     * @brief Luego se elimina ese valor que se le asigno a value de data_. por medio de un pop_back()
     * 
     */
    data_.pop_back();
    /**
     * @return el valor asignado del que era el ultimo elemento de data_. 
     */
    return value;
  }
  /**
   * @brief Metodo para vaciar la pila
   * 
   */
  void clear() {
    /**
     * @brief elimina todos los elementos del vector data_.
     * 
     */
    data_.clear();
  }
  /**
   * @brief boleano para saber si el vector data_. esta vacio
   * 
   * @return true si se encuentra vacio
   * @return false si cuenta con elementos
   */

  bool empty() const {
    return data_.empty();
  }
  /**
   * @brief Metodo para obtener el tamanio de los elementos almacenados
   * 
   * @return el tamanio del vector
   */
  std::size_t size() const {
    return data_.size();
  }

  /**
   * @brief funcion que se le aplica a cada miembro del vector
   * @param T recibe un objeto tipo T
   * @param func se encarga de realizar la operacion deseada sobre cada elemento
   */
  void foreach(const std::function<void(T&)>& func) {
    std::for_each(data_.begin(), data_.end(), func);
  }
};

int main() {
  /**
   * @brief Valores de la pila 1
   * 
   */
  Stack<int> s;
  s.push(2021);
  s.push(2054);
  s.push(6524);
  /**
   * @brief Valores de la pila 2
   * 
   */
  Stack<char> c;
  c.push('a');
  c.push('b');
  c.push('c');
  c.push('d');


  /**
   * @brief Imprime la el tamanio del stack 1
   * 
   */
  std::cout << "Stack size: " << s.size() << std::endl;
  /**
   * @brief Imprime cada uno de los valores del stack 1
   */
  s.foreach([](int& value) {
    std::cout << "Value: " << value << std::endl;
  });

  /**
   * @brief Se realiza un pop() de los valores del stack 1 mientras no se encuentre vacio
   * 
   */
  try {
    while (!s.empty()) {
      int value = s.pop();
      std::cout << "Popped value: " << value << std::endl;
    }
    /**
     * @brief imprime el tamanio del stack despues del pop(), ademas se coloca un catch en caso de un error que tire la excepcion
     * 
     */
    std::cout << "Stack size: " << s.size() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  /**
   * @brief Empieza la implementacion del Stack<char> c;
   * 
   */
  std::cout<<"Segunda pila: "<<std::endl;
  /**
   * @brief se imprime el tamanio del Stack
   * 
   */
  std::cout << "Stack size: " << c.size() << std::endl;
  /**
   * @brief Se realiza un pop() mientras no se encuentre vacio
   * 
   */
  while (!c.empty()) {
      
      std::cout <<"Valor que se le aplica el pop: " << c.pop() << std::endl;
    }
    //std::cout<<c.pop()<<std::endl;
    /**
     * @brief este pop() generaría el error out of range
    */

  return 0;
}
