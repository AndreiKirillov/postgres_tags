#ifndef DBDATAPARSER_H
#define DBDATAPARSER_H

#include "DbReader.h"
#include "SensorRecords/SensorRecord.h"
#include "SensorRecords/SensorRecordDouble.h"
#include "SensorRecords/SensorRecordBool.h"

#include <QtXml>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <vector>

class DbDataParser
{
private:

public:
    static std::vector<std::shared_ptr<SensorRecord>> processData(std::shared_ptr<QSqlQueryModel> model);
};

#endif // DBDATAPARSER_H
