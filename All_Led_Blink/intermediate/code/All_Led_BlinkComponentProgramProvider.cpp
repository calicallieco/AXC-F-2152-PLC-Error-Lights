#include "All_Led_BlinkComponentProgramProvider.hpp"
#include "All_Led_BlinkProgram.hpp"

namespace All_Led_Blink
{

#if ARP_ABI_VERSION_MAJOR < 2
#else
All_Led_BlinkComponentProgramProvider::All_Led_BlinkComponentProgramProvider(All_Led_BlinkComponent& all_Led_BlinkComponentArg)
    : all_Led_BlinkComponent(all_Led_BlinkComponentArg)
{
}

#endif
IProgram::Ptr All_Led_BlinkComponentProgramProvider::CreateProgramInternal(const String& programName, const String& programType)
{
    if (programType == "All_Led_BlinkProgram")
    { 
        return std::make_shared<::All_Led_Blink::All_Led_BlinkProgram>(this->all_Led_BlinkComponent, programName);
    }

    // else unknown program
    return nullptr;
}

} // end of namespace All_Led_Blink
