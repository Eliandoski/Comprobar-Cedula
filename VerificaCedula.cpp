// Estudiante: Cifuentes González Elian Alejandro
// Fecha: 30/07/2024
// Tema: Algoritmo de módulo 10
// Programa para verificar el último dígito de una cédula ecuatoriana

#include <iostream>
using namespace std;

// Función que verifica si la cédula es correcta
bool CedulaCorrecta(int cedula[], int total)
{
    int SumaPar = 0, SumaImpar = 0;
    for (int k = 0; k < total - 1; k++)
    {
        // Multiplicar las posiciones pares * 2
        int num = 0;
        if (k % 2 == 0)
        {
            num = cedula[k] * 2; 
            if (num >= 9) // Si el resultado es >=9, se resta 9
                num = num - 9;
            SumaPar += num;
        }
        else
        { // Se suman las posiciones impares
            SumaImpar += cedula[k];
        }
    } // Fin for
    int Suma = SumaPar + SumaImpar;
    // Aplicamos módulo 10
    int resto = Suma % 10;
    int digitoVer = 10 - resto;
    if (digitoVer == 10)
        digitoVer = 0;

    // Validamos si el dígito coincide con el último número de la serie
    if (digitoVer == cedula[total - 1])
        return true;
    else
        return false;
}

int main()
{
    int cedula[] = {0, 8, 5, 0, 7, 0, 3, 4, 9, 7};
    int total = sizeof(cedula) / sizeof(cedula[0]);

    if (CedulaCorrecta(cedula, total))
        cout << endl << "La cédula es correcta";
    else
        cout << endl << "La cédula No es correcta";

    return 0;
}