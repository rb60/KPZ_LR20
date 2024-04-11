#ifndef CREAMERYDIALOG_H
#define CREAMERYDIALOG_H

#include <QDialog>
#include "creamery.h"

namespace Ui {
class CreameryDialog;
}

class CreameryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreameryDialog(QWidget *parent = nullptr);
    ~CreameryDialog();
    Creamery *getCreamery() const;
    void setCreamery(Creamery *newCreamery);
    void showEvent(QShowEvent* event) override;
private slots:
    void setChanges();

private:
    Creamery* creamery = nullptr;
    Ui::CreameryDialog *ui;
};

#endif // CREAMERYDIALOG_H
