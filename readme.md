# WORDLE
Programmé par : Halfoun Melissa (groupe 1)
Date : 03/11/2026

## Description du jeu
Wordle est un jeu dans lequel le joueur doit deviner un mot secret de cinq lettres. Le joueur dispose de six essais maximum. Après chaque proposition, les lettres sont affichées en couleur:
    - Vert : la lettre est à la bonne place.
    - Jaune : la lettre est dans le mot secret, mais à une autre place.
    - Gris : la lettre n'est pas disponible à cette place dans le mot secret.
Le mot proposé doit être présent dans le dictionnaire du programme.Les lettres majuscules sont converties en minuscules automatiquement.


## Installation

Le jeu fonctionne sous **Windows** et sous **Linux**. Il faut un compilateur `gcc` et l'outil `make`, et un terminal qui affiche les couleurs.

Le programme efface l'écran avec la commande `system("cls")` (Windows). Sous Linux, il suffit de modifier ce point (voir plus bas).

### Sous Windows

1. Ouvrir un terminal (PowerShell) dans le dossier du projet, celui qui contient `mainwordle.c`, `fonctions.c`, `fonctions.h` et `Makefile`.
2. Compiler le jeu :

```bash
mingw32-make
```

3. Lancer le jeu :

```bash
.\wordle.exe
```

### Sous Linux

1. Dans le fichier `mainwordle.c`, remplacer `system("cls")` par `system("clear")`. Cette ligne apparaît deux fois, il faut modifier les deux.
2. Ouvrir un terminal dans le dossier du projet.
3. Compiler le jeu :

```bash
make
```

4. Lancer le jeu :

```bash
./wordle.exe
```

### Nettoyage

Pour supprimer les fichiers générés (`.o` et exécutable) :

```bash
mingw32-make clean   # Windows
make clean           # Linux
```

## Comment jouer

-Lancer le programme (./wordle.exe ou .\wordle.exe)
-Entrer un mot de cinq lettres à chaque essai.
-Le jeu affiche les couleurs des lettres et la grille des essais.
-Le joueur gagne s'il trouve le mot secret en six essais maximum.
-Sinon, le mot secret est affiché à la fin de la partie.


## Description du générateur d'instances

Le jeu n'a pas de générateur complexe . L'« instance » est le **mot secret**, tiré au hasard au début de chaque partie parmi les 638 mots du dictionnaire (écrit directement dans `mainwordle.c`).

- `srand(time(NULL))` initialise le hasard avec l'heure actuelle, pour que le mot change à chaque lancement.
- `rand() % NBMOTS` donne un indice valide du dictionnaire (de 0 à 637). Le mot correspondant est copié dans `secret` avec la fonction `copier`.


## Détails importants

- **Organisation** : `mainwordle.c` contient le dictionnaire et la boucle du jeu ; `fonctions.c` et `fonctions.h` contiennent les fonctions.
- **Dictionnaire** : 638 mots écrits en dur, en minuscules et sans accents. Je voulais tous les mots français de 5 lettres, mais il y en a trop : j'ai gardé une sélection, surtout de mots courants. Certains mots valides sont donc refusés.
- **Majuscules** : acceptées, `minuscule` les convertit.
- **Mot invalide** : un message s'affiche et l'essai n'est **pas** décompté.
- **Lettres en double** : `bonnecouleur` colore d'abord les verts (marqués dans `dejavu`), puis les jaunes sans réutiliser une lettre déjà associée.
- **Fonctions** : `copier` (copie un mot), `comparer` (compare deux mots), `existe` (cherche dans le dictionnaire), `minuscule` (met en minuscules), `bonnecouleur` (calcule les couleurs), `affichage` (affiche la grille).


## Difficultés rencontrées

- **Le dictionnaire** : je voulais mettre tous les mots français de 5 lettres, mais il y en a beaucoup trop pour les écrire à la main. J'ai gardé une sélection de mots, surtout courants.
- **Les majuscules** : au début, un mot tapé en majuscules était refusé comme « mot invalide », car le dictionnaire est en minuscules. J'ai écrit la fonction `minuscule`, qui convertit la proposition avant de la comparer.
- **La saisie avec `scanf`** : le joueur peut taper un mot trop long, et `scanf("%s")` écrirait au-delà de la taille du tableau. J'ai donc utilisé `scanf("%5s", ...)`, qui ne lit que 5 caractères. Mais les caractères en trop restaient dans le buffer (la mémoire d'entrée) et étaient lus au tour suivant, ce qui faussait la partie. J'ai réglé ça avec `while (getchar() != '\n');`, qui lit et jette tout ce qui reste jusqu'à la fin de la ligne.
- **Les lettres en double** : le plus délicat a été de colorer correctement les jaunes quand une lettre apparaît plusieurs fois. J'ai utilisé un tableau `dejavu` et traité les verts avant les jaunes, pour ne pas colorer une lettre plus de fois qu'elle n'existe dans le mot secret.
- **L'affichage en couleur** : il a fallu utiliser des codes ANSI (comme `\33[30;42m`) pour colorer les lettres dans le terminal.
- **Les mots invalides** : un mot absent du dictionnaire ne doit pas compter comme un essai, d'où l'utilisation de `continue` dans la boucle.


## Plaisir d'avoir codé ce jeu

J'ai découvert Wordle pendant l'été, quand un proche m'a proposé d'y jouer ensemble pour la première fois. Le jeu m'a tout de suite plu. Depuis, je ne rate plus une seule journée sans y jouer.

Quand j'ai vu Wordle dans la liste des jeux proposés pour ce projet, je n'ai même pas hésité : c'était évident que c'était celui-là que je voulais coder. Passer de joueuse à créatrice du jeu, comprendre ce qui se cache derrière chaque couleur et chaque essai, m'a beaucoup motivée tout au long du projet.