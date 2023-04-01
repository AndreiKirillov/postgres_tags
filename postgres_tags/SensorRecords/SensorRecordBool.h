#ifndef SENSORRECORDBOOL_H
#define SENSORRECORDBOOL_H

#include "SensorRecord.h"

class SensorRecordBool : public SensorRecord
{
private:
    bool _bool_value;
public:
    SensorRecordBool();
    SensorRecordBool(int sensor_id, QString tag, QDateTime time, bool value,
                     QString description = "", QString type_tag = "");

    void print() const override;
    QDomElement convertToXml(QDomDocument& xml_root_doc) override;
};

#endif // SENSORRECORDBOOL_H
