#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sstream>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("String");
    ui->comboBox->addItem("Int");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_button_clicked()
{
    if(ui->comboBox->currentText() == "String"){
       QString tmp;
       tmp = ui->ToSet1->text();
       ui->ToSet1->clear();
       if(!tmp.isEmpty()){
         FirstString.push_back(tmp.toStdString());
         std::string string_text;
         for(auto i : FirstString){
               string_text += "         " + i + "\n";
         }
         tmp = QString::fromStdString(string_text);
         ui->textEditSET1->setText(tmp);
       }
       tmp = ui->ToSet2->text();
       ui->ToSet2->clear();
       if(!tmp.isEmpty()){
         SecondString.push_back(tmp.toStdString());
         std::string string_text;
         for(auto i : SecondString){
               string_text += "         " + i + "\n";
         }
         tmp = QString::fromStdString(string_text);
         ui->textEditSET2->setText(tmp);
       }
    }
    else{
        QString tmp;
        tmp = ui->ToSet1->text();
        ui->ToSet1->clear();
        if(!tmp.isEmpty()){
          FirstInt.push_back(tmp.toUInt());
          std::string string_text;
          for(auto i : FirstInt){
              std::stringstream ss;
              ss << i;
              string_text += "         " + ss.str() + "\n";
          }
          tmp = QString::fromStdString(string_text);
          ui->textEditSET1->setText(tmp);
        }
        tmp = ui->ToSet2->text();
        ui->ToSet2->clear();
        if(!tmp.isEmpty()){
            SecondInt.push_back(tmp.toUInt());
            std::string string_text;
            for(auto i : SecondInt){
                std::stringstream ss;
                ss << i;
                string_text += "         " + ss.str() + "\n";
            }
            tmp = QString::fromStdString(string_text);
            ui->textEditSET2->setText(tmp);
        }
    }
}


void MainWindow::on_ClearSet1_clicked()
{
    if(ui->comboBox->currentText() == "String"){
        FirstString = {};
        ui->textEditSET1->setText("");
    }
    else{
        FirstInt = {};
        ui->textEditSET1->setText("");
    }
}

void MainWindow::on_ClearSet2_clicked()
{
    if(ui->comboBox->currentText() == "String"){
        SecondString = {};
        ui->textEditSET2->setText("");
    }
    else{
        SecondInt = {};
        ui->textEditSET2->setText("");
    }
}

void MainWindow::on_ClearResult_clicked()
{
    ui->textEditRESULT->setText("");
}


void MainWindow::on_Union_clicked()
{
   if(ui->comboBox->currentText() == "String"){
        if(!FirstString.empty() && !SecondString.empty()){
        Set<std::string> First (FirstString);
        Set<std::string> Second (SecondString);
        Set<std::string> output = First.add(Second);
        QString tmp;
        std::string string_text;
        for(auto i : output.T_set){
              string_text += "         " + i + "\n";
        }
        tmp = QString::fromStdString(string_text);
        ui->textEditRESULT->setText(tmp);
       }
       else{
           QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
       }
   }
   else{
       if(!FirstInt.empty() && !SecondInt.empty()){
       Set<int> First (FirstInt);
       Set<int> Second (SecondInt);
       Set<int> output = First.add(Second);
       QString tmp;
       std::string string_text;
       for(auto i : output.T_set){
           std::stringstream ss;
           ss << i;
             string_text += "         " + ss.str() + "\n";
       }
       tmp = QString::fromStdString(string_text);
       ui->textEditRESULT->setText(tmp);
       }
       else{
           QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
       }
       }
   }

void MainWindow::on_Intersect_clicked()
{
    if(ui->comboBox->currentText() == "String"){
         if(!FirstString.empty() && !SecondString.empty()){
         Set<std::string> First (FirstString);
         Set<std::string> Second (SecondString);
         Set<std::string> output = First.mult(Second);
         QString tmp;
         if(!output.T_set.empty()){
         std::string string_text;
         for(auto i : output.T_set){
               string_text += "         " + i + "\n";               
            }
            tmp = QString::fromStdString(string_text);
         }
         else{
             tmp = QString::fromStdString(" ");
         }

         ui->textEditRESULT->setText(tmp);
         }
         else{
             QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
         }
    }
    else{
        if(!FirstInt.empty() && !SecondInt.empty()){
        Set<int> First (FirstInt);
        Set<int> Second (SecondInt);
        Set<int> output = First.mult(Second);
        QString tmp;
        if(!output.T_set.empty()){
        std::string string_text;
        for(auto i : output.T_set){
            std::stringstream ss;
            ss << i;
              string_text += "         " + ss.str() + "\n";
        }
        tmp = QString::fromStdString(string_text);
        }
        else{
        tmp = QString::fromStdString(" ");
        }
        ui->textEditRESULT->setText(tmp);
        }
        else{
            QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
        }
    }
}

void MainWindow::on_SimSub_clicked()
{
    if(ui->comboBox->currentText() == "String"){
        if(!FirstString.empty() && !SecondString.empty()){
         Set<std::string> First (FirstString);
         Set<std::string> Second (SecondString);
         Set<std::string> output = First.sim_sub(Second);
         QString tmp;
         if(!output.T_set.empty()){
         std::string string_text;
         for(auto i : output.T_set){
               string_text += "         " + i + "\n";
         }
         tmp = QString::fromStdString(string_text);
         }
         else{
         tmp = QString::fromStdString(" ");
         }
         ui->textEditRESULT->setText(tmp);
        }
        else{
            QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
        }
    }
    else{
        if(!FirstInt.empty() && !SecondInt.empty()){
        Set<int> First (FirstInt);
        Set<int> Second (SecondInt);
        Set<int> output = First.sim_sub(Second);
        QString tmp;
        if(!output.T_set.empty()){
        std::string string_text;
        for(auto i : output.T_set){
            std::stringstream ss;
            ss << i;
              string_text += "         " + ss.str() + "\n";
        }
        tmp = QString::fromStdString(string_text);
        }else{
            tmp = QString::fromStdString(" ");
        }
        ui->textEditRESULT->setText(tmp);
        }
        else{
            QMessageBox::critical(this,"Error","Все множества должны быть не пустые !");
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(ui->comboBox->currentText() == "String"){
        FirstInt = {};
        SecondInt = {};
    }
    else{
        FirstString = {};
        SecondString = {};
    }
    ui->textEditSET1->setText("");
    ui->textEditSET2->setText("");
    ui->textEditRESULT->setText("");
}
