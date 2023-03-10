#ifndef MATERIEL_H
#define MATERIEL_H

#include <QWidget>

namespace Ui {
class materiel;
}

class materiel : public QWidget
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

private:
    Ui::materiel *ui;
};

#endif // MATERIEL_H
