#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <Tools/defines.hpp>

#include <QString>
#include <vector>
#include <cstdint>

namespace QTP
{
namespace input
{

class InputManager
{
public:
    InputManager();
    ~InputManager() = default;

    InputManager(const InputManager&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(const InputManager&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    struct Data
    {
        platform::Second timestamp{};

        platform::Length length1{};
        platform::Length length2{};
        platform::Length length3{};
        platform::Length length4{};

        platform::Length cageDepth{};

        platform::Pressure pressure1{};
        platform::Pressure pressure2{};
    };

    void readFile(const QString&, const QRegExp &);

    Data& getNextData()
    {
        return content[++currentPos];
    }

    void reset()
    {
        currentPos = -1;
    }

private:
    std::vector<Data> content;
    int32_t currentPos{-1};
};

} // namespace input
} // namespace QTP


#endif // INPUTMANAGER_H
