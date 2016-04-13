<?php

# CPCDOS, RASPBERRY PI, ARDUINO par Esteban Cadic le 06/04/2016
# Partie : Raspberry Pi : PHP

$url_fonction = $_GET['fonction']; # on récupère l'argument fonction
$url_texte = $_GET['texte']; # on récupère l'argument texte

if (isset($url_fonction)) # si l'argument fonction a été défini
{
	if ($url_fonction == 'effacer') 
	{
		$res = exec('sudo python lcd.py "##clear"'); # alors on envoie ##clear à l'arduino
		echo $res; # DEBUG
	}
	
	elseif ($url_fonction == 'ligne1')
	{
		$res = exec('sudo python lcd.py "##l1"'); # alors on envoie ##l1 à l'arduino
		echo $res; # DEBUG
	}
	
	elseif ($url_fonction == 'ligne2')
	{
		$res = exec('sudo python lcd.py "##l2"'); # alors on envoie ##l2 à l'arduino
		echo $res; # DEBUG
	}
	
	elseif ($url_fonction == 'texte') 
	{
		if (isset($url_texte)) # si l'argument texte a été défini
		{
			$txt_tmp = "sudo python lcd.py \"$url_texte\"";  # alors on envoie le texte (variable : url_texte) à l'arduino
			$res = exec($txt_tmp);
			echo $res; # DEBUG
		}
		
		else
		{
			echo 'Merci d\'entrer du texte !';
		}		
	}
	
	else
	{
		echo 'Merci d\'entrer une fonction valide !';
	}
}

else
{
    echo 'Merci d\'entrer une fonction !';
}
?>