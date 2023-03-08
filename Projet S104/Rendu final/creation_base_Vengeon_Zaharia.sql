BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "ville" (
	"idVille"	INT,
	"nomVille"	VARCHAR(50),
	"codePostale"	INT NOT NULL,
	"idAdresse"	INT NOT NULL,
	PRIMARY KEY("idVille"),
	FOREIGN KEY("idAdresse") REFERENCES "adresse"("idAdresse")
);
CREATE TABLE IF NOT EXISTS "Produit" (
	"idProduit"	INT,
	"typeProduit"	VARCHAR(50),
	"prixProduit"	DECIMAL(15, 2),
	"idCategorie"	INTEGER,
	PRIMARY KEY("idProduit")
);
CREATE TABLE IF NOT EXISTS "Adherent" (
	"idAdhérent"	INT,
	"nomAdherent"	VARCHAR(50),
	"prenomAdherent"	VARCHAR(50),
	"adresseMail"	VARCHAR(50),
	"numTel"	VARCHAR(50) UNIQUE,
	"idAdresse"	INT NOT NULL,
	PRIMARY KEY("idAdhérent"),
	FOREIGN KEY("idAdresse") REFERENCES "adresse"("idAdresse")
);
CREATE TABLE IF NOT EXISTS "adresse" (
	"idAdresse"	INT,
	"numRue"	VARCHAR(50),
	"nomRue"	VARCHAR(50),
	"idLivraison"	INT,
	PRIMARY KEY("idAdresse"),
	FOREIGN KEY("idLivraison") REFERENCES "Livraison"("idLivraisons")
);
CREATE TABLE IF NOT EXISTS "Categorie" (
	"idCatégorie"	INT,
	"nomCatégorie"	VARCHAR(50),
	PRIMARY KEY("idCatégorie")
);
CREATE TABLE IF NOT EXISTS "quantiteCommande" (
	"idProduit"	INT,
	"idCommande"	INT,
	"quantité"	INTEGER NOT NULL,
	PRIMARY KEY("idProduit","idCommande"),
	FOREIGN KEY("idProduit") REFERENCES "Produit"("idProduit"),
	FOREIGN KEY("idCommande") REFERENCES "commande"("idCommande")
);
CREATE TABLE IF NOT EXISTS "Livraison" (
	"idLivraisons"	INT,
	"dateLivraison"	DATE,
	PRIMARY KEY("idLivraisons")
);
CREATE TABLE IF NOT EXISTS "commande" (
	"idCommande"	INT,
	"dateCommande"	DATE,
	"idAdherent"	INT NOT NULL,
	"idlivraison"	INTEGER,
	FOREIGN KEY("idAdherent") REFERENCES "Adherent"("idAdhérent"),
	PRIMARY KEY("idCommande","idlivraison")
);

COMMIT;
