#pragma once
#include "Arp/System/Core/Arp.h"
#if ARP_ABI_VERSION_MAJOR < 2
#include "Arp/System/Core/AppDomain.hpp"
#include "Arp/System/Core/Singleton.hxx"
#include "Arp/System/Core/Library.h"
#endif
#include "Arp/Plc/Commons/Meta/MetaLibraryBase.hpp"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeDomain.hpp"

namespace All_Led_Blink
{

#if ARP_ABI_VERSION_MAJOR < 2
using namespace Arp::System::Acf;
#else
using namespace Arp::Base::Acf::Commons;
#endif
using namespace Arp::Plc::Commons::Meta;
using namespace Arp::Plc::Commons::Meta::TypeSystem;

class All_Led_BlinkLibrary : public MetaLibraryBase
#if ARP_ABI_VERSION_MAJOR < 2
    , public Singleton<All_Led_BlinkLibrary>
#endif
{
#if ARP_ABI_VERSION_MAJOR < 2
public: // typedefs
    typedef Singleton<All_Led_BlinkLibrary> SingletonBase;
#else
    All_Led_BlinkLibrary(void);
#endif
public: // construction/destruction
#if ARP_ABI_VERSION_MAJOR < 2
    All_Led_BlinkLibrary(AppDomain& appDomain);
    virtual ~All_Led_BlinkLibrary() = default;

public: // static operations (called through reflection)
    static void Main(AppDomain& appDomain);
#else
    static All_Led_BlinkLibrary& GetInstance();
#endif

private: // methods
    void InitializeTypeDomain();

#if ARP_ABI_VERSION_MAJOR < 2
private: // deleted methods
    All_Led_BlinkLibrary(const All_Led_BlinkLibrary& arg) = delete;
    All_Led_BlinkLibrary& operator= (const All_Led_BlinkLibrary& arg) = delete;
#endif
private:  // fields
    TypeDomain typeDomain;
};

#if ARP_ABI_VERSION_MAJOR < 2
extern "C" ARP_CXX_SYMBOL_EXPORT ILibrary& ArpDynamicLibraryMain(AppDomain& appDomain);
#endif
///////////////////////////////////////////////////////////////////////////////
// inline methods of class All_Led_BlinkLibrary

} // end of namespace All_Led_Blink
