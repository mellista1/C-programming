#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "Solucion-guia.h"

# define NAME_LEN 50




/*----------------------------------------------------------------------- */
//Ejercicio 1

typedef struct
{
  char * nombre;
  int vida;
  double ataque;
  double defensa;
} monstruo_t;



void ejercicio_1(){
  monstruo_t array_ejer_1[3] = {
    {"Tito", 100, 100, 100},
    {"Tita", 1000, 2000, 3000},
    {"Pepita", 1000000, 2000000, 3000000}
  };


  for (int i = 0; i < 3; i++) {
    printf("%s, %d, %lf, %lf\n", 
        array_ejer_1[i].nombre, 
        array_ejer_1[i].vida, 
        array_ejer_1[i].ataque, 
        array_ejer_1[i].defensa);
  }

}


/*----------------------------------------------------------------------- */
//Funcion del Ejercicio 2
monstruo_t evolution (monstruo_t monstruo){
  monstruo_t nuevo_monstruo;
  nuevo_monstruo.ataque= monstruo.ataque+10;
  nuevo_monstruo.defensa = monstruo.defensa+10;
  nuevo_monstruo.nombre = monstruo.nombre;
  nuevo_monstruo.vida = monstruo.vida;
  return nuevo_monstruo;
  
}

void ejercicio_2(){
  monstruo_t monstruo_ejer_2;

monstruo_ejer_2.nombre = "Ejercicio 2";
monstruo_ejer_2.vida = 100;
monstruo_ejer_2. ataque = 30;
monstruo_ejer_2.defensa = 40;

printf("Nombre: %s, Vida: %d, Ataque: %lf, Defensa: %lf\n", 
  monstruo_ejer_2.nombre, monstruo_ejer_2.vida, monstruo_ejer_2.ataque, monstruo_ejer_2.defensa );

printf("Monstruo Evolucionado -> Nombre: %s, Vida: %d, Ataque: %lf, Defensa: %lf\n", 
  evolution(monstruo_ejer_2).nombre, 
  evolution(monstruo_ejer_2).vida, 
  evolution(monstruo_ejer_2).ataque, 
  evolution(monstruo_ejer_2).defensa );

  return;
}

/*----------------------------------------------------------------------- */

//Respuestas Ejercicio 3

/*La diferencia entre x y p es que x es el nombre que le ponemos a la dirección 0x100.
  En la dirección 0x100 de memoria es donde se guarda el valor 42. Por otro lado p es el nombre
  que le ponemos a la dirección 0x130. Cuando utilizo p* es porque estoy indicando que en la posición 0x130
  voy a guardar una posición de memoria. 

  La diferencia entre x y &x es que x me devuelve lo que se guarda en la posicion de memoria 0x100, pero
  &x hace una referencia a la dirección de x, que es justamente 0x100. 


  La diferencia entre p y *p es la que nombre recién: p guarda directamente un valor puede ser de cualquier tipo: char, int, float, etc..)
  pero *p significa que voy a guardar en p una dirección de memoria del estilo 0x100, 0x465, etc. Al escribir p*, la compu
  entiende que no tiene que leer literalmente el numero 0x100, sino que se trata de una dirección de memoria a la cual después va a tener que viajar. 

  &x -> imprime la dirección de memoria de x.
  x -> imprime 42
  &p -> imprime la dirección de memoria de p.
  p -> imprimer la dirección de memoria que guarda p.
  *p -> imprime el 42.


  */


/*----------------------------------------------------------------------- */
// Funcion a printear del Ejercicio 4.

void ejercicio_4(){
  int x = 42;
  int *p = &x;
  printf("Direccion de x: %p Valor: %d\n", (void*) &x, x);
  printf("Direccion de p: %p Valor: %p\n", (void*) &p, (void*) p);
  printf("Valor de lo que apunta p: %d\n", *p);
}

/*----------------------------------------------------------------------- */

//Respuestas Ejercicio 5.

//Según la imagen en 0xF0 tengo el valor 255. EN 0xF6 está eñ valor -128.  
//Entonces cada dirección apunta a valores diferentes, por ende a cad puntero se le asigna un tipo
//diferente. 


/*----------------------------------------------------------------------- */

//Funcion de Ejercicio 6.
//La idea es que quiero imprimir una dirección de memoria válida. En el snippet 12 usan direcciones que no se sabe si se pueden acceder
// Entonces literalmente armo un array, el cual reserva
//memoria y ahora sí podría imprimir la direcciones y valores dependiendo de como quiera.
void ejercicio_6(){
  uint8_t memoria[1] = {-42};           
  uint8_t *x = (uint8_t*) &memoria[0]; //acá lo voy a leer sin signo al valor -42
  int8_t *y = &memoria[0];  //acá lo voy a leer con signo
  
  printf("Dir de x: %p Valor: %d\n", (void*) x, *x);  
  printf("Dir de y: %p Valor: %d\n", (void*) y, *y);
}


/*----------------------------------------------------------------------- */
  //Ejercicio 7
  //En ese caso no se podrían intercambiar los valores porque se pasan los argumentos por copia.
  //Por ende haríamos el swap entre las copias hechas, pero al volver de la función, las variables originales permanecerían iguales.




/*----------------------------------------------------------------------- */

  //Ejercicio 8
  void ejercicio_8(){
    char *str1 = "Hola";
    char str2[] = "Hola";
    printf("%s\n", str1);
    printf("%s\n", str2);
    return;
  }

  //Según str2, estamos definiendo un array de chars. Estos arrays representan un string. Los puedo definir
  // de dos maneras diferentes equivalentes.

  //char s[] = "Hola!";        -> string literal
  //char u[] = {'H', 'o', 'l', 'a', '!', '\0'};     -> char literals

  // Ambas formas se comportan iguales. Lo importante es que, como vimos antes, los arrays se comportan como un puntero
  //pero el array tiene un tamaño fijo y no le puedo reasignar otra dirección de memoria.


  //Por otro lado, según str1, estoy definiendo un puntero que apunta al comienzo del string. Es decir, en str1 voy a tener 
  //guardado la posición de memoria del primer char del strig. La forma de descubrir donde termina la cadena de chars es buscando "\0".

  //La diferencia radica que 
    // -> puedo modificar str1 para que apunte a otra dirección de memoria cuando uno desee, mientras str2 se mantendrá apuntando al array de manera fija. 
    // -> char *a = "texto";  // Literal en memoria de solo lectura
   //     char b[] = "texto"; // Array en memoria del stack, modificable. Es decir, tengo permiso de escritura en el array.

  //Observación: Amabos punteros IMPRIMEN LO MISMO -> Esto es porque imprimimos el valor apuntado en ambos casos. 

/*----------------------------------------------------------------------- */
//Ejercicio 9:

  void ejercicio_9(char* str){
    

    uint8_t i= 0;
    while (str[i] != '\0')
    {
      if ((str[i] > 96) && (str[i] < 123))
      {
        str[i] = str[i] - 32;
      }
      i++;
    }

    printf("%s\n", str);
    
  
  }


/*----------------------------------------------------------------------- */
  //Ejercicio 10

 /* strcpy - copia cadenas

  char *strcpy(char *dest, const char *src); 
    -> strcpy copia una cadena de caracteres desde src hacia dest, incluyendo el carácter nulo '\0' al final.
    -> No verifica el tamaño del destino. Si dest no tiene suficiente espacio, puede causar un desbordamiento.
  
  EJEMPLO CON restrict:
   void copiar(int *restrict a, int *restrict b, size_t n) {
    for (size_t i = 0; i < n; i++)
     a[i] = b[i];
    }
  Le dice al compilador: “Este puntero es el único que va a acceder a la región de memoria a la que apunta (durante su uso).”
*/


/*strcat – Concatenar cadenas

char *strcat(char *dest, const char *src);

    -> Agrega el contenido de src al final de dest.
    -> Modifica dest.
    -> dest debe tener suficiente espacio para contener ambas cadenas.
    -> Incluye el '\0' del final de src.
*/



/*strlen – Obtener la longitud de una cadena

size_t strlen(const char *str);
  
    -> Devuelve la cantidad de caracteres en la cadena, sin contar el '\0' final.
*/



/*strcmp – Comparar dos cadenas

int strcmp(const char *s1, const char *s2);

    -> Compara dos strings carácter por carácter.

    -> Devuelve:

        -> 0 si son iguales

        -> Valor negativo si s1 < s2

        -> Valor positivo si s1 > s2

(Usa el valor ASCII para comparar.)
*/



/*strlen – Obtener la longitud de una cadena

  size_t strlen(const char *str);

    -> Devuelve la cantidad de caracteres en la cadena, sin contar el '\0' final.
*/






/*----------------------------------------------------------------------- */

//Ejercicio 11

uint16_t *secuencia(uint16_t n){
  uint16_t arr[n];
  for(uint16_t i = 0; i < n; i++)
  arr[i] = i;
  return arr;
  }


void ejercicio_11(){

  uint16_t *arr = secuencia(10);
  printf("%d\n", arr[0]);
  return;

}


/*Este codigo devuelve violación de segmento. El problema, básicamente radica en que la variable arr es una variable automática, y por
lo tanto, se libera al salir de la función. Esto significa que la dirección de memoria a la que
apunta arr ya no es válida al salir de la función. Por lo tanto, el puntero arr en la función main
apunta a una dirección de memoria inválida. Esto es un error común en C, y es importante tener
cuidado al usar variables automáticas y punteros. Para evitar este error, podemos usar memoria
dinámica para reservar el array.
*/



/*----------------------------------------------------------------------- */
//Ejercicio 12


typedef struct persona_s {
  char nombre[NAME_LEN+1];
  int edad;
  struct persona_s* hijo;
  } persona_t;


persona_t * crearPersona(char* nombre, uint16_t edad){
  
  persona_t * nuevo_ptr = malloc(sizeof(persona_t)); //acá abusé con sizeof ajajaja pero porque aun no vimos alineacion de estructuras.
  nuevo_ptr->edad = edad;
  nuevo_ptr->hijo = NULL;

  for (size_t i = 0; i < sizeof(nombre); i++)
  {
    nuevo_ptr->nombre[i] = nombre[i]; //NOTAR: Con malloc ya reservé el espacio en memoria para guardar el nombre. Por ende la copia la hago justamente en ese espacio de memoria. 
  }

  return nuevo_ptr;

}



/*----------------------------------------------------------------------- */

//Ejercicio 13

void eliminarPersona(persona_t* ptr_a_eliminar){
  free(ptr_a_eliminar);
}


/*----------------------------------------------------------------------- */

//Ejercicio 14

//copio y pego las implementaciones de la catedra

typedef enum e_type {
  TypeFAT32 = 0,
  TypeEXT4 = 1,
  TypeNTFS = 2
  } type_t;



  typedef struct node {
    void* data;
    struct node* next;
    } node_t;

    typedef struct list {
    type_t type;
    uint8_t size;
    node_t* first;
    } list_t;


    list_t* listNew(type_t t);
    void listAddFirst(list_t* l, void* data); //copia el dato
    void* listGet(list_t* l, uint8_t i); //se asume: i < l->size
    void* listRemove(list_t* l, uint8_t i); //se asume: i < l->size
    void listDelete(list_t* l);


list_t* listNew(type_t t) {
  list_t* l = malloc(sizeof(list_t));
  l->type = t; // l->type es equivalente a (*l).type
  l->size = 0;
  l->first = NULL;
  return l;
}


//funcionces de la catedra

void listAddFirst(list_t* l, void* data) {
  node_t* n = malloc(sizeof(node_t));
  switch(l->type) {
    case TypeFAT32:
      n->data = (void*) copy_fat32((fat32_t*) data);
      break;
    case TypeEXT4:
      n->data = (void*) copy_ext4((ext4_t*) data);
      break;
    case TypeNTFS:
      n->data = (void*) copy_ntfs((ntfs_t*) data);
      break;
  }

  n->next = l->first;
  l->first = n;
  l->size++;
}


  //se asume: i < l->size
  void* listGet(list_t* l, uint8_t i){
    node_t* n = l->first;
    for(uint8_t j = 0; j < i; j++){
        n = n->next;
    }
      
      return n->data;
  }


  //se asume: i < l->size
  void* listRemove(list_t* l, uint8_t i){
    
    node_t* tmp = NULL;
    
    void* data = NULL;
    
    if(i == 0){
      data = l->first->data;
      tmp = l->first;
      l->first = l->first->next;
    
    }else{
      
      node_t* n = l->first;
      
      for(uint8_t j = 0; j < i - 1; j++){
        n = n->next;
      }
      
      data = n->next->data;
      tmp = n->next;
      n->next = n->next->next;
    }

    free(tmp);
    l->size--;
    return data;
  }


  void listDelete(list_t* l){
    node_t* n = l->first;
    while(n){
      node_t* tmp = n;
      n = n->next;
      switch(l->type) {
        case TypeFAT32:
          rm_fat32((fat32_t*) tmp->data);
          break;
        case TypeEXT4:
          rm_ext4((ext4_t*) tmp->data);
          break;
        case TypeNTFS:
          rm_ntfs((ntfs_t*) tmp->data);
          break;
      }
      free(tmp);
    }
    free(l);
}




//IMPORTANTE: ARMAR EL ARCHIVO .H -> EN EL VAN TODAS LAS DECLARACIONES!!!! -> SIN ESE ARCHIVO SE ROMPE TODO


//Las funciones de tipo new crean archivos, y las funciones de tipo copy copian archivos y las
//funciones de tipo rm eliminan archivos.

fat32_t* new_fat32(){
  fat32_t* x;
  return x;
}


fat32_t* copy_fat32(fat32_t* file){
  file = malloc(sizeof(fat32_t));
  return file;
}

ext4_t* copy_ext4(ext4_t* file){
  file = malloc(sizeof(ext4_t));
  return file;
}

ntfs_t* copy_ntfs(ntfs_t* file){
  file = malloc(sizeof(ntfs_t));
  return file;
}

void rm_fat32(fat32_t* file){
  free(file);
}

void rm_ext4(ext4_t* file){
  free(file);
}

void rm_ntfs(ntfs_t* file){
  free(file);
}




/*----------------------------------------------------------------------- */
//Ejercicio 15

//asumo que me pasan dos nodos válidos.
void intercambiarNodos (list_t* lista, node_t* nodo_a, node_t* nodo_b){
    node_t * ptr_previous_a = lista->first;
    node_t * ptr_previous_b = lista->first;
    
    //contemplo casos bases
    if (lista->first == NULL)
    {
      printf("La lista está vacía!!");
    }else{
      if (ptr_previous_a->next == NULL)
      {
        printf("La lista tiene un solo elemento!");
      }else
      {
        //obtengo el previous de node_a
        while (ptr_previous_a->next != nodo_a)
        {
          ptr_previous_a = ptr_previous_a->next;
        }
        //obtengo el previous de node_b

        while (ptr_previous_b->next != nodo_b)
        {
          ptr_previous_b = ptr_previous_b->next;
        }
        
        //ahora puedo realizar el intercambio.

        ptr_previous_a->next = nodo_b;
        ptr_previous_b->next = nodo_a;

        //swap
        node_t* auxiliar = nodo_a->next;
        nodo_a->next = nodo_b->next;
        nodo_b->next = auxiliar; 

      }
      
      
    }

    return;
    
}

/*----------------------------------------------------------------------- */

//ejercicio 18

void allocateArray(int **arr, int size, int value) {
  *arr = (int*)malloc(size * sizeof(int));
  if(*arr != NULL) {
  for(int i=0; i<size; i++) {
  (*arr)[i] = value;
  }
  }
  }

/*----------------------------------------------------------------------- */

//ejercicio 19


void ejercicio_19(){
  int matrix[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };
    // p apunta al int en la fila 0, columna 0
    int *p = &matrix[0][0];
    // ¿qué es reshape?
    int (*reshape)[2] = (int (*)[2]) p;
    printf("%d\n", p[3]); // Qué imprime esta lı́nea?
    printf("%d\n", reshape[1][1]); // Qué imprime esta lı́nea?
    return 0;
}

//Respuestas => 
  /*
    El reshape nos permite reinterpretar ese puntero p (que apunta al primer int del array) como un puntero a un arreglo de 2 enteros, o sea, como si estuvieras diciendo:

    “A partir de esta dirección, quiero ver la memoria como una secuencia de arrays de 2 enteros.”
  
    ¿Qué significa int (*)[2]?

    int (*)[2] es un puntero a un array de 2 enteros.

    No es un array de punteros, es un puntero a un array.

    Entonces, si hacés:

  reshape[0][0] → accede al 1
  reshape[0][1] → accede al 2
  reshape[1][0] → accede al 3
  reshape[1][1] → accede al 4
  reshape[2][0] → accede al 5

   ¿Qué estás logrando con esto?

  Estás reinterpretando la memoria de una matriz 3x4 como si fuera una secuencia de arrays de 2 elementos. Como tenés 12 elementos, estás formando una matriz virtual 6x2:

  reshape[0] → {1, 2}
  reshape[1] → {3, 4}
  reshape[2] → {5, 6}
  reshape[3] → {7, 8}
  reshape[4] → {9, 10}
  reshape[5] → {11, 12}

  */





/*----------------------------------------------------------------------- */

  //ejercicio 20

  /*

  ¿Qué hace esta línea?   ca (*p)[VIDEO_COLS] = (ca (*)[VIDEO_COLS]) VIDEO;
    
    Esa línea convierte un puntero a memoria cruda (VIDEO) en un puntero a una matriz de estructuras ca de tamaño [VIDEO_COLS].

    Desglosemos:

    VIDEO es un puntero a la dirección base del buffer de video, o sea, una zona de memoria donde cada "posición" representa un carácter en pantalla (con su color/atributo).

    Cada posición de pantalla tiene 2 bytes: un carácter (c) y un atributo (a).

    ca es una estructura de 2 bytes que representa eso.

    El casteo (ca(*)[VIDEO_COLS]) le dice al compilador:

        “A partir de esta dirección de memoria, quiero tratarla como una matriz de VIDEO_FILS filas, y cada fila tiene VIDEO_COLS columnas (o sea, columnas de estructuras ca).”

    Entonces, p[f][c] accede a la posición f, c del buffer de video.
  

¿Por qué funciona esto?

p[f][c].c = ' ';

✅ Respuesta:

Porque p[f][c] accede a una estructura ca, y ca tiene este campo:

uint8_t c;  // caracter

Entonces, p[f][c].c = ' '; guarda el carácter ' ' (espacio en blanco) en la posición de pantalla (fila f, columna c).

Es decir, estás limpiando la pantalla: rellenando cada celda del buffer de video con un espacio (' ') y, en la línea siguiente, con un atributo:

p[f][c].a = 0x10;  // probablemente color de fondo

Esto se traduce en que toda la pantalla se llena con espacios en blanco, con un determinado color (según lo que represente el atributo 0x10).



  */



/*----------------------------------------------------------------------- */
/*----------------------------------------------------------------------- */
/*----------------------------------------------------------------------- */






int main(){

/*----------------------------------------------------------------------- */
printf("Ejercicio 1\n");

ejercicio_1();

printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 2\n");

ejercicio_2();

printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 4\n");

ejercicio_4();

printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 6\n");

ejercicio_6();

printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 8\n");

ejercicio_8();

printf("\n");

/*----------------------------------------------------------------------- */


printf("Ejercicio 9\n");

char str_ejer_9[] = "AaaaBBBccCcC";
ejercicio_9(str_ejer_9);

printf("\n");


/*----------------------------------------------------------------------- */


printf("Ejercicio 12\n");

char nombre_ejer_12[] = "Melanie";
persona_t* melanie = crearPersona(nombre_ejer_12, 24 );

printf("Nombre: %s. Edad: %d.\n", melanie->nombre, melanie->edad);

free(melanie);

printf("\n");


/*----------------------------------------------------------------------- */
printf("Ejercicio 18\n");

int *vector = NULL;
allocateArray(&vector,5,45);
for(int i = 0; i < 5; i++)
printf("%d\n", vector[i]);
free(vector);

printf("\n");
/*----------------------------------------------------------------------- */


printf("Snippet 42:\n");

int matrix[3][4] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12}
  };
  // Todos estos prints imprimen 7
  printf("matrix[1][2]: %d\n", matrix[1][2]);
  printf("matrix[1][2]: %d\n", *(*(matrix + 1) + 2));
  printf("matrix[1][2]: %d\n", *((int*) matrix + 4*1 + 2));
  matrix[0][3] = 100; // asigna 100 a la fila 0, columna 3
  printf("matrix[0][3]: %d\n", matrix[0][3]); // imprime 100



printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 19\n");


ejercicio_19();


printf("\n");
/*----------------------------------------------------------------------- */
printf("Ejercicio 21\n");



printf("\n");
/*----------------------------------------------------------------------- */

  return 0;
}
