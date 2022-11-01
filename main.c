#include <stdio.h>
#include <stdlib.h>
#include "simcity.h"

int creer_jeux(){

    t_jeu *jeu = (t_jeu*)malloc(sizeof(t_jeu));
    jeu->compteur_habitants =0;
    jeu->compteur_monnaie = 500000;
    jeu->nombre_de_centrale_electrique =0;
    jeu->nombre_de_chateau_eau =0;
    jeu->nombre_de_maison =0;
    jeu->compteur_capacite_eau = 0;
    jeu->compteur_temps =0;
    jeu->compteur_capacite_electrique = 0;  //capacitee totale de tt les centrale
    jeu->tab_maison = (t_maison*)malloc(jeu->nombre_de_maison*sizeof(t_maison));
    jeu->tab_chateau_eau = (t_eau*)malloc(jeu->nombre_de_chateau_eau*sizeof(t_eau));
    jeu->tab_centrale_electrique = (t_centraleElectrique*)malloc( jeu->nombre_de_centrale_electrique*sizeof(t_centraleElectrique));

    return jeu;
}

void construire_chateau_eau(t_jeu *jeu){

    jeu->compteur_capacite_eau += jeu->tab_chateau_eau[jeu->nombre_de_chateau_eau].capacite_totale;
    jeu->compteur_monnaie -= jeu->tab_chateau_eau[jeu->nombre_de_chateau_eau].prix;
    jeu->nombre_de_chateau_eau++;
}

/*void maj_centrale_electrique(t_jeu *jeu){
    for(int i=0; i< jeu->nombre_de_centrale_electrique; i++){
        jeu->tab_chateau_eau[i].prix = 100000;
        jeu->tab_chateau_eau[i].capacite_totale = 5000;
    }

}*/

void init_centrale_electrique(t_jeu *jeu){
    jeu->tab_centrale_electrique[jeu->nombre_de_centrale_electrique].prix = 100000;
    jeu->tab_centrale_electrique[jeu->nombre_de_centrale_electrique].capacite_totale = 5000;
}

void init_chateau_eau(t_jeu *jeu){
    jeu->tab_chateau_eau[jeu->nombre_de_chateau_eau].prix = 100000;
    jeu->tab_chateau_eau[jeu->nombre_de_chateau_eau].capacite_totale = 5000;
}

void init_maison(t_jeu *jeu, int stade){   //, int stade

    jeu->tab_maison[jeu->nombre_de_maison].stade = 1;
    jeu->tab_maison[jeu->nombre_de_maison].prix = 1000;
    if(jeu->tab_maison[jeu->nombre_de_maison].stade ==0){
        jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant = 0;
        strcpy(jeu->tab_maison[jeu->nombre_de_maison].nom, "terrain vague");
    }
    if(jeu->tab_maison[jeu->nombre_de_maison].stade == 1){
        jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant = 10;
        strcpy(jeu->tab_maison[jeu->nombre_de_maison].nom, "cabane");
    }
    if(jeu->tab_maison[jeu->nombre_de_maison].stade == 2){
        jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant = 50;
        strcpy(jeu->tab_maison[jeu->nombre_de_maison].nom, "maison");
    }
    if(jeu->tab_maison[jeu->nombre_de_maison].stade == 3){
        jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant = 100;
        strcpy(jeu->tab_maison[jeu->nombre_de_maison].nom, "immeuble");
    }
    if(jeu->tab_maison[jeu->nombre_de_maison].stade == 4){
        jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant = 500;
        strcpy(jeu->tab_maison[jeu->nombre_de_maison].nom, "gratte-ciel");
    }
}



void construire_centrale_electrique(t_jeu *jeu){  //, int numero_centrale

    jeu->compteur_monnaie -= jeu->tab_centrale_electrique[jeu->nombre_de_centrale_electrique].prix;
    jeu->compteur_capacite_electrique += jeu->tab_centrale_electrique[jeu->nombre_de_centrale_electrique].capacite_totale;
    jeu->nombre_de_centrale_electrique++;
}

void construire_maison(t_jeu *jeu){
    jeu->compteur_habitants += jeu->tab_maison[jeu->nombre_de_maison].nombre_habitant;
    jeu->compteur_monnaie -= jeu->tab_maison[jeu->nombre_de_maison].prix;
    jeu->nombre_de_maison++;
}

void afficher_etat_du_jeu(t_jeu *jeu){
    printf("nombre de maison: %d\n", jeu->nombre_de_maison);
    printf("nombre de chateau d'eau: %d\n", jeu->nombre_de_chateau_eau );
    printf("nombre de centrale electrique: %d\n", jeu->nombre_de_centrale_electrique );
    printf("nombre d'habitants de la ville: %d\n", jeu->compteur_habitants);
    printf("nombre d'argent de la banque : %d\n", jeu->compteur_monnaie);
    printf("capacite totale en eau de tous les chateau : %d\n", jeu->compteur_capacite_eau);
    printf("capacite en electricite de la ville: %d / %d\n", jeu->compteur_capacite_electrique - jeu->capacite_restante_en_electricite, jeu->compteur_capacite_electrique);

    printf("\n\n");
}

void faire_choix_de_construire(t_jeu *jeu){
    jeu->tab_maison[jeu->nombre_de_maison].stade = 0;
    int choix;
    int stade;
    stade = jeu->tab_maison[jeu->nombre_de_maison].stade;
    do{
        printf("\n***************boite a outil :******************\n\n");
        printf("saisir 1 pour construire un chateau d'eau (prix 100 000)\n");
        printf("saisir 2 pour construire une centrale electrique (prix 100 000)\n");
        printf("saisir 3 pour construire une maison (prix 1 000)\n");
        printf("saisir 4 pour afficher l'etat du jeux (nombre d'habitants, nombre de maison, nombre de centrale electrique....)\n");
        printf("saisir 5 pour sortir\n");
        scanf("%d", &choix);
        if (choix == 1){
            init_chateau_eau(jeu);
            if(jeu->tab_chateau_eau[jeu->nombre_de_chateau_eau].prix <= jeu->compteur_monnaie ){
                construire_chateau_eau(jeu);
                printf("un chateau d'eau a ete construit\n");
            }
            else{
                printf("pas asse d'argent");
            }
        }
        if(choix ==2){
            init_centrale_electrique(jeu);
            if(jeu->tab_centrale_electrique[jeu->nombre_de_centrale_electrique].prix <= jeu->compteur_monnaie ){
                construire_centrale_electrique(jeu);
                printf("une centrale electrique a ete construite\n");
            }
            else{
                printf("pas asse d'argent");
            }
        }
        if(choix ==3){
            init_maison(jeu, stade);
            if(jeu->tab_maison[jeu->nombre_de_maison].prix <= jeu->compteur_monnaie ){
                construire_maison(jeu);
                printf("une maison a ete construite\n");
            }
            else{
                printf("pas asse d'argent");
            }
        }
        if(choix ==4){
            printf("etat du jeux\n\n");
            calcul_electricite_restante(jeu); //il faut update tous les compteurs en meme temps
            afficher_etat_du_jeu(jeu);
        }

    }while(choix == 1 || choix ==2 || choix ==3 || choix ==4);

    if (choix ==5){
        printf("\n fin");
    }

}

/*void calcul_capacite_eau_restante(t_jeu *jeu){
    for(i=0; i<jeu->nombre_de_chateau_eau; i++){
       jeu->tab_chateau_eau[i]->capcite_restante = jeu->tab_chateau_eau[i]->capacite_totale - jeu->compteur_habitants;
    }


}*/

void calcul_electricite_restante(t_jeu *jeu){
    jeu->capacite_restante_en_electricite = jeu->compteur_capacite_electrique - jeu->compteur_habitants;
}


int main()
{
    t_jeu *jeu;
    jeu = creer_jeux();
    faire_choix_de_construire(jeu);
    return 0;
}
