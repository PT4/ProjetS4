![alt text](Code/images/RecolteurJoueur1.png "Ours") PT4 - ROUDEAU & REY & SILVERIO ![alt text](Code/images/RecolteurJoueur2.png "Ours")
==============================

BearCraft est un Jeu développé grâce à la bibliothèque SFML.
Pour compiler le jeu, il faut donc installer cette bibliothèque.

Table des matières
------------------

###### I] Installation et Compilation/Exécution ######

###### II] Cahier des charges ######

###### III] Diagramme des classes ######

###### IV] Règles du jeu ######

I] Installation et Compilation/Exécution
----------------------------------------

### Commande pour installer la SFML sous Linux: ###
    - Ouvrir un Terminal/Console
    - exécuter la commande suivante :
        sudo apt-get install libcsfml-dev


La SFML est maintenant installée.


### Commande pour compiler/lancer le jeu: ###
    - Ouvrir un Terminal/Console
    - Se rendre dans le dossier contenant le jeu
    - exécuter la commande "make" pour compiler le jeu
    - exécuter la commande "./BearCraft" pour exécuter le jeu

II] Cahier des charges
----------------------

### 1) Objectifs ###
  
    Gérer un joueur et une IA en temps réels.

##### Joueurs #####
    - quantité de miel récolté
    - quantité de bois récolté
    - quantité de population (ne dois pas dépasser la limite fixée)

##### Carte #####
    - Une arène de jeu ( 2 maps différentes )
    - Différents sites de départs possibles
    - Différents sites de ressources
    - Obstacles
    - Taille de l'arène plus grande que la fenêtre de jeu

##### Ressources #####
    - Miel (pour les unités)
    - Bois (pour les batiments)

##### Bâtiments ####
    - Base : créer des récolteurs
    - Entrepôt : amasser des ressources
    - Caserne : créer des soldats
Clic de sélection sur les batiments.
Points de vie.
Chaque batiment possède un prix en bois qu'il faut débourser pour créer le nouveau batiment.
Un batiment possède deux états : normal (ne fait rien) et création (forme de nouvelles unités). Le dernier
état n'est pas valable pour les entrepôts.
Le joueur ne peut créer un batiment que s'il possède les ressources nécessaires.

##### Unités ####
    - Récolteurs
    - Soldats
Clic de sélections sur les unités.
Points de vie.
Vitesse de déplacement.
Chaque unité possède un prix en miel qu'il faut débourser pour créer la nouvelle unité.
Les récolteurs possèdent trois états : déplacement (objectif sur la carte), collecte (aller-retour) et attaque.
Les soldats possèdent deux états : déplacement et attaque. Les récolteurs et les soldats peuvent être aussi immobiles.
L'état déplacement nécessite un objectif sur l'arène de jeu cliqué par le joueur.
Lorsqu'une unité se déplace, si elle rencontre un ennemi, elle passe en mode attaque. Si l'unité ennemi est tuée alors l'unité repend son chemin.
La zone d'attque des soldats est plus grande que celle des récolteurs. La zone d'attaque peut être paramétrée par son rayon.

### 2) Constantes ###

Deux joueurs.
Nombre de sources de miels et de bois pour chaque emplacement de départ.
Limite de population.

III] Diagramme des classes
--------------------------

![alt text](class\ diagram.jpeg "diagram")

IV] Règles du jeu
-----------------
