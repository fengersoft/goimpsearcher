#include "editgopackagedialog.h"
#include "ui_editgopackagedialog.h"

EditGoPackageDialog::EditGoPackageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditGoPackageDialog)
{
    ui->setupUi(this);
}

EditGoPackageDialog::~EditGoPackageDialog()
{
    delete ui;
}
