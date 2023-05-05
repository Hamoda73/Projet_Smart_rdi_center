
#ifndef CHERCHEUR_H
#define CHERCHEUR_H
#include <QCoreApplication>


#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QString>
#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QCompleter>
#include <QCoreApplication>
#include <QUrl>
#include <QtPrintSupport/QPrinter>
#include<QTextDocument>
#include <QPainter>
#include <QFileDialog>
#include<QPrintDialog>
#include <QSqlTableModel>
#include<QMessageBox>
#include <QDate>
#include <QSqlRecord>

#include <QVBoxLayout>
#include<QtCharts/QPieSeries>
#include<QChart>





#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

using namespace QXlsx;


class chercheur
{
private:
    int CIN_c;
    QString nom;
    QString prenom;
    int age;
    QString email;
    QDate currentDate;

public:
    chercheur();
    chercheur(int CIN_c, QString nom, QString prenom, int age, QString email, QDate currentDate);

    //Getters and Setters
    int getCIN_c(){return CIN_c;}
    void setCIN_c(int val){CIN_c = val;}
    QString getnom(){return nom;}
    void setnom(QString val){nom = val;}
    QString getprenom(){return prenom;}
    void setCprenom(QString val){prenom = val;}
    int getage(){return age;}
    void setage(int val){age = val;}
    QString getemail(){return email;}
    void setemail(QString val){email = val;}
    QDate getcurrentDate(){return currentDate;}
    void setcurrentDate(QDate val){currentDate = val;}

    //Fonctionalités de base
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int CIN_c);
    bool modifier();

    //Autres Fonctions


    QSqlQueryModel * afficherHistorique();
    QSqlQueryModel * afficherTriCroissant();
    QSqlQueryModel * afficherTriDecroissant();
    QSqlQueryModel * afficherTriNom();
    QSqlQueryModel* chercherChercheur(QString depart);
    void writeToLog(QStringList values);

};

#endif // CHERCHEUR_H
