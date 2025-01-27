# vayetek
Ce code présente la réponse de la question 1 du test technique que vous m'avez envoyé.

## Explication de la 1ère partie
- La première partie présente la fonction extraction qui va extraire le premier chiffre et le dernier d'une chaine de caractère à l'aide d'une boucle for pour chacun. 
- Suite à l'extraction, la fonction va faire la somme du premier chiffre * 10 avec le dernier chiffre et la retourner.

### Pourquoi paralléliser cette fonction:
- Les 2 boucles for sont semi-dépendantes donc la parallélisation est possible. Dans ce cas, j'ai utilisé la directive sections pour que les 2 boucles s'exécutent en parallèle. 
- Grâce à la barrière implicite de cette directive, la somme des 2 chiffres ne va être effectuée qu'à la fin des 2 boucles ensembles, donc pas de risque de synchronisation.

## Explication de la 2ème partie
- La 2ème partie est conçue pour faire ouvrir le fichier et le lire ligne par ligne à l'aide d'une boucle while, appliquer à chaque fois la fonction extraction qui va donner un nombre et faire ajouter ce nombre à une somme.
- Le résultat finale va être cette somme calculée.

