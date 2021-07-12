#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char nombre[20];
    int infectados;
    int recuperados;
    int muertos;
}ePais;

/**
1. Dada una estructura ePais cuyos campos son id(int), nombre(20 caracteres),
infectados(int), recuperados(int) y muertos(int).
Desarrollar una función llamada actualizarRecuperados que reciba el país y los
recuperados del dia y que acumule estos a los que ya tiene el país. La función no devuelve nada.

2. Crear una función que se llame invertirCadena que reciba una cadena de caracteres como parámetro
y su responsabilidad es invertir los caracteres de la misma. Ejemplo si le pasamos UTN-FRA la deja como ARF-NTU

3. Crear una función que se llame ordenarCaracteres que reciba una cadena de caracteres como parámetro
y su responsabilidad es ordenarlos caracteres de manera ascendente dentro de la cadena. Ejemplo si le pasamos "algoritmo" la deja como "agilmoort"
*/

void actualizarRecuperados(ePais* unPais, int recuperadosDelDia);

void invertirCadena(char cadena[]);

void ordenarCaracteres(char cadena[]);

int main()
{
    ePais pais = {1,"Argentina",500,300,200};
    printf("Antes: %d\n",pais.recuperados);
    actualizarRecuperados(&pais,100);
    printf("Despues: %d\n",pais.recuperados);

    char cadena[20];
    strcpy(cadena,"pruebas");
    ordenarCaracteres(cadena);
    printf("%s\n",cadena);

    invertirCadena("UTN-FRA");
    return 0;
}

void actualizarRecuperados(ePais* unPais, int recuperadosDelDia)
{
    if(unPais!=NULL)
    {
        unPais->recuperados += recuperadosDelDia;
    }
}

void invertirCadena(char cadena[])
{
    char newCadena[50];
    int tam;
    if(cadena!=NULL)
    {
        tam=strlen(cadena);
        strcpy(newCadena,cadena);
        for(int i=0; i<tam; i++)
        {
            for(int j=strlen(cadena)-1; j>=0; j--)
            {
                cadena[i]=newCadena[j];
                j--;
            }
            break;
        }
    }
    printf("%s",cadena);
}

void ordenarCaracteres(char cadena[])
{
    char auxChar;
    int tam;
    if(cadena!=NULL)
    {
        tam=strlen(cadena);
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(cadena[i]>cadena[j])
                {
                    auxChar=cadena[i];
                    cadena[i]=cadena[j];
                    cadena[j]=auxChar;
                }
            }
        }
    }
}
