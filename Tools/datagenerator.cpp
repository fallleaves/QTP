#include "datagenerator.hpp"
#include "timer.hpp"

#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <chrono>

using namespace QTP::util;
using namespace std::chrono;

void DataGenerator::generateRandom(const QString& fileName, const QString& delimiter)
{
    QFile mFile{fileName};

    if (!mFile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << "fatal error: can't open file: " << fileName;
        return;
    }

    auto time_now = duration_cast<nanoseconds>(high_resolution_clock::now().time_since_epoch()).count();
    QTextStream os{&mFile};
    const auto interval = 1 * Timer::ONE_MILLISECOND;
    double length[NUMBER_OF_ROPE] = {0.0};
    double step[NUMBER_OF_ROPE] = {0.1, 0.1, 0.1, 0.1001};

    for (uint32_t i = 0; i <= LINE_COUNT; ++i)
    {
        os << time_now << delimiter;
        time_now += interval;

        for (uint32_t j = 0; j < NUMBER_OF_ROPE; ++j)
        {
            os << length[j] << delimiter;
            length[j] += step[j];
        }

        os << '\n';
    }

    mFile.flush();
    mFile.close();
}
