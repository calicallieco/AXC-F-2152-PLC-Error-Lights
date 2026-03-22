#include "All_Led_BlinkProgram.hpp"
#include "Arp/System/Commons/Logging.h"
#if ARP_ABI_VERSION_MAJOR < 2
#include "Arp/System/Core/ByteConverter.hpp"
#else
#include "Arp/Base/Core/ByteConverter.hpp"
#endif

namespace All_Led_Blink
{
 
void All_Led_BlinkProgram::Execute()
{
    //implement program 
    auto now = std::chrono::steady_clock::now();
    static auto lastToggle = now;
    static bool ledState = false;

    if (now - lastToggle >= std::chrono::seconds(1)) {
        ledState = !ledState;
        lastToggle = now;
    }

    red_led = ledState;
    orange_led = ledState;
    green_led = ledState;
    blue_led = ledState;
    white_led = ledState;

}

} // end of namespace All_Led_Blink
