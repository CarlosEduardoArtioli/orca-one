#pragma once

#include <WString.h>
#include <stdexcept>
#include <vector>
#include <memory>

#include "Interfaces.h"
#include "InterfaceType.h"
#include "IInterface.h"

#ifdef __cplusplus
extern "C"
{
#endif
    namespace Domain::Entities
    {
        class DeviceBase
        {
        public:
            DeviceBase(const Interfaces interfaces);

            static const DeviceBase *getCurrent();

            virtual String getName() = 0;
            virtual void begin();
            virtual void loop();

            bool hasInterface(InterfaceType type);

            virtual const Interfaces getInterfaces();

        private:
            static DeviceBase *_current;
            static bool _initialized;

        protected:
            Interfaces interfaces;
        };
    }
#ifdef __cplusplus
}
#endif