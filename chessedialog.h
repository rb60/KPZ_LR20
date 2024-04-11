#ifndef CHESSEDIALOG_H
#define CHESSEDIALOG_H

#include <QDialog>
#include "cheese.h"
#include <QList>

namespace Ui {
class ChesseDialog;
}

class ChesseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChesseDialog(QList<VisitorElement *>* creamerys, QList<VisitorElement *>* milk, QWidget *parent = nullptr);
    ~ChesseDialog();

    Cheese *getCheese() const;
    void showEvent(QShowEvent* event) override;

private slots:
    void makeCheese();

private:
    Cheese* cheese = nullptr;
    QList<VisitorElement*>* creamerys;
    QList<VisitorElement*>* milk;
    Ui::ChesseDialog *ui;
};

#endif // CHESSEDIALOG_H
