#include "DbDataParser.h"

std::vector<std::shared_ptr<SensorRecord>> DbDataParser::processData(std::shared_ptr<QSqlQueryModel> model)
{
    std::vector<std::shared_ptr<SensorRecord>> data_rows;

    for (int i = 0; i < model->rowCount(); ++i)
    {
        // читаем общие данные

        int sensor_id = model->record(i).value("id").toInt();

        auto tag_db = model->record(i).value("tag"); // читаем tag
        if(tag_db.isNull())
        {
            continue;    // переходим к следующей записи, если null
        }
        QString tag_str = tag_db.toString();

        auto record_time_db = model->record(i).value("timsta"); // читаем timsta
        if(record_time_db.isNull())
        {
            continue;    // переходим к следующей записи, если null
        }
        QDateTime record_time = record_time_db.toDateTime();

        auto description_db = model->record(i).value("description"); // читаем description
        QString description_str;
        if(!description_db.isNull())
        {
            description_str = description_db.toString();
        }

        auto type_tag_db = model->record(i).value("type_tag"); // читаем type_tag
        QString type_tag_str;
        if(!type_tag_db.isNull())
        {
            type_tag_str = type_tag_db.toString();
        }

        //проверяем значение параметра
        auto value = model->record(i).value("value");
        if(!value.isNull())
        {
            if(value.type() == QVariant::Type::Bool)
            {
                data_rows.emplace_back(std::make_shared<SensorRecordBool>(sensor_id, tag_str, record_time,
                value.toBool(), description_str, type_tag_str));
            }
            else
            if(value.type() == QVariant::Type::Double)
            {
                data_rows.emplace_back(std::make_shared<SensorRecordDouble>(sensor_id, tag_str, record_time,
                value.toDouble(), description_str, type_tag_str));
            }
            continue;
        }
    }
    return data_rows;
}






