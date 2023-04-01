#include <iostream>

#include <QString>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>

#include "DbReader.h"
#include "DbDataParser.h"
#include "DataSaver.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if(DbReader::connectToDb())
    {
        cout << "Подключение к базе удалось!" << endl;

        // читаем таблицы
        auto bool_tags = DbReader::readFromTable("bool_tags");
        auto double_tags = DbReader::readFromTable("double_tags");

        // обрабатываем прочитанные данные
        auto parsed_data = DbDataParser::processData(std::move(bool_tags));
        auto double_data = DbDataParser::processData(std::move(double_tags));
        parsed_data.insert(            // перемещаем данные из второго вектора в первый
                    parsed_data.end(),
                    std::make_move_iterator(double_data.begin()),
                    std::make_move_iterator(double_data.end())
        );

        // выводим в xml формат
        DataSaver::saveToXml(parsed_data);
        cout << "Data was saved" << endl;
    }
    else
    {
        cout << "Не удалось подключиться!" << endl;
    }
    return a.exec();
}
