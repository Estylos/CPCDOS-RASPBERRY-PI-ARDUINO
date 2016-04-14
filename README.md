# Cpcdos, Raspberry Pi, Arduino


# Le but : 

Le but est de contrôler un écran LCD et des LEDS avec Cpcdos en passant par un Raspberry Pi et un Arduino...


# Fonctionnement :

Le fonctionnement est assez simple : Cpcdos télécharge une page PHP sur le Raspberry Pi avec un ou plusieurs arguments, selon le ou les arguments envoyés par Cpcdos, PHP va exécuter en tant que root un script Python avec un argument (du style : "##..." pour une commande (allumer une LED, effacer l'écran LCD...) ou du texte pour l'afficher sur l'écran LCD). Ensuite dans le fichier Python, on va établir la communication entre le Raspberry Pi et l'Arduino, puis on va envoyer l'argument à l'Arduino. Selon ce que l'Arduino va recevoir, il va afficher du texte sur l'écran LCD, effacer l'écran LCD, allumer une LED ou encore, changer de ligne.


# Inconvénient :

Premièrement, il ne gère pas les espaces tout seul (ça, c'est la faute à Cpcdos). Il faut tous les remplacer par \\\%20 si on veut afficher du texte avec des espaces sur l'écran LCD.

Deuxièmement, il ne gère pas non plus les accents et les lettres accentuées (franchement, je ne sais pas trop d'où ça vient... Je reste assez perplexe ).


# Informations :

Ce texte a été repris de ma discussion sur http://www.developpez.net/forums/d1579907/systemes/autres-systemes/cpcdos/cpcdos-raspberry-pi-arduino/ .

