#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

// Variables globales
int nj = 0;                   // Jour actuel (1-31)
int nm = 0;                   // Mois actuel (1-12)
int ny = 0;                   // Annee actuelle
int dateValidee = 0;          // Test date saisie (0=non, 1=oui)
int nbl = 50;                 // Nombre de livres
int nbe = 40;                 // Nombre d'emprunts en cours
int nbk = 70;                 // Nombre d'emprunts historique

int T_NLivre[300] = {712,141,199,312,473,574,619,821,905,451,101,222,643,444,231,666,934,416,179,898,211,999,
135,246,357,468,579,680,791,802,913,104,145,124,137,146,234,567,678,890,345,432,876,321,374,777,270,964,542,786};

int T_Nbr_exp[300] = {0,3,0,6,14,1,0,4,4,10,12,5,6,11,13,1,2,0,3,14,0,5,1,6,17,0,1,6,5,8,3,4,1,2,0,6,10,4,12,8,7,0,5,1,11,4,2,3,2,7};

char T_Titre[300][300] =
{"The Godfather","1984","To Kill a Mockingbird","The Shining","Dracula","Frankenstein","Pride and Prejudice","The Great Gatsby","The Hobbit","Harry Potter","The Catcher in the Rye","The Lord of the Rings",
"Moby Dick","War and Peace","The Odyssey","Crime and Punishment","Jane Eyre","Wuthering Heights","Brave New World","Animal Farm","Fahrenheit 451","Animal Farm","Don Quixote","Les Miserables","The Count of Monte Cristo",
"Anna Karenina","Madame Bovary","The Metamorphosis","The Trial","The Stranger","Catch-22","Slaughterhouse-Five","The Bell Jar","On the Road","The Grapes of Wrath","Of Mice and Men","East of Eden",
"The Old Man and the Sea","A Farewell to Arms","The Sun Also Rises","The Road","The Color Purple","Invisible Man","One Flew Over the Cuckoos Nest","The Road","Life of Pi","The Kite Runner","The Alchemist","The Book Thief","The Handmaids Tale"};

int empruntsCourants[300][8] =
{
    {11111111,473,5,9,2025,28,9,2025},
    {13007890,468,2,10,2025,25,10,2025},
    {11111111,712,10,10,2025,5,11,2025},
    {11111111,619,15,10,2025,10,11,2025},
    {15009012,680,20,10,2025,15,11,2025},
    {11111475,199,25,10,2025,20,11,2025},
    {11111111,579,28,10,2025,25,11,2025},
    {15846130,678,1,11,2025,28,11,2025},
    {12006789,357,2,11,2025,30,11,2025},
    {11111111,312,5,11,2025,3,12,2025},
    {13064879,913,8,11,2025,6,12,2025},
    {19002345,712,10,11,2025,8,12,2025},
    {10003456,473,12,11,2025,10,12,2025},
    {11146027,416,15,11,2025,13,12,2025},
    {17001234,145,18,11,2025,16,12,2025},
    {12034847,821,20,11,2025,18,12,2025},
    {12004567,234,22,11,2025,20,12,2025},
    {11123409,211,25,11,2025,23,12,2025},
    {11004567,619,28,11,2025,26,12,2025},
    {12005678,222,1,12,2025,29,12,2025},
    {17328942,802,3,12,2025,31,12,2025},
    {14008901,579,5,12,2025,2,1,2026},
    {13007891,101,7,12,2025,4,1,2026},
    {14006789,231,8,12,2025,5,1,2026},
    {13006789,643,10,12,2025,7,1,2026},
    {15003456,246,12,12,2025,9,1,2026},
    {14007890,444,14,12,2025,11,1,2026},
    {16009876,104,16,12,2025,13,1,2026},
    {15008901,124,18,12,2025,15,1,2026},
    {16001234,791,20,12,2025,17,1,2026},
    {11111111,666,22,12,2025,19,1,2026},
    {19007777,234,24,12,2025,21,1,2026},
    {17001234,432,25,12,2025,22,1,2026},
    {11002222,666,26,12,2025,23,1,2026},
    {18005555,137,27,12,2025,24,1,2026},
    {18002345,898,28,12,2025,25,1,2026},
    {12556677,890,29,12,2025,26,1,2026},
    {19003456,270,30,12,2025,27,1,2026},
    {13007891,135,31,12,2025,28,1,2026},
    {11005678,913,31,12,2025,29,1,2026}
};

int historiqueEmprunts[300][8] =
{
    {11234567,712,12,3,2017,22,3,2017},
    {10234568,473,5,6,2017,15,6,2017},
    {11345678,141,9,11,2017,19,11,2017},
    {12345670,574,2,2,2018,12,2,2018},
    {13456789,199,15,4,2018,25,4,2018},
    {14567890,619,7,7,2018,17,7,2018},
    {11111111,999,1,9,2018,11,9,2018},
    {16789012,712,3,12,2018,13,12,2018},
    {17890123,473,6,1,2019,16,1,2019},
    {18901234,141,10,2,2019,20,2,2019},
    {19123456,574,18,3,2019,28,3,2019},
    {10111213,619,5,5,2019,15,5,2019},
    {12334455,199,9,6,2019,19,6,2019},
    {13445566,312,12,7,2019,22,7,2019},
    {14556677,712,1,9,2019,11,9,2019},
    {15667788,473,4,11,2019,14,11,2019},
    {16778899,141,8,1,2020,18,1,2020},
    {17889900,574,3,2,2020,13,2,2020},
    {18990011,619,6,3,2020,16,3,2020},
    {19001122,199,7,5,2020,17,5,2020},
    {11112223,312,11,6,2020,21,6,2020},
    {12223334,712,2,7,2020,12,7,2020},
    {13334445,473,9,9,2020,19,9,2020},
    {14445556,141,5,11,2020,15,11,2020},
    {15556667,574,3,12,2020,13,12,2020},
    {11111111,821,4,2,2021,14,2,2021},
    {17778889,619,6,3,2021,16,3,2021},
    {18889990,312,8,4,2021,18,4,2021},
    {19990001,712,10,5,2021,20,5,2021},
    {10191929,473,14,6,2021,24,6,2021},
    {11101010,141,5,8,2021,15,8,2021},
    {12212121,574,7,9,2021,17,9,2021},
    {13323232,199,9,10,2021,19,10,2021},
    {14434343,619,3,12,2021,13,12,2021},
    {12035419,270,2,4,2018,29,4,2018},
    {15545454,712,6,1,2022,16,1,2022},
    {16656565,312,8,2,2022,18,2,2022},
    {17767676,473,11,3,2022,21,3,2022},
    {18878787,141,15,4,2022,25,4,2022},
    {19989898,574,6,5,2022,16,5,2022},
    {10090909,199,9,6,2022,19,6,2022},
    {11111111,444,13,7,2022,23,7,2022},
    {12222222,712,2,9,2022,12,9,2022},
    {11111111,312,5,10,2022,15,10,2022},
    {11111111,473,8,11,2023,18,11,2023},
    {15555555,141,11,12,2023,21,12,2023},
    {16666666,574,7,1,2024,17,1,2024},
    {17777777,199,10,3,2025,20,3,2025},
    {11111111,321,10,3,2025,17,3,2025},
    {13007891,345,5,7,2025,12,7,2025},
    {11111111,137,3,4,2025,10,4,2025},
    {18005555,146,12,5,2025,19,5,2025},
    {19007777,374,22,2,2025,1,3,2025},
    {11111111,802,15,9,2015,22,9,2015},
    {15003456,432,20,2,2015,27,2,2015},
    {16009876,876,11,1,2016,15,1,2016},
    {17001234,964,8,6,2016,25,6,2016},
    {12004567,231,3,8,2017,16,8,2017},
    {12556677,542,7,11,2020,14,11,2020},
    {13007891,104,1,9,2021,21,9,2021},
    {14006789,619,6,2,2023,13,2,2023},
    {18005555,890,25,5,2024,1,6,2024},
    {11223344,451,2,3,2020,15,3,2020},
    {12345678,934,12,7,2019,22,7,2019},
    {13456789,179,8,5,2021,18,5,2021},
    {14567890,777,2,6,2022,20,6,2022},
    {15678901,786,12,4,2023,20,4,2023}
};

// Déclarations de fonctions
void admn();
void usr();
void stat();
int confirmerSuppression(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[],int empruntsCourants[300][8], int indexLivre, int nbl,int nbe);
void err0(char msg[]);
void err1(char msg[]);
int comp(char s1[], char s2[]);
int verif_numero(char ch[]);
void trim(char ch[]);
int rechercherParNumero(int numeroLivre, int T_NLivre[], int nbl);
int rechercherParTitre(char titreRecherche[], char T_Titre[][300], int nbl, int indicesResultats[]);
int estAnneeBissextile(int annee);
int verif_date(int annee, int mois, int jour);
long calculerJoursDepuisEpoque(int annee, int mois, int jour);
void saisir_date();
void afficherLivres(int T_NLivre[], char T_Titre[][300], int T_Nbr_exp[], int nbl, int filtreDisponibilite, char message[]);
void ajouterLivre();
int supprimerLivre(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[], int nbl,int empruntsCourants[300][8]);
int modifierNombreExemplaires(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[],int empruntsCourants[300][8], int nbl);
void rechercherLivre(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[], int nbl);
int emprunterLivre(int nbl, int T_NLivre[], char T_Titre[][300], int T_Nbr_exp[], int empruntsCourants[300][8], int nbe);
void afficherEmpruntsAdherent(int empruntsCourants[300][8], int historiqueEmprunts[300][8], char T_Titre[300][300], int nbl, int nbk, int nbe);
void retournerLivre(int empruntsCourants[300][8],int historiqueEmprunts[300][8], char T_Titre[300][300]);
void afficherEmpruntsFiltres(int empruntsCourants[300][8],char T_Titre[300][300],int T_NLivre[],int nbe, int nbl, int filtreRetard,char message[]);
void afficherEmpruntsParDate(int empruntsCourants[300][8],int historiqueEmprunts[300][8],char T_Titre[300][300],int T_NLivre[],int nbe, int nbl,int nbk);
int supprimerEmpruntsParPeriode();
void afficherStatistiquesBasiques(int T_NLivre[] ,int T_Nbr_exp[],int empruntsCourants[300][8],int historiqueEmprunts[300][8],int nbe,int nbk,int nbl);
void afficherLivresPlusEmpruntes();
void afficherLivresJamaisEmpruntes();
void afficherEmprunteursFrequents();
void afficherLivresPlusEmpruntesPeriode();
void afficherRetour(char msg[]);
void quitterApplication();

// Fonctions d'erreur
void err0(char msg[])
{
    system("cls");
    system("color 0C");
    printf("--------------------------------------------------- \n\n");
    printf(" :(  Malheureusement,\n\n");
    printf(" Votre choix est invalide (Votre saisie ne correspond pas a une donnee numerique)!\n");
    printf(" %s.\n\n", msg);
    printf("--------------------------------------------------- \n\n");
    system("pause");
    system("color 07");
}

void err1(char msg[])
{
    system("cls");
    system("color 0C");
    printf("--------------------------------------------------- \n\n");
    printf(" :(  Malheureusement,\n\n");
    printf(" Votre Choix est invalide (Valeur numerique hors intervalle)!\n");
    printf(" %s.\n\n", msg);
    printf("--------------------------------------------------- \n\n");
    system("pause");
    system("color 07");
}

int comp(char s1[], char s2[])
{
    int i = 0;
    int result = 0;
    int found = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && found == 0)
    {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;
        if (c1 != c2)
        {
            result = c1 - c2;
            found = 1;
        }
        i++;
    }

    if (found == 0)
    {
        result = s1[i] - s2[i];
    }

    return result;
}

int verif_numero(char ch[])
{
    int i=0 , j=0;
    int len;
    while (ch[i] != '\0')
    {
        if (ch[i] != ' ')
        {
            ch[j] = ch[i];
            j++;
        }
        i++;
    }
    ch[j] = '\0';
    len = strlen(ch);
    int test = 1;
    if (len == 0)
        test = 0;
    i=0;
    while (i < len)
    {
        if (ch[i] < '0' || ch[i] > '9')
            test = 0;
        i++;
    }
    return test;
}

void trim(char ch[])
{
    int i = 0;
    int j = 0;
    int len = strlen(ch);
    int espacePrecedent = 0;
    while (ch[i] == ' ')
        i++;
    while (i < len)
    {
        if (ch[i] != ' ')
        {
            ch[j] = ch[i];
            j = j + 1;
            espacePrecedent = 1;
        }
        else if (espacePrecedent ==1)
        {
            ch[j] = ' ';
            j = j + 1;
            espacePrecedent = 0;
        }
        i = i + 1;
    }
    if (j > 0 && ch[j - 1] == ' ')
        j = j - 1;
    ch[j] = '\0';
}

int rechercherParNumero(int numeroLivre, int T_NLivre[], int nbl)
{
    int indexTrouve = -1;
    int i = 0;
    while (indexTrouve == -1 && i < nbl)
    {
        if (numeroLivre == T_NLivre[i])
            indexTrouve = i;
        i++;
    }
    return indexTrouve;
}

int rechercherParTitre(char titreRecherche[], char T_Titre[][300], int nbl, int indicesResultats[])
{
    int i = 0, nbResultats = 0;
    while (i < nbl)
    {
        if (comp(titreRecherche, T_Titre[i]) == 0)
        {
            indicesResultats[nbResultats] = i;
            nbResultats++;
        }
        i++;
    }
    return nbResultats;
}

int estAnneeBissextile(int annee)
{
    int estBissextile =0;
    if ((annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0) )
        estBissextile =1;
    return estBissextile;
}

int verif_date(int annee, int mois, int jour)
{
    int estValide = 1;
    int joursParMois[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(estAnneeBissextile(annee))
        joursParMois[1] = 29;
    if(mois < 1 || mois > 12)
        estValide = 0;
    else if(jour < 1 || jour > joursParMois[mois - 1])
        estValide = 0;
    return estValide;
}

long calculerJoursDepuisEpoque(int annee, int mois, int jour)
{
    long totalJours = 0;
    int i;
    for (i = 1; i < annee; i++)
    {
        if (estAnneeBissextile(i))
            totalJours = totalJours + 366;
        else
            totalJours = totalJours + 365;
    }
    int joursParMois[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for (i = 1; i < mois; i++)
    {
        totalJours = totalJours + joursParMois[i - 1];
        if (i == 2 && estAnneeBissextile(annee))
            totalJours = totalJours + 1;
    }
    totalJours = totalJours + jour;
    return totalJours;
}

void saisir_date()
{
    if (dateValidee ==0)
    {
        char saisie[300];
        int dateCorrecte = 0;
        do {
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |-------------------------------       Saisir la date        -------------------------------| \n\n");
                Sleep(500);
                printf("                                    veuiller saisir la date d'aujourd'hui\n");
                printf("                                    Jour : ");
                fgets(saisie, sizeof(saisie), stdin);
                saisie[strcspn(saisie, "\n")] = 0;
                if (verif_numero(saisie) == 0)
                {
                    err0("Veuillez entrer un jour valide");
                    nj = 0;
                }
                else
                {
                    nj = atoi(saisie);
                    if (nj <= 0 || nj > 31)
                        err1("Veuillez entrer un jour valide");
                }
            } while (nj <= 0 || nj > 31);
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |-------------------------------       Saisir la date        -------------------------------| \n\n");
                printf("                                    veuiller saisir la date d'aujourd'hui\n");
                printf("                                    Jour : %02d\n",nj);
                printf("                                    Mois : ");
                fgets(saisie, sizeof(saisie), stdin);
                saisie[strcspn(saisie, "\n")] = 0;
                if (verif_numero(saisie) == 0)
                {
                    err0("Veuillez entrer un mois valide");
                    nm = 0;
                }
                else
                {
                    nm = atoi(saisie);
                    if (nm <= 0 || nm > 12)
                        err1("Veuillez entrer un mois valide");
                }
            } while (nm <= 0 || nm > 12);
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |-------------------------------       Saisir la date        -------------------------------| \n\n");
                printf("                                    veuiller saisir la date d'aujourd'hui\n");
                printf("                                    Jour : %02d\n",nj);
                printf("                                    Mois : %02d\n",nm);
                printf("                                    Annee : ");
                fgets(saisie, sizeof(saisie), stdin);
                saisie[strcspn(saisie, "\n")] = 0;
                if (verif_numero(saisie) == 0)
                {
                    err0("Veuillez entrer une annee valide");
                    ny = 0;
                }
                else
                {
                    ny = atoi(saisie);
                    if (ny < 2000 || ny > 2500)
                        err1("Veuillez entrer une annee valide");
                }
            } while (ny < 2000 || ny > 2500);
            if (verif_date(ny, nm, nj) == 0)
            {
                system("cls");
                system("color 0C");
                printf("                                        ------------------------------------------------------------------------ \n\n");
                printf("                                                     La date est invalide.\n\n");
                printf("                                        ------------------------------------------------------------------------ \n\n");
                system("pause");
                dateCorrecte = 0;
            }
            else
            {
                system("cls");
                system("color 0A");
                printf("                                        ------------------------------------------------------------------------ \n\n");
                printf("                                                     La date est valide.\n");
                printf("                                                     Aujourd'hui : %02d/%02d/%04d\n\n",nj,nm,ny);
                printf("                                        ------------------------------------------------------------------------ \n\n");
                dateCorrecte =1;
                system("pause");
            }
        } while (dateCorrecte == 0);
        dateValidee =1;
    }
}

void afficherLivres(int T_NLivre[], char T_Titre[][300], int T_Nbr_exp[], int nbl, int filtreDisponibilite, char message[] )
{
    int i;
    int nbLivresAffiches =0;
    system("color 07");
    system("cls");
    if (nbl == 0)
    {
        system("cls");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         La bibliotheque est vide.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        for (i = 0; i < nbl; i++)
        {
            if (T_Nbr_exp[i] !=0)
                nbLivresAffiches++;
        }
        if (filtreDisponibilite ==0)
            nbLivresAffiches =nbl;
        printf("                                   --------------------------------------------------------------------------------------------- \n\n");
        printf("                                                          Il y a %d livre(s)%s.\n\n", nbLivresAffiches,message);
        printf("                                   --------------------------------------------------------------------------------------------- \n\n");
        printf("                                              Numero                     Titre                                     Exemplaire(s)  \n\n");
        printf("                                   ---------------------------------------------------------------------------------------------\n");
        for (i = 0; i < nbl; i++)
        {
            if (filtreDisponibilite ==1)
            {
                if (T_Nbr_exp[i] !=0)
                {
                    printf("                                                %-5.3d                    %-25s                    %-15d   \n\n",T_NLivre[i],T_Titre[i],T_Nbr_exp[i]);
                    printf("                                   ---------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
            }
            else if (filtreDisponibilite ==0)
            {
                printf("                                                %-5.3d                    %-25s                    %-15d   \n\n",T_NLivre[i],T_Titre[i],T_Nbr_exp[i]);
                printf("                                   ---------------------------------------------------------------------------------------------\n");
                Sleep(100);
            }
        }
    }
        system("pause");
}

void ajouterLivre()
{
    char saisieNumero[20], saisieExemplaires[20];
    int nouveauID,confirmation;
    system("cls");
    system("color 07");
    printf("                                   |-------------------------------------------------------------------------------------------| \n");
    printf("                                   |------------------------------       AJOUT D'UN LIVRE        ------------------------------| \n\n");
    Sleep(500);
    if (nbl < 300)
    {
        printf("                                              numero du livre : ");
        fgets(saisieNumero, sizeof(saisieNumero), stdin);
        saisieNumero[strcspn(saisieNumero, "\n")] = '\0';
        if (verif_numero(saisieNumero) == 0)
            err0("Il faut le numero du livre a ajouter");
        else if (atoi(saisieNumero)<100 || atoi(saisieNumero)>999)
            err1("veuillez entrer un numero de 3 chiffres");
        else
        {
            nouveauID = atoi(saisieNumero);
            if (rechercherParNumero(nouveauID, T_NLivre, nbl) != -1)
            {
                system("cls");
                system("color 0E");
                printf("                                         ----------------------------------------------------------- \n\n");
                printf("                                                     Cet ID existe deja dans la liste.\n\n");
                printf("                                         ----------------------------------------------------------- \n");
                system("pause");
            }
            else
            {
                printf("                                              Titre du livre : ");
                fgets(T_Titre[nbl], 300, stdin);
                T_Titre[nbl][strcspn(T_Titre[nbl], "\n")] = '\0';
                trim(T_Titre[nbl]);
                do
                {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |------------------------------       AJOUT D'UN LIVRE        ------------------------------| \n\n");
                    printf("                                        Numero du livre : %03d \n",nouveauID);
                    printf("                                        Titre du livre : %s \n",T_Titre[nbl]);
                    printf("                                        Nombre d'exemplaires : ");
                    fgets(saisieExemplaires, sizeof(saisieExemplaires), stdin);
                    saisieExemplaires[strcspn(saisieExemplaires, "\n")] = '\0';
                    if (verif_numero(saisieExemplaires) == 0 )
                        err0("Veuillez entrer le nombre d'exemplaires du livre (ne depassant pas 100 copies)");
                    else if (atoi(saisieExemplaires)>100)
                    {
                        system("cls");
                        system("color 0E");
                        printf("                                         --------------------------------------------------------------------- \n\n");
                        printf("                                              Le nombre d'exemplaires du livre doit ne pas depasser 100.\n\n");
                        printf("                                         --------------------------------------------------------------------- \n");
                        system("pause");
                    }
                } while (verif_numero(saisieExemplaires) == 0 || atoi(saisieExemplaires)>100);
                T_NLivre[nbl] = nouveauID;
                T_Nbr_exp[nbl] = atoi(saisieExemplaires);
                system("cls");
                system("color 0A");
                printf("                                         ----------------------------------------------------------------- \n\n");
                printf("                                               Operation executee avec succes :\n");
                printf("                                               Livre ajoute : %s (numero %d, %d exemplaire(s) )\n\n", T_Titre[nbl],T_NLivre[nbl], T_Nbr_exp[nbl]);
                printf("                                         ----------------------------------------------------------------- \n");
                nbl++;
                system("pause");
            }
        }
    }
    else
    {
        system("color 0C");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Erreur survenue :\n");
        printf("                                                         La bibliotheque est pleine.\n\n");
        printf("                                         ----------------------------------------------------------- \n\n");
        system("pause");
    }
}

int supprimerLivre(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[], int nbl,int empruntsCourants[300][8])
{
    char titreRecherche[300];
    char saisieNumero[10];
    int indicesResultats[300];
    int nbOccurrences;
    int numeroChoisi;
    int i;
    int indexConfirme;
    int saisieValide = 0;
    if (nbl == 0)
    {
        system("cls");
        system("color 0E");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                     La bibliotheque est vide.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("pause");
    }
    else
    {
        system("cls");
        system("color 07");
        printf("                                   |------------------------------------------------------------------------------------------------| \n");
        printf("                                   |-----------------------------       SUPPRIMER UN LIVRE        ----------------------------------| \n\n");
        Sleep(500);
        printf("                                        Titre du livre : ");
        fgets(titreRecherche, sizeof(titreRecherche), stdin);
        titreRecherche[strcspn(titreRecherche, "\n")] = 0;
        trim(titreRecherche);
        nbOccurrences = rechercherParTitre(titreRecherche, T_Titre, nbl, indicesResultats);
        if (nbOccurrences == 0)
        {
            system("cls");
            system("color 0E");
            printf("                                         ----------------------------------------------------------- \n\n");
            printf("                                                  Ce livre n'existe pas dans la bibliotheque.\n\n");
            printf("                                         ----------------------------------------------------------- \n");
            system("pause");
        }
        else if (nbOccurrences == 1)
        {
            nbl = confirmerSuppression(T_Titre, T_NLivre, T_Nbr_exp,empruntsCourants, indicesResultats[0],nbl,nbe);
        }
        else
        {
            do
            {
                system("cls");
                system("color 07");
                printf("                                   |------------------------------------------------------------------------------------------------| \n");
                printf("                                   |-------------------------------       SUPPRIMER UN LIVRE        --------------------------------| \n\n");
                Sleep(500);
                printf("                                     Il y a %d livres portant ce titre \n\n", nbOccurrences);
                Sleep(500);
                printf("                                    ------------------------------------------------------------------------------------------------ \n\n");
                printf("                                               Numero                  Titre                                 Exemplaire(s)  \n\n");
                printf("                                    ------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < nbOccurrences; i++)
                {
                    printf("                                                %-8.3d                %-25s                    %d   \n\n",T_NLivre[indicesResultats[i]], T_Titre[indicesResultats[i]], T_Nbr_exp[indicesResultats[i]]);
                    printf("                                    ------------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
                printf("                                Numero de livre a supprimer: ");
                fgets(saisieNumero, sizeof(saisieNumero), stdin);
                saisieNumero[strcspn(saisieNumero, "\n")] = 0;
                if (verif_numero(saisieNumero) == 0)
                {
                    err0("Veuillez entrer un numero du livre valide");
                }
                else
                {
                    numeroChoisi = atoi(saisieNumero);
                    indexConfirme = 0;
                    for (i = 0; i < nbOccurrences; i++)
                    {
                        if (T_NLivre[indicesResultats[i]] == numeroChoisi)
                            indexConfirme = indicesResultats[i] + 1;
                    }
                    if (indexConfirme == 0)
                    {
                        printf("\n                                         ----------------------------------------------------------- \n");
                        printf("                                                  Veuillez entrer un des numero affiches.\n");
                        printf("                                         ----------------------------------------------------------- \n");
                        Sleep(1500);
                        saisieValide = 0;
                    }
                    else
                    {
                        indicesResultats[0] = indexConfirme - 1;
                        nbl = confirmerSuppression(T_Titre, T_NLivre, T_Nbr_exp, empruntsCourants, indicesResultats[0], nbl,nbe);
                        saisieValide = 1;
                    }
                }

            } while (saisieValide == 0);
        }
    }
    return nbl;
}

int confirmerSuppression(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[],int empruntsCourants[300][8], int indexLivre, int nbl,int nbe)
{
    char saisieConfirmation[10];
    char titreCopie[300];
    int choixUtilisateur;
    int i;
    int nbExemplairesEmpruntes;
    int numeroLivreCopie;
    int jourRetourProche, moisRetourProche, anneeRetourProche;
    int j;
    nbExemplairesEmpruntes =0;
     for (i=0;i<nbe;i++)
    {
        if (empruntsCourants[i][1]==T_NLivre[indexLivre])
            nbExemplairesEmpruntes++;
    }
    if (nbExemplairesEmpruntes ==0)
    {
        system("cls");
        system("color 0E");
        printf("                            |------------------------------------------------------------------------------------------------| \n");
        printf("                            |-------------------------------       SUPPRIMER UN LIVRE        --------------------------------| \n\n");
        printf("                                  Voulez-vous vraiment supprimer %s (numero %d, exemplaires %d) ?\n\n", T_Titre[indexLivre], T_NLivre[indexLivre], T_Nbr_exp[indexLivre]);
        printf("                             ------------------------------------------------------------------------------------------------ \n");
        printf("                                             0 : Non (retour)                                1 : Oui (supprimer)\n");
        printf("                             ------------------------------------------------------------------------------------------------ \n");
        printf("                                Votre choix : ");
        fgets(saisieConfirmation, sizeof(saisieConfirmation), stdin);
        saisieConfirmation[strcspn(saisieConfirmation, "\n")] = 0;
        strcpy(titreCopie,T_Titre[indexLivre]);
        numeroLivreCopie =T_NLivre[indexLivre];
        if (verif_numero(saisieConfirmation) == 0)
        {
            err0("Veuillez selectionner 0 pour annuler ou 1 pour confirmer");
        }
        else
        {
            choixUtilisateur = atoi(saisieConfirmation);
            if (choixUtilisateur <0 || choixUtilisateur >1)
            err1("Veuillez selectionner 0 pour annuler ou 1 pour confirmer");
            else
            {
                if (choixUtilisateur == 1)
                {
                    for (i = indexLivre; i < nbl - 1; i++)
                    {
                        strcpy(T_Titre[i], T_Titre[i + 1]);
                        T_NLivre[i] = T_NLivre[i + 1];
                        T_Nbr_exp[i] = T_Nbr_exp[i + 1];
                    }
                    nbl = nbl - 1;
                    system("cls");
                    system("color 0A");
                    printf("                                             ---------------------------------------------------------------- \n\n");
                    printf("                                                  Operation executee avec succes :\n");
                    printf("                                                  Livre (%03d: %s) supprime \n\n",numeroLivreCopie,titreCopie);
                    printf("                                             ---------------------------------------------------------------- \n");
                    system("pause");
                }
            }
        }
    }
    else
    {
        system("cls");
        system("color 0E");
        jourRetourProche =0;
        moisRetourProche =0;
        anneeRetourProche =0;
        for (j = 0; j < nbe; j++)
        {
            if (empruntsCourants[j][1] == T_NLivre[indexLivre])
            {
                if ((empruntsCourants[j][7] > anneeRetourProche) || (empruntsCourants[j][7] == anneeRetourProche && empruntsCourants[j][6] > moisRetourProche) || (empruntsCourants[j][7] == anneeRetourProche && empruntsCourants[j][6] == moisRetourProche && empruntsCourants[j][5] > jourRetourProche))
                {
                    jourRetourProche = empruntsCourants[j][5];
                    moisRetourProche = empruntsCourants[j][6];
                    anneeRetourProche = empruntsCourants[j][7];
                }
            }
        }
        system("color 06");
        printf("                                             ------------------------------------------------------------------- \n\n");
        printf("                                                Ce livre est emprente et ne peut pas etre supprime \n");
        printf("                                                Livre (%03d: %s) peut etre supprime apres %02d/%02d/%04d\n\n",T_NLivre[indexLivre],T_Titre[indexLivre],jourRetourProche, moisRetourProche, anneeRetourProche);
        printf("                                             ------------------------------------------------------------------- \n");
        system("pause");
    }
    return nbl;
}

int modifierNombreExemplaires(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[],int empruntsCourants[300][8], int nbl)
{
    char titreRecherche[300];
    char saisieNouveauNombre[10];
    int indicesResultats[300];
    int nbOccurrences;
    int nouveauNombreExemplaires;
    int i;
    int indexConfirme;
    int nbExemplairesEmpruntes;
    int saisieValide = 0;
    if (nbl == 0)
    {
        system("cls");
        system("color 0E");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                     La bibliotheque est vide.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("pause");
    }
    else
    {
        system("cls");
        system("color 07");
        printf("                            |-------------------------------------------------------------------------------------------| \n");
        printf("                            |-----------------   MODIFIER LE NOMBRE D'EXEMPLAIRES D'UN LIVRE   -------------------------| \n\n");
        Sleep(500);
        printf("                                        Titre du livre : ");
        fgets(titreRecherche, sizeof(titreRecherche), stdin);
        titreRecherche[strcspn(titreRecherche, "\n")] = 0;
        trim(titreRecherche);
        nbOccurrences = rechercherParTitre(titreRecherche, T_Titre, nbl, indicesResultats);
        if (nbOccurrences == 0)
        {
            system("cls");
            system("color 0E");
            printf("                                         ----------------------------------------------------------- \n\n");
            printf("                                                  Ce livre n'existe pas dans la bibliotheque.\n\n");
            printf("                                         ----------------------------------------------------------- \n");
            system("pause");
        }
        else if (nbOccurrences == 1)
        {
            do
            {
                nbExemplairesEmpruntes =0;
                for (i=0;i<nbe;i++)
                {
                    if (empruntsCourants[i][1]==T_NLivre[indicesResultats[0]])
                        nbExemplairesEmpruntes++;
                }
                system("cls");
                system("color 0E");
                printf("                            |-------------------------------------------------------------------------------------------| \n");
                printf("                            |-----------------   MODIFIER LE NOMBRE D'EXEMPLAIRES D'UN LIVRE   -------------------------| \n\n");
                Sleep(500);
                printf("                                    Le livre ( %s ) ( numero %03d ) a %d exemplaire(s).\n\n", T_Titre[indicesResultats[0]], T_NLivre[indicesResultats[0]], T_Nbr_exp[indicesResultats[0]]);
                printf("                                    Nouveau nombre d'exemplaire pour ce livre : ");
                fgets(saisieNouveauNombre, sizeof(saisieNouveauNombre), stdin);
                saisieNouveauNombre[strcspn(saisieNouveauNombre, "\n")] = 0;
                if (verif_numero(saisieNouveauNombre) == 0)
                    err0("Veuillez entrer le nombre d'exemplaires du livre");
                else if ((atoi(saisieNouveauNombre)+nbExemplairesEmpruntes)>100)
                    err1("Veuillez ne pas depasser 100 copies");
                else
                {
                    nouveauNombreExemplaires = atoi(saisieNouveauNombre);
                    if (nouveauNombreExemplaires == T_Nbr_exp[indicesResultats[0]])
                    {
                        system("cls");
                        system("color 07");
                        printf("\n                                         ----------------------------------------------------------- \n");
                        printf("                                                  Le nombre d'exemplaire n'a pas change.\n");
                        printf("                                         ----------------------------------------------------------- \n");
                        system("pause");
                    }
                    else
                    {
                        T_Nbr_exp[indicesResultats[0]] = nouveauNombreExemplaires;
                        system("cls");
                        system("color 0A");
                        printf("                                         ----------------------------------------------------------- \n\n");
                        printf("                                                 Operation executee avec succes :\n");
                        printf("                                                 Livre ( %s ) (numero : %03d) a %d exemplaire(s) \n\n", titreRecherche,T_NLivre[indicesResultats[0]], nouveauNombreExemplaires);
                        printf("                                         ----------------------------------------------------------- \n");
                        system("pause");
                    }
                }
            }while(verif_numero(saisieNouveauNombre) == 0 || (atoi(saisieNouveauNombre)+nbExemplairesEmpruntes)>100);
        }
        else
        {
            do
            {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |-----------------   MODIFIER LE NOMBRE D'EXEMPLAIRES D'UN LIVRE   -------------------------| \n\n");
                Sleep(500);
                printf("                                     Il y a %d livres portant ce titre \n\n", nbOccurrences);
                Sleep(500);
                printf("                                    ------------------------------------------------------------------------------------------------ \n\n");
                printf("                                               Numero                  Titre                                  Exemplaire(s)  \n\n");
                printf("                                    ------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < nbOccurrences; i++)
                {
                    printf("                                                %-8.3d                %-25s                    %d   \n\n", T_NLivre[indicesResultats[i]], T_Titre[indicesResultats[i]], T_Nbr_exp[indicesResultats[i]]);
                    printf("                                    ------------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
                printf("                                     Numero du livre a modifier : ");
                fgets(saisieNouveauNombre, sizeof(saisieNouveauNombre), stdin);
                saisieNouveauNombre[strcspn(saisieNouveauNombre, "\n")] = 0;
                    if (verif_numero(saisieNouveauNombre) == 0)
                        err0("Veuillez entrer un des numero affiches");
                    else if (strlen(saisieNouveauNombre)!=3)
                        err1("le numero de livre doit contenir 3 chiffres");
                    else
                    {
                        nouveauNombreExemplaires = atoi(saisieNouveauNombre);
                        indexConfirme = 0;
                        for (i = 0; i < nbOccurrences; i++)
                        {
                            if (T_NLivre[indicesResultats[i]] == nouveauNombreExemplaires)
                                indexConfirme = indicesResultats[i] + 1;
                        }
                        if (indexConfirme == 0)
                        {
                            printf("\n                                         ----------------------------------------------------------- \n");
                            printf("                                                  Veuillez entrer un numero de livre existant.\n");
                            printf("                                         ----------------------------------------------------------- \n");
                            Sleep(1500);
                            saisieValide = 0;
                        }
                        else
                        {
                            do
                            {
                                saisieValide =0;
                                nbExemplairesEmpruntes =0;
                                for (i=0;i<nbe;i++)
                                {
                                    if (empruntsCourants[i][1]==T_NLivre[indicesResultats[0]])
                                        nbExemplairesEmpruntes++;
                                }
                                indicesResultats[0] = indexConfirme - 1;
                                system("cls");
                                system("color 0E");
                                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                                printf("                                   |-----------------   MODIFIER LE NOMBRE D'EXEMPLAIRES D'UN LIVRE   -------------------------| \n\n");
                                printf("                                        Numero du livre : %03d \n", T_NLivre[indicesResultats[0]]);
                                printf("                                        Titre du livre : %s \n", T_Titre[indicesResultats[0]]);
                                printf("                                        Nombre d'exemplaire courrant : %d (avec %d emprente).\n\n",T_Nbr_exp[indicesResultats[0]],nbExemplairesEmpruntes);
                                printf("                                        Nouveau nombre d'exemplaires pour ce livre : ");
                                fgets(saisieNouveauNombre, sizeof(saisieNouveauNombre), stdin);
                                saisieNouveauNombre[strcspn(saisieNouveauNombre, "\n")] = 0;
                                if (verif_numero(saisieNouveauNombre) == 0)
                                {
                                    err0("Veuillez entrer le nombre d'exemplaires du livre");
                                    saisieValide =0;
                                }
                                else if ((atoi(saisieNouveauNombre)+nbExemplairesEmpruntes)>100)
                                {
                                    if (nbExemplairesEmpruntes ==0)
                                    {
                                        err1("veuillez ne pas depasser 100 copies");
                                        saisieValide =0;
                                    }
                                    else
                                    {
                                        err1("veuillez ne pas depasser 100 copies(y compries ceux emprentes)");
                                        saisieValide =0;
                                    }
                                }
                                else
                                {
                                    nouveauNombreExemplaires = atoi(saisieNouveauNombre);
                                    if (nouveauNombreExemplaires == T_Nbr_exp[indicesResultats[0]])
                                    {
                                        system("cls");
                                        system("color 07");
                                        printf("\n                                         ----------------------------------------------------------- \n");
                                        printf("                                                  Le nombre d'exemplaire n'a pas change.\n");
                                        printf("                                         ----------------------------------------------------------- \n");
                                        system("pause");
                                        saisieValide =1;
                                    }
                                    else
                                    {
                                        T_Nbr_exp[indicesResultats[0]] = nouveauNombreExemplaires;
                                        system("cls");
                                        system("color 0A");
                                        printf("                                         ----------------------------------------------------------- \n\n");
                                        printf("                                                        Operation executee avec succes :\n");
                                        printf("                                                        Livre ( %s ) (numero %03d) a %d exemplaire(s) \n\n", titreRecherche,T_NLivre[indicesResultats[0]], nouveauNombreExemplaires);
                                        printf("                                         ----------------------------------------------------------- \n");
                                        system("pause");
                                        saisieValide = 1;
                                    }
                                }
                            }while(saisieValide ==0);
                        }
                    }
            } while (saisieValide == 0);
        }
    }
    return nbl;
}

void rechercherLivre(char T_Titre[][300], int T_NLivre[], int T_Nbr_exp[], int nbl)
{
    char saisieMode[10];
    char saisieNumero[10];
    char titreRecherche[300];
    int modeRecherche;
    int saisieValide;
    int numeroRecherche;
    int nbOccurrences;
    int i;
    int indicesResultats[300];
    system("cls");
    system("color 07");
    if (nbl == 0)
    {
        system("cls");
        system("color 0E");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                     La bibliotheque est vide.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("pause");
    }
    else
    {
        printf("                                   |------------------------------------------------------------------------------------------------| \n");
        printf("                                   |----------------------------       RECHERCHE D'UN LIVRE        ---------------------------------| \n\n");
        Sleep(500);
        printf("                                   |------------------------------------------------------------------------------------------------| \n");
        printf("                                         Effectuer la recherche en utilisant\n");
        printf("                                    ------------------------------------------------------------------------------------------------ \n");
        printf("                                             0: Le numero du livre                               1: le titre du livre\n");
        printf("                                    ------------------------------------------------------------------------------------------------ \n");
        printf("                                     Votre choix: ");
        fgets(saisieMode, sizeof(saisieMode), stdin);
        saisieMode[strcspn(saisieMode, "\n")] = 0;
        if (verif_numero(saisieMode) == 0)
        {
            err0("il faut taper 0 pour rechercher avec ID ou 1 pour rechercher avec titre");
        }
        else
        {
            modeRecherche = atoi(saisieMode);
            if (modeRecherche < 0 || modeRecherche > 1)
            {
                err1("Veuillez taper 0 pour rechercher avec ID ou 1 pour rechercher avec titre");
            }
            else if (modeRecherche == 0)
            {
                saisieValide =0;
                do
                {
                    system("cls");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |-----------------------       RECHERCHE D'UN LIVRE PAR NUMERO        ----------------------| \n\n");
                    Sleep(500);
                    printf("                                        Il y a %d livre(s) dans la bibliotheque.\n\n", nbl);
                    printf("                                        Donner le numero du livre recherche : ");
                    fgets(saisieNumero, sizeof(saisieNumero), stdin);
                    saisieNumero[strcspn(saisieNumero, "\n")] = 0;
                    if (verif_numero(saisieNumero) == 0)
                    {
                        err0("Veuillez taper un numero valide");
                        saisieValide =0;
                    }
                    else if (strlen(saisieNumero)!=3)
                    {
                        err1("veuillez entrer un numero de 3 chiffres");
                        saisieValide =0;
                    }
                    else
                    {
                        numeroRecherche = atoi(saisieNumero);
                        i = rechercherParNumero(numeroRecherche, T_NLivre, nbl);
                        if (i == -1)
                        {
                            system("cls");
                            system("color 0E");
                            printf("                                         ----------------------------------------------------------- \n\n");
                            printf("                                                  Ce Livre n'existe pas dans la bibliotheque.\n\n");
                            printf("                                         ----------------------------------------------------------- \n");
                            system("pause");
                            saisieValide =1;
                        }
                        else
                        {
                            system("cls");
                            printf("                                         ----------------------------------------------------------- \n\n");
                            printf("                                                     Livre numero %03d trouve.\n\n", numeroRecherche);
                            printf("                                         ----------------------------------------------------------- \n");
                            printf("                                               Titre : %s\n", T_Titre[i]);
                            printf("                                               Nombre d'exemplaire : %d\n", T_Nbr_exp[i]);
                            system("pause");
                            saisieValide =1;
                        }
                    }
                }while(saisieValide ==0);
            }
            else
            {
                system("cls");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |-----------------------       RECHERCHE D'UN LIVRE PAR TITRE        -----------------------| \n\n");
                Sleep(500);
                printf("                                        Il y a %d livre(s) dans la bibliotheque.\n\n", nbl);
                Sleep(500);
                printf("                                        Entrer le titre du livre recherche : ");
                fgets(titreRecherche, sizeof(titreRecherche), stdin);
                titreRecherche[strcspn(titreRecherche, "\n")] = 0;
                trim(titreRecherche);
                nbOccurrences = rechercherParTitre(titreRecherche, T_Titre, nbl, indicesResultats);
                if (nbOccurrences == 0)
                {
                    system("cls");
                    system("color 0E");
                    printf("                                         ----------------------------------------------------------- \n\n");
                    printf("                                                  Ce livre n'existe pas dans la bibliotheque.\n\n");
                    printf("                                         ----------------------------------------------------------- \n");
                    system("pause");
                }
                else if (nbOccurrences == 1)
                {
                    system("cls");
                    printf("                                         ----------------------------------------------------------- \n\n");
                    printf("                                                     Livre titre %s trouve.\n\n", T_Titre[indicesResultats[0]]);
                    printf("                                         ----------------------------------------------------------- \n");
                    printf("                                               Numero : %03d\n", T_NLivre[indicesResultats[0]]);
                    printf("                                               Nombre d'exemplaire : %d\n", T_Nbr_exp[indicesResultats[0]]);
                    system("pause");
                }
                else
                {
                    system("cls");
                    printf("                                   |-----------------------------------------------------------------------------------------------| \n");
                    printf("                                   |-------------------------       RECHERCHE D'UN LIVRE PAR TITRE        -------------------------| \n\n");
                    Sleep(500);
                    printf("                                     %d livres trouves portant ce titre ( %s ). \n\n", nbOccurrences, T_Titre[indicesResultats[0]]);
                    Sleep(500);
                    printf("                                    ------------------------------------------------------------------------------------------------ \n\n");
                    printf("                                              Numero                   Titre                                    Exemplaire(s)  \n\n");
                    printf("                                    ------------------------------------------------------------------------------------------------\n");
                    for (i = 0; i < nbOccurrences; i++)
                    {
                        printf("                                                %-8.3d                %-25s                    %d   \n\n", T_NLivre[indicesResultats[i]], T_Titre[indicesResultats[i]], T_Nbr_exp[indicesResultats[i]]);
                        printf("                                    ------------------------------------------------------------------------------------------------\n");
                        Sleep(100);
                    }
                    system("pause");
                }
            }
        }
    }
}

int emprunterLivre(int nbl, int T_NLivre[], char T_Titre[][300], int T_Nbr_exp[], int empruntsCourants[300][8], int nbe)
{
    int indexLivre;
    int choixUtilisateur;
    int cinUtilisateur;
    int numeroLivre;
    int jourRetourProche, moisRetourProche, anneeRetourProche;
    int j;
    int nbEmpruntsUtilisateur;
    int dateValide;
    int livreDisponible;
    int u;
    int saisieValide;
    char saisie[300];

    afficherLivres(T_NLivre, T_Titre, T_Nbr_exp, nbl, 0, " dans la bibliotheque");

    do
    {
        system("cls");
        system("color 07");
        printf("                            |------------------------------------------------------------------------------------------------| \n");
        printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
        Sleep(500);
        printf("                                  Voullez-vous emprenter un livre ?\n");
        printf("                             ------------------------------------------------------------------------------------------------ \n");
        printf("                                          0:non (retour)                                        1:oui (emprenter)\n");
        printf("                             ------------------------------------------------------------------------------------------------ \n");
        Sleep(500);
        printf("                                Votre choix: ");
        fgets(saisie, sizeof(saisie), stdin);
        saisie[strcspn(saisie, "\n")] = 0;
        if (verif_numero(saisie) == 0)
        {
            err0("Veuillez entrer 0 pour annuler ou 1 pour emprenter.");
            choixUtilisateur = -1;
        }
        else
        {
            choixUtilisateur = atoi(saisie);
            if (choixUtilisateur != 0 && choixUtilisateur != 1)
            {
                err1("Veuillez entrer 0 pour annuler ou 1 pour emprenter.");
                choixUtilisateur = -1;
            }
        }
    } while (choixUtilisateur == -1);

    if (choixUtilisateur == 1)
    {
        do
        {
            system("cls");
            system("color 07");
            printf("                            |------------------------------------------------------------------------------------------------| \n");
            printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
            Sleep(500);
            printf("                                Votre numero de CIN (8 chiffres): ");
            fgets(saisie, sizeof(saisie), stdin);
            saisie[strcspn(saisie, "\n")] = 0;
            if (verif_numero(saisie) == 0 )
            {
                err0("Veuillez entrer un numero CIN valide");
                cinUtilisateur = 0;
            }
            else
            {
                cinUtilisateur = atoi(saisie);
                if (strlen(saisie)!=8 || atoi(saisie)==0)
                    err1("Veuillez entrer un numero CIN de 8 chiffres");
            }
        } while (strlen(saisie)!=8 || cinUtilisateur==0);
        nbEmpruntsUtilisateur =0;
        for (indexLivre = 0; indexLivre < nbe; indexLivre++)
        {
            if (empruntsCourants[indexLivre][0] == cinUtilisateur)
                nbEmpruntsUtilisateur++;
        }
        if (nbEmpruntsUtilisateur > 7)
        {
            system("cls");
            system("color 06");
            printf("\n                                         -------------------------------------------------------------- \n");
            printf("                                                Vous ne pouvez pas emprenter plus de livres.\n");
            printf("                                                Vous avez deja emprente %d livres\n", nbEmpruntsUtilisateur);
            printf("                                                Retourner au moins %d livre(s) pour emprenter de plus.\n\n", nbEmpruntsUtilisateur - 6);
            printf("                                          -------------------------------------------------------------- \n");
            system("pause");
        }
        else
        {
            do
            {
                numeroLivre =0;
                system("cls");
                system("color 07");
                printf("                            |------------------------------------------------------------------------------------------------| \n");
                printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
                printf("                                CIN : %08d\n", cinUtilisateur);
                printf("                                Livre numero : ");
                fgets(saisie, sizeof(saisie), stdin);
                saisie[strcspn(saisie, "\n")] = 0;
                if (verif_numero(saisie) == 0)
                {
                    err0("Veuillez entrer un numero de livre valide.");
                    numeroLivre = -1;
                }
                else if (strlen(saisie)!=3)
                {
                    err1("veuiller saisir un numero de 3 chiffres");
                    numeroLivre = -1;
                }
            }while (numeroLivre ==-1);
            numeroLivre = atoi(saisie);
            if (rechercherParNumero(numeroLivre, T_NLivre, nbl) == -1)
            {
                system("cls");
                system("color 06");
                printf("                                         ----------------------------------------------------------- \n\n");
                printf("                                                  Ce livre n'existe pas dans la bibliotheque.\n\n");
                printf("                                         ----------------------------------------------------------- \n");
                system("pause");
            }
            else
            {
                livreDisponible =0;
                indexLivre =rechercherParNumero(numeroLivre, T_NLivre, nbl);
                if (T_Nbr_exp[indexLivre]==0)
                    livreDisponible =-1;
                if (livreDisponible ==-1)
                {
                    for (u = 0; u < nbl; u++)
                    {
                        if (T_NLivre[u] == numeroLivre)
                        {
                            if (T_Nbr_exp[u] == 0)
                            {
                                jourRetourProche = 31;
                                moisRetourProche = 12;
                                anneeRetourProche = 9999;
                                for (j = 0; j < nbe; j++)
                                {
                                    if (empruntsCourants[j][1] == numeroLivre)
                                    {
                                        if ((empruntsCourants[j][7] < anneeRetourProche) || (empruntsCourants[j][7] == anneeRetourProche && empruntsCourants[j][6] < moisRetourProche) || (empruntsCourants[j][7] == anneeRetourProche && empruntsCourants[j][6] == moisRetourProche && empruntsCourants[j][5] < jourRetourProche))
                                        {
                                            jourRetourProche = empruntsCourants[j][5];
                                            moisRetourProche = empruntsCourants[j][6];
                                            anneeRetourProche = empruntsCourants[j][7];
                                        }
                                    }
                                }
                            }
                            indexLivre =u;
                            u=nbl;
                        }
                    }
                    system("cls");
                    system("color 06");
                    printf("\n                                         -------------------------------------------------------------- \n");
                    printf("                                                Malheureusement,\n");
                    printf("                                                Ce livre est indisponible.\n");
                    printf("                                                (%s) sera disponible a partir de : %02d/%02d/%04d.\n", T_Titre[indexLivre], jourRetourProche, moisRetourProche, anneeRetourProche);
                    printf("                                          -------------------------------------------------------------- \n");
                    system("pause");
                }
                if (livreDisponible !=-1)
                {
                    T_Nbr_exp[indexLivre]--;
                    empruntsCourants[nbe][0] = cinUtilisateur;
                    empruntsCourants[nbe][1] = numeroLivre;
                    empruntsCourants[nbe][2] = nj;
                    empruntsCourants[nbe][3] = nm;
                    empruntsCourants[nbe][4] = ny;
                    saisieValide = 0;
                    while (saisieValide == 0 )
                    {
                        do
                        {
                            system("cls");
                            system("color 07");
                            printf("                            |------------------------------------------------------------------------------------------------| \n");
                            printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
                            printf("                                CIN : %08d\n", cinUtilisateur);
                            printf("                                Livre numero : %03d\n", numeroLivre);
                            printf("                                Titre : %s\n", T_Titre[indexLivre]);
                            printf("                                Date d'emprunt : %02d/%02d/%04d\n",nj,nm,ny);
                            printf("                                Jour de retour : ");
                            fgets(saisie, sizeof(saisie), stdin);
                            saisie[strcspn(saisie, "\n")] = 0;
                            if (verif_numero(saisie) == 0)
                            {
                                err0("Veuillez entrer un jour valide");
                                empruntsCourants[nbe][5] = 0;
                            }
                            else
                            {
                                empruntsCourants[nbe][5] = atoi(saisie);
                                if (empruntsCourants[nbe][5] <= 0 || empruntsCourants[nbe][5] > 31)
                                    err1("Veuillez entrer un jour valide");
                            }
                        } while (empruntsCourants[nbe][5] <= 0 || empruntsCourants[nbe][5] > 31);
                        do
                        {
                            system("cls");
                            system("color 07");
                            printf("                            |------------------------------------------------------------------------------------------------| \n");
                            printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
                            printf("                                CIN : %08d\n", cinUtilisateur);
                            printf("                                Livre numero : %03d\n", numeroLivre);
                            printf("                                Titre : %s\n", T_Titre[indexLivre]);
                            printf("                                Date d'emprunt : %02d/%02d/%04d\n",empruntsCourants[nbe][2],empruntsCourants[nbe][3],empruntsCourants[nbe][4]);
                            printf("                                Jour de retour : %02d\n", empruntsCourants[nbe][5]);
                            printf("                                Mois de retour : ");
                            fgets(saisie, sizeof(saisie), stdin);
                            saisie[strcspn(saisie, "\n")] = 0;
                            if (verif_numero(saisie) == 0)
                            {
                                err0("Veuillez entrer un mois valide");
                                empruntsCourants[nbe][6] = 0;
                            }
                            else
                            {
                                empruntsCourants[nbe][6] = atoi(saisie);
                                if (empruntsCourants[nbe][6] <= 0 || empruntsCourants[nbe][6] > 12)
                                    err1("Veuillez entrer un mois valide");
                            }
                        } while (empruntsCourants[nbe][6] <= 0 || empruntsCourants[nbe][6] > 12);
                        do
                        {
                            system("cls");
                            system("color 07");
                            printf("                            |------------------------------------------------------------------------------------------------| \n");
                            printf("                            |-------------------------------       EMPRENTER UN LIVRE        --------------------------------| \n\n");
                            printf("                                CIN : %08d\n", cinUtilisateur);
                            printf("                                Livre numero : %03d\n", numeroLivre);
                            printf("                                Titre : %s\n", T_Titre[indexLivre]);
                            printf("                                Date d'emprunt : %02d/%02d/%04d\n",empruntsCourants[nbe][2],empruntsCourants[nbe][3],empruntsCourants[nbe][4]);
                            printf("                                Jour de retour : %02d\n", empruntsCourants[nbe][5]);
                            printf("                                Mois de retour : %02d\n",empruntsCourants[nbe][6]);
                            printf("                                Annee de retour : ");
                            fgets(saisie, sizeof(saisie), stdin);
                            saisie[strcspn(saisie, "\n")] = 0;
                            if (verif_numero(saisie) == 0)
                            {
                                err0("Veuillez entrer une annee valide");
                                empruntsCourants[nbe][7] = 0;
                            }
                            else
                            {
                                empruntsCourants[nbe][7] = atoi(saisie);
                                if (empruntsCourants[nbe][7] < ny || empruntsCourants[nbe][7] > ny + 1)
                                    err1("Veuillez entrer l'annee de retour");
                            }
                        } while (empruntsCourants[nbe][7] < ny || empruntsCourants[nbe][7] > ny + 1);
                        dateValide = verif_date(empruntsCourants[nbe][7], empruntsCourants[nbe][6], empruntsCourants[nbe][5]);
                        if (dateValide ==1)
                        {
                            if ((calculerJoursDepuisEpoque(empruntsCourants[nbe][7], empruntsCourants[nbe][6], empruntsCourants[nbe][5])-calculerJoursDepuisEpoque(ny,nm,nj)>30))
                            {
                                system("cls");
                                system("color 06");
                                printf("                                        ------------------------------------------------------------------------------- \n\n");
                                printf("                                          La date de retour doit ne pas depasser 1 mois a partir de la date d'emprunt.\n");
                                printf("                                          Date d'emprunt : %02d/%02d/%04d\n\n", nj, nm, ny);
                                printf("                                        ------------------------------------------------------------------------------- \n\n");
                                system("pause");
                                saisieValide = 0;
                            }
                            else if ((calculerJoursDepuisEpoque(empruntsCourants[nbe][7], empruntsCourants[nbe][6], empruntsCourants[nbe][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0))
                            {
                                system("cls");
                                system("color 06");
                                printf("                                        ------------------------------------------------------------------------ \n\n");
                                printf("                                          La date de retour doit etre apres la date d'emprunt.\n");
                                printf("                                          Date d'emprunt : %02d/%02d/%04d\n\n", nj, nm, ny);
                                printf("                                        ------------------------------------------------------------------------ \n\n");
                                system("pause");
                                saisieValide = 0;
                            }
                            else
                            {
                                nbe++;
                                system("cls");
                                system("color 0A");
                                printf("                                         -------------------------------------------------------------- \n\n");
                                printf("                                                Emprunt effectue\n");
                                printf("                                                CIN: %08d\n", cinUtilisateur);
                                printf("                                                Livre: %s\n", T_Titre[indexLivre]);
                                printf("                                                Date d'emprunt : %02d/%02d/%04d\n",empruntsCourants[nbe-1][2],empruntsCourants[nbe-1][3],empruntsCourants[nbe-1][4]);
                                printf("                                                Date de retour: %02d/%02d/%04d\n", empruntsCourants[nbe - 1][5], empruntsCourants[nbe - 1][6], empruntsCourants[nbe - 1][7]);
                                printf("                                          -------------------------------------------------------------- \n");
                                system("pause");
                                saisieValide = 1;
                            }
                        }
                        else
                        {
                            system("cls");
                            system("color 0C");
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            printf("                                          La date de retour est invalide.\n\n");
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            system("pause");
                            saisieValide =0;
                        }
                    }
                }
            }

        }
    return nbe;
    }
}

void afficherEmpruntsAdherent(int empruntsCourants[300][8], int historiqueEmprunts[300][8], char T_Titre[300][300], int nbl, int nbk, int nbe)
{
    int i;
    int cinUtilisateur;
    int totalEmprunts;
    int indexLivre;
    char saisie[300];
    char etatEmprunt[300];
    char titreLivre[300];

    if (nbe == 0 && nbk == 0)
    {
        system("cls");
        system("color 0E");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("pause");
    }
    else
    {
        system("color 07");
        system("cls");
        do
        {
            system("cls");
            system("color 07");
            printf("                            |------------------------------------------------------------------------------------------------| \n");
            printf("                            |---------------------------        Consultation des emprunts        ----------------------------| \n\n");
            Sleep(500);
            printf("                                Votre numero de CIN (8 chiffres): ");
            fgets(saisie, sizeof(saisie), stdin);
            saisie[strcspn(saisie, "\n")] = 0;
            if (verif_numero(saisie) == 0)
            {
                err0("Veuillez entrer un numero CIN valide");
                cinUtilisateur = 0;
            }
            else
            {
                cinUtilisateur = atoi(saisie);
                if (strlen(saisie) != 8 || atoi(saisie) == 0)
                    err1("Veuillez entrer un numero CIN de 8 chiffres");
            }
        } while (strlen(saisie) != 8 || cinUtilisateur == 0);

        totalEmprunts = 0;
        for (i = 0; i < nbe; i++)
        {
            if (empruntsCourants[i][0] == cinUtilisateur)
                totalEmprunts++;
        }
        for (i = 0; i < nbk; i++)
        {
            if (historiqueEmprunts[i][0] == cinUtilisateur)
                totalEmprunts++;
        }

        if (totalEmprunts == 0)
        {
            system("cls");
            system("color 0E");
            printf("                                         ----------------------------------------------------------- \n\n");
            printf("                                                         Vous n'avez aucun emprunt.\n\n");
            printf("                                         ----------------------------------------------------------- \n");
        }
        else
        {
            system("cls");
            system("color 07");
            printf("                                  |-------------------------------------------------------------------------------------------------------| \n");
            printf("                                  |------------------------------        Consultation des emprunts        --------------------------------| \n\n");
            Sleep(500);
            printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
            printf("                                                                    Utilisateur : %08d \n", cinUtilisateur);
            printf("                                                                    Vous avez %d emprunt(s).\n\n", totalEmprunts);
            printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
            printf("                                        Numero           Titre                Date d'emprunt        Date de retour        Etat\n\n");
            printf("                                   -------------------------------------------------------------------------------------------------------\n");
            for (i = 0; i < nbk; i++)
            {
                if (historiqueEmprunts[i][0] == cinUtilisateur)
                {
                    indexLivre = rechercherParNumero(historiqueEmprunts[i][1], T_NLivre, nbl);
                    if (indexLivre == -1)
                        strcpy(titreLivre, "supprime");
                    else
                        strcpy(titreLivre, T_Titre[indexLivre]);

                    printf("                                        %-5.3d          %-20s     %02d/%02d/%04d          %02d/%02d/%04d          Retourne\n\n",
                           historiqueEmprunts[i][1], titreLivre, historiqueEmprunts[i][2], historiqueEmprunts[i][3], historiqueEmprunts[i][4], historiqueEmprunts[i][5], historiqueEmprunts[i][6], historiqueEmprunts[i][7]);
                    printf("                                   -------------------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
            }
            for (i = 0; i < nbe; i++)
            {
                if (empruntsCourants[i][0] == cinUtilisateur)
                {
                    indexLivre = rechercherParNumero(empruntsCourants[i][1], T_NLivre, nbl);
                    if (indexLivre == -1)
                        strcpy(titreLivre, "supprime");
                    else
                        strcpy(titreLivre, T_Titre[indexLivre]);

                    if (calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5]) - calculerJoursDepuisEpoque(ny, nm, nj) < 0)
                        strcpy(etatEmprunt, "Retard de retour");
                    else
                        strcpy(etatEmprunt, "Emprunte");

                    printf("                                        %-5.3d          %-20s     %02d/%02d/%04d          %02d/%02d/%04d          %-10s\n\n",
                           empruntsCourants[i][1], titreLivre, empruntsCourants[i][2], empruntsCourants[i][3], empruntsCourants[i][4], empruntsCourants[i][5], empruntsCourants[i][6], empruntsCourants[i][7], etatEmprunt);
                    printf("                                   -------------------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
            }
        }
    }
    system("pause");
}

void retournerLivre(int empruntsCourants[300][8],int historiqueEmprunts[300][8], char T_Titre[300][300])
{
    char saisieCIN[300];
    char saisieNumeroLivre[300];
    char titreLivre[300];
    char etatRetour[300];
    int cinUtilisateur;
    int indexEmpruntSelectionne;
    int i;
    int indexLivre;
    int saisieValide;
    int numeroLivreChoisi;
    int numeroLivreCopie;
    int nbEmpruntsUtilisateur;
    int j;
    if (nbl==0)
    {
        system("cls");
        system("color 0E");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("color 07");
        system("cls");
    }
    else
    {
        do
        {
            system("cls");
            system("color 07");
            printf("                            |------------------------------------------------------------------------------------------------| \n");
            printf("                            |-------------------------------        Retour d'un livre        --------------------------------| \n\n");
            Sleep(500);
            printf("                                Votre numero de CIN (8 chiffres): ");
            fgets(saisieCIN, sizeof(saisieCIN), stdin);
            saisieCIN[strcspn(saisieCIN, "\n")] = 0;
            if (verif_numero(saisieCIN) == 0 )
            {
                err0("Veuillez entrer un numero CIN valide");
                cinUtilisateur = 0;
            }
            else
            {
                cinUtilisateur = atoi(saisieCIN);
                if (strlen(saisieCIN)!=8 || atoi(saisieCIN)==0)
                    err1("Veuillez entrer un numero CIN de 8 chiffres");
            }
        } while (strlen(saisieCIN)!=8 || cinUtilisateur==0);
        nbEmpruntsUtilisateur =0;
        for (i=0;i<nbe;i++)
        {
            if (empruntsCourants[i][0]==cinUtilisateur)
                nbEmpruntsUtilisateur++;
        }
        if (nbEmpruntsUtilisateur==0)
        {
            system("cls");
            system("color 0E");
            printf("                                         ----------------------------------------------------------- \n\n");
            printf("                                                         vous n'avez aucun emprunt.\n\n");
            printf("                                         ----------------------------------------------------------- \n");
        }
        else
        {
            saisieValide=0;
            do
            {
                system("cls");
                system("color 07");
                printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
                printf("                                                                    Utilisateur : %08d \n",cinUtilisateur);
                printf("                                                                    Vous avez %d emprunt(s).\n\n", nbEmpruntsUtilisateur);
                printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
                printf("                                        Numero           Titre                Date d'emprunt        Date de retour        Etat\n\n");
                printf("                                   -------------------------------------------------------------------------------------------------------\n");
                for (i = 0; i < nbe; i++)
                {
                    if (empruntsCourants[i][0]==cinUtilisateur)
                    {
                        indexLivre =rechercherParNumero(empruntsCourants[i][1], T_NLivre, nbl );
                        if(calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0)
                            strcpy(etatRetour,"Retard de retour");
                        else
                            strcpy(etatRetour,"Emprunte");
                        printf("                                        %-5.3d          %-20s     %02d/%02d/%04d          %02d/%02d/%04d          %-10s\n\n",empruntsCourants[i][1],T_Titre[indexLivre],empruntsCourants[i][2],empruntsCourants[i][3],empruntsCourants[i][4],empruntsCourants[i][5],empruntsCourants[i][6],empruntsCourants[i][7],etatRetour);
                        printf("                                   -------------------------------------------------------------------------------------------------------\n");
                        Sleep(100);
                    }
                }
                printf("                                      Numero du livre a retourner : ");
                fgets(saisieNumeroLivre, sizeof(saisieNumeroLivre), stdin);
                saisieNumeroLivre[strcspn(saisieNumeroLivre, "\n")] = 0;
                if (verif_numero(saisieNumeroLivre) == 0)
                {
                    err0("Veuillez entrer un des numero affiches");
                    saisieValide=0;
                }
                else if (atoi(saisieNumeroLivre)<100 || atoi(saisieNumeroLivre)>999)
                {
                    err1("le numero de livre doit contenir 3 chiffres");
                    saisieValide=0;
                }
                else
                {
                    numeroLivreChoisi = atoi(saisieNumeroLivre);
                    indexEmpruntSelectionne = -1;
                    for (i = 0; i < nbe; i++)
                    {
                        if (empruntsCourants[i][1] == numeroLivreChoisi && empruntsCourants[i][0]==cinUtilisateur)
                        {
                            indexEmpruntSelectionne = i;
                        }
                    }
                    if (indexEmpruntSelectionne == -1)
                    {
                        printf("\n                                         ----------------------------------------------------------- \n");
                        printf("                                                  Veuillez entrer le numero du livre emprunte.\n");
                        printf("                                         ----------------------------------------------------------- \n");
                        Sleep(1500);
                        saisieValide=0;
                    }
                    else
                    {
                        indexLivre =rechercherParNumero(empruntsCourants[indexEmpruntSelectionne][1],T_NLivre,nbl);
                        T_Nbr_exp[indexLivre]++;
                        numeroLivreCopie =T_NLivre[indexLivre];
                        strcpy(titreLivre,T_Titre[indexLivre]);
                        historiqueEmprunts[nbk][0]=empruntsCourants[indexEmpruntSelectionne][0];
                        historiqueEmprunts[nbk][1]=empruntsCourants[indexEmpruntSelectionne][1];
                        historiqueEmprunts[nbk][2]=empruntsCourants[indexEmpruntSelectionne][2];
                        historiqueEmprunts[nbk][3]=empruntsCourants[indexEmpruntSelectionne][3];
                        historiqueEmprunts[nbk][4]=empruntsCourants[indexEmpruntSelectionne][4];
                        historiqueEmprunts[nbk][5]=nj;
                        historiqueEmprunts[nbk][6]=nm;
                        historiqueEmprunts[nbk][7]=ny;
                        nbk++;
                        for (j = indexEmpruntSelectionne; j < nbe - 1; j++)
                        {
                            empruntsCourants[j][0]=empruntsCourants[j+1][0];
                            empruntsCourants[j][1]=empruntsCourants[j+1][1];
                            empruntsCourants[j][2]=empruntsCourants[j+1][2];
                            empruntsCourants[j][3]=empruntsCourants[j+1][3];
                            empruntsCourants[j][4]=empruntsCourants[j+1][4];
                            empruntsCourants[j][5]=empruntsCourants[j+1][5];
                            empruntsCourants[j][6]=empruntsCourants[j+1][6];
                            empruntsCourants[j][7]=empruntsCourants[j+1][7];
                        }
                        nbe--;
                        system("cls");
                        system("color 0A");
                        printf("                                             ---------------------------------------------------------------- \n\n");
                        printf("                                                  Operation executee avec succes :\n");
                        printf("                                                  Livre (%03d: %s) retourne \n\n",numeroLivreCopie,titreLivre);
                        printf("                                             ---------------------------------------------------------------- \n");
                        system("pause");
                        saisieValide=1;
                    }
                }
            }while(saisieValide==0);
        }
    }
}

void afficherEmpruntsFiltres(int empruntsCourants[300][8],char T_Titre[300][300],int T_NLivre[],int nbe, int nbl, int filtreRetard,char message[])
{
    int nbEmpruntsAffiches = 0;
    int i;
    int indexLivre;
    char etatEmprunt[300];
    system("color 07");
    system("cls");
    if (nbe == 0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        for (i=0;i<nbe;i++)
        {
            if(calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0)
                nbEmpruntsAffiches++;
        }
        if (filtreRetard==1)
            nbEmpruntsAffiches =nbe;
        if (nbEmpruntsAffiches==0)
        {
            system("cls");
            system("color 06");
            printf("                                         ----------------------------------------------------------- \n\n");
            printf("                                                         Il n'y a aucun retour en retard.\n\n");
            printf("                                         ----------------------------------------------------------- \n");
        }
        else
        {
            printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
            printf("                                                                 Il y a %d %s.\n\n", nbEmpruntsAffiches,message);
            printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
            printf("                                        Numero           Titre                Date d'emprunt        Date de retour        Etat\n\n");
            printf("                                   -------------------------------------------------------------------------------------------------------\n");
            for (i = 0; i < nbe; i++)
            {
                indexLivre =rechercherParNumero(empruntsCourants[i][1], T_NLivre, nbl );
                if(calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0)
                {
                    strcpy(etatEmprunt,"Retard de retour");
                    printf("                                        %-5.3d          %-20s     %02d/%02d/%04d          %02d/%02d/%04d          %-10s\n\n",empruntsCourants[i][1],T_Titre[indexLivre],empruntsCourants[i][2],empruntsCourants[i][3],empruntsCourants[i][4],empruntsCourants[i][5],empruntsCourants[i][6],empruntsCourants[i][7],etatEmprunt);
                    printf("                                   -------------------------------------------------------------------------------------------------------\n");
                    Sleep(100);
                }
                else
                {
                    if (filtreRetard==1)
                    {
                        strcpy(etatEmprunt,"Emprunte");
                        printf("                                        %-5.3d          %-20s     %02d/%02d/%04d          %02d/%02d/%04d          %-10s\n\n",empruntsCourants[i][1],T_Titre[indexLivre],empruntsCourants[i][2],empruntsCourants[i][3],empruntsCourants[i][4],empruntsCourants[i][5],empruntsCourants[i][6],empruntsCourants[i][7],etatEmprunt);
                        printf("                                   -------------------------------------------------------------------------------------------------------\n");
                        Sleep(100);
                    }
                }
            }
        }
    }
    system("pause");
}

void afficherEmpruntsParDate(int empruntsCourants[300][8],int historiqueEmprunts[300][8],char T_Titre[300][300],int T_NLivre[],int nbe, int nbl,int nbk)
{
   int nbEmpruntsTrouves = 0;
    int jourRecherche, moisRecherche, anneeRecherche;
    int i;
    int indexLivre;
    char etatEmprunt[300];
    char saisie[300];
    int dateValide = 0;
    if (nbe == 0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        do {
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |---------------     Les emprunts relatifs a une date de retour prevue       ---------------| \n\n");
                Sleep(500);
                printf("                                    veuiller saisir la date de retour prevue\n");
                printf("                                    Jour : ");
                fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un jour valide");
                        jourRecherche = 0;
                    }
                    else
                    {
                        jourRecherche = atoi(saisie);
                        if (jourRecherche <= 0 || jourRecherche > 31)
                            err1("Veuillez entrer un jour valide");
                    }
                } while (jourRecherche <= 0 || jourRecherche > 31);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |---------------     Les emprunts relatifs a une date de retour prevue       ---------------| \n\n");
                    printf("                                    veuiller saisir la date de retour prevue\n");
                    printf("                                    Jour : %02d\n",jourRecherche);
                    printf("                                    Mois : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un mois valide");
                        moisRecherche = 0;
                    }
                    else
                    {
                        moisRecherche = atoi(saisie);
                        if (moisRecherche <= 0 || moisRecherche > 12)
                            err1("Veuillez entrer un mois valide");
                    }
                } while (moisRecherche <= 0 || moisRecherche > 12);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |---------------     Les emprunts relatifs a une date de retour prevue       ---------------| \n\n");
                    printf("                                    veuiller saisir la date de retour prevu\n");
                    printf("                                    Jour : %02d\n",jourRecherche);
                    printf("                                    Mois : %02d\n",moisRecherche);
                    printf("                                    Annee : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer une annee valide");
                        anneeRecherche = 0;
                    }
                    else
                    {
                        anneeRecherche = atoi(saisie);
                        if (anneeRecherche < 2000 || anneeRecherche > 2500)
                            err1("Veuillez entrer une annee valide");
                    }
                } while (anneeRecherche < 2000 || anneeRecherche > 2500);
                if (verif_date(anneeRecherche, moisRecherche, jourRecherche) == 0)
                {
                    system("cls");
                    system("color 0C");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    printf("                                                     La date est invalide.\n\n");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    system("pause");
                    dateValide = 0;
                }
                else
                    dateValide=1;
            } while (dateValide == 0);
            if (dateValide==1)
            {
                for(i=0;i<nbe;i++)
                {
                    if (empruntsCourants[i][7]==anneeRecherche && empruntsCourants[i][6]==moisRecherche && empruntsCourants[i][5]==jourRecherche)
                        nbEmpruntsTrouves++;
                }
                for(i=0;i<nbk;i++)
                {
                    if (historiqueEmprunts[i][7]==anneeRecherche && historiqueEmprunts[i][6]==moisRecherche && historiqueEmprunts[i][5]==jourRecherche)
                        nbEmpruntsTrouves++;
                }
                if (nbEmpruntsTrouves==0)
                {
                    system("cls");
                    system("color 06");
                    printf("                                         ---------------------------------------------------------------- \n\n");
                    printf("                                            Il y a n'y a aucun livre prevu retourne le %02d/%02d/%04d.\n\n",jourRecherche,moisRecherche,anneeRecherche);
                    printf("                                         ---------------------------------------------------------------- \n");
                }
                else
                {
                    system("cls");
                    system("color 07");
                    printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
                    printf("                                                        Il y a %d livre(s) prevu(s) retourne(s) le %02d/%02d/%04d.\n\n", nbEmpruntsTrouves,jourRecherche,moisRecherche,anneeRecherche);
                    printf("                                   ------------------------------------------------------------------------------------------------------- \n\n");
                    printf("                                     Numero            Titre                CIN       Date d'emprunt        Date de retour        Etat\n\n");
                    printf("                                   -------------------------------------------------------------------------------------------------------\n");
                    for (i = 0; i < nbe; i++)
                    {
                        indexLivre =rechercherParNumero(empruntsCourants[i][1], T_NLivre, nbl );
                        if (empruntsCourants[i][7]==anneeRecherche && empruntsCourants[i][6]==moisRecherche && empruntsCourants[i][5]==jourRecherche)
                        {
                            if(calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0)
                                strcpy(etatEmprunt,"Retard de retour");
                            else
                                strcpy(etatEmprunt,"Emprunte");
                            printf("                                     %-5.3d          %-20s %08d     %02d/%02d/%04d          %02d/%02d/%04d          %-10s\n\n",empruntsCourants[i][1],T_Titre[indexLivre],empruntsCourants[i][0],empruntsCourants[i][2],empruntsCourants[i][3],empruntsCourants[i][4],empruntsCourants[i][5],empruntsCourants[i][6],empruntsCourants[i][7],etatEmprunt);
                            printf("                                   -------------------------------------------------------------------------------------------------------\n");
                            Sleep(100);
                        }
                    }
                    for (i = 0; i < nbk; i++)
                    {
                        indexLivre =rechercherParNumero(historiqueEmprunts[i][1], T_NLivre, nbl );
                        if (indexLivre==-1)
                            strcpy(etatEmprunt,"supprime");
                        else
                            strcpy(etatEmprunt,T_Titre[indexLivre]);
                        if (historiqueEmprunts[i][7]==anneeRecherche && historiqueEmprunts[i][6]==moisRecherche && historiqueEmprunts[i][5]==jourRecherche)
                        {
                            printf("                                     %-5.3d          %-20s %08d     %02d/%02d/%04d          %02d/%02d/%04d          Retourne\n\n",historiqueEmprunts[i][1],etatEmprunt,historiqueEmprunts[i][0],historiqueEmprunts[i][2],historiqueEmprunts[i][3],historiqueEmprunts[i][4],historiqueEmprunts[i][5],historiqueEmprunts[i][6],historiqueEmprunts[i][7]);
                            printf("                                   -------------------------------------------------------------------------------------------------------\n");
                            Sleep(100);
                            system("pause");
                        }
                    }
                }
            }
        }
    }


int supprimerEmpruntsParPeriode()
{
    int jourEmprunt, moisEmprunt, anneeEmprunt;
    int jourRetour, moisRetour, anneeRetour;
    int i;
    int indexLivre;
    int nbEmpruntsCorrespondants;
    int choixUtilisateur;
    int dateValide;
    int saisieValide;
    int empruntsTrouves;
    char saisie[300];
    char etatEmprunt[300];
    int j;
    if (nbe == 0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
        system("pause");
    }
    else
    {
        afficherEmpruntsFiltres(empruntsCourants,T_Titre,T_NLivre,nbe,nbl,1,"emprunt(s) en cours");
        do {
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                Sleep(500);
                printf("                                    veuiller saisir la date d'emprunt\n");
                printf("                                    Jour : ");
                fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un jour valide");
                        jourEmprunt = 0;
                    }
                    else
                    {
                        jourEmprunt = atoi(saisie);
                        if (jourEmprunt <= 0 || jourEmprunt > 31)
                            err1("Veuillez entrer un jour valide");
                    }
                } while (jourEmprunt <= 0 || jourEmprunt > 31);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                    printf("                                    veuiller saisir la date d'emprunt \n");
                    printf("                                    Jour : %02d\n",jourEmprunt);
                    printf("                                    Mois : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un mois valide");
                        moisEmprunt = 0;
                    }
                    else
                    {
                        moisEmprunt = atoi(saisie);
                        if (moisEmprunt <= 0 || moisEmprunt > 12)
                            err1("Veuillez entrer un mois valide");
                    }
                } while (moisEmprunt <= 0 || moisEmprunt > 12);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                    printf("                                    veuiller saisir la date d'emprunt\n");
                    printf("                                    Jour : %02d\n",jourEmprunt);
                    printf("                                    Mois : %02d\n",moisEmprunt);
                    printf("                                    Annee : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer une annee valide");
                        anneeEmprunt = 0;
                    }
                    else
                    {
                        anneeEmprunt = atoi(saisie);
                        if (anneeEmprunt < 2000 || anneeEmprunt > 2500)
                            err1("Veuillez entrer une annee valide");
                    }
                } while (anneeEmprunt < 2000 || anneeEmprunt > 2500);
                if (verif_date(anneeEmprunt, moisEmprunt, jourEmprunt) == 0)
                {
                    system("cls");
                    system("color 0C");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    printf("                                                            La date d'emprunt est invalide.\n\n");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    system("pause");
                    saisieValide = 0;
                }
                else
                    saisieValide=1;
            } while (saisieValide == 0);
            nbEmpruntsCorrespondants=0;
            for (i=0;i<nbe;i++)
            {
                if (empruntsCourants[i][2]==jourEmprunt && empruntsCourants[i][3]==moisEmprunt && empruntsCourants[i][4]==anneeEmprunt)
                    nbEmpruntsCorrespondants++;
            }
            if (nbEmpruntsCorrespondants==0)
            {
                system("cls");
                system("color 06");
                printf("                                        ------------------------------------------------------------------------ \n\n");
                printf("                                            Aucun emprunt ne correspent a %02d/%02d/%04d.\n\n",jourEmprunt,moisEmprunt,anneeEmprunt);
                printf("                                        ------------------------------------------------------------------------ \n\n");
                system("pause");
            }
            else
            {
                dateValide= 0;
                do {
                    do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                    Sleep(500);
                    printf("                                    Date d'emprunt : %02d/%02d/%04d.\n\n",jourEmprunt,moisEmprunt,anneeEmprunt);
                    Sleep(250);
                    printf("                                    veuiller saisir la date de retour \n");
                    printf("                                    Jour : ");
                    fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer un jour valide");
                            jourRetour = 0;
                        }
                        else
                        {
                            jourRetour = atoi(saisie);
                            if (jourRetour <= 0 || jourRetour > 31)
                                err1("Veuillez entrer un jour valide");
                        }
                    } while (jourRetour <= 0 || jourRetour > 31);
                    do {
                        system("cls");
                        system("color 07");
                        printf("                                   |-------------------------------------------------------------------------------------------| \n");
                        printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                        printf("                                    Date d'emprunt : %02d/%02d/%04d.\n\n",jourEmprunt,moisEmprunt,anneeEmprunt);
                        printf("                                    veuiller saisir la date de retour \n");
                        printf("                                    Jour : %02d\n",jourRetour);
                        printf("                                    Mois : ");
                        fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer un mois valide");
                            moisRetour = 0;
                        }
                        else
                        {
                            moisRetour = atoi(saisie);
                            if (moisRetour <= 0 || moisRetour > 12)
                                err1("Veuillez entrer un mois valide");
                        }
                    } while (moisRetour <= 0 || moisRetour > 12);
                    do {
                        system("cls");
                        system("color 07");
                        printf("                                   |-------------------------------------------------------------------------------------------| \n");
                        printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                        printf("                                    Date d'emprunt : %02d/%02d/%04d.\n\n",jourEmprunt,moisEmprunt,anneeEmprunt);
                        printf("                                    veuiller saisir la date de retour\n");
                        printf("                                    Jour : %02d\n",jourRetour);
                        printf("                                    Mois : %02d\n",moisRetour);
                        printf("                                    Annee : ");
                        fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer une annee valide");
                            anneeRetour = 0;
                        }
                        else
                        {
                            anneeRetour = atoi(saisie);
                            if (anneeRetour < 2000 || anneeRetour > 2500)
                                err1("Veuillez entrer une annee valide");
                        }
                    } while (anneeRetour < 2000 || anneeRetour > 2500);
                    if (verif_date(anneeRetour, moisRetour, jourRetour) == 0)
                    {
                        system("cls");
                        system("color 0C");
                        printf("                                        ------------------------------------------------------------------------ \n\n");
                        printf("                                                          La date de retour est invalide.\n\n");
                        printf("                                        ------------------------------------------------------------------------ \n\n");
                        system("pause");
                        dateValide = 0;
                    }
                    else
                    {
                        if (calculerJoursDepuisEpoque(anneeRetour, moisRetour, jourRetour)-calculerJoursDepuisEpoque(anneeEmprunt,moisEmprunt,jourEmprunt)>30)
                        {
                            system("cls");
                            system("color 06");
                            printf("                                        ------------------------------------------------------------------------------- \n\n");
                            printf("                                          La date de retour ne peut pas depasser 1 mois a partir de la date d'emprunt.\n");
                            printf("                                          Date d'emprunt : %02d/%02d/%04d\n\n", jourEmprunt, moisEmprunt, anneeEmprunt);
                            printf("                                        ------------------------------------------------------------------------------- \n\n");
                            system("pause");
                            dateValide=0;
                        }
                        else if (calculerJoursDepuisEpoque(anneeRetour, moisRetour, jourRetour)-calculerJoursDepuisEpoque(anneeEmprunt,moisEmprunt,jourEmprunt)<0)
                        {
                            system("cls");
                            system("color 06");
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            printf("                                          La date de retour doit etre apres la date d'emprunt.\n");
                            printf("                                          Date d'emprunt : %02d/%02d/%04d\n\n", jourEmprunt, moisEmprunt, anneeEmprunt);
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            system("pause");
                            dateValide = 0;
                        }
                        else
                            dateValide=1;
                    }
                } while (dateValide == 0);
            do
            {
                nbEmpruntsCorrespondants=0;
                for (i=0;i<nbe;i++)
                {
                    if (empruntsCourants[i][2]==jourEmprunt && empruntsCourants[i][3]==moisEmprunt && empruntsCourants[i][4]==anneeEmprunt && empruntsCourants[i][5]==jourRetour && empruntsCourants[i][6]==moisRetour && empruntsCourants[i][7]==anneeRetour)
                        nbEmpruntsCorrespondants++;
                }
                if (nbEmpruntsCorrespondants==0)
                {
                    system("cls");
                    system("color 0C");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    printf("                                            Aucun emprunt ne correspent a %02d/%02d/%04d ---> %02d/%02d/%04d.\n\n",jourEmprunt,moisEmprunt,anneeEmprunt,jourRetour,moisRetour,anneeRetour);
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    system("pause");
                    empruntsTrouves = 0;
                }
                else
                {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |--------------------         Supprimer ensemble des emprunts          ---------------------| \n\n");
                    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
                    printf("                                                     Il y a %d emprunt(s) pour %02d/%02d/%04d ---> %02d/%02d/%04d.\n\n", nbEmpruntsCorrespondants,jourEmprunt,moisEmprunt,anneeEmprunt,jourRetour,moisRetour,anneeRetour);
                    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
                    printf("                                            Numero                 Titre                       CIN                   Etat\n\n");
                    printf("                                   ---------------------------------------------------------------------------------------------\n");
                    for (i=0;i<nbe;i++)
                    {
                        if (empruntsCourants[i][2]==jourEmprunt && empruntsCourants[i][3]==moisEmprunt && empruntsCourants[i][4]==anneeEmprunt && empruntsCourants[i][5]==jourRetour && empruntsCourants[i][6]==moisRetour && empruntsCourants[i][7]==anneeRetour)
                        {
                            indexLivre =rechercherParNumero(empruntsCourants[i][1], T_NLivre, nbl );
                            if(calculerJoursDepuisEpoque(empruntsCourants[i][7], empruntsCourants[i][6], empruntsCourants[i][5])-calculerJoursDepuisEpoque(ny,nm,nj)<0)
                                strcpy(etatEmprunt,"Retard de retour");
                            else
                                strcpy(etatEmprunt,"Emprunte");
                            printf("                                            %-5.3d                %-20s        %08d               %-10s\n\n",empruntsCourants[i][1],T_Titre[indexLivre],empruntsCourants[i][0],etatEmprunt);
                            printf("                                   ---------------------------------------------------------------------------------------------\n");
                            Sleep(100);
                        }
                    }
                    Sleep(500);
                    printf("\n                                      Voullez-vous supprimer ces emprunt(s) ?\n");
                    printf("                                   --------------------------------------------------------------------------------------------- \n");
                    printf("                                             0:non (retour)                                        1:oui (supprimer)\n");
                    printf("                                   --------------------------------------------------------------------------------------------- \n");
                    Sleep(500);
                    printf("                                       Votre choix: ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer 0 pour annuler ou 1 pour supprimer.");
                        empruntsTrouves = -1;
                    }
                    else
                    {
                        empruntsTrouves = atoi(saisie);
                        if (empruntsTrouves != 0 && empruntsTrouves != 1)
                        {
                            err1("Veuillez entrer 0 pour annuler ou 1 pour supprimer.");
                            empruntsTrouves = -1;
                        }
                    }
                }
            } while (empruntsTrouves == -1);
            if (empruntsTrouves==1)
            {
                for (choixUtilisateur = nbe - 1; choixUtilisateur >= 0; choixUtilisateur--)
                {
                    if (empruntsCourants[choixUtilisateur][2]==jourEmprunt && empruntsCourants[choixUtilisateur][3]==moisEmprunt && empruntsCourants[choixUtilisateur][4]==anneeEmprunt && empruntsCourants[choixUtilisateur][5]==jourRetour && empruntsCourants[choixUtilisateur][6]==moisRetour && empruntsCourants[choixUtilisateur][7]==anneeRetour)
                    {
                            indexLivre =rechercherParNumero(empruntsCourants[choixUtilisateur][1],T_NLivre,nbl);
                            T_Nbr_exp[indexLivre]++;
                            historiqueEmprunts[nbk][0]=empruntsCourants[choixUtilisateur][0];
                            historiqueEmprunts[nbk][1]=empruntsCourants[choixUtilisateur][1];
                            historiqueEmprunts[nbk][2]=empruntsCourants[choixUtilisateur][2];
                            historiqueEmprunts[nbk][3]=empruntsCourants[choixUtilisateur][3];
                            historiqueEmprunts[nbk][4]=empruntsCourants[choixUtilisateur][4];
                            historiqueEmprunts[nbk][5]=empruntsCourants[choixUtilisateur][5];
                            historiqueEmprunts[nbk][6]=empruntsCourants[choixUtilisateur][6];
                            historiqueEmprunts[nbk][7]=empruntsCourants[choixUtilisateur][7];
                            nbk++;
                            for (j = choixUtilisateur; j < nbe - 1; j++)
                            {
                                empruntsCourants[j][0]=empruntsCourants[j+1][0];
                                empruntsCourants[j][1]=empruntsCourants[j+1][1];
                                empruntsCourants[j][2]=empruntsCourants[j+1][2];
                                empruntsCourants[j][3]=empruntsCourants[j+1][3];
                                empruntsCourants[j][4]=empruntsCourants[j+1][4];
                                empruntsCourants[j][5]=empruntsCourants[j+1][5];
                                empruntsCourants[j][6]=empruntsCourants[j+1][6];
                                empruntsCourants[j][7]=empruntsCourants[j+1][7];
                            }
                            nbe--;
                    }
                }
                            system("cls");
                            system("color 0A");
                            printf("                                             ---------------------------------------------------------------- \n\n");
                            printf("                                                  Operation executee avec succes :\n");
                            printf("                                                  %d livre(s) retourne \n\n",nbEmpruntsCorrespondants);
                            printf("                                             ---------------------------------------------------------------- \n");
                            system("pause");
                            afficherEmpruntsFiltres(empruntsCourants,T_Titre,T_NLivre,nbe,nbl,1,"emprunt(s) en cours");
            }
        }
    }
    return nbe;
}

void afficherStatistiquesBasiques(int T_NLivre[] ,int T_Nbr_exp[],int empruntsCourants[300][8],int historiqueEmprunts[300][8],int nbe,int nbk,int nbl)
{
    int nbAdherentsCourants = 0;
    int nbAdherentsHistorique = 0;
    int totalExemplaires;
    int i;
    int j;
    int dejaCompte;
    int cinsDejaComptes[300];
    totalExemplaires=0;
    for(i=0;i<nbl;i++)
        totalExemplaires=totalExemplaires+T_Nbr_exp[i];
    for (i=0;i<nbe;i++)
    {
        dejaCompte=0;
        for (j=0;j<nbe;j++)
        {
            if (empruntsCourants[i][0]==cinsDejaComptes[j])
                dejaCompte=1;
        }
        if (dejaCompte==0)
        {
            cinsDejaComptes[nbAdherentsCourants]=empruntsCourants[i][0];
            nbAdherentsCourants++;
        }
    }
    for (i=0;i<nbk;i++)
    {
        dejaCompte=0;
        for (j=0;j<nbk;j++)
        {
            if (historiqueEmprunts[i][0]==cinsDejaComptes[j])
                dejaCompte=1;
        }
        if (dejaCompte==0)
        {
            cinsDejaComptes[nbAdherentsHistorique]=historiqueEmprunts[i][0];
            nbAdherentsHistorique++;
        }
    }
    system("cls");
    system("color 07");
    printf("                                   |-------------------------------------------------------------------------------------------| \n");
    printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
    Sleep(500);
    printf("\n\n                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre de livre dans la bibliotheque :");
    Sleep(500);
    printf(" %d\n",nbl);
    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre de copies des livre dans la bibliotheque :");
    Sleep(500);
    printf(" %d \n",totalExemplaires);
    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre des adherents courrants :");
    Sleep(500);
    printf(" %d\n",nbAdherentsCourants);
    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre des emprunts courrants :");
    Sleep(500);
    printf(" %d\n",nbe);
    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre des adherents total :");
    Sleep(500);
    printf(" %d\n",nbAdherentsCourants+nbAdherentsHistorique);
    printf("                                   --------------------------------------------------------------------------------------------- \n\n");
    Sleep(500);
    printf("                                    Nombre des emprunts total :");
    Sleep(500);
    printf(" %d\n",nbe+nbk);
    printf("                                   --------------------------------------------------------------------------------------------- \n");
    system("pause");
}

void afficherLivresPlusEmpruntes()
{
    int i;
    int j;
    int empruntsCourantsLivre;
    int empruntsTotauxLivre;
    int maxEmprunts = 0;
    if (nbe==0 && nbk==0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        for (i = 0; i < nbl; i++)
        {
            empruntsCourantsLivre = 0;
            empruntsTotauxLivre = 0;
            for (j = 0; j < nbe; j++)
            {
                if (empruntsCourants[j][1] == T_NLivre[i])
                    empruntsCourantsLivre++;
            }
            for (j = 0; j < nbk; j++)
            {
                if (historiqueEmprunts[j][1] == T_NLivre[i])
                    empruntsTotauxLivre++;
            }

            if (empruntsCourantsLivre + empruntsTotauxLivre > maxEmprunts)
                maxEmprunts = empruntsCourantsLivre + empruntsTotauxLivre;
        }
        system("cls");
        system("color 07");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
        Sleep(500);
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
        Sleep(500);
        printf("                                     Numero            Titre      Nombres d'exemplaire     Emprunt courrant     Emprunt total\n");
        printf("                                    ------------------------------------------------------------------------------------------- \n\n");
        Sleep(500);
        for (i = 0; i < nbl; i++)
        {
            empruntsCourantsLivre = 0;
            empruntsTotauxLivre = 0;
            for (j = 0; j < nbe; j++)
            {
                if (empruntsCourants[j][1] == T_NLivre[i])
                    empruntsCourantsLivre++;
            }
            for (j = 0; j < nbk; j++)
            {
                if (historiqueEmprunts[j][1] == T_NLivre[i])
                    empruntsTotauxLivre++;
            }
            if (empruntsCourantsLivre + empruntsTotauxLivre == maxEmprunts && maxEmprunts > 0)
            {
                printf("                                       %5.3d            %-20s  %-5d              %-5d            %-5d\n",T_NLivre[i], T_Titre[i],T_Nbr_exp[i],empruntsCourantsLivre,maxEmprunts);
                printf("                                    ------------------------------------------------------------------------------------------- \n\n");
                Sleep(100);
            }
        }
    }
    system("pause");
}

void afficherLivresJamaisEmpruntes()
{
    int i;
    int j;
    int nbLivresJamaisEmpruntes = 0;
    int empruntsCourantsLivre;
    int empruntsTotauxLivre;
    if (nbe==0 && nbk==0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        for (i = 0; i < nbl; i++)
        {
            empruntsCourantsLivre = 0;
            empruntsTotauxLivre = 0;
            for (j = 0; j < nbe; j++)
            {
                if (empruntsCourants[j][1] == T_NLivre[i])
                    empruntsCourantsLivre++;
            }
            for (j = 0; j < nbk; j++)
            {
                if (historiqueEmprunts[j][1] == T_NLivre[i])
                    empruntsTotauxLivre++;
            }

            if (empruntsCourantsLivre + empruntsTotauxLivre == 0)
                nbLivresJamaisEmpruntes++;
        }
        if (nbLivresJamaisEmpruntes==0)
        {
            system("cls");
            system("color 07");
            printf("                                   |-------------------------------------------------------------------------------------------| \n");
            printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
            Sleep(500);
            printf("                                   |-------------------------------------------------------------------------------------------| \n");
            printf("                                        Il n'y a aucun livre jamais emprunte.\n");
        }
        else
        {
            system("cls");
            system("color 07");
            printf("                                   |-------------------------------------------------------------------------------------------| \n");
            printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
            Sleep(500);
            printf("                                   |-------------------------------------------------------------------------------------------| \n");
            printf("                                   |-------------------         Le(s) livre(s) jamais emprente(s)          --------------------| \n\n");
            Sleep(500);
            printf("                                          Numero                          Titre                       Nombres d'exemplaire    \n");
            printf("                                    ------------------------------------------------------------------------------------------- \n\n");
            Sleep(500);
            for (i = 0; i < nbl; i++)
            {
                empruntsCourantsLivre = 0;
                empruntsTotauxLivre = 0;
                for (j = 0; j < nbe; j++)
                {
                    if (empruntsCourants[j][1] == T_NLivre[i])
                        empruntsCourantsLivre++;
                }
                for (j = 0; j < nbk; j++)
                {
                    if (historiqueEmprunts[j][1] == T_NLivre[i])
                        empruntsTotauxLivre++;
                }
                if (empruntsCourantsLivre + empruntsTotauxLivre == 0)
                {
                    printf("                                          %5.3d                           %-20s                   %-5d          \n",T_NLivre[i], T_Titre[i],T_Nbr_exp[i]);
                    printf("                                    ------------------------------------------------------------------------------------------- \n\n");
                    Sleep(100);
                }
            }
        }
    }
    system("pause");
}

void afficherEmprunteursFrequents()
{
    int i;
    int j;
    int empruntsCourantsUtilisateur;
    int empruntsTotauxUtilisateur;
    int dejaAffiche;
    int k;
    int tousCins[600];
    int maxEmprunts = 0;
    if (nbe==0 && nbk==0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        for (i=0;i<nbe;i++)
            tousCins[i]=empruntsCourants[i][0];
        for(i=nbe;i<nbk+nbe;i++)
            tousCins[i]=historiqueEmprunts[i-nbe][0];
        for (i = 0; i < nbe+nbk; i++)
        {
            empruntsCourantsUtilisateur = 0;
            for (j = 0; j < nbe+nbk; j++)
            {
                if (tousCins[i] == tousCins[j])
                    empruntsCourantsUtilisateur++;
            }
            if (empruntsCourantsUtilisateur > maxEmprunts)
            {
                maxEmprunts = empruntsCourantsUtilisateur;
            }
        }
        system("cls");
        system("color 07");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
        Sleep(500);
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |---------------         Le(s) emprenteur(s) le(s) plus frequent(s)         ----------------| \n\n");
        Sleep(500);
        printf("                                              CIN              Nombre d'emprunt courrant         Nombre d'emprunt total    \n");
        printf("                                    ------------------------------------------------------------------------------------------- \n\n");
        Sleep(500);
        for (i = 0; i < nbe+nbk; i++)
        {
            empruntsCourantsUtilisateur = 0;
            empruntsTotauxUtilisateur = 0;
            dejaAffiche =0;
            for (k = 0; k < i; k++)
            {
                if (tousCins[i] == tousCins[k])
                    dejaAffiche = 1;
            }
            if (dejaAffiche == 0)
            {
                for (j = 0; j < nbe+nbk; j++)
                {
                    if (tousCins[i] == tousCins[j])
                    {
                        if (j >= nbe)
                            empruntsTotauxUtilisateur++;
                        else
                            empruntsCourantsUtilisateur++;
                    }
                }
                if (empruntsCourantsUtilisateur+empruntsTotauxUtilisateur == maxEmprunts)
                {
                    printf("                                           %08d                         %-5d                         %-5d\n",tousCins[i],empruntsCourantsUtilisateur,maxEmprunts);
                    printf("                                    ------------------------------------------------------------------------------------------- \n\n");
                    Sleep(100);
                }
            }
        }
    }
    system("pause");
}

void afficherLivresPlusEmpruntesPeriode()
{
   int jourDebut, moisDebut, anneeDebut;
    int jourFin, moisFin, anneeFin;
    int maxEmprunts = 0;
    int i;
    int j;
    int compteurTemporaire;
    int saisieValide;
    int dateValide;
    int saisieCorrecte;
    int empruntsTrouves;
    int empruntsCourantsLivre;
    int empruntsTotauxLivre;
    int aDesEmpruntsPeriode;
    char saisie[300];
    if (nbe+nbk == 0)
    {
        system("cls");
        system("color 06");
        printf("                                         ----------------------------------------------------------- \n\n");
        printf("                                                         Il n'y a aucun emprunt.\n\n");
        printf("                                         ----------------------------------------------------------- \n");
    }
    else
    {
        do {
            do {
                system("cls");
                system("color 07");
                printf("                                   |-------------------------------------------------------------------------------------------| \n");
                printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                Sleep(500);
                printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                printf("                                                           Date 1             ----->            Date 2\n");
                Sleep(500);
                printf("                                    veuiller saisir la date 1\n");
                printf("                                    Jour : ");
                fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un jour valide");
                        jourDebut = 0;
                    }
                    else
                    {
                        jourDebut = atoi(saisie);
                        if (jourDebut <= 0 || jourDebut > 31)
                            err1("Veuillez entrer un jour valide");
                    }
                } while (jourDebut <= 0 || jourDebut > 31);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                    printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                    printf("                                                           Date 1             ----->            Date 2\n");
                    printf("                                    veuiller saisir la date 1 \n");
                    printf("                                    Jour : %02d\n",jourDebut);
                    printf("                                    Mois : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer un mois valide");
                        moisDebut = 0;
                    }
                    else
                    {
                        moisDebut = atoi(saisie);
                        if (moisDebut <= 0 || moisDebut > 12)
                            err1("Veuillez entrer un mois valide");
                    }
                } while (moisDebut <= 0 || moisDebut > 12);
                do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                    printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                    printf("                                                           Date 1             ----->            Date 2\n");
                    printf("                                    veuiller saisir la date 1\n");
                    printf("                                    Jour : %02d\n",jourDebut);
                    printf("                                    Mois : %02d\n",moisDebut);
                    printf("                                    Annee : ");
                    fgets(saisie, sizeof(saisie), stdin);
                    saisie[strcspn(saisie, "\n")] = 0;
                    if (verif_numero(saisie) == 0)
                    {
                        err0("Veuillez entrer une annee valide");
                        anneeDebut = 0;
                    }
                    else
                    {
                        anneeDebut = atoi(saisie);
                        if (anneeDebut < 2000 || anneeDebut > 2500)
                            err1("Veuillez entrer une annee valide");
                    }
                } while (anneeDebut < 2000 || anneeDebut > 2500);
                if (verif_date(anneeDebut, moisDebut, jourDebut) == 0)
                {
                    system("cls");
                    system("color 0C");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    printf("                                                            La date 1 est invalide.\n\n");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    system("pause");
                    saisieCorrecte = 0;
                }
                else
                    saisieCorrecte=1;
            } while (saisieCorrecte == 0);
                dateValide= 0;
                do {
                    do {
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                    Sleep(500);
                    printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                    printf("                                                           %02d/%02d/%04d         ----->        Date 2\n",jourDebut,moisDebut,anneeDebut);
                    Sleep(500);
                    printf("                                    veuiller saisir la date 2 \n");
                    printf("                                    Jour : ");
                    fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer un jour valide");
                            jourFin = 0;
                        }
                        else
                        {
                            jourFin = atoi(saisie);
                            if (jourFin <= 0 || jourFin > 31)
                                err1("Veuillez entrer un jour valide");
                        }
                    } while (jourFin <= 0 || jourFin > 31);
                    do {
                        system("cls");
                        system("color 07");
                        printf("                                   |-------------------------------------------------------------------------------------------| \n");
                        printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                        printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                        printf("                                                           %02d/%02d/%04d         ----->        Date 2\n",jourDebut,moisDebut,anneeDebut);
                        printf("                                    veuiller saisir la date 2 \n");
                        printf("                                    Jour : %02d\n",jourFin);
                        printf("                                    Mois : ");
                        fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer un mois valide");
                            moisFin = 0;
                        }
                        else
                        {
                            moisFin = atoi(saisie);
                            if (moisFin <= 0 || moisFin > 12)
                                err1("Veuillez entrer un mois valide");
                        }
                    } while (moisFin <= 0 || moisFin > 12);
                    do {
                        system("cls");
                        system("color 07");
                        printf("                                   |-------------------------------------------------------------------------------------------| \n");
                        printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                        printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                        printf("                                                           %02d/%02d/%04d         ----->        Date 2\n",jourDebut,moisDebut,anneeDebut);
                        printf("                                    veuiller saisir la date 2\n");
                        printf("                                    Jour : %02d\n",jourFin);
                        printf("                                    Mois : %02d\n",moisFin);
                        printf("                                    Annee : ");
                        fgets(saisie, sizeof(saisie), stdin);
                        saisie[strcspn(saisie, "\n")] = 0;
                        if (verif_numero(saisie) == 0)
                        {
                            err0("Veuillez entrer une annee valide");
                            anneeFin = 0;
                        }
                        else
                        {
                            anneeFin = atoi(saisie);
                            if (anneeFin < 2000 || anneeFin > 2500)
                                err1("Veuillez entrer une annee valide");
                        }
                    } while (anneeFin < 2000 || anneeFin > 2500);
                    if (verif_date(anneeFin, moisFin, jourFin) == 0)
                    {
                        system("cls");
                        system("color 0C");
                        printf("                                        ------------------------------------------------------------------------ \n\n");
                        printf("                                                          La date 2 est invalide.\n\n");
                        printf("                                        ------------------------------------------------------------------------ \n\n");
                        system("pause");
                        dateValide = 0;
                    }
                    else
                    {
                        if (calculerJoursDepuisEpoque(anneeFin, moisFin, jourFin)-calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<0)
                        {
                            system("cls");
                            system("color 06");
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            printf("                                          La date 2 doit etre apres la date 1.\n");
                            printf("                                          Date 1 : %02d/%02d/%04d\n\n", jourDebut, moisDebut, anneeDebut);
                            printf("                                        ------------------------------------------------------------------------ \n\n");
                            system("pause");
                            dateValide = 0;
                        }
                        else
                            dateValide=1;
                    }
                } while (dateValide == 0);
                compteurTemporaire=0;
                for (i=0;i<nbe;i++)
                {
                    if (calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<=calculerJoursDepuisEpoque(empruntsCourants[i][4],empruntsCourants[i][3],empruntsCourants[i][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(empruntsCourants[i][4],empruntsCourants[i][3],empruntsCourants[i][2]))
                        compteurTemporaire++;
                }
                for (i=0;i<nbk;i++)
                {
                    if (calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<= calculerJoursDepuisEpoque(historiqueEmprunts[i][4],historiqueEmprunts[i][3],historiqueEmprunts[i][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(historiqueEmprunts[i][4],historiqueEmprunts[i][3],historiqueEmprunts[i][2]))
                        compteurTemporaire++;
                }
                if (compteurTemporaire==0)
                {
                    system("cls");
                    system("color 06");
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    printf("                                               Aucun emprunt pour %02d/%02d/%04d ---> %02d/%02d/%04d.\n\n",jourDebut,moisDebut,anneeDebut,jourFin,moisFin,anneeFin);
                    printf("                                        ------------------------------------------------------------------------ \n\n");
                    empruntsTrouves = 0;
                }
                else
                {
                    maxEmprunts=0;
                    for (i = 0; i < nbl; i++)
                    {
                        empruntsCourantsLivre = 0;
                        empruntsTotauxLivre = 0;
                        aDesEmpruntsPeriode = 0;
                        for (j = 0; j < nbe; j++)
                        {
                            if (empruntsCourants[j][1] == T_NLivre[i])
                            {
                                if (calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<=calculerJoursDepuisEpoque(empruntsCourants[j][4],empruntsCourants[j][3],empruntsCourants[j][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(empruntsCourants[j][4],empruntsCourants[j][3],empruntsCourants[j][2]))
                                {
                                    aDesEmpruntsPeriode=1;
                                    empruntsCourantsLivre++;
                                }
                            }
                        }
                        for (j = 0; j < nbk; j++)
                        {
                            if (historiqueEmprunts[j][1] == T_NLivre[i])
                            {
                                if (calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<= calculerJoursDepuisEpoque(historiqueEmprunts[j][4],historiqueEmprunts[j][3],historiqueEmprunts[j][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(historiqueEmprunts[j][4],historiqueEmprunts[j][3],historiqueEmprunts[j][2]))
                                {
                                    aDesEmpruntsPeriode=1;
                                    empruntsTotauxLivre++;
                                }
                            }
                        }
                        if (empruntsCourantsLivre + empruntsTotauxLivre > maxEmprunts && aDesEmpruntsPeriode ==1)
                            maxEmprunts = empruntsCourantsLivre + empruntsTotauxLivre;
                    }
                    system("cls");
                    system("color 07");
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |------------------------------         Statistiques          ------------------------------| \n\n");
                    Sleep(500);
                    printf("                                   |-------------------------------------------------------------------------------------------| \n");
                    printf("                                   |-----------------         Le(s) livre(s) le(s) plus emprente(s)          ------------------| \n\n");
                    printf("                                                           %02d/%02d/%04d          --->         %02d/%02d/%04d\n",jourDebut,moisDebut,anneeDebut,jourFin,moisFin,anneeFin);
                    printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
                    Sleep(500);
                    printf("                                          Numero         Titre            Nombres d'exemplaire   Nombre d'emprunt de la periode\n");
                    printf("                                    ------------------------------------------------------------------------------------------- \n\n");
                    Sleep(500);
                    for (i = 0; i < nbl; i++)
                    {
                        empruntsCourantsLivre = 0;
                        empruntsTotauxLivre = 0;
                        for (j = 0; j < nbe; j++)
                        {
                            if (empruntsCourants[j][1] == T_NLivre[i] && calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<=calculerJoursDepuisEpoque(empruntsCourants[j][4],empruntsCourants[j][3],empruntsCourants[j][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(empruntsCourants[j][4],empruntsCourants[j][3],empruntsCourants[j][2]))
                                empruntsCourantsLivre++;
                        }
                        for (j = 0; j < nbk; j++)
                        {
                            if (historiqueEmprunts[j][1] == T_NLivre[i] && calculerJoursDepuisEpoque(anneeDebut,moisDebut,jourDebut)<= calculerJoursDepuisEpoque(historiqueEmprunts[j][4],historiqueEmprunts[j][3],historiqueEmprunts[j][2]) && calculerJoursDepuisEpoque(anneeFin,moisFin,jourFin)>=calculerJoursDepuisEpoque(historiqueEmprunts[j][4],historiqueEmprunts[j][3],historiqueEmprunts[j][2]))
                                empruntsTotauxLivre++;
                        }
                        if (empruntsCourantsLivre + empruntsTotauxLivre == maxEmprunts )
                        {
                            printf("                                         %5.3d            %-20s    %-5d                        %-5d\n",T_NLivre[i], T_Titre[i],T_Nbr_exp[i],maxEmprunts);
                            printf("                                    ------------------------------------------------------------------------------------------- \n\n");
                            Sleep(100);
                        }
                    }
        }
    }
    system("pause");
}

void afficherRetour(char msg[])
{
    system("cls");
    system("color 0A");
    printf("                                             -----------------------------------------------------------\n\n");
    printf("                                                %s...\n\n",msg);
    printf("                                             -----------------------------------------------------------\n");
    Sleep(750);
    system("color 07");
}

void quitterApplication()
{
    system("cls");
    system("color 09");
    printf("\n\n");
    printf("                                             ----------------------------------------------------------- \n\n");
    printf("                                               Merci d'avoir utilise l'application de la bibliotheque.\n\n");
    printf("                                               Fermeture de l'application en cours.\n\n");
    printf("                                             ----------------------------------------------------------- \n");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("                                             ----------------------------------------------------------- \n\n");
    printf("                                               Merci d'avoir utilise l'application de la bibliotheque.\n\n");
    printf("                                               Fermeture de l'application en cours..\n\n");
    printf("                                             ----------------------------------------------------------- \n");
    Sleep(500);
    system("cls");
    printf("\n\n");
    printf("                                             ----------------------------------------------------------- \n\n");
    printf("                                               Merci d'avoir utilise l'application de la bibliotheque.\n\n");
    printf("                                               Fermeture de l'application en cours...\n\n");
    printf("                                             ----------------------------------------------------------- \n");
    Sleep(500);
}

// Fonctions des menus
void admn()
{
    int choixMenu;
    char saisieMenu[10];

    do
    {
        system("color 07");
        system("cls");
        printf("\n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |--------------------------      Gestion de la bibliotheque       --------------------------| \n\n");
        Sleep(500);
        printf("\n\n");
        printf("                                   |---------------------------------     Veuillez choisir    ---------------------------------| \n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |  1. AFFICHER TOUT LES LIVRES DE LA BIBLIOTHEQUE                                           | \n");
        printf("                                   |  2. AJOUTER UN NOUVEAU LIVRE                                                              | \n");
        printf("                                   |  3. SUPPRIMER UN LIVRE                                                                    | \n");
        printf("                                   |  4. MODIFIER LE NOMBRE D'EXEMPLAIRE D'UN LIVRE                                            | \n");
        printf("                                   |  5. RECHERCHER UN LIVRE                                                                   | \n");
        printf("                                   |  6. AFFICHER LES LIVRES DISPONIBLES                                                       | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        printf("                                   |  7. MENU PRINCIPALE                                                                       | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |     Veuillez saisir le numero de l'operation souhaitee: ");
        fgets(saisieMenu, sizeof(saisieMenu), stdin);
        saisieMenu[strcspn(saisieMenu, "\n")] = 0;
        if (verif_numero(saisieMenu)== 0)
            err0("Veuillez selectionner de 1 a 7 selon l'option desiree");
        else
        {
            choixMenu = atoi(saisieMenu);
            if (choixMenu<1 || choixMenu>7)
                err1("Veuillez selectionner de 1 a 7 selon l'option desiree");
            else
            {
                switch (choixMenu)
                {
                    case 1:
                        afficherLivres (T_NLivre, T_Titre, T_Nbr_exp, nbl, 0," dans la bibliotheque");
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 2:
                        ajouterLivre();
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 3:
                        nbl = supprimerLivre(T_Titre, T_NLivre, T_Nbr_exp, nbl,empruntsCourants);
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 4:
                        nbl=modifierNombreExemplaires(T_Titre,T_NLivre, T_Nbr_exp,empruntsCourants, nbl);
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 5:
                        rechercherLivre(T_Titre,T_NLivre,T_Nbr_exp,nbl);
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 6:
                        afficherLivres (T_NLivre, T_Titre, T_Nbr_exp, nbl, 1," disponible(s) pour emprenter");
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 7:
                        afficherRetour("Retour au menu principal en cours");
                        break;
                }
            }
        }
    }
    while(choixMenu  != 7);
}

void usr()
{
    int choixMenu;
    char saisieMenu[10];
    saisir_date();

    do
    {
        system("color 07");
        system("cls");
        printf("\n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |---------------------------        Gestion des emprunts         ---------------------------| \n\n");
        printf("\n\n");
        Sleep(500);
        printf("                                   |---------------------------------     Veuillez choisir    ---------------------------------| \n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |  1. AJOUTER UN EMPRUNT                                                                    | \n");
        printf("                                   |  2. CONSULTER LES EMPRUNTS D'UN ADHERENT                                                  | \n");
        printf("                                   |  3. ENNREGISTRER LE RETOUR D'UN LIVRE                                                     | \n");
        printf("                                   |  4. AFFICHER LA LISTE D'EMPRUNTS EN COURS                                                 | \n");
        printf("                                   |  5. AFFICHER LES LIVRES EN RETARD DE RETOUR                                               | \n");
        printf("                                   |  6. AFFICHER LES EMPRUNTS RELATIFS A UNE DATE DE RETOUR PREVUE                            | \n");
        printf("                                   |  7. SUPPRIMER UN ENSEMBLE D'EMPRUNTS                                                      | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        printf("                                   |  8. MENU PRINCIPALE                                                                       | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |     Veuillez saisir le numero de l'operation souhaitee: ");
        fgets(saisieMenu, sizeof(saisieMenu), stdin);
        saisieMenu[strcspn(saisieMenu, "\n")] = 0;
        if (verif_numero(saisieMenu)== 0)
            err0("Veuillez selectionner de 1 a 8 selon l'option desiree");
        else
        {
            choixMenu = atoi(saisieMenu);
            if (choixMenu<1 || choixMenu>8)
                err1("Veuillez selectionner de 1 a 8 selon l'option desiree");
            else
            {
                switch (choixMenu)
                {
                    case 1:
                        nbe=emprunterLivre(nbl, T_NLivre, T_Titre, T_Nbr_exp, empruntsCourants, nbe);
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 2:
                        afficherEmpruntsAdherent(empruntsCourants,historiqueEmprunts,T_Titre,nbl,nbk,nbe);
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 3 :
                        retournerLivre(empruntsCourants,historiqueEmprunts,T_Titre);
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 4:
                        afficherEmpruntsFiltres(empruntsCourants,T_Titre,T_NLivre,nbe,nbl,1,"emprunt(s) en cours");
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 5:
                        afficherEmpruntsFiltres(empruntsCourants,T_Titre,T_NLivre,nbe,nbl,0,"livre(s) en retard de retour");
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 6:
                        afficherEmpruntsParDate(empruntsCourants,historiqueEmprunts,T_Titre,T_NLivre,nbe,nbl,nbk);
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 7:
                        nbe=supprimerEmpruntsParPeriode();
                        afficherRetour("Retour au menu de gestion des emprunts en cours");
                        break;
                    case 8:
                        afficherRetour("Retour au menu principal en cours");
                        break;
                }
            }
        }
    }while(choixMenu != 8);
}

void stat()
{
    int choixMenu;
    char saisieMenu[10];
    do
    {
        system("color 07");
        system("cls");
        printf("\n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |-------------------------      Consultation des statistiques      -------------------------| \n\n");
        printf("\n\n");
        Sleep(500);
        printf("                                   |---------------------------------     Veuillez choisir    ---------------------------------| \n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |  1. AFFICHER LE NOMBRE TOTAL DES LIVRES, D'ADHERENTS ET D'EMPRUNTS                        | \n");
        printf("                                   |  2. AFFICHER LE(S) LIVRE(S) LE(S) PLUS EMPRUNTE(S)                                        | \n");
        printf("                                   |  3. AFFICHER LE(S) LIVRE(S) LE(S) JAMAIS EMPRUNTE(S)                                      | \n");
        printf("                                   |  4. AFFICHER LE(S) LIVRE(S) LE(S) PLUS EMPRUNTE(S) DANS UNE PERIODE DONNEE                | \n");
        printf("                                   |  5. AFFICHER LES EMPRUNTEUR LES PLUS FREQUENTS                                            | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        printf("                                   |  6. MENU PRINCIPALE                                                                       | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |     Veuillez saisir le numero de l'operation souhaitee: ");
        fgets(saisieMenu, sizeof(saisieMenu), stdin);
        saisieMenu[strcspn(saisieMenu, "\n")] = 0;
        if (verif_numero(saisieMenu)== 0)
            err0("Veuillez selectionner de 1 a 7 selon l'option desiree");
        else
        {
            choixMenu = atoi(saisieMenu);
            if (choixMenu<1 || choixMenu>7)
                err1("Veuillez selectionner de 1 a 7 selon l'option desiree");
            else
            {
                switch (choixMenu)
                {
                    case 1:
                        afficherStatistiquesBasiques(T_NLivre, T_Nbr_exp,empruntsCourants,historiqueEmprunts,nbe,nbk,nbl);
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 2:
                        afficherLivresPlusEmpruntes();
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 3:
                        afficherLivresJamaisEmpruntes();
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 4:
                        afficherLivresPlusEmpruntesPeriode();
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 5:
                        afficherEmprunteursFrequents();
                        afficherRetour("Retour au menu de gestion de la bibliotheque en cours");
                        break;
                    case 6:
                        afficherRetour("Retour au menu principal en cours");
                        break;

                }
            }
        }
    }
    while(choixMenu  != 6);
}

int main()
{
    char saisieMenu[10];
    int choixMenu;
    do
    {
        system("color 07");
        system("cls");
        printf("\n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n");
        printf("                                   |-----------------   Bienvenue dans le menu principal de la bibliotheque   -----------------| \n\n");
        Sleep(500);
        printf("                                   |---------------------------------     Veuillez choisir    ---------------------------------| \n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |  1. GESTION DE LA BIBLIOTHEQUE                                                            | \n");
        printf("                                   |  2. GESTION DES EMPRUNTS                                                                  | \n");
        printf("                                   |  3. CONSULTATION DES STATISTIQUES                                                         | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        printf("                                   |  4. Quitter l'application                                                                 | \n\n");
        printf("                                   |-------------------------------------------------------------------------------------------| \n\n");
        Sleep(500);
        printf("                                   |     Veuillez saisir le numero de l'operation souhaitee: ");
        fgets(saisieMenu, sizeof(saisieMenu), stdin);
        saisieMenu[strcspn(saisieMenu, "\n")] = 0;
            if (verif_numero(saisieMenu)== 0)
                err0("Veuillez selectionner de 1 a 4 selon l'option desiree");
            else
            {
                choixMenu = atoi(saisieMenu);
                if (choixMenu<1 || choixMenu>4)
                    err1("Veuillez selectionner de 1 a 4 selon l'option desiree");
                else
                {
                    switch (choixMenu)
                    {
                    case 1:
                        admn();
                        break;
                    case 2:
                        usr();
                        break;
                    case 3:
                        stat();
                        break;
                    case 4:
                        quitterApplication();
                        break;
                    }
                }
            }
    } while (choixMenu != 4);

    return 0;
}
