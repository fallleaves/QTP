#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <QString>

namespace QTP
{
namespace util
{

class DataGenerator
{
public:
    DataGenerator() = default;
    ~DataGenerator() = default;

    DataGenerator(const DataGenerator&) = delete;
    DataGenerator(DataGenerator&&) = delete;
    DataGenerator& operator=(const DataGenerator&) = delete;
    DataGenerator& operator=(DataGenerator&&) = delete;

    static constexpr uint32_t LINE_COUNT = 1000;
    static constexpr uint32_t NUMBER_OF_ROPE = 4;

    void generateRandom(const QString&, const QString&);

private:
    void writeLine(const QString&);
};

} // namespace util
} // namespace QTP


#endif // DATAGENERATOR_H
