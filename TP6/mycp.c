#include <stdio.h>  // Seulement pour afficher les messages d'erreur.
#include <stdlib.h> // Pour utiliser la fonction exit.
#include "myio.h"

int copy(MY_FILE* fsrc, MY_FILE* fdst);
int streq(char* s1, char* s2);
void error(char* s);

/* _______________________________________________________________ */
int main(int argc, char* argv[]) {
    MY_FILE* fsrc;
    MY_FILE* fdst;
    if (argc != 3 && (argc != 4 || !streq(argv[1], "--append")))
        error("Utilisation: ./mycp [--append] SOURCE DEST");
    if (argc == 3) {
        if ((fsrc = myfopen(argv[1], "r")) == MY_NULL)
            error("Erreur d'ouverture du fichier source.");
        if ((fdst = myfopen(argv[2], "w")) == MY_NULL)
            error("Erreur d'ouverture du fichier destination.");
    } else {
        if ((fsrc = myfopen(argv[2], "r")) == MY_NULL)
            error("Erreur d'ouverture du fichier source.");
        if ((fdst = myfopen(argv[3], "a")) == MY_NULL)
            error("Erreur d'ouverture du fichier destination.");
    }
    copy(fsrc, fdst);
    if (myfclose(fsrc) != 0)
        error("Erreur de fermeture du fichier source.");
    if (myfclose(fdst) != 0)
        error("Erreur de fermeture du fichier destination.");
    return 0;
}

/* _______________________________________________________________ */
int copy(MY_FILE* fsrc, MY_FILE* fdst) {
    int c, d;
    while ((c = myfgetc(fsrc)) != MY_EOF) {
        d = myfputc(c, fdst);
        if (d == MY_EOF)
            error("Erreur d'écriture dans le fichier destination.");
        if (d != c)
            error("Erreur: myfputc retourne une valeur inattendue.");
    }
    return 0;
}

/* _______________________________________________________________ */
int streq(char* s1, char* s2) {
    while (*s1 == *s2 && *s1 != '\0')
        ++s1, ++s2;
    return (*s1 == *s2);
}

/* _______________________________________________________________ */
void error(char* s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}
