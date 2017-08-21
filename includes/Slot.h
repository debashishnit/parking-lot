/*
 * Slot.h
 *
 *  Created on: Aug 19, 2017
 *      Author: debashish.g
 */

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

#endif /* SLOT_H_ */
