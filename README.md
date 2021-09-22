# TP 2 Bases du Génie Logiciel -- Makefile & Tests

**Enseignant**: Pablo de Oliveira < pablo.oliveira@uvsq.fr >

Le but de ce TP est de mettre en pratique les notions sur Git, les Makefile et les tests unitaires dans un projet logiciel simple.
En fin de TP si nous avons le temps nous pourrons utiliser des outils de couverture de code, et réaliser des mesures de performance.

## Prérequis

Pour faire ce TP vous aurez besoin d'installer

- La bibliothèque [cmocka](https://cmocka.org/)
- Le compilateur `gcc` ou `clang`
- (optionnel) L'outil `gcov`

Assurez-vous de bien commiter chacune de vos modifications avec des messages clairs et détaillés.

## Spécifications

Dans ce TP nous allons développer un programme pour résoudre le problème classique des n-reines.

On dispose d'un échiquier carré de n x n cases. Pouvons nous disposer n reines sur l'échiquier de manière à ce qu'aucune reine puisse en attaquer une autre ?

Voici un exemple de solution pour 4 reines, les reines sont matérialisées par la lettre R,

```
. . R .
R . . .
. . . R
. R . .
```

### Structures de données

Nous allons commencer par réfléchir à nos structures de données. Il faut pouvoir représenter l'échiquier et le placement des reines. Une première solution consisterait à utiliser un tableau à double entrée de booléens dont la valeur indique la présence d'une reine,

```c
#include <stdbool.h>
#define n 4
bool queen[n][n] = { { false, false, true, false }, 
                     { true, false, false, false },
                      ... };
```

On peut cependant remarquer que chaque colonne ne peut contenir qu'une seule reine. En effet, deux reines sur la même colonne pourraient s'attaquer. Ainsi, il y a une et une seule reine par colonne dans les échiquiers solutions. Il suffit donc de stocker pour chaque colonne le numéro de ligne où la reine est présente. Cela donnera pour l'exemple ci-dessus,

```c
#define n 4
int queen_row[n] = {1,3,0,2};
```

De la même manière, deux reines ne peuvent pas être placées sur la même ligne. Donc le tableau `queen_row` ne peut pas contenir des entrées dupliquées. Pour savoir quelles lignes ont déjà été utilisées au fur et à mesure du programme, nous pourrons nous servir d'un tableau de booléens qui indique quelles lignes sont encore libres. Par exemple au début de l'algorithme nous l'initialiserons de la manière suivante,

```c
#define n 4
bool available[n] = {true, true, true, true}
```

### Organisation du code

Le code va être organisé en plusieurs fichiers:

- `main.c`, contient la fonction main et s'occuppe de l'interface ligne de commande
- `queens.h`, contient la fonction publique `find_solution` qui permet de résoudre le problème des n-reines
- `queens.c`, contient l'implémentation de l'algorithme qui est décomposé en plusieurs fonctions intermédiaires

Merci de prendre le temps de lire ces trois fichiers attentivement. Le code de `main.c` est donné mais l'implementation dans `queens.c` est à faire.

Nous utiliserons des tests unitaires pour développer ce code. Les tests seront écrits avec la bibliothèque [cmocka](https://cmocka.org/).

Les tests sont dans les fichiers `test_main.c` et `test_queens.c` respectivement.

Pour construire le programme, un script `build.sh` est donné.

## Questions

1. Remplacer le script `build.sh` par un `Makefile`. Utilisez toutes les techniques vues en cours pour améliorer votre `Makefile`. Assurez vous d'inclure des cibles pour nettoyer le projet, lancer les tests, etc. Utilisez la compilation séparée pour réduire le temps de build.

2. Lisez attentivement les tests de main dans `test_main.c`. Quelle fonction de main est testée ? Comment les entrées de tests ont-elles été choisies ? Manque-t-il des tests à votre avis ?

3. Implémentez chacune des fonctions dans `queens.c` dans l'ordre où elles sont données. Attention a bien suivre la philosophie de développement guidé par les tests. Avant d'écrire le code d'une fonction, rajoutez un ensemble de tests unitaires dans `test_queens.c` pour tester la fonction.

3. Testez le programme finalisé pour plusieurs tailles de grille. Vérifiez que le programme réponds bien au problème posé initialement dans les spécifications.

## Questions bonus

4. Utilisez l'outil `llvm-cov` ou `gcov` pour calculer la couverture de code obtenue durant les tests. Par exemple avec llvm les commandes nécessaires sont,

```sh
# utiliser l'option --coverage pendant la compilation
clang-6.0 --coverage -std=c99 -O0 -g test_queens.c -o test_queens -lcmocka

# exécuter les tests
./test_queens

# produire les rapports de couverture
llvm-cov-6.0 gcov -f -b test_queens
```

Quel taux de couverture est atteint par nos tests ?

5. Utilisez la fonction définié dans `rdtsc.h` pour mesurer précisément le nombre de cycles pris par l'algorithme. Tracez ce nombre de cycles en fonction de la taille n de l'échiquier. Est-ce que plusieurs mesures répétées sont stables ? Comment transformer le nombre de cycles mesuré par RDTSC en temps ? Pouvez vous faire une hypothèse sur la compléxité de l'algorithme ?

6. Pouvez vous accélérer le programme ? 

7. Pouvez vous améliorer l'interface ? 
