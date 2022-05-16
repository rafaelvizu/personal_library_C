#ifndef PERSONAL_LIBRARY_H_INCLUDED
#define PERSONAL_LIBRARY_H_INCLUDED

#include <string.h>
#include <stdio.h>

int CheckNumberCharacters(char str[250], char caracter) {
   /*************************************************************************
    *  Pt-br: Verificar quantas vezes um caracte aparece em uma string      *
    *  En: Check how many characters are in the string                      *
    *************************************************************************/
    int cont = 0;

    for (int i = 0; i < (int)strlen(str); i++)
    {
        if (str[i] == caracter)
        {
            cont++;
        }
    }

    if (cont==1)
    {
        return 1;
    } else {
        return 0;
    }
}



int CheckNumberInSet(char valor[250], char conjunto[250]) {
    /********************************************************
    *   pt-br: Verifica se a string pertence a um conjunto numerico *
    *   En: Checks if the string belongs to a numeric set           *
    *****************************************************************/
    int cont = 0;
    for (int i = 0; i < (int)strlen(valor); i++)
    {
        for (int j = 0; j < (int)strlen(conjunto)-1; j++)
        {
            if (conjunto[j] == valor[i])
            {
                cont++;
            }
        }
        if ((valor[i] == '-' || valor[i] == '.') && conjunto[10] == '-')
        {
            cont++;
        }
    }

    if (cont == (int)strlen(valor))
    {
        return 1;
    } else {
        return 0;
    }
}




int CheckStrValueToNumber(char valor[250]) {
    /*********************************************************
    *   Verifica se a string a um valor numerico             *
    *   En: Checks if the string is a numeric value          *
    **********************************************************/
   int qntMenos, qntPonto;

    qntMenos = CheckNumberCharacters(valor, '-');
    qntPonto = CheckNumberCharacters(valor, '.');

    if (qntMenos <= 1 && qntPonto <= 1)
    {
        if (qntMenos == 1 && valor[0] != '-')
        {
            return 0;
        } else {
            if (CheckNumberInSet(valor, "0123456789-"))
            {
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        return 0;
    }

}



#endif // PERSONAL_LIBRARY_H_INCLUDED
