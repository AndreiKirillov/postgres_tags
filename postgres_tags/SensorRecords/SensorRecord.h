#ifndef SENSORRECORD_H
#define SENSORRECORD_H

#include <iostream>
#include <QString>
#include <QDateTime>
#include <QtXml>

class SensorRecord
{
protected:
    int _sensor_id;
    QString _tag;
    QDateTime _record_time;
    QString _description;
    QString _type_tag;
public:
    SensorRecord();
    SensorRecord(int sensor_id, QString tag, QDateTime time, QString description = "", QString type_tag = "");

    virtual void print() const;
    virtual QDomElement convertToXml(QDomDocument& xml_root_doc);
};

#endif // SENSORRECORD_H
