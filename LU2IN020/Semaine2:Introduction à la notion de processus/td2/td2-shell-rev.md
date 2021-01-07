------- Td2: Introduction à la notion de processus ------
objectifs:
x appréhender la notion de processus
x Etudier le lancement d'un programme depuis le terminal
x Apprendre à travailler avec la valeur retourné d'un programme
x Une commande Bash n'est rien d'autre qu'un programme qu'on lance
*Exercice 1: Code source, exécutable et processus*
**Question 1:
Pour commencer, étudiez la fonction main(). Que fait ce programme ? Quel affichage est produit, si l’on
appelle le programme avec les paramètres 22 et 34 ? ***
Réponse : le programme prend 2 arguments et calcule leurs somme.
22+34 = 56  donc le programme affichera 56
**Question 2 :
Le programme a besoin de deux paramètres, mais on fait le test sur argc par rapport à 3. Pourquoi ? ***
Réponse : car le nom de l'executable ./sum est pris en compte comme argument
**Question 3 :
Le terme programme est souvent employé à mauvais escient. On préférera donc les termes de code source, exécutable (ou binaire) et processus, moins ambigus. Illustrez ces trois termes avec notre cas d’étude (le cas échéant vous indiquerez la commande permettant de l’obtenir). ***
Réponse :
Code Source : C'est le code qu'on écrit dans un langage de programmation et il est converti en exécutable ( C, Java) , on peut le lire.
exécutable : Ce fichier est crée lors de la compilation , il contient un programme binaire directement exploitable par le processeur
Processus: c'est un programme en cours d'exécution
*Exercice 2 : Le lancement d’un programme **
Dans cet exercice nous allons étudier ce qui se passe lorsque nous lançons des programmes depuis la
console. On supposera ici l’existence d’un binaire sum correspondant à la compilation du code étudié dans
l’exercice 1.
**Question 1 : Les étapes étudiées de l'exécution de la commande ./sum 23 12 dans la console. ***
Réponse :- Après qu'une commande est taper sur la ligne de commande et la clé entrer est cliquer dessus, le shell passe par les étapes suivantes  pour exécuter cette commande
1- Recherche de la fin de la commande , tokenization
2- Substitutions : $ ... , [..], {..} Rien à faire
3- Découpage : $IFS signale le séparateur (on prépare un tab argv )
   - argv[0] = sum
   - argv[1]= 22
   - argv[2]= 34
4- Recherche du binaire , de l'exécutable
   - on lui a donné un chemin dans le dossier courant
5- On crée un processus, qui va exécuter le binaire
6- On bloque jusqu'au nouveau processus
**Question 2: Quel lien existe entre les deux processus ? ***
Réponse : Il existe un lien de parenté ( père - fils) entre les Processus ou une relation de filiation
**Question 3 : Comment le système d’exploitation identifie ces deux processus et leurs relations de filiation ? ***
Réponse : à partir de leurs pid (process identifier ), le processus père sera représenter par son ppid et le fils par le pid.
**Question 4 : Dessinez le chronogramme correspondant à ce lancement. ***
Réponse :
    Bash
       |
       |
./sum.c →→→→→¬
             | 56
        -----|     
       |
       |  

 **Question 5 : On considère maintenant le script creation_dir.sh dont le code est donné ci-dessous. Quelle commande permet de lancer ce script ? Combien de processus sont alors créés ? ***
Réponse : Pour lancer le script on doit exécuter le programme en tapant la commande ./creation_dir.sh et on doit changer les droits s'il nous le demande
mkdir n'est pas une commande built-in donc c'est un processus
la boucle for crée 11 processus
et le programme exécuter est un processus aussi
ce qui fait un total de 13 processus
**Question 6 : Peut-on générer la même arborescence en se limitant à la création d’un processus ? Quel en serait
l’intérêt ? ***
Réponse : Oui il est possible de générer la même arborescence en se limitant à la création d'un processus , l'intérêt serait de gagner le temps perdus en écrivant le code source avec la boucle for et le temps d'exécuter le script , aussi ça prend moins de temps d'exécution car on à un seul père qui est le bash qui crée tout les processus fils .
la commande est : mkdir -p LU2IN020/TP_{0{1..9},10,11}
**Question 7: On veut maintenant afficher tous les README présents dans les différents sujets de TP. Combien de
processus sont créés par l’exécution du script suivant : ***
cd, pwd sont des commandes built-in on peut vérifier cela avec la commande which
ls et cat sont des processus
donc 3 processus ( ls,cat et le script )
*Exercice 3: Recherche de l'exécutable
Dans cet exercice, on considère l’arborescence suivante qui contient plusieurs instances d’un exécutable : **
**Question 1 :
Quelle instance de monProg va utiliser Bash pour lancer la commande, sachant que la recherche de
l’exécutable se fait suivant l’algorithme suivant :
— cherche l’exécutable à l’endroit indiqué s’il est préfixé d’un chemin absolu (commençant par / ou
relatif (commençant par un ., un .., ou le nom d’un sous-répertoire du répertoire courant) ;
— cherche itérativement dans tous les répertoires listés dans la variable $PATH sous la forme d’une suite
de répertoires cibles séparés par le caractère ':'.
— affiche un message d’erreur si l’exécutable n’a pas été trouvé. ***
Réponse : comme l'exécutable n'est pas préfixé d'un chemin absolu ( il n'y'a pas de / ) , le bash va utiliser l'instance de monProg qui se trouve dans le premier répertoire du $PATH qui contient monProg qui est /bin
**Question 2 :
1- Proposez une ligne de commande qui modifie la variable $PATH de façon à ce que ce soit l’exécutable du répertoire td_02/exo_01 qui soit lancé.
2- En étant lancé depuis la home, le script suivant permet-il de lancer toutes les instances de monProg du
td_02. Si oui pourquoi ? Si non, proposez une correction. ***   
Réponse :
1-  $PATH = /home/moi/td_02/exo_01/$PATH
2- Non , car il faut lancer le script depuis le repertoire td2.
Si on veut lancer le script depuis le home on doit ajouter ./ avant monProg
*Exercice 4 : Test et exécution conditionnelle
Comme tous les langages le Bash offre une structure de contrôle conditionnelle. Ainsi le mot clé if
permet de tester si la commande qui suit s’est exécutée sans problème, i.e., a retourné la valeur 0. **
**Question 1:  Si la syntaxe du if est correcte, une erreur s’est glissée dans ce script. Trouvez là et proposez une
solution. ***
Réponse : dans le deuxième script il faut mettre le chemin en préfixe avant l'exécutable donc on écrit ./monProg au lieu de monProg
**Question 2
Quel est l’affichage produit par la version corrigée du script ?***
Réponse : Si monProg retourne 0 alors il affiche le numéro sinon il n'affiche pas le numéro donc il affiche tout les numéro paire dans l'intervalle [0,100]
**Question 3
Pourquoi est-il difficile d’utiliser notre programme C pour faire le test inverse, sans avoir à le modifier.**
Réponse : car en C , il n'est pas possible d'écrire ./monProg avec ces arguments dans le code
**Question 4: Lorsqu’une commande se termine**
*le Bash affecte sa valeur de retour à la variable $?. Attention, dès
qu’on lance une nouvelle commande cette valeur est perdue, puisqu’elle remplacée par la valeur de retour de la dernière commande lancée.*
**Pour tester la valeur de la variable $?, le Bash offre la commande "test" qui permet d’évaluer une expression booléenne et retourne 0 si son résultat est vrai. Grâce à elle on peut utiliser le if du Bash comme
on le fait dans les autres langages.
Il existe un grand nombre de tests possible : sur les chaînes de caractères, sur les valeurs entières ou encore sur le système de fichiers. Leurs descriptions sont à lire sur l’Annexe Shell de l’UE. ***
test x -lt y −→ retourne 0 si x < y
Réponse :
for num in {1..100}; do
./monProg $num
if test 0 -lt $?;
then
   echo $num impair
fi
done
**Question 5 :Pour simplifier son accès aux programmeurs habitués aux parenthèses, Bash introduit un alias à la
commande test sous la forme de la commande [ qui s’utilise exactement comme test avec un dernier
paramètre ] pour faire beau.
test x -lt y ⇐⇒ [ x -lt y ]
Réimplémentez votre script avec cette nouvelle syntaxe. ***
Réponse :
for num in {1..100}; do
./monProg $num
if [ 0 -lt $?] ;
then
   echo $num impair
fi
done
