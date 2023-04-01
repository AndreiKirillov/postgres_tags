#include "DataSaver.h"

DataSaver::DataSaver()
{

}

void DataSaver::saveToXml(std::vector<std::shared_ptr<SensorRecord> > data_rows)
{
    QDomDocument document("VestaInpData");
    QDomElement root_elem = document.createElement("VestaInpData");
    document.appendChild(root_elem);

    QDomElement general_elem = document.createElement("General");
    root_elem.appendChild(general_elem);

    for(auto& record : data_rows)
    {
        auto xml_record = record->convertToXml(document);
        general_elem.appendChild(xml_record);
    }


    QString timestamp = QDateTime::currentDateTime().toString("yyyyMMdd_HH_mm_ss");
    QFile file (QString("IN_") + timestamp + QString(".xml"));
    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << document.toString();
        file.close();
    }
}
