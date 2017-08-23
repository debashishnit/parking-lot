
#include "cute.h"
#include "../includes/Slot.h"

class SlotTest {
public:
    SlotTest() {};
    void operator()() {
        Slot s(4);

        ASSERTM("wrong constructor", s.getSlotNumber() == 4);
    };
};

