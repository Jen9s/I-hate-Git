#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "TemplSet.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    std::vector<int> FirstInt;
    std::vector<int> SecondInt;
    std::vector<std::string> FirstString;
    std::vector<std::string> SecondString;
    ~MainWindow();

private slots:
    void on_add_button_clicked();
    void on_ClearSet1_clicked();

    void on_ClearSet2_clicked();

    void on_ClearResult_clicked();

    void on_Union_clicked();

    void on_Intersect_clicked();

    void on_SimSub_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
