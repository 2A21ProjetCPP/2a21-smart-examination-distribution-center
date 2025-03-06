#include "centre_examen.h"
#include <iostream>

// Constructeurs
CentreExamen::CentreExamen()
    : id(0), capacite(0), nbEtudiants(0), numRespLogistique(0) {}

CentreExamen::CentreExamen(int id, QString nom, QString adresse, int capacite,
                           QString statut, QString ville, int nbEtudiants, int numRespLogistique)
    : id(id), nom(nom), adresse(adresse), capacite(capacite), statut(statut),
    ville(ville), nbEtudiants(nbEtudiants), numRespLogistique(numRespLogistique) {}

// Getters
int CentreExamen::getId() const { return id; }
QString CentreExamen::getNom() const { return nom; }
QString CentreExamen::getAdresse() const { return adresse; }
int CentreExamen::getCapacite() const { return capacite; }
QString CentreExamen::getStatut() const { return statut; }
QString CentreExamen::getVille() const { return ville; }
int CentreExamen::getNbEtudiants() const { return nbEtudiants; }
int CentreExamen::getNumRespLogistique() const { return numRespLogistique; }

// Setters
void CentreExamen::setId(int id) { this->id = id; }
void CentreExamen::setNom(const QString &nom) { this->nom = nom; }
void CentreExamen::setAdresse(const QString &adresse) { this->adresse = adresse; }
void CentreExamen::setCapacite(int capacite) { this->capacite = capacite; }
void CentreExamen::setStatut(const QString &statut) { this->statut = statut; }
void CentreExamen::setVille(const QString &ville) { this->ville = ville; }
void CentreExamen::setNbEtudiants(int nbEtudiants) { this->nbEtudiants = nbEtudiants; }
void CentreExamen::setNumRespLogistique(int numRespLogistique) { this->numRespLogistique = numRespLogistique; }

// Méthode pour afficher les informations du centre d'examen
void CentreExamen::afficher() const {
    std::cout << "Centre d'Examen: " << nom.toStdString() << "\n"
              << "ID: " << id << "\n"
              << "Adresse: " << adresse.toStdString() << "\n"
              << "Capacité: " << capacite << "\n"
              << "Statut: " << statut.toStdString() << "\n"
              << "Ville: " << ville.toStdString() << "\n"
              << "Nombre d'étudiants: " << nbEtudiants << "\n"
              << "Responsable Logistique: " << numRespLogistique << "\n";
}
