#include <stdio.h>

int streq(char s1[], char s2[]){
    int i = 0;
    while (s1[i] != 0) {
        if (s1[i] != s2[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}


void echanger(char tableau[], int a, int b)
{
    char temp = tableau[a];
    tableau[a] = tableau[b];
    tableau[b] = temp;
}

void quickSort(char tableau[], int debut, int fin)
{
    int gauche = debut-1;
    int droite = fin+1;
    const char pivot = tableau[debut];
    if(debut >= fin)
        return;
    while(1)
    {
        do droite--; while(tableau[droite] > pivot);
        do gauche++; while(tableau[gauche] < pivot);
        if(gauche < droite)
            echanger(tableau, gauche, droite);
        else break;
    }
    quickSort(tableau, debut, droite);
    quickSort(tableau, droite+1, fin);
}

