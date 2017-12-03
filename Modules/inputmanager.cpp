#include "inputmanager.hpp"

using namespace QTP::input;

#include <Tools/datagenerator.hpp>

#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>

InputManager::InputManager()
{
    content.reserve(500000);
}

void InputManager::readFile(const QString &fileName, const QRegExp &delimiter)
{
    content.clear();
    QFile mFile{fileName};

    if (!mFile.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << "fatal error: can't open file: " << fileName;
        return;
    }

    QTextStream is{&mFile};
    QString input = is.readAll();
    QStringList inputList = input.split(delimiter);

    // erase last empty symbol
    inputList.pop_back();

    if (inputList.size() % (util::DataGenerator::NUMBER_OF_ROPE + 5))
    {
        qDebug() << "input data incomplete";
        qDebug() << "line count: " << inputList.size();
        return;
    }

    Data tmp;

    for (auto it = inputList.begin(); it != inputList.end();)
    {
        tmp.timestamp = (*++it).toDouble();
        tmp.length1 = (*++it).toDouble();
        tmp.length2 = (*++it).toDouble();
        tmp.length3 = (*++it).toDouble();
        tmp.length4 = (*++it).toDouble();
        tmp.pressure1 = (*++it).toDouble();
        tmp.pressure2 = (*++it).toDouble();
        tmp.cageDepth = (*++it).toDouble();

        content.emplace_back(tmp);

        ++it; // skipping index
    }
}
