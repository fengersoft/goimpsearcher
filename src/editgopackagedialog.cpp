#include "editgopackagedialog.h"
#include "ui_editgopackagedialog.h"

EditGoPackageDialog::EditGoPackageDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::EditGoPackageDialog)
{
    ui->setupUi(this);
}

EditGoPackageDialog::~EditGoPackageDialog()
{
    delete ui;
}

QString EditGoPackageDialog::name()
{
    return ui->edtName->text();

}

QString EditGoPackageDialog::path()
{
    return ui->edtPath->text();
}

QString EditGoPackageDialog::url()
{
    return ui->edtUrl->text();
}

QString EditGoPackageDialog::remark()
{
    return ui->edtRemark->text();
}

void EditGoPackageDialog::on_btnCancel_clicked()
{
    reject();
}

void EditGoPackageDialog::on_btnOk_clicked()
{
    accept();
}
