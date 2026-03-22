#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Esm/ProgramProviderBase.hpp"

namespace All_Led_Blink
{

using namespace Arp;
using namespace Arp::Plc::Commons::Esm;

//forwards
class All_Led_BlinkComponent;

class All_Led_BlinkComponentProgramProvider : public ProgramProviderBase
{

public:   // construction/destruction
    All_Led_BlinkComponentProgramProvider(All_Led_BlinkComponent& all_Led_BlinkComponentArg);
#if ARP_ABI_VERSION_MAJOR < 2
    virtual ~All_Led_BlinkComponentProgramProvider() = default;
#endif

public:   // IProgramProvider operations
    IProgram::Ptr CreateProgramInternal(const String& programName, const String& programType) override;

#if ARP_ABI_VERSION_MAJOR < 2
private:   // deleted methods
    All_Led_BlinkComponentProgramProvider(const All_Led_BlinkComponentProgramProvider& arg) = delete;
    All_Led_BlinkComponentProgramProvider& operator=(const All_Led_BlinkComponentProgramProvider& arg) = delete;
#endif

private: // fields
    All_Led_BlinkComponent& all_Led_BlinkComponent;
};

///////////////////////////////////////////////////////////////////////////////
// inline methods of class All_Led_BlinkComponentProgramProvider

#if ARP_ABI_VERSION_MAJOR < 2
inline All_Led_BlinkComponentProgramProvider::All_Led_BlinkComponentProgramProvider(All_Led_BlinkComponent& all_Led_BlinkComponentArg)
    : all_Led_BlinkComponent(all_Led_BlinkComponentArg)
{
}
#endif
} // end of namespace All_Led_Blink
