#ifndef RECHERCHE_H
#define RECHERCHE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class recherche
{
    int id_r;
    QString titre,duree,date_debut,resultat,statut,etat_event,event;
public:
    recherche();
    recherche(int id_r, QString titre, QString duree, QString date_debut, QString resultat, QString statut, QString etat_event, QString event);

    //Getters
    int getId(){return id_r;}
    QString getTitre(){return titre;}
    QString getDuree(){return duree;}
    QString getDateDebut(){return date_debut;}
    QString getResultat(){return resultat;}
    QString getStatut(){return statut;}
    QString getEtatEvent(){return etat_event;}
    QString getEvent(){return event;}

    //Setters
    void setId(int id_r){this->id_r=id_r;}
    void setTitre(QString titre){this->titre=titre;}
    void setDuree(QString duree){this->duree=duree;}
    void setDateDebut(QString date_debut){this->date_debut=date_debut;}
    void setResultat(QString resultat){this->resultat=resultat;}
    void setStatut(QString statut){this->statut=statut;}
    void setEtatEvent(QString etat_event){this->etat_event=etat_event;}
    void setEvent(QString event){this->event=event;}

    //Les fonctions
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel* chercherRecherche(QString chaine);
    // QSqlQueryModel*  chercherRecherche(QString id_r);
//QSqlQueryModel* chercherRecherche(QString depart);
//QSqlQueryModel * afficherTriCroissant();
    QSqlQueryModel * triRecherche(QString test);

    QSqlQueryModel* afficherTODO();
    QSqlQueryModel* afficherINPROGRESS();
    QSqlQueryModel* afficherDONE();
    bool modifierEtat(int id_r, const QString &etat);


};

#endif // RECHERCHE_H
