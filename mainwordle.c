/*HALFOUN MELISSA G1*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fonctions.h"

#define NBMOTS 638

/////////////*WORDLE*/////////////

int main(){
    char tableau[6][6];
    int couleurs[6][5];
    char dictionnaire[NBMOTS][6]={"amour","radar","robot","livre","plage","point","copie","table","chaud","fleur",
    "porte","monde","reine","route","arbre","glace","jouer","lundi","pomme","sucre",
    "tigre","ville","vache","verre","vigne","zebre","avion","balle","carte","dents",
    "mardi","jeudi","blanc","noire","rouge","verte","jaune","brune","grand","petit",
    "force","bruit","nuage","neige","pluie","orage","herbe","fruit","poire","melon",
    "tarte","crepe","sauce","poule","chien","lapin","singe","stylo","lampe","salon",
    "mains","pieds","jambe","coeur","genou","doigt","femme","homme","frere","soeur",
    "ecole","musee","train","metro","ferme","champ","foret","ocean","sable","roche",
    "terre","tapis","balai","tasse","nappe","image","ecran","radio","piano","danse",
    "chant","jouet","sport","match","temps","heure","annee","matin","calme","drole",
    "belle","laide","forte","douce","plume","panda","koala","aigle","perle","ambre",
    "opera","cadre","magie","ruban","veste","gants","bague","abime","abord","achat","acier","actif","adieu","aigus","ailes","ainsi","alibi",
    "alors","amant","ample","ancre","anges","angle","anime","apres","armee","armes",
    "assez","astre","atlas","atout","aucun","autre","avale","avare","avant","avise",
    "ayant","badge","baies","bancs","bande","bains","barge","baril","baser","bases",
    "basse","baton","beche","belge","beret","beton","biens","bille","bingo","bison",
    "blond","boite","bonne","borne","bosse","botte","bouge","bouts","brave","brise",
    "brode","broie","brume","brute","buche","cable","cacao","cages","canal","canne",
    "canon","capte","carpe","cases","casse","cause","cedre","celle","cense","cents",
    "cerne","chats","choix","chute","cieux","cirer","cites","civil","clame","clair",
    "clerc","cloue","clous","coins","colin","colon","conte","corps","coton","coude",
    "coule","coupe","cours","court","coups","crane","crans","creme","creux","crise",
    "croix","cruel","cubes","cuire","cuite","cycle","dalle","dames","dates","debat",
    "debut","decor","delta","depot","desir","dette","devis","dinde","diner","dites",
    "divin","donne","dorer","doses","doute","drame","droit","duels","duree","dures",
    "echec","echos","ecrin","effet","egale","egaux","elans","elire","elite","elles",
    "envie","epais","epice","epoux","essai","etage","etain","etale","etape","etats",
    "etend","etude","exact","exode","fable","facon","fagot","faire","faits","faute",
    "feint","ferie","fiche","fichu","fille","filme","final","firme","flanc","flair",
    "flots","foyer","frais","franc","frein","frite","froid","front","fumer","fumet",
    "gains","galop","gamin","gagne","garde","gares","gaule","geler","gemme","genre",
    "gerer","geste","givre","glane","globe","gorge","grade","grain","grave","greve",
    "grise","guide","guise","hache","haies","haine","harde","harpe","heros","hiver",
    "honte","hotel","huile","humer","hymne","ideal","idole","imite","index","inoui",
    "issue","jabot","jalon","jeune","jouir","jours","juste","label","ladre","laine",
    "lance","large","laser","latin","laver","lavis","legal","leger","lecon","levre",
    "libre","liens","lieue","ligne","lilas","liste","local","loger","longe","loupe",
    "loups","lourd","lueur","maire","major","malle","malin","mange","maree","marin",
    "masse","mauve","meler","merci","merle","metal","metre","mieux","micro","mille",
    "mince","mines","moins","mitre","mixte","moine","moisi","monte","morts","motif",
    "moyen","muets","murir","nager","naive","natal","natte","naval","navet","nerfs",
    "niche","norme","notre","nouer","noyau","nulle","objet","obeit","obole","obtus",
    "octet","odeur","offre","ogive","olive","ombre","oncle","ondes","ordre","orgue",
    "orner","osier","otage","ouvre","ouate","ouest","oubli","ourse","outil","outre",
    "pages","paire","palet","palme","panne","parmi","paroi","parti","passe","patin",
    "patio","patte","pause","pavot","payer","peche","peine","pense","perdu","peste",
    "phare","photo","piece","pieux","pince","piste","pivot","place","plein","pleur",
    "poche","poeme","poing","poilu","poker","polie","poser","poste","potes","pouls",
    "poupe","prier","prime","prise","prose","proue","prune","puces","puits","quand",
    "quart","quasi","quete","queue","rabat","raide","raies","raler","rance","range",
    "rangs","raser","rater","rayon","recit","recto","refus","repos","reste","riche",
    "rimes","riper","roder","rosee","roter","roule","ruche","ruine","ruser","russe",
    "sabre","sacre","sages","saint","salut","sante","satin","saute","savon","savez",
    "scier","seche","seing","seine","semer","serie","serpe","serre","seuil","seize",
    "semis","sente","seule","siege","signe","silex","sinon","sirop","situe","sobre",
    "socle","somme","sonde","songe","sonne","sorte","souci","soude","soule","soupe",
    "sourd","stade","stage","stand","stele","style","suite","super","tabac","tache",
    "talon","taupe","taxes","tende","tenue","terme","teste","texte","tibia","tissu",
    "titre","toile","toise","tombe","tonne","torse","torts","total","tours","trace",
    "tract","trait","trame","trier","trocs","trous","tronc","tuyau","union","unite",
    "usage","usure","utile","vague","valet","valve","vaste","veaux","venir","vente",
    "verbe","vertu","vieux","villa","vingt","virer","virus","visse","vivre","vocal",
    "vogue","voile","voire","voles","voler","votes","votre","vouer","voulu","yacht",
    "zeste"};
    char secret[6],proposition[6];
    int gagne=0;
    int essaie=0;
    srand(time(NULL));
    copier(dictionnaire[rand()%NBMOTS],secret);
    do{
    system("cls");
    printf ("\e[1;37m\e[41m ********WORDLE******** \e[0m\n\n");
    affichage(tableau,couleurs,essaie);
    printf("entrez un mot de 5 lettres en minuscule:");
    scanf("%5s", proposition);
    while (getchar() != '\n');

    minuscule(proposition);
    if (!existe(proposition, dictionnaire, NBMOTS)){
        printf("Ce mot n'est pas dans le dictionnaire.\n");   
        printf("Appuyez sur Entree pour reessayer...");
        getchar();
        continue;
    } else {
        copier(proposition, tableau[essaie]);
        bonnecouleur(secret, proposition, couleurs[essaie]);
        if (comparer(proposition, secret)){
            gagne = 1;
        }
        essaie++;
    }
    }while(!gagne && essaie<6);
    system("cls");
        printf ("\e[1;37m\e[41m ********WORDLE******** \e[0m\n\n");
    affichage(tableau,couleurs,essaie);
    if(gagne){
        printf("\e[1;37m\e[42m Bravo, vous avez gagne en %d essais! \e[0m\n",essaie);
    }else{
        printf("\e[1;37m\e[41m Perdu! , le mot etait : %s \e[0m \n",secret);
    }
    return 0;
}