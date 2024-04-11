#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "listvisitor.h"
#include "farmdialog.h"
#include "milkdialog.h"
#include "creamerydialog.h"
#include "chessedialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void addFarm();
    void addMilk();
    void addCreamery();
    void addCheese();

private:
    QList<VisitorElement*> farms;
    QList<VisitorElement*> milk;
    QList<VisitorElement*> usedMilk;
    QList<VisitorElement*> creamerys;
    QList<VisitorElement*> cheese;
    FarmDialog* farmDialog;
    MilkDialog* milkDialog;
    CreameryDialog* creameryDialog;
    ChesseDialog* cheeseDialog;
    ListVisitor visitor;
    Ui::MainWindow *ui;
    void deleteList(QList<VisitorElement*> list);
};
#endif // MAINWINDOW_H
