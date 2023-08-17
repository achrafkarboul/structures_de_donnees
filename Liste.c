#include <stdio.h>
#include <stdlib.h>
typedef struct Element Element;
struct Element {
  int nombre;
  Element* suivant;
};
typedef Element Liste;
// ------------------------------------------------------------------------------------------------
// Fonction : ajout_tete
// role : ajouter un element à la tete de la liste
// ------------------------------------------------------------------------------------------------
void ajout_tete(Liste** liste, int valeur) {
  Element* element = (Element*)calloc(1, sizeof(Element));
  element->suivant = *liste;
  element->nombre = valeur;
  *liste = element;
}
// ------------------------------------------------------------------------------------------------
// Fonction : ajout_queux
// role : ajouter un element à la fin de la liste
// ------------------------------------------------------------------------------------------------
void ajout_queux(Liste** liste, int valeur) {
  Element* element = (Element*)calloc(1, sizeof(Element));
  element->nombre = valeur;

  Liste* temp = *liste;
  while(temp->suivant != NULL) {
    temp = temp->suivant;
  }
  temp->suivant = element;
  element->suivant = NULL;
}
// ------------------------------------------------------------------------------------------------
// Fonction : ajout_queux_recursive
// role : ajouter un element à la tete de la liste d'une manière récursive 
// ------------------------------------------------------------------------------------------------
Liste* ajout_queux_recursive(Liste* liste, int valeur) {
    if (liste->suivant == NULL) {
      Element* element = (Element*)calloc(1, sizeof(Element));
      element->nombre = valeur;
      liste->suivant = element;
      return liste;
    }
    return ajout_queux_recursive(liste->suivant, valeur);
}
// ------------------------------------------------------------------------------------------------
// Fonction : supprimer_tete
// role : supprimer le 1er élement de la liste
// ------------------------------------------------------------------------------------------------
void supprimer_tete(Liste** liste) {
  Liste* temp = *liste;
  *liste = (*liste)->suivant;
  free(temp);
}
// ------------------------------------------------------------------------------------------------
// Fonction : supprimer_queux
// role : supprimer le dernier élement de la liste
// ------------------------------------------------------------------------------------------------
void supprimer_queux(Liste** liste) {
    Liste* temp = *liste;
    while((temp->suivant)->suivant != NULL) {
        temp = temp->suivant;
    }
    free(temp->suivant->suivant);
    temp->suivant = NULL;
}
// ------------------------------------------------------------------------------------------------
// Fonction : afficher_liste
// role : afficher tout les élements de la liste
// ------------------------------------------------------------------------------------------------
void afficher_liste(Liste* liste) {
  if (!liste) {
    puts("");
    return;
  }
  printf(" %d", liste->nombre);
  afficher_liste(liste->suivant);
}
// ------------------------------------------------------------------------------------------------
// Fonction : nombreElement
// role : afficher le nombre d'element de la liste
// ------------------------------------------------------------------------------------------------
int nombreElement(Liste* liste) {
  if (liste == NULL)
    return 0;
  return 1 + nombreElement(liste->suivant);
}

int main(void) {
  Liste* liste = NULL;
  ajout_tete(&liste, 2);
  ajout_tete(&liste, 1);
  ajout_tete(&liste, 0);
  ajout_queux(&liste, 3);
  afficher_liste(liste);
  supprimer_tete(&liste);
  supprimer_queux(&liste);
  afficher_liste(liste);
  printf("Le nombre d'element est %d", nombreElement(liste));
  return 0;
}
