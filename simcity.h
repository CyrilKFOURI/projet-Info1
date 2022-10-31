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
    t_eau  *tab_chateau_eau;
    t_centraleElectrique  *tab_centrale_electrique;
    t_maison * tab_maison;
} t_jeu;
