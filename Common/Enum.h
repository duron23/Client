#pragma once

#include "Global.h"

#include <QtCore/QEvent>

class COMMON_EXPORT Enum
{
    public:
        struct EventType
        {
            enum Type
            {
                StatusbarMessage = QEvent::User + 11
            };
        };
};
