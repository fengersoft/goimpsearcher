#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_model = new QStandardItemModel(this);
    QStringList labels;
    labels << "包名称" << "导入名称" << "网址" << "备注";
    m_model->setHorizontalHeaderLabels(labels);
    ui->lvData->setModel(m_model);

    showData("select * from data order by id");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showData(const QString& sql)
{
    m_model->removeRows(0, m_model->rowCount());
    QSqlQuery qry;
    sqliteDao()->sqliteWrapper()->select(sql, qry);
    QStandardItem* item;
    while (qry.next())
    {
        QList<QStandardItem*> items;
        QString fldNames[] = {"name", "path", "url", "remark", "id"};
        for (int i = 0; i < 5; i++)
        {
            item = new QStandardItem();
            item->setText(qry.value(fldNames[i]).toString());
            items << item;
        }



        ui->lvData->setColumnWidth(1, 300);
        ui->lvData->setColumnWidth(2, 300);
        m_model->appendRow(items);

    }
    ui->lvData->setColumnHidden(4, true);

}


void MainWindow::on_btnAdd_clicked()
{
    EditGoPackageDialog* dlg = new EditGoPackageDialog();
    dlg->setWindowTitle("新增");
    int ret = dlg->exec();
    if (ret == QDialog::Accepted)
    {
        QString sql = QString("insert into data(name,path,url,remark) values ('%1','%2','%3','%4')")
                      .arg(dlg->name()).arg(dlg->path()).arg(dlg->url()).arg(dlg->remark());
        sqliteDao()->sqliteWrapper()->execute(sql);
        emit ui->btnSearch->click();

    }
    delete dlg;
}

void MainWindow::on_btnSearch_clicked()
{
    QString sql = "select * from data where path like '%" + ui->edtSearch->text() + "%'";
    showData(sql);

}

void MainWindow::on_lvData_doubleClicked(const QModelIndex& index)
{
    if (!index.isValid())
    {
        return;
    }
    QStandardItem* item = m_model->item(index.row(), 1);
    qApp->clipboard()->setText("\"" + item->text() + "\"");
}

void MainWindow::on_btnCopy_clicked()
{
    emit ui->lvData->doubleClicked(ui->lvData->currentIndex());
}

void MainWindow::on_edtSearch_returnPressed()
{
    emit ui->btnSearch->click();
}
