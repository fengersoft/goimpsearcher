#ifndef EDITGOPACKAGEDIALOG_H
#define EDITGOPACKAGEDIALOG_H

#include <QDialog>

namespace Ui {
class EditGoPackageDialog;
}

class EditGoPackageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditGoPackageDialog(QWidget *parent = nullptr);
    ~EditGoPackageDialog();

private:
    Ui::EditGoPackageDialog *ui;
};

#endif // EDITGOPACKAGEDIALOG_H
