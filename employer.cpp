#include "employer.h"

// --- Constructeur paramétré ---
employer::employer(int id, QString nom, QString prenom, QString cin_,
                   QString telephone, QString poste, QString statut,
                   QString photo_profil, QString email, QString mot_de_passe)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->cin_ = cin_;
    this->telephone = telephone;
    this->poste = poste;
    this->statut = statut;
    this->photo_profil = photo_profil;
    this->email = email;
    this->mot_de_passe = mot_de_passe;
}

// --- Ajouter un employé dans la table EMPLOYER ---
bool employer::ajouter()
{
    QSqlQuery query;

    // Préparer la requête d'insertion
    query.prepare("INSERT INTO EMPLOYER (ID, NOM, PRENOM, CIN, TELEPHONE, POSTE, STATUT, PHOTO_PROFIL, EMAIL, MOT_DE_PASSE) "
                  "VALUES (:id, :nom, :prenom, :cin, :telephone, :poste, :statut, :photo_profil, :email, :mot_de_passe)");
    // Lier les valeurs
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":cin", cin_);
    query.bindValue(":telephone", telephone);
    query.bindValue(":poste", poste);
    query.bindValue(":statut", statut);
    query.bindValue(":photo_profil", photo_profil);
    query.bindValue(":email", email);
    query.bindValue(":mot_de_passe", mot_de_passe);

    // Exécuter la requête
    return query.exec();
}

// --- Afficher la liste des employés ---
QSqlQueryModel* employer::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYER");
    return model;
}

// --- Supprimer un employé via son ID ---
bool employer::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYER WHERE ID = :id");
    query.bindValue(":id", id);

    return query.exec();
}
