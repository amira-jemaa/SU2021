+ Le but de cette neuvième semaine est d’étudier la communication par signaux. On y étudiera l’envoi de
signaux, mais aussi la redéfinition des handlers de signaux.

## Exercice 1: : Exploiter au mieux ses ressources
-kill [-num] pid
+ num = numéro d’identification du signal (si omis signal SIGTERM envoyé)
+ Pas obligatoirement depuis le terminal de rattachement du processus
+ Signal SIGKILL (numéro 9) provoque TOUJOURS l’arrêt du processus
• Pas de possibilité de modifier le comportement du processus
+ Autres signaux intéressants: STOP (numéro 19) et CONT (numéro 18)
+ Interruption uniquement des processus dont l’utilisateur est propriétaire
- Question 1 : Sachant que la commande kill permet d’envoyer un signal à un processus dont le pid est passé en
paramètre, quel affichage est produit par l’exécution du script pere.sh.
- Réponse :  + kill -signal_name pid
+ $! : PID du dernier processus créé en arrière plan
le lancement de pere.sh nous donne :
Debut du père (18585)
Debut du fils (18586)
Fils : 1
Fils : 2
./pere.sh: line 5: 18586 Terminated: 15          ./fils.sh
./pere.sh: line 7: kill: (18586) - No such process
./pere.sh: line 7: kill: (18586) - No such process
./pere.sh: line 7: kill: (18586) - No such process
Fin père
+ On lance pere.sh qui affiche son pid , puis il lance le processus fils.sh & en paralléle, qui affiche debut fils est son pid 
puis à chaque seconde (sleep 1) affiche fils $i ( i de 1 à 10) mais dans l'affichage du programme , il affiche seulement fils 1 et fils 2
on explique cela car pere.sh est lancé en paralléle , d'aprés le script il attend 2 secondes (sleep 2) ce qui permet au fils d'afficher fils 1 et fils 2 puis , il envoie un signal kill -s sigterm $pid_du qui interrompe et termine le processus fils. la boucle du pére continue comme il n'y'a plus de processes avec ce pid il affiche no such process à chaque itération puis affiche Fin pére
-Question 2 : Voici une nouvelle version qui utilise la commande trap pour redéfinir la fonction à exécuter à la réception
d’un signal, appelée handler. Quel affichage est produit par l’exécution du script pere_2.sh ?
Debut du père (18760)
Debut du fils (18761)
Fils : 1
Fils : 2
Réception signal à
Fils : 3
Fils : 4
Réception signal à
Fils : 5
Fils : 6
Réception signal à
Fils : 7
Fils : 8
Fin père
amira@As-MacBook-Pro TD9ISS % Réception signal à
Fils : 9
Fils : 10
Fin du fils
 La valeur de $i ne s'affiche pas à chaque Reception de signal 
- Question 3 : Proposez une correction qui permette un affichage correct à la réception d’un signal SIGTERM.
#! /bin/bash
echo "Debut du fils ($$)"
for i in {1..10} ; do
trap "echo Réception signal à $i" SIGTERM
echo "Fils : $i"
sleep 1
done
echo Fin du fils
 ==> on met trap dans la boucle      
- Question 4 : Proposez maintenant une nouvelle version qui restaure le handler par défaut (il suffit dans un trap de
remplacer le handler par un -) après la réception du premier signal.
- Question 5 : On veut maintenant restaurer le handler par défaut après la réception de trois signaux, quel que soit la
date de réception.
-Question 6 : Que devient l’affichage de votre dernier script si l’on modifie le père en sortant la commande sleep de
la boucle (sans modifier le fils) ?
Le fils reçoit le signal seulement aprés deux affichage de fils $i ( à 2 ) . puis affiche le reste des fils $i 
## Exercice 2 : Ping Pong
- Question 1:Implémentez ces deux scripts en utilisant l’envoi du signal SIGUSR1 pour synchroniser les affichages.
Dans cette première version, les affichages se feront de manière infinie.
- Question 2:Modifiez vos scripts de façon à pouvoir les arrêter (tous les deux) en envoyant un signal SIGUSR2 au
processus exécutant ping.sh.
