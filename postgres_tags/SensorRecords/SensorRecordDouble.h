#ifndef SENSORRECORDDOUBLE_H
#define SENSORRECORDDOUBLE_H

#include "SensorRecord.h"

class SensorRecordDouble : public SensorRecord
{
private:
    double _double_value;
public:
    SensorRecordDouble();
    SensorRecordDouble(int sensor_id, QString tag, QDateTime time, double value,
                     QString description = "", QString type_tag = "");

    void print() const override;
    QDomElement convertToXml(QDomDocument& xml_root_doc) override;
};

#endif // SENSORRECORDDOUBLE_H
