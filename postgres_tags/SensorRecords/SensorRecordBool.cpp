#include "SensorRecordBool.h"

SensorRecordBool::SensorRecordBool()
{

}

SensorRecordBool::SensorRecordBool(int sensor_id, QString tag, QDateTime time, bool value, QString description, QString type_tag):
    SensorRecord(sensor_id, tag, time, description,type_tag), _bool_value(value)
{

}


void SensorRecordBool::print() const
{
    SensorRecord::print();
    std::cout << "Bool value: " << (_bool_value ? "true":"false") << std::endl;
}

QDomElement SensorRecordBool::convertToXml(QDomDocument &xml_root_doc)
{
    // элемент записи в xml
    QDomElement parameter_elem = xml_root_doc.createElement("Parameter");

    // Задаём шифр
    QDomAttr code_attribute = xml_root_doc.createAttribute("Code");
    code_attribute.setValue(_tag);
    parameter_elem.setAttributeNode(code_attribute);

    // Задаём значение
    QDomAttr value_attribute = xml_root_doc.createAttribute("Value");
    value_attribute.setValue(_bool_value ? "1":"0");
    parameter_elem.setAttributeNode(value_attribute);

    return parameter_elem;
}
