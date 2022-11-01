#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED


typedef struct maison
{
    int prix;
    int stade;
    char nom[50];
    int nombre_habitant;

}t_maison;


typedef struct chateau_eau
{
    int capacite_totale; //capacite en nombre d'habitant
    int capcite_restante;
    int prix;

} t_eau;

typedef struct centrale_electrique
{
    int capacite_totale; //capacite en nombre d'habitant
    int capcite_restante;
    int prix;
    int position_colonne;
    int position_ligne;

}t_centraleElectrique;

typedef struct jeu
{
    int compteur_habitants;
    int compteur_temps;
    int compteur_monnaie;
    int compteur_capacite_electrique;  //capacite totale en electricite de la ville
    int compteur_capacite_eau;    //capacite totale en eau de la ville
    int nombre_de_chateau_eau;
    int nombre_de_maison;
    int nombre_de_centrale_electrique;
    int capacite_restante_en_electricite;
    t_eau  *tab_chateau_eau;
    t_centraleElectrique  *tab_centrale_electrique;
    t_maison * tab_maison;

} t_jeu;



#endif // GRAPHE_H_INCLUDED

