<?php

# CPCDOS, RASPBERRY PI, ARDUINO par Esteban Cadic le 06/04/2016
# Partie : Raspberry Pi : PHP

$url_couleur = $_GET['couleur']; # on récupère l'argument couleur
$url_etat = $_GET['etat']; # on récupère l'argument état

if (isset($url_couleur) AND isset($url_etat)) # si tout les arguments ont été définis
{

	if ($url_couleur == 'bleu')
	{
		if ($url_etat == 'on')
		{
			$res = exec('sudo python led.py "##1"'); # alors on envoie ##1 à l'arduino
			echo $res; # DEBUG
		}
		elseif ($url_etat == 'off')
		{
			$res = exec('sudo python led.py "##4"'); # alors on envoie ##4 à l'arduino
			echo $res; # DEBUG
		}
		else
		{
			echo 'Merci d\'entrer un état valide !';
		}
	}
	
	elseif ($url_couleur == 'blanc')
	{
		if ($url_etat == 'on')
		{
			$res = exec('sudo python led.py "##2"'); # alors on envoie ##2 à l'arduino
			echo $res; # DEBUG
		}
		elseif ($url_etat == 'off')
		{
			$res = exec('sudo python led.py "##5"'); # alors on envoie ##5 à l'arduino
			echo $res; # DEBUG
		}
		else
		{
			echo 'Merci d\'entrer un état valide !';
		}
	}
	
	elseif ($url_couleur == 'rouge')
	{
		if ($url_etat == 'on')
		{
			$res = exec('sudo python led.py "##3"'); # alors on envoie ##3 à l'arduino
			echo $res; # DEBUG
		}
		elseif ($url_etat == 'off')
		{
			$res = exec('sudo python led.py "##6"'); # alors on envoie ##6 à l'arduino
			echo $res; # DEBUG
		}
		else
		{
			echo 'Merci d\'entrer un état valide !';
		}
	}
	
	else
	{
		echo 'Merci d\'entrer une couleur valide !';
	}
}

else
{
    echo 'Merci d\'entrer une couleur et un état !';
}
?>