#ifndef EDITGOPACKAGEDIALOG_H
#define EDITGOPACKAGEDIALOG_H

#include <QDialog>

namespace Ui
{
class EditGoPackageDialog;
}

class EditGoPackageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditGoPackageDialog(QWidget* parent = nullptr);
    ~EditGoPackageDialog();
    QString name();
    QString path();
    QString url();
    QString remark();

private slots:
    void on_btnCancel_clicked();

    void on_btnOk_clicked();

private:
    Ui::EditGoPackageDialog* ui;
};

#endif // EDITGOPACKAGEDIALOG_H
