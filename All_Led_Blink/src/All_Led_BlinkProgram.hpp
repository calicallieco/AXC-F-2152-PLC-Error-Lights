#pragma once
#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Esm/ProgramBase.hpp"
#include "Arp/System/Commons/Logging.h"
#include "All_Led_BlinkComponent.hpp"

namespace All_Led_Blink
{

using namespace Arp;
using namespace Arp::System::Commons::Diagnostics::Logging;
using namespace Arp::Plc::Commons::Esm;

//#program
//#component(All_Led_Blink::All_Led_BlinkComponent)
class All_Led_BlinkProgram : public ProgramBase, private Loggable<All_Led_BlinkProgram>
{
public: // typedefs

public: // construction/destruction
    All_Led_BlinkProgram(All_Led_Blink::All_Led_BlinkComponent& all_Led_BlinkComponentArg, const String& name);
#if ARP_ABI_VERSION_MAJOR < 2
    All_Led_BlinkProgram(const All_Led_BlinkProgram& arg) = delete;
    virtual ~All_Led_BlinkProgram() = default;
#endif

public: // operators
#if ARP_ABI_VERSION_MAJOR < 2
    All_Led_BlinkProgram&  operator=(const All_Led_BlinkProgram& arg) = delete;
#endif

public: // properties

public: // operations
    void    Execute() override;

public: /* Ports
           =====
           Ports are defined in the following way:
           //#port
           //#attributes(Input|Retain)
           //#name(NameOfPort)
           boolean portField;

           The attributes comment define the port attributes and is optional.
           The name comment defines the name of the port and is optional. Default is the name of the field.
        */
        //#port
        //#attributes(Output)
        //#name(red)
        bool red_led = false;

        //#port
        //#attributes(Output)
        //#name(orange)
        bool orange_led = false;

        //#port
        //#attributes(Output)
        //#name(green)
        bool green_led = false;

        //#port
        //#attributes(Output)
        //#name(blue)
        bool blue_led = false;

        //#port
        //#attributes(Output)
        //#name(white)
        bool white_led = false;

private: // fields
    All_Led_Blink::All_Led_BlinkComponent& all_Led_BlinkComponent;

};

///////////////////////////////////////////////////////////////////////////////
// inline methods of class ProgramBase
inline All_Led_BlinkProgram::All_Led_BlinkProgram(All_Led_Blink::All_Led_BlinkComponent& all_Led_BlinkComponentArg, const String& name)
: ProgramBase(name)
, all_Led_BlinkComponent(all_Led_BlinkComponentArg)
{
}

} // end of namespace All_Led_Blink
