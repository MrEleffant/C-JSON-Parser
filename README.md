# C Project
## Sujet
Réaliser un parser (analyser) de fichier.
Le fichier sera un fichier au format texte. Le contenu du fichier de sera de la forme suivante:

[elem1, elem2, elem3, ….. ]

Chaque élément peut être de type, “entier” (int), virgule flottante, chaine de caractère,
booléen. le début et la de la liste sont marqués par les caractères [ ].
Un fichier ne contient qu’une seule liste d'éléments.
Les flottants sont en notation américaine (ie: 12.42 et non 12,42)

Exemple de contenu de fichier:
[ 42, “ma chaîne de character”, true,1, 67]
[ ]
[ toto, 42, 10, 11.567, 12]

Vous devez réaliser un programme qui ouvre le fichier, charge les éléments en mémoire, et affiche de le résultat de l’analyse sur la forme suivante:
#:
type: ...
content: ...
Pour une liste [ 1, “42”] le résultat est le suivant:
0:
type: int
content: 1
1:
type: string
content: “42”

Le programme doit être exécuté de la façon suivante:
./projet1 <nom_de_fichier>
exemple:
./projet1 fichier_test1.txt

Contraintes: !!!! ATTENTION !!!!
Vous devez créer une structure de donnée en mémoire, votre programme doit faire l’analyse
et l’affichage en 2 étapes, exemple en pseudo code:
ma_liste = analyse_fichier(“fichier.txt);
fonction_affiche(ma_liste);
Vous devez utiliser les fonctions malloc et free.

Barème
Si le programme fonctionne mais ne respecte pas les contraintes du sujet note max 10/20.
Si le programme fonctionne et respecte les contraintes, note max 15/20.
5 points sont sur la gestion des cas d’erreurs.
3 points peuvent être retirés, si le code n’est pas formaté correctement, s’il est
anormalement complexe ou difficile à lire.

## Rendu
Ce projet est un programme en C qui prend un ou plusieurs noms de fichiers en tant qu'arguments de ligne de commande, lit le contenu de chaque fichier et analyse le contenu en tant que liste d'éléments. Chaque élément peut être un booléen, un entier, un flottant ou une chaîne. Le programme stocke ensuite le type et la valeur de l'élément dans une liste chaînée, et appelle une fonction pour afficher les éléments. Enfin, il libère la mémoire allouée pour la liste chaînée.

Utilisation
Pour utiliser ce programme, vous devez d'abord compiler le fichier source en utilisant un compilateur C tel que GCC. Vous pouvez le faire en utilisant la commande suivante :

```
gcc main.c -o main
```
Une fois compilé, vous pouvez exécuter le programme en ligne de commande en lui donnant les noms de fichiers en tant qu'arguments :

```
.\main "./inputs/fichier1.json" ... "./inputs/fichierN.json"
```
Le programme va alors lire le contenu de chaque fichier et afficher les éléments dans la console.

Commmande de compilation et d'exécution
```sh
gcc main.c -o main.exe && ./main.exe "./inputs/fichier1.json" "./inputs/fichier2.json"
```
```powershell
if ($?) { gcc main.c -o main} ; if ($?) { .\main "./inputs/fichier1.json"}
```

### Note
- Wall ne remonte aucune érreur  
- Il est important de noter que le format attendu pour les fichiers en entrée est une liste d'éléments séparés par des virgules et encadrés par des crochets, comme ceci :
    ```
    [true, 123, 4.56, "hello"]
    ```
    Si le format n'est pas respecté, le programme pourrait ne pas fonctionner correctement.

### Gestion des Erreurs
- Possibilité de parser plusieurs fichiers
- La détection des booleans n'est pas case sensitive.
- Le programme retourne une erreur si le fichier n'existe pas ou s'il n'est pas accessible.
- les nombres flottants .5 et 5. sont acceptés.
- chaques arguments est trim sur la gauche (gestiond des espaces superflus)
- Gestion des gros fichiers (Testé avec 3Mo, 187k structures)