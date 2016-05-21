
/* el bitmask se usa para representar los numeros binarios como un arreglo de booleanos, con las manipulaciones de bits podemos chequear
si un bit esta prendido (&), prender un bit (|), invertirlo (^), etc. Bitmask tambien pueden representar estados usando un arreglo
podemos chequear si tenemos algo de ese arreglo, por ejemplo si hago un arreglo de llaves 1 2 3 4 5 y, tengo la llave 1 y 3 entonces,
puedo guardar ese estado en el numero 20 ya que su numero binario correspondiente es 10100.*/

int array[] = {1,2,3,4,5};

void Bitmask(int n){
  int mask = 1<<n; //numero de elementos en el arreglo, 1<<n es igual a 2^n
  
  for(int i=0; i<mask; ++i){
    for(int j=0; j<n; ++j){
      if((1<<j)&i){
        //hacer algo, esto da una permutacion del arreglo
        //1<<j mueve el 1 j espacios por ejemplo 1<<j & i cuando j = 0,i = 4,
        //4 en binario es 100 y 1<<0 es 001 ya que el bit permanece en la posicion 0
        //entones la operacion seria  
        //                            100
        //                               &
        //                            001
        //                            ---
        //                            000
        //por lo que la condicion seria falsa
      }
    }
  }

}
