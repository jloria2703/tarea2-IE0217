#Instrucciones de ejecución
1. En su consola con coloque el comando "make".
2. Presione la tecla < enter > 
3. El programa compilara y se ejecutará por sí solo.

##Todas las bibliotecas son necesarias, aquí una pequeña explicación de cuando se utilizan en el código:

1. include < iostream > es necesaria para operaciones de entrada y salida.

2. include < vector > se usa cuando se quiere utilizar la clase std::vector.

3. include < stdexcept > se necesita para poder usar la clase std::out_of_range, para así poder tirar una excepción en caso de que se intente realizar la operación pop en una pila que se encuentre vacía.

4. include < algorithm > se ocupa para poder utilizar la función std::for_each, que es usada en el método foreach. Se complementa con < functional >

5. include < functional > es necesaria para definir el tipo de datos de la función que se utiliza en el método "foreach", para ser más específicos sería la parte de código que dice: std::function < void(T&) >



###Métodos no conocidos

``` C++
void foreach(const std::function<void(T&)>& func) {
    std::for_each(data_.begin(), data_.end(), func);
}
s.foreach([](int& value) {
    std::cout << "Value: " << value << std::endl;
  });
```
El método foreach no lo conocía, y la forma en que se representaba en el código me parecía confusa. Investigando comprendí que es una estructura repetitiva, que es utilizada para recorrer colecciones de datos. (en este caso el vector data_.) Tiene la capacidad de poder modificar los elementos de una colección, pero no puede eliminar ni agregar elementos.