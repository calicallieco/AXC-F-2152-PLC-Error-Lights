#include "All_Led_BlinkLibrary.hpp"
#if ARP_ABI_VERSION_MAJOR < 2
#include "Arp/System/Core/CommonTypeName.hxx"
#else
#include "Arp/Base/Core/CommonTypeName.hxx"
#include "All_Led_BlinkLibraryInfo.hpp"
#endif
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeSystem.h"
#include "All_Led_BlinkComponent.hpp"

namespace All_Led_Blink
{

#if ARP_ABI_VERSION_MAJOR < 2
All_Led_BlinkLibrary::All_Led_BlinkLibrary(AppDomain& appDomain)
    : MetaLibraryBase(appDomain, ARP_VERSION_CURRENT, typeDomain)
    , typeDomain(CommonTypeName<All_Led_BlinkLibrary>().GetNamespace())
#else
All_Led_BlinkLibrary::All_Led_BlinkLibrary()
    : MetaLibraryBase(All_Led_BlinkLibraryVersion, typeDomain)
    , typeDomain(CommonTypeName<All_Led_BlinkLibrary>().GetNamespace())
#endif
{
#if ARP_ABI_VERSION_MAJOR < 2
    this->componentFactory.AddFactoryMethod(CommonTypeName<::All_Led_Blink::All_Led_BlinkComponent>(), &::All_Led_Blink::All_Led_BlinkComponent::Create);
#else
 
    this->AddComponentType<::All_Led_Blink::All_Led_BlinkComponent>();
#endif
    this->InitializeTypeDomain();
}

#if ARP_ABI_VERSION_MAJOR < 2
void All_Led_BlinkLibrary::Main(AppDomain& appDomain)
{
    SingletonBase::CreateInstance(appDomain);
}
#else
All_Led_BlinkLibrary& All_Led_BlinkLibrary::GetInstance()
{
    static All_Led_BlinkLibrary instance;
    return instance;
}
#endif


#if ARP_ABI_VERSION_MAJOR < 2
extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain)
{
    All_Led_BlinkLibrary::Main(appDomain);
    return  All_Led_BlinkLibrary::GetInstance();
}
} // end of namespace All_Led_Blink
#else
} // end of namespace All_Led_Blink
extern "C" ARP_EXPORT Arp::Base::Acf::Commons::ILibrary& All_Led_Blink_MainEntry()
{
    return  All_Led_Blink::All_Led_BlinkLibrary::GetInstance();
}
#endif

