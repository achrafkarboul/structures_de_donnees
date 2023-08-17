#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef struct Element Element;
struct Element
{
  char* chaine;
  Element* suivant;
};

typedef struct Pile Pile;
struct Pile
{
  Element* premier;
};

Pile* creer()
{
  Pile* pile = malloc(sizeof(Pile*));

  assert(pile != NULL);

  pile->premier = NULL;
  return pile;
}

void ajout(Pile* pile, char* chaine2)
{
  Element* element = malloc(sizeof(*element));

  assert(element != NULL || pile != NULL);

  element->chaine = malloc((strlen(chaine2) + 1) * sizeof(char));
  strcpy(element->chaine, chaine2);
  element->suivant = pile->premier;
  pile->premier = element;
}

void afficher(Pile* liste)
{
  Element* actuel = liste->premier;

  assert(liste != NULL || actuel != NULL);

    while(actuel != NULL)
    {
      printf("%s -> ", actuel->chaine);
      actuel = actuel->suivant;
    }
  puts("NULL");
}

int main(void)
{
  Pile* mapile = creer();

  ajout(mapile, "dajkbfjkd");
  ajout(mapile, "dajkbfjkd");
  ajout(mapile, "dajkbfjkd");
  afficher(mapile);
  return 0;
}
