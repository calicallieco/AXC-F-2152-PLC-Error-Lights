#include "All_Led_BlinkComponent.hpp"
#include "Arp/Plc/Commons/Esm/ProgramComponentBase.hpp"
#include "All_Led_BlinkLibrary.hpp"

namespace All_Led_Blink
{
#if ARP_ABI_VERSION_MAJOR < 2
All_Led_BlinkComponent::All_Led_BlinkComponent(IApplication& application, const String& name)
: ComponentBase(application, ::All_Led_Blink::All_Led_BlinkLibrary::GetInstance(), name, ComponentCategory::Custom)
    , programProvider(*this)
    , ProgramComponentBase(::All_Led_Blink::All_Led_BlinkLibrary::GetInstance().GetNamespace(), programProvider)
#else
All_Led_BlinkComponent::All_Led_BlinkComponent(ILibrary& library, const String& name)
    : ComponentBase(library, name, ComponentCategory::Custom, GetDefaultStartOrder())
    , programProvider(*this)
    , ProgramComponentBase(::All_Led_Blink::All_Led_BlinkLibrary::GetInstance().GetNamespace(), programProvider)
#endif
{
}

void All_Led_BlinkComponent::Initialize()
{
    // never remove next line
    ProgramComponentBase::Initialize();

    // subscribe events from the event system (Nm) here
}

void All_Led_BlinkComponent::LoadConfig()
{
    // load project config here
}

void All_Led_BlinkComponent::SetupConfig()
{
    // never remove next line
    ProgramComponentBase::SetupConfig();

    // setup project config here
}

void All_Led_BlinkComponent::ResetConfig()
{
    // never remove next line
    ProgramComponentBase::ResetConfig();

    // implement this inverse to SetupConfig() and LoadConfig()
}

void All_Led_BlinkComponent::PowerDown()
{
	// implement this only if data shall be retained even on power down event
	// will work only for PLCnext controllers with an "Integrated uninterruptible power supply (UPS)"
	// Available with 2021.6 FW
}

} // end of namespace All_Led_Blink
