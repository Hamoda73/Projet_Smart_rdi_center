#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QString>

class Equipement
{
public:

    Equipement();
    Equipement(int,int,int,int,QString,QString);
    int getid();
    int getnombre_occ();
    int getQr_code();
    int getprix_achat();

    QString getnom();
    QString getetat();

    void setid(int);
    void setnombre_occ(int);
    void setQr_code(int);
    void setprix_achat(int);
    void setnom(QString);
    void setetat(QString);
private:
    int id,nombre_occ,Qr_code,prix_achat;
    QString nom,etat;
};

#endif // EQUIPEMENT_H
