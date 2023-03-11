# Sujet du projet S106


## Organisation et planning

⚠ Valérie Fabre étant en arrêt maladie, certaines séances ne seront pas encadrées.

Ce projet se fait en binômes (sauf quelques exceptions). Vous pouvez trouver votre groupe ici.

Pour ce projet, vous aurez:

7 séances d'1h30 jusqu'en novembre, encadrées par Benjamin Hellouin et Valérie Fabre (par alternance).

Planning recommandé
Vous êtes autonomes pour diriger votre projet. Les dates ci-dessous ne sont que des suggestions de votre niveau d'avancement après chaque session.
1ère session : vous avez choisi un thème, un nom, un slogan, un logo, et commencé à réflechir à écrire des textes pour les pages 1 et 2. Vous avez un dossier partagé avec un fichier qui prépare le rapport.
2ème session : vous êtes d'accord sur l'idée générale de l'apparence du site et vous répartissez le travail. Premiers jets des textes qui apparaissent sur le site.
5ème session : la structure générale du site doit être faite, et vous corrigez des détails, vous travaillez la conception adaptative. Vous pouvez décider de faire du travail supplémentaire si vous avancez bien.
6ème session : le site doit être presque finalisé ; la dernière séance pour nettoyer le code, le valider, compléter et vérifier les détails du rapport.
A la dernière séance, pensez à relire le sujet pour vérifier que vous n'oubliez rien. Il vous reste du temps avant de rendre si nécessaire.

## Consignes générales :

⚠ Ce site est la seule référence pour les consignes. Si vous avez un doute, vous devez nous demander.

Les consignes du sujet sont un cahier des charges ; il faut les respecter en détail (cela fait partie de la notation) mais vous pouvez toujours ajouter des choses non demandées (plus de détail en section Notation.

C'est normal que vous ne sachiez pas tout faire. N'hésitez pas à faire des recherches sur Internet, regarder d'autres sites, nous poser des questions...
Vous devez suivre les bonnes pratiques vues en cours même si le sujet ne le précise pas. Par exemple, pensez à la lisibilité, à la validation W3C...
Vous avez beaucoup de liberté sur le contenu, mais il est important de respecter rigoureusement les consignes du sujet (c'est votre cahier des charges). Vous pouvez aller au-delà (voir section Notation) mais cela ne doit pas aller à l'encontre des consignes.
Après chaque séance, sauvegardez votre travail sur la machine et quelque part en ligne (par exemple sur le cloud de l'IUT).
Ressources externes :
Vous pouvez utiliser des ressources externes (code, images, texte...) de manière raisonnable, en citant leur origine (le site, pas le moteur de recherche) dans le rapport. Il faut que nous puissions retrouver l'original. Si vous l'avez adaptée ou modifiée, dites-le. Bien sûr, ne récupérez pas des pages entières (ça se voit).
Si vous utilisez du code externe sans le signaler, nous considèrerons que vous n'avez rien fait sur la partie concernée.
Vous ne pouvez pas réutiliser du code d'autres projets (cette année ou années passées).
Binômes
La présence et le travail sont obligatoires à chaque séance. Si vous n'êtes pas actifs dans votre groupe (absences non justifiées, retards, discussions...), cela sera pris en compte dans la notation finale. En cas d'absence, vous devez prévenir vos partenaires et rattraper votre travail plus tard.
Les changements de partenaire ne sont pas autorisés, sauf situation exceptionnelle et avec notre autorisation.
Si vous avez un problème avec votre binôme, vous devez nous en parler avant la fin du projet. Nous serons vigilants à ce qui se passe dans votre groupe, et nous vous aiderons à trouver une solution.

## Choix du sujet

L'entreprise :
Vous choisissez une entreprise fictive concentrée sur un ou deux produits ou concepts. Votre entreprise peut être :

en informatique ou pas,
réaliste ou imaginaire,
sérieuse ou parodique...
Le but est que le sujet vous plaise et que vous puissiez en parler de manière crédible. Votre site sera visible par toute la promotion. Evitez donc des sujets :

trop provocateurs (thèmes crus, inconfortables, etc.)
trop surréalistes (il faut que vous puissiez expliquer l'utilité de l'entreprise)
Demandez-nous si vous avez un doute.

## Identité visuelle

Dés la première séance, vous commencerez à définir l'identité de l'école :

- Un nom.
- Une image qui servira de logo.
- Un sous-titre ou slogan (du type "Notre qualité c'est l'excellence").
- Au moins deux couleurs majeures (en RGB) à utiliser sur le site et le rapport.
- Au moins deux polices (textes / titres).

## Site Web - général

Votre site Web contiendra plusieurs pages (fichiers HTML différents qui peuvent partager des fichiers CSS) et un menu de navigation qui permettra de passer d'une page à l'autre.

Toutes les pages du site doit contenir le nom de l'entreprise, le logo et le menu de navigation, situés comme vous le souhaitez.

Chaque page doit avoir un pied de page contenant la liste des membres du projet ainsi qu'un lien vers votre rapport aux formats traitement de texte et au format pdf.

### Spécifications :
Les polices doivent s'afficher correctement même si la police n'est pas installée chez l'utilisateur (en utilisant @font-face dans le CSS).
Le site doit passer la validation W3C.
L'image du logo et un titre doivent apparaître dans l'onglet du site.
Le site doit utiliser l'espace disponible et rester utilisable sur une taille d'écran entre 350px et 1600px. Il faut utiliser au moins une requête média pour changer la mise en page d'un bloc.
A un endroit dans votre site, vous devez avoir du texte sur une image.
Le code du projet doit être bien rangé (pas de redondance ou de code mort) et bien formaté.
Si les autres spécifications sont faites, un exemple de travail supplémentaire est d'ajouter au menu de navigation un menu déroulant fait en HTML+CSS qui permet de choisir à quel endroit de la page on arrive. Vous pouvez tenter de le faire vous-même avec ce que vous avez appris et la pseudo-classe :hover, ou bien vous inspirer d'exemples sur Internet (en les citant dans votre rapport !)

## Site Web - page à page
Première page: accueil
Les visiteurs doivent arriver automatiquement sur cette page (index.html).

Elle contient un texte argumenté présentant votre entreprise (plus de détails en partie Communication). Les différents paragraphes doivent être visuellement séparés (pas de gros blocs de texte). La page doit avoir à un endroit une grande image de fond et votre logo affiché en grand.

Elle doit aussi contenir une vidéo venant d'un fourniseur de votre choix : framatube, youtube, dailymotion... Elle peut être pertinente ou non.

## Deuxième page : produits
Cette page propose différents produits ou services proposés par votre entreprise (au moins trois), chacun dans un bloc indépendant. Chaque bloc doit contenir :

Le nom ainsi qu'une courte description ;
Quelques informations factuelles de votre choix (prix, temps de livraison...) placés hors du texte ;
Une image ou une icône.
Les deux aspects les plus importants sont que les informations doivent être présentées de manière cohérente entre les blocs, et qu'il doit être facile de rajouter un bloc si nécessaire (copier-coller + modifications mineures). Autrement dit, il ne faut pas que chaque bloc ait beaucoup de CSS spécifique.

Vous pouvez utiliser ici des outils vus en cours de Web comme flexbox ou les grilles CSS.

## Troisième page : contact
Cette page sert aux informations de contact et d'accès. Elle contient dans l'ordre que vous voulez :

Des informations de contact (adresse, téléphone, mail - vous pouvez tout inventer).
Une carte pointant sur l'entreprise.
Un formulaire de contact avec un bouton inactif.
Le formulaire doit permettre au visiteur d'indiquer son nom, adresse mail et message et de sélectionner une personne à contacter. Le formulaire est décoratif : vous verrez comment faire des formulaires actifs plus tard. Vous devez trouver et utiliser les éléments HTML appropriés.

La carte doit utiliser un service externe tel que OpenStreetMaps ♡, Google Maps, Bing Maps... C'est à vous d'aller vous renseigner sur leur site.
