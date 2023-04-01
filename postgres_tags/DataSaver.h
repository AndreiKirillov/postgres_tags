#ifndef DATASAVER_H
#define DATASAVER_H

#include "SensorRecords/SensorRecord.h"
#include "SensorRecords/SensorRecordDouble.h"
#include "SensorRecords/SensorRecordInt.h"
#include "SensorRecords/SensorRecordBool.h"

#include <QDateTime>

#include <vector>
#include <memory>

class DataSaver
{
public:
    DataSaver();

    static void saveToXml(std::vector<std::shared_ptr<SensorRecord>> data_rows);
};

#endif // DATASAVER_H
