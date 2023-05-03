#Se elimina la biblioteca < algorithim > debido a que la biblioteca < functional> puede abarcar la función foreach. Además aquí hay una pequeña explicación del por qué se emplean las otras librerías:

1. include < iostream > es necesaria para operaciones de entrada y salida.

2. include < vector > se usa cuando se quiere utilizar la clase std::vector.

3. include < stdexcept > se necesita para poder usar la clase std::out_of_range, para así poder tirar una excepción en caso de que se intente realizar la operación pop en una pila que se encuentre vacía.

4. include < functional > es necesaria para definir el tipo de datos de la función que se utiliza en el método "foreach", es decir, std::function < void(T&) >