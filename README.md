Afficher un prompt :

Afficher un prompt pour attendre une nouvelle commande.
Exemple attendu : Affichage d'un prompt (minishell$) à chaque nouvelle ligne de commande.
Recherche et lancement d'exécutables :

Recherche du bon exécutable en utilisant la variable PATH ou des chemins relatifs/absolus.
Exemple attendu : Exécution correcte des commandes comme ls, echo, etc.
Builtins à implémenter :

echo avec option -n :
Exemple attendu : echo -n "Hello" affiche Hello sans retour à la ligne.
cd avec un chemin relatif ou absolu :
Exemple attendu : cd /home/user change le répertoire courant.
pwd sans options :
Exemple attendu : pwd affiche le répertoire courant.
export sans options :
Exemple attendu : export VAR=value ajoute ou modifie une variable d'environnement.
unset sans options :
Exemple attendu : unset VAR supprime une variable d'environnement.
env sans options et sans arguments :
Exemple attendu : env affiche toutes les variables d'environnement.
exit sans options :
Exemple attendu : exit termine le shell.
Séparation des commandes par ; :

Exemple attendu : ls ; pwd exécute ls puis pwd.
Gestion des quotes simples (') et doubles (") :

Les quotes doivent fonctionner comme dans bash, sauf pour les commandes multi-lignes.
Exemple attendu : echo "Hello World" affiche Hello World.
Redirections :

<, >, >> doivent fonctionner comme dans bash, sauf pour l'agrégation de descripteurs de fichiers.
Exemple attendu : echo "Hello" > file.txt écrit Hello dans file.txt.
Pipes (|) :

Doivent fonctionner comme dans bash pour connecter la sortie d'une commande à l'entrée d'une autre.
Exemple attendu : ls | grep file affiche les fichiers contenant file.
Variables d'environnement :

Les variables ($VAR) doivent être interprétées comme dans bash.
Exemple attendu : echo $HOME affiche le chemin du répertoire utilisateur.
Valeur de retour des commandes ($?) :

Doit refléter le statut de sortie de la dernière commande exécutée.
Exemple attendu : echo $? après une commande affiche son statut de sortie.
Gestion des signaux :

ctrl-C, ctrl-D, ctrl-\ doivent avoir le même comportement que dans bash.
Exemple attendu : ctrl-C interrompt la commande en cours.
Commandes externes et fonctions autorisées
Commandes externes : malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, getcwd, chdir, stat, lstat, fstat, execve, dup, dup2, pipe, opendir, readdir, closedir, strerror, errno.
