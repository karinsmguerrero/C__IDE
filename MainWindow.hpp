//
// Created by Roger Valderrama on 3/29/18.
//

#ifndef C_IDE_MAINWINDOW_HPP
#define C_IDE_MAINWINDOW_HPP


#include <QtWidgets>
#include <QDebug>
#include <QLocalSocket>
#include "Server/LocalServer.h"
#include "Server/loguru.hpp"
#include "CodeEditor.hpp"
#include "Highlighter.hpp"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow();

    ~MainWindow() override;

private:
    CodeEditor *codeEditor;

    QWidget *centralWidget;

    QVBoxLayout *vLayout;

    QLabel *stdOut;

    QTextBrowser *applicationLog;

    QTableView *ramview;

    QHBoxLayout *titlehLayout;

    QHBoxLayout *apploghLayout;

    QPushButton *runBtn;

    QPushButton *clearBtn;

    Highlighter *highlighter;

    void updateAppLog();

    //Botón para ejecutar por pasos
    QPushButton *stepBtn;
    QPushButton *stopBtn;


    //SERVER STUFF

    QLocalSocket *socket;
    LocalServer *server;
    void client_send(const QString &msg);
    void client_read();
    /*void server_send(const QString &msg);
    void server_read();*/
    int currentLine;
    void startServer();


private slots:

    void runBtnHandler();

    void clearBtnHandler();

    void stopBtnHandler();
    void stepBtnHandler();

};


#endif //C_IDE_MAINWINDOW_HPP