#include <iostream>
#include <QtWidgets>
#include "GUI/MainWindow.hpp"
#define LOGURU_IMPLEMENTATION 1
#include "Server/loguru.hpp"
#include "GUI/CodeEditor.hpp"


int main(int argc, char *argv[]) {
    loguru::init(argc, argv);
    loguru::add_file("C_IDE_log.log", loguru::Truncate, loguru::Verbosity_INFO);
    LOG_F(INFO, "C! IDE started");
    QApplication a(argc, argv);
    MainWindow window;
    window.show();
    return a.exec();

   /* JSONparser *parser;
    QJsonDocument receivedData = parser->writeMallocRequest(100);
    QString jsonString = receivedData.toJson(QJsonDocument::Compact);
    std::cout << jsonString.toStdString() << std::endl;*/
}