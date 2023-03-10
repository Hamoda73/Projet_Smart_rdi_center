#ifndef RECHERCHE2_H
#define RECHERCHE2_H

#include <QDialog>

namespace Ui {
class recherche2;
}

class recherche2 : public QDialog
{
    Q_OBJECT

public:
    explicit recherche2(QWidget *parent = nullptr);
    ~recherche2();

private:
    Ui::recherche2 *ui;
};

#endif // RECHERCHE2_H
