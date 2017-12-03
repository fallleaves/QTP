#ifndef TIMER_H
#define TIMER_H

#include <cstdint>

namespace QTP
{
namespace util
{

class Timer
{
public:
    Timer() = default;
    ~Timer() = default;

    Timer(const Timer&) = delete;
    Timer(Timer&&) = delete;
    Timer& operator=(const Timer&) = delete;
    Timer& operator=(Timer&&) = delete;

    static constexpr uint64_t ONE_NANOSECOND = 1;
    static constexpr auto ONE_MICROSECOND = 1000 * ONE_NANOSECOND;
    static constexpr auto ONE_MILLISECOND = 1000 * ONE_MICROSECOND;
    static constexpr auto ONE_SECOND = 1000 * ONE_MILLISECOND;
};

} // namespace util
} // namespace QTP


#endif // TIMER_H
