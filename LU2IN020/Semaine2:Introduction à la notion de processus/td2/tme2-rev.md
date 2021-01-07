------- Tme2: Introduction à la notion de processus ------
objectifs:
x appréhender la notion de processus
x Etudier le lancement d'un programme depuis le terminal
x Apprendre à travailler avec la valeur retourné d'un programme
x Une commande Bash n'est rien d'autre qu'un programme qu'on lance
Exercice 1: Question de nom
Question 1 :
wget http://julien.sopena.fr/LU2IN020-TP_02.tgz
ou bien curl -O http://julien.sopena.fr/LU2IN020-TP_02.tgz
pour extraire le fichier : tar -zxvf lefichier.tgz
Question 2 :
Pour compiler le code source et le transformer en exécutable/binaire en utilise : gcc -o mon_test mon_test.c
Pour exécuter le binaire et lancer le programme : ./test
voir le contenu du fichier : cat mon_test.c
Question 3 :
En absence de paramètres  , il affiche une erreur
Plus qu'un argument : renvoie le resultat du premier param
Un argument : affiche si le numero est pair ou impair
Question 4 :
mv mon_test il_est_pair
Question 5 : on change arc < 2 par argc ==2
Exercice 2 : Et PATH le chemin
Question 1:
 cp exo1/est_il_pair /exo2
Question 2:
le probléme vient du préfixe de l'exécutable il faut lui ajouter un ./ sinon bash ne trouve pas le chemin correspondant
Question 3 :
$PATH_OLD = $PATH
$PATH = /home/moi/td_02/exo2/$PATH_OLD
Question 4:

Question 5:
cd rep1
mkdir rep2
Question 6:
Il est dangereux de mettre un '.' dans un PATH car le point désigne le répertoire courant, ou peut également désigner le début de l'extension d'un fichier. on peut aussi stomper notre path avec ça
Exercice 3 : Une histoire de famille
Q1:
#!/bin/bash
#fils.sh
if [ ! $# -eq 0 ]; then
echo "il ne faut pas d'arguments"
else
echo "je suis $$ et mon père est $PPID"
fi
Question 2/3:
 #!/bin/bash -> #! le shebang : identifie l'executable comme script n'est pas un binaire il est suivie du nom de l'interprête  
 #pere.sh
 if [ ! $# -eq 0 ]; then
 echo "il ne faut pas d'arguments"
 else
 echo "je suis $$"
 for i in {0..10}; do
 ./fils.sh
 done
 fi
 Question 4 :
 En dehors du shebang qui se trouve toujours au début du
 fichier, le caractère dièse # (en réalité le
caractère croisillon) est utilisé comme caractère d’échappement pour les commentaires. Ainsi, pour chaque
ligne de code tout ce qui se trouve après un # est ignoré.
