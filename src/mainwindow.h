#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editgopackagedialog.h"
#include "src/api/sql/sqlitedao.h"
#include <QClipboard>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void showData(const QString& sql);

private slots:
    void on_btnAdd_clicked();

    void on_btnSearch_clicked();

    void on_lvData_doubleClicked(const QModelIndex& index);

    void on_btnCopy_clicked();

    void on_edtSearch_returnPressed();

private:
    Ui::MainWindow* ui;
    QStandardItemModel* m_model;
    QString m_sql;
};
#endif // MAINWINDOW_H
