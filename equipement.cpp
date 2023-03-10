#include "equipement.h"


Equipement::Equipement()
{
   id=0; nombre_occ=0; Qr_code=0;prix_achat=0 ; nom=" "; etat=" ";
}


Equipement::Equipement(int id,int nombre_occ,int Qr_code,int prix_achat,QString nom,QString etat)
{this->id=id;this->nombre_occ=nombre_occ;this->nom = nom;this->etat = etat; this->Qr_code=Qr_code;this->prix_achat=prix_achat;}
int Equipement :: getid(){return id;}
int Equipement :: getnombre_occ(){return nombre_occ;}
int Equipement :: getQr_code(){return Qr_code;}
int Equipement :: getprix_achat(){return prix_achat;}
QString Equipement :: getnom(){return nom;}
QString Equipement :: getetat(){return etat;}
void Equipement :: setid(int id){this->id=id;}
void Equipement :: setnombre_occ(int nombre_occ){this->nombre_occ=nombre_occ;}
void Equipement :: setQr_code(int Qr_code){this->Qr_code=Qr_code;}
void Equipement :: setprix_achat(int prix_achat){this->prix_achat=prix_achat;}
void Equipement :: setnom(QString nom){this->nom=nom;}
void Equipement :: setetat(QString etat){this->etat=etat;}
