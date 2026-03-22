#include "Arp/System/Core/Arp.h"
#include "Arp/Plc/Commons/Meta/TypeSystem/TypeSystem.h"
#include "All_Led_BlinkProgram.hpp"
#include "All_Led_BlinkLibrary.hpp"

namespace All_Led_Blink
{

using namespace Arp::Plc::Commons::Meta;

    void All_Led_BlinkLibrary::InitializeTypeDomain()
    {
        this->typeDomain.AddTypeDefinitions
        (
            // Begin TypeDefinitions
            {
                {   // ProgramDefinition: All_Led_Blink::All_Led_BlinkProgram
                    DataType::Program, CTN<All_Led_Blink::All_Led_BlinkProgram>(), sizeof(::All_Led_Blink::All_Led_BlinkProgram), alignof(::All_Led_Blink::All_Led_BlinkProgram), StandardAttribute::None,
                    {
                        // FieldDefinitions:
                        { "red", offsetof(::All_Led_Blink::All_Led_BlinkProgram, red_led), DataType::Boolean, String::Empty, sizeof(bool), alignof(bool), {  }, StandardAttribute::Output },
                        { "orange", offsetof(::All_Led_Blink::All_Led_BlinkProgram, orange_led), DataType::Boolean, String::Empty, sizeof(bool), alignof(bool), {  }, StandardAttribute::Output },
                        { "green", offsetof(::All_Led_Blink::All_Led_BlinkProgram, green_led), DataType::Boolean, String::Empty, sizeof(bool), alignof(bool), {  }, StandardAttribute::Output },
                        { "blue", offsetof(::All_Led_Blink::All_Led_BlinkProgram, blue_led), DataType::Boolean, String::Empty, sizeof(bool), alignof(bool), {  }, StandardAttribute::Output },
                        { "white", offsetof(::All_Led_Blink::All_Led_BlinkProgram, white_led), DataType::Boolean, String::Empty, sizeof(bool), alignof(bool), {  }, StandardAttribute::Output },
                    }
                },
            }
            // End TypeDefinitions
        );
    }

} // end of namespace All_Led_Blink

