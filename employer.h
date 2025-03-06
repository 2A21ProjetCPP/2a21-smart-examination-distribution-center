#ifndef EMPLOYER_H
#define EMPLOYER_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class employer
{
private:
    int id;
    QString nom;
    QString prenom;
    QString cin_;
    QString telephone;
    QString poste;
    QString statut;
    QString photo_profil;
    QString email;
    QString mot_de_passe;

public:
    // --- Constructeurs ---
    employer() {}
    employer(int, QString, QString, QString, QString, QString, QString, QString, QString, QString);

    // --- Getters ---
    int     getId()           const { return id; }
    QString getNom()          const { return nom; }
    QString getPrenom()       const { return prenom; }
    QString getCin()          const { return cin_; }
    QString getTelephone()    const { return telephone; }
    QString getPoste()        const { return poste; }
    QString getStatut()       const { return statut; }
    QString getPhotoProfil()  const { return photo_profil; }
    QString getEmail()        const { return email; }
    QString getMotDePasse()   const { return mot_de_passe; }

    // --- Setters ---
    void setId(int val)               { id = val; }
    void setNom(QString val)          { nom = val; }
    void setPrenom(QString val)       { prenom = val; }
    void setCin(QString val)          { cin_ = val; }
    void setTelephone(QString val)    { telephone = val; }
    void setPoste(QString val)        { poste = val; }
    void setStatut(QString val)       { statut = val; }
    void setPhotoProfil(QString val)  { photo_profil = val; }
    void setEmail(QString val)        { email = val; }
    void setMotDePasse(QString val)   { mot_de_passe = val; }

    // --- Méthodes CRUD ---
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
};

#endif // EMPLOYER_H
