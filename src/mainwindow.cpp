#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAdd_clicked()
{
    EditGoPackageDialog* dlg = new EditGoPackageDialog();
    dlg->setWindowTitle("新增");
    dlg->exec();
    delete dlg;
}
