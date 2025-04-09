#include <stdio.h> 
#include <stdlib.h>
#include <stdint.h>



//funcion de ejercicio 12
void rotarIzquierda(int arr[], int n, int rotaciones) {
    int temp[n];

    rotaciones = rotaciones % n;

    int i, j = 0;
    for (i = rotaciones; i < n; i++) {
        temp[j] = arr[i];
        ++j;
    }
    for (i = 0; i < rotaciones; i++) {
        temp[j] = arr[i];
        ++j;
    }

    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
    }
    return;
};


//funcion de ejercicio 13
void tiraDado(int* arr[], int cant_de_tiros){
        
    for (int i = 0; i < cant_de_tiros; i++)
    {
        ++arr[rand()%6] ;
    }
    return;
}


//funciones de ejercicio 14
void ocultar_variable3 (){
    int variable_global2 = 10;
    printf("La variable global es: %d. Y la variable local es: %d.\n", variable_global2, variable_global2);
    return;
}

void ocultar_variable2 (){
    int variable_global2 = 10;
    return;
}

void ocultar_variable (){
    int variable_local = 10;
    return;
}


//funcion de ejercicio 15

int factorial(int num){
    if (num == 0)
    {
        return 1;
    }else{
        return (factorial(num-1)*num);
    }
}



int main() { 

    printf("Hola Orga!\n"); 

/*--------------------------------------------------------------------------*/

    char c = 100;
    short s = -8712;
    int i = 123456;
    long l = 1234567890;
 

    printf("char(%lu): %d \n", sizeof(c),c);
    printf("short(%lu): %d \n", sizeof(s),s);
    printf("int(%lu): %d \n", sizeof(i),i);
    printf("long(%lu): %ld \n", sizeof(l),l);
    printf("\n");


/*--------------------------------------------------------------------------*/



    uint8_t u_byte = 1;
    uint16_t u_dos_bytes = 1;
    uint32_t u_cuatro_bytes = 1;
    uint64_t u_ocho_bytes = 1;

    int8_t byte =1;
    int16_t dos_bytes = 1;
    int32_t cuatro_bytes = 1;
    int64_t ocho_bytes = 1;

    printf("Unsigned byte = %ld \n", sizeof(u_byte));
    printf("Unsigned two bytes = %ld \n", sizeof(u_dos_bytes));
    printf("Unsigned four bytes = %ld \n", sizeof(u_cuatro_bytes));
    printf("Unsigned eight bytes = %ld \n", sizeof(u_ocho_bytes));
    
    printf("byte = %ld \n", sizeof(byte));
    printf("two bytes = %ld \n", sizeof(dos_bytes));
    printf("four bytes = %ld \n", sizeof(cuatro_bytes));
    printf("eight bytes = %ld \n", sizeof(ocho_bytes));
    printf("\n");


/*--------------------------------------------------------------------------*/



    // Ejercicio 5. 
    printf("Ejercicio 5: \n");
    float valor_secreto = 0.1;
    double valor_secretisimo = 0.1;

    printf ("este es el valor secreto -> %f \n", valor_secreto);
    printf ("este es el valor super mega secreto ojito -> %lf \n", valor_secretisimo);

    //ahora casteo:

    valor_secreto = (int) (valor_secreto);
    valor_secretisimo = (int) (valor_secretisimo);

    printf ("este es el valor secreto casteado-> %i \n", valor_secreto);
    printf ("este es el valor super mega secreto casteado -> %i \n", valor_secretisimo);

    //Se rompe porque el casteo implica que aquello que estaba en memoria, se lo interpreta exactamente como un int. Devuelve cualquier otro numero
    //porque aquello que se interpretaba como potencia, mantisa, etc... se lo lee de manera literal como un int. 
    printf("\n");


   /*--------------------------------------------------------------------------*/

    //Ejercicio 6:
    printf("Ejercicio 6: \n");
    int mensaje_secreto[] = {116, 104, 101, 32, 103, 105, 102, 116, 32, 111,
        102, 32, 119, 111, 114, 100, 115, 32, 105, 115, 32, 116, 104, 101, 32,
        103, 105, 102, 116, 32, 111, 102, 32, 100, 101, 99, 101, 112, 116, 105,
        111, 110, 32, 97, 110, 100, 32, 105, 108, 108, 117, 115, 105, 111, 110};
    
    size_t length = sizeof(mensaje_secreto) / sizeof(int);
    char decoded[length];
    
    for (size_t i = 0; i < length; i++) {
        decoded[i] = (char) (mensaje_secreto[i]); // casting de int a char
    }
        
    for (size_t i = 0; i < length; i++) {
        printf("%c", decoded[i]);
    }

    printf("\n");
    printf("\n");


/*--------------------------------------------------------------------------*/


    //Ejercicio 7:

    printf("Ejercicio 7: \n");
    uint32_t a_ = 5;
    uint32_t b_ = 3;
    uint32_t c_ = 2; 
    uint32_t d_ = 1;

    printf("a:%d, b: %d, c: %d, d: %d \n", a_, b_, c_, d_);

    uint32_t res = (a_ + b_ * c_ / d_);
    printf("a+b*c/d: %d \n", res );

    res = a_ % b_;
    printf("a mod b: %d \n", res );

    res = (a_ == b_);
    printf("a == b: %x \n", res );

    res = (a_ != b_);
    printf("a!=b: %x \n", res );
    
    res = (a_ & b_);
    printf("a&b: %x \n", res );

    res = (a_ | b_);
    printf("a|b: %x \n", res );

    res= (~a_);
    printf("~a: %d \n", res );

    res = (a_ && b_);
    printf("a&&b: %d \n", res );

    res = (a_ << 1);
    printf("a<<1: %d \n", res );
    
    res=(a_ >> 1);
    printf("a>>1: %d \n", res );
     
    res = (a_+=b_);
    printf("a+=b: %d \n", res );

    res = (a_-=b_);
    printf("a-=b: %d \n", res );
    
    res = (a_*=b_);
    printf("a*=b: %d \n", res );

    res=(a_%=b_);
    printf("a mod= b: %d \n", res );

    printf("\n");


/*--------------------------------------------------------------------------*/
    //Ejercicio 8:
    printf("Ejercicio 8: \n");
    uint16_t i0 = 1;
    uint16_t i1 = i0++;
    i0 = 1;
    uint16_t i2 = ++i0;
    i0 =1;
    printf("Observemos que si i: %d entonces => i++: %d y ++i: %d. \n", i0, i1, i2);
    printf("\n");
    //Esto se debe a que ++i incrementa y luego retorna. Mientras que i++ retorna y luego incrementa.


    /*--------------------------------------------------------------------------*/

    /*Ejercicio 9*/
    printf("Ejercicio 9: \n");
    uint32_t palabra1 = 0xF0000000; // 0xF0000000 = 1111 0000 0000 0000 0000 0000 0000 0000
    uint32_t palabra2 = 0xA0000000; // 0xA0000000 = 1010 0000 0000 0000 0000 0000 0000 0000
    uint32_t comparador = ((palabra1 & 0xE0000000) == (palabra2 & 0xE0000000));
    
    printf("palabra 1 == palabra 2? -> %d \n" ,comparador);

    palabra2 = 0xF0000000;
    comparador = ((palabra1 & 0xE0000000) == (palabra2 & 0xE0000000));

    printf("palabra 1 == palabra 2? -> %d \n" ,comparador);
    printf("\n");
   
/*--------------------------------------------------------------------------*/

    printf("Ejercicio 10: \n");

    for (int i = 10 ; i > 0; --i) //no cambia nada si uso --i o i--
    {
        printf("i = %d\n",i);
    }
    
    printf("\n");

/*--------------------------------------------------------------------------*/
    printf("Ejercicio 11: \n");

    uint32_t arreglo[5] = {1, 2, 3, 4, 5};
    printf("El array = ");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d ", arreglo[i]);
    }
    printf("ahora es= ");
    uint32_t ultimo = arreglo[0];
    for (size_t i = 0; i < 4; i++)
    {
        arreglo[i] = arreglo[i+1];
        printf(" %d ", arreglo[i]);
    }
    arreglo[4] = ultimo;
    printf(" %d\n ", arreglo[4]);
    printf("\n");

/*--------------------------------------------------------------------------*/
    printf("Ejercicio 12: \n");

    //rotar izquierda -> funcion definida por encima del main.

    uint32_t *arreglo2[5] = {1, 2, 3, 4, 5};
    uint32_t n = 5;
    uint32_t rotaciones = 3;
    rotarIzquierda(arreglo2, 5, rotaciones);
    
    for (uint32_t i = 0; i < n; i++) {
        printf("%d ", arreglo2[i]);
    }
    printf("\n");

    printf("\n");
/*--------------------------------------------------------------------------*/
   
    printf("Ejercicio 13: \n");
    
    //funcion definida por encima del main
   
    int cantidades[6] = {0,0,0,0,0,0};
    tiraDado(cantidades, 60000000);
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", cantidades[i]);
    }

    printf("\n");
    printf("\n");
/*--------------------------------------------------------------------------*/
   
    printf("Ejercicio 14: \n");

    //por encima del main están definidas las funciones.

    int variable_global = 14;

    //printf("la variable global es: %d. Y la variable local es: %d.", variable_global, variable_local);
    // esta expresión devuelve error pues quiero llamar a una variable por fuera de su scope.


    //el siguiente caso intentará imprimir la variable local.
    int variable_global2 = 14;
    printf("La variable global es: %d. Y la variable local es: %d.\n", variable_global2, variable_global2);
    //aquí no me salta error porque interpreta que me estoy refieriendo a la variable global ya que ambas tienen el mismo nombre.


   //el siguiente caso intentará imprimir la variable local. 
    ocultar_variable3();
    //en este caso imprime unicamente la variable local pues en el contexto de ejecución prioriza la variable local. 
    printf("\n");

/*--------------------------------------------------------------------------*/

    printf("Ejercicio 15: \n");

    int fact = 4;
    printf("el factorial de %i es: %i.\n ", fact, factorial(fact));
    printf("\n");

/*--------------------------------------------------------------------------*/

int resultado = 0;
for (int i = 10; i >= 0; i--)
{
    resultado++;
}
printf("%i\n", resultado );


    return 0;

}





