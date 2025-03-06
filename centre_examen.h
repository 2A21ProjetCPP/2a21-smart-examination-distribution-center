#ifndef CENTRE_EXAMEN_H
#define CENTRE_EXAMEN_H

#include <QString>

class CentreExamen {
private:
    int id;
    QString nom;
    QString adresse;
    int capacite;
    QString statut;
    QString ville;
    int nbEtudiants;
    int numRespLogistique;

public:
    // Constructeurs
    CentreExamen();
    CentreExamen(int id, QString nom, QString adresse, int capacite, QString statut,
                 QString ville, int nbEtudiants, int numRespLogistique);

    // Getters
    int getId() const;
    QString getNom() const;
    QString getAdresse() const;
    int getCapacite() const;
    QString getStatut() const;
    QString getVille() const;
    int getNbEtudiants() const;
    int getNumRespLogistique() const;

    // Setters
    void setId(int id);
    void setNom(const QString &nom);
    void setAdresse(const QString &adresse);
    void setCapacite(int capacite);
    void setStatut(const QString &statut);
    void setVille(const QString &ville);
    void setNbEtudiants(int nbEtudiants);
    void setNumRespLogistique(int numRespLogistique);

    // Méthodes
    void afficher() const;
};

#endif // CENTRE_EXAMEN_H
