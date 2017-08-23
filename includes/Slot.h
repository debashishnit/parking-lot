
#ifndef SLOT_H_
#define SLOT_H_

class Slot {
private:
    int number;
public:
    Slot(int);
    virtual ~Slot();

    int getSlotNumber();
};

#endif
