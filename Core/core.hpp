#ifndef CORE_H
#define CORE_H

#include <Modules/inputmanager.hpp>
#include <Tools/datagenerator.hpp>

namespace QTP
{
namespace core
{

class Core
{
public:
    Core() = default;
    ~Core() = default;

    Core(const Core&) = delete;
    Core(Core&&) = delete;
    Core& operator=(const Core&) = delete;
    Core& operator=(Core&&) = delete;

    util::DataGenerator& getDataGenerator()
    {
        return dataGen;
    }

    input::InputManager& getInputManager()
    {
        return inputMgr;
    }

private:
    input::InputManager inputMgr;
    util::DataGenerator dataGen;
};

} // namespace core
} // namespce QTP


#endif // CORE_H
