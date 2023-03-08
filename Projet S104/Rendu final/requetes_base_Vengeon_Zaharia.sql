Requête 1
Renvoie les noms et prénoms des adhérents ayant déjà commandés au moins une fois
Cela permet de connaitre les adhérent ayant déjà utiliser nos services.

SELECT nomAdherent, PrenomAdherent
FROM Adherent A
INNER JOIN commande C ON A.idAdhérent=C.idAdherent;

Requête 2
Renvoie les noms des adhérents ayant été livré triés par ordre alphabétique
Cela permet de savoir si tous les adhérents ont bien été livré ou s'il en manque.

SELECT nomAdherent, PrenomAdherent
FROM Adherent A
INNER JOIN adresse AD ON A.idAdresse=AD.idAdresse
WHERE idLivraisons IS NOT NULL
ORDER BY nomAdherent;

Requête 3
Renvoie le prix total des commandes passés par tous les adhérents nominativement
Cela permet de connaitre le prix de chaque commande des adhérents.

SELECT nomAdherent, PrenomAdherent, SUM(prixProduit*quantité) AS PrixTotal
FROM Adherent A
INNER JOIN commande C ON A.idAdhérent=C.idAdherent
INNER JOIN quantitéCommande QC ON C.idCommande=QC.idCommande
INNER JOIN Produit P ON QC.idProduit=P.idProduit
GROUP BY nomAdherent;

Requête 4
Renvoie le nombre de produits commandés par les adhérents nominativement
Cela permet de connaitre les produits à livrés

SELECT nomAdherent, COUNT(typeProduit) as nbproduits
FROM Produit P
INNER JOIN quantitéCommande QC ON P.idProduit=QC.idProduit
INNER JOIN commande C ON QC.idCommande=C.idCommande
INNER JOIN Adherent A ON C.idAdherent=A.idAdhérent
GROUP BY nomAdherent;

Requête 5
Renvoie les types de produits contenu dans toutes les commandes d'un adhérent qui a pour nom
de famille « LEROI »
Cela permet de savoir ce qu'a commandé le client M.leroi jusqu'à aujourd'hui.

SELECT typeProduit
FROM Produit P
INNER JOIN quantitéCommande QC ON P.idProduit=QC.idProduit
INNER JOIN commande C ON QC.idCommande=C.idCommande
INNER JOIN Adherent A ON C.idAdherent=A.idAdhérent
WHERE nomAdherent='LEROI';

Requête 6
Renvoie le prix moyen des produits de la catégorie Isolation
Cela permet de comparer les prix moyens des différentes catégories si on effectue cette commande pour chacune catégorie.

SELECT AVG(prixProduit) as PrixMoyenIsolation
FROM Produit P
INNER JOIN Catégorie C ON P.idCategorie=C.idCatégorie
WHERE nomCatégorie = 'Isolation';

Requête 7
Renvoie le nombre de produits de la catégorie Menuiserie commandés par les adhérents
nominativement
Cela permet de savoir quels produits sont les plus demandés.

SELECT nomAdherent, prenomAdherent, COUNT(nomAdherent) as NbProduitsIsolation
FROM Produit P
INNER JOIN Catégorie C ON P.idCategorie=C.idCatégorie
INNER JOIN quantitéCommande QC ON P.idProduit=QC.idProduit
INNER JOIN commande C ON QC.idCommande=C.idCommande
INNER JOIN Adherent A ON C.idAdherent=A.idAdhérent
WHERE nomCatégorie = 'Menuiserie'
GROUP BY nomAdherent, prenomAdherent
ORDER BY NbProduitsIsolation;

Requête 8
Donner le nom et prénom des adhérents qui ont passés commandes durant le mois de juillet de
2022.
Cela permet de savoir s'il y eu beaucoup d'adhérent au mois de juillet

SELECT DISTINCT nomAdherent,prenomAdherent
FROM Adherent A
INNER JOIN commande C ON A.idAdhérent=C.idAdherent
WHERE dateCommande BETWEEN '2022-07-01' AND '2022-07-30';

Requête 9
Donner les id des commandes et le temps le livraison de chacune.
Cela permet de savoir si les services de livraison sont convenable ou non

SELECT C.idCommande, L.idLivraisons, JULIANDAY(dateCommande) -
JULIANDAY(dateLivraison) AS datedifference
FROM commande C
INNER JOIN Adherent A ON C.idAdherent = A.idAdhérent
INNER JOIN adresse AD ON A.idAdresse=AD.idAdresse
INNER JOIN Livraison L ON AD.idLivraisons=L.idLivraisons;

Requête 10
Donner les noms, prénoms et adresse e-mail des adhérents ayant une boîte mail : Gmail
Cela permet de savoir quel boîte maîl est la plus utilisé chez les adhérents pour de la publicité.

SELECT nomAdherent, prenomAdherent, adresseMail
FROM Adherent A
WHERE adresseMail LIKE '%gmail.com';

Requête 11
Donner les noms et prénoms des adhérents habitant à Angers
Cela permet de dénombre les adhérents habitant à Angers pour une potentielle promotion.

SELECT nomAdherent, prenomAdherent
FROM Adherent A
INNER JOIN adresse AD ON AD.idAdresse=A.idAdresse
INNER JOIN ville V ON AD.idAdresse=V.idAdresse
WHERE nomVille='Angers';

Requête 12
Donner le nombre total de numéro de téléphone de tous les adhérents puis le nombre de numéro de
téléphone commençant par 06 puis 07 des adhérents.
Cela permet de savoir combien d'adhérents se sont inscrits avec leur téléphone personnel et non professionnel.

SELECT
(SELECT COUNT(numTel) FROM Adherent) AS NumeroTotal,
(SELECT COUNT(numTel) FROM Adherent WHERE numTel LIKE '06%') AS
NumeroEn06,
(SELECT COUNT(numTel) FROM Adherent WHERE numTel LIKE '07%') AS NumeroEn07;

Requête 13
Donner le nom, prénom et numéro de téléphone des adhérents ayant le numéro « 14 » dans leurs
numéros de téléphone
Cela permet de chercher les adhérents avec le numero 14 dans leur numero de telephone.

SELECT nomAdherent,prenomAdherent,numTel
FROM Adherent C
WHERE numTel LIKE '%14%';

Requête 14
Donner l'adresse complète de tous les adhérents.
Cela permet de savoir à quelles adresses il faut livrer les commandes.
ex : POURTY | Bernard | 56 rue du Colisée 75008 Paris

SELECT nomAdherent,prenomAdherent,AD.numRue || ' ' || AD.nomRue || ' ' || V.nomVille || ' ' ||
V.codePostale AS adresse
FROM Adherent A
INNER JOIN adresse AD ON AD.idAdresse=A.idAdresse
INNER JOIN ville V ON AD.idAdresse=V.idAdresse;

Requête 15
Donner les noms de villes dans l'ordre croissant du nombre de lettres
Cela peut servir à ordonner lors d'une autre requête.

SELECT nomVille
FROM ville
ORDER BY LENGTH(nomville);

Requête 16
Donner la catégorie du type de produit nommé « douilles »
Cela permet de savoir de retrouver la catégorie en rayon du produit « douilles ».

SELECT nomCatégorie
FROM Catégorie C
INNER JOIN Produit P ON P.idCategorie=C.idCatégorie
WHERE typeProduit = 'douilles';

Requête 17
Donner les id des commandes contenant minimum 3 articles différents
Cela permet de savoir si la stratégie commericale est bonne ou au contraire que l'adhérent parte avec qu'un seul produit.

SELECT idCommande, COUNT(idCommande) AS nbArticle
FROM quantitéCommande QC
GROUP BY idCommande
HAVING nbArticle >=3;

Requête 18
Donner les commandes contenant minimum 15 articles (différent ou similaire)
Cela permet connaître les adhérents qui ont fait de grosses commandes.

SELECT idCommande, SUM(quantité) AS nbArticleTotal
FROM quantitéCommande QC
GROUP BY idCommande
HAVING nbArticleTotal > 15;

Requête 19
Donner le type de produit ayant le prix minimal
Cela permet de connaître le produit pour les petits budgets.

SELECT P.typeProduit, MIN(P.prixProduit)
FROM Produit P;

Requête 20
Donner le type de produit ayant le prix maximal
Cela permet de connaître le produit pour les budgets conséquents.

SELECT P.typeProduit, MAX(P.prixProduit)
FROM Produit P;

Requête 21
Donner les produits qui sont dans la catégorie "toiture"
Cela permet de connaître l'ensemble des produits de la catégorie toiture (même ceux qui sont en rupture de stock).

SELECT typeProduit
FROM Produit P
INNER JOIN Categorie C ON P.idCategorie=C.idCatégorie
WHERE nomCategorie='toiture';

Requête 22
Donner les noms des adhérents qui ont commandé des produits de la catégorie n°2 en précisant 
le type de produit qu'ils ont commandé.
Cela permet de savoir quels produits sont les plus ou moins commandés parmi la catégorie 2.

SELECT nomAdherent,prenomAdherent, typeProduit
FROM Adherent A
INNER JOIN commande C ON A.idAdhérent=C.idAdherent
INNER JOIN quantitéCommande QC ON C.idCommande=QC.idCommande
INNER JOIN Produit P ON QC.idProduit=P.idProduit
WHERE idCategorie=2;

Requête 23
Donner les noms et le prénom des adhérents qui se sont fait livrer entre mai et juin 2022
Cela permet de savoir les adhérents qui font des livraisons entre mai et juin.

SELECT nomAdherent,prenomAdherent
FROM Adherent A
INNER JOIN adresse AD ON A.idAdresse=AD.idAdresse
INNER JOIN Livraison L ON L.idLivraisons=AD.idLivraisons
WHERE AD.idLivraisons IS NOT NULL AND dateLivraison BETWEEN '01/05/2022' AND 
'30/06/2022';

Requête 24
Donner le nombre de type de produit qu'il y a pour chacune des catégorie
Cela permet de savoir quels catégorie possède le plus de références de produits.

SELECT COUNT(idCategorie) as 'nbtotal produit', nomCatégorie
FROM Produit P
INNER JOIN Catégorie C ON P.idCategorie=C.idCatégorie
Group by nomCatégorie;

Requête 25
Donner la liste nominative des adhérents ayant commandés des "carelage"
Cela permet de savoir qui a commandé du carelage pour des offres promotionnelle de pose.

SELECT nomAdherent,prenomAdherent
FROM Adherent A
INNER JOIN commande C ON A.idAdhérent=C.idAdherent
INNER JOIN quantitéCommande QC ON C.idCommande=QC.idCommande
INNER JOIN Produit P ON QC.idProduit=P.idProduit
WHERE typeProduit='carelage';

Requête 26
Donner le nombre de fois qu'un produit a été commandé dans l'ordre décroissant
Cela permet de connaître le produit le plus commandé du magasin.

SELECT idProduit,COUNT(idCommande)
FROM quantitéCommande QC 
GROUP BY idProduit
ORDER BY count(idCommande) DESC;

Requête 28
Donner les prix de chaque produit
Cela permet de vérifier si les prix affichés en rayons sont correctes.

SELECT prixProduit, typeProduit
FROM Produit 
GROUP BY typeProduit
ORDER BY prixProduit;

Requête 29
Donner le nombre total de produit contenu dans la base
Cela permet à titre indicatif de savoir combien de produits nous proposons à la vente au total.

SELECT COUNT(*) as 'nombre total de produit'
FROM Produit;