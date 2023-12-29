#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPTES 100

struct Compte {
    int numero;
    char nom[50];
    double solde;
};


void creerCompte(struct Compte *comptes, int *nombreComptes);
void afficherDetails(struct Compte *comptes, int nombreComptes);
void effectuerDepot(struct Compte *comptes, int nombreComptes);
void effectuerRetrait(struct Compte *comptes, int nombreComptes);
void afficherListeClients(struct Compte *comptes, int nombreComptes);
void miseAJourCompte(struct Compte *comptes, int nombreComptes);

int main() {
    struct Compte *comptes = malloc(sizeof(struct Compte) * MAX_COMPTES);
    int nombreComptes = 0;

    int choix;
    do {
        printf("\nMenu:\n");
        printf("1. Créer un nouveau compte\n");
        printf("2. Afficher les détails d'un compte\n");
        printf("3. Effectuer un dépôt\n");
        printf("4. Effectuer un retrait\n");
        printf("5. Afficher la liste des clients\n");
        printf("6. Supprimer un compte\n");
        printf("7. Mettre a jour un compte\n");
        printf("0. Quitter\n");
        printf("Choisissez une option: ");

        if (scanf("%d", &choix) != 1) {
            printf("Option invalide. Veuillez réessayer.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (choix) {
            case 1:
                creerCompte(comptes, &nombreComptes);
                break;
            case 2:
                afficherDetails(comptes, nombreComptes);
                break;
            case 3:
                effectuerDepot(comptes, nombreComptes);
                break;
            case 4:
                effectuerRetrait(comptes, nombreComptes);
                break;
            case 5:
                afficherListeClients(comptes, nombreComptes);
                break;
            case 6:
                supprimerCompte(comptes, &nombreComptes);
                break;
            case 7:
                miseAJourCompte(comptes, nombreComptes);
                break;
            case 0:
                printf("Programme terminé.\n");
                break;
            default:
                printf("Option invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    free(comptes);

    return 0;
}

void creerCompte(struct Compte *comptes, int *nombreComptes) {
    printf("Entrez le nom du titulaire du compte : ");
    scanf("%s", comptes[*nombreComptes].nom);

    comptes[*nombreComptes].numero = *nombreComptes + 1;
    comptes[*nombreComptes].solde = 0.0;

    (*nombreComptes)++;
    printf("Compte créé avec succès.\n");
}

void afficherDetails(struct Compte *comptes, int nombreComptes) {
    int numeroCompte;
    printf("Entrez le numéro de compte : ");
    scanf("%d", &numeroCompte);

    if (numeroCompte > 0 && numeroCompte <= nombreComptes) {
        printf("Numéro de compte : %d\n", comptes[numeroCompte - 1].numero);
        printf("Nom du titulaire : %s\n", comptes[numeroCompte - 1].nom);
        printf("Solde : %.2f\n", comptes[numeroCompte - 1].solde);
    } else {
        printf("Compte non trouvé.\n");
    }
}

void effectuerDepot(struct Compte *comptes, int nombreComptes) {
    int numeroCompte;
    double montant;
    printf("Entrez le numéro de compte : ");
    scanf("%d", &numeroCompte);

    if (numeroCompte > 0 && numeroCompte <= nombreComptes) {
        printf("Entrez le montant du dépôt : ");
        scanf("%lf", &montant);

        comptes[numeroCompte - 1].solde += montant;
        printf("Dépôt effectué avec succès.\n");
    } else {
        printf("Compte non trouvé.\n");
    }
}

void effectuerRetrait(struct Compte *comptes, int nombreComptes) {
    int numeroCompte;
    double montant;
    printf("Entrez le numéro de compte : ");
    scanf("%d", &numeroCompte);

    if (numeroCompte > 0 && numeroCompte <= nombreComptes) {
        printf("Entrez le montant du retrait : ");
        scanf("%lf", &montant);

        if (montant <= comptes[numeroCompte - 1].solde) {
            comptes[numeroCompte - 1].solde -= montant;
            printf("Retrait effectué avec succès.\n");
        } else {
            printf("Solde insuffisant.\n");
        }
    } else {
        printf("Compte non trouvé.\n");
    }
}

void afficherListeClients(struct Compte *comptes, int nombreComptes) {
    printf("Liste des clients :\n");
    for (int i = 0; i < nombreComptes; i++) {
        printf("%d. %s\n", comptes[i].numero, comptes[i].nom);
    }
}
void supprimerCompte(struct Compte *comptes, int *nombreComptes) {
    int numeroCompte;
    printf("Entrez le numéro de compte à supprimer : ");
    scanf("%d", &numeroCompte);

    if (numeroCompte > 0 && numeroCompte <= *nombreComptes) {
        for (int i = numeroCompte - 1; i < *nombreComptes - 1; i++) {
            comptes[i] = comptes[i + 1];
        }

        (*nombreComptes)--;
        printf("Compte supprimé avec succès.\n");
    } else {
        printf("Compte non trouvé.\n");
    }
}
void miseAJourCompte(struct Compte *comptes, int nombreComptes) {
    int numeroCompte;
    printf("Entrez le numéro de compte à mettre à jour : ");
    scanf("%d", &numeroCompte);

    if (numeroCompte > 0 && numeroCompte <= nombreComptes) {
        printf("Nouveau nom du titulaire : ");
        scanf("%s", comptes[numeroCompte - 1].nom);
        printf("Mise à jour du compte effectuée avec succès.\n");
    } else {
        printf("Compte non trouvé.\n");
    }
}
