#include "DbReader.h"

QSqlDatabase DbReader::_db = QSqlDatabase();

DbReader::DbReader()
{
}

// Подключение к базе
bool DbReader::connectToDb()
{
    _db = QSqlDatabase::addDatabase("QPSQL");
    _db.setHostName("127.0.0.1");
    _db.setDatabaseName("tags_test");
    _db.setUserName("postgres");
    _db.setPassword("postgres");

    return _db.open();
}

// выборка всех данных из таблицы
std::shared_ptr<QSqlQueryModel> DbReader::readFromTable(const QString& table_name)
{
    auto model = std::make_shared<QSqlQueryModel>();
    QString query = "SELECT * FROM " + table_name;
    model->setQuery(query);

    return model;
}
