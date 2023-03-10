#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QWidget>

namespace Ui {
class employes;
}

class employes : public QWidget
{
    Q_OBJECT

public:
    explicit employes(QWidget *parent = nullptr);
    ~employes();

private:
    Ui::employes *ui;
};

#endif // EMPLOYES_H
