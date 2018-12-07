//
// Created by hadend on 12/7/18.
//

#ifndef PITRI_OUTOFRANGEEXCEPTION_H
#define PITRI_OUTOFRANGEEXCEPTION_H


class OutOfRangeException {

    const char * what() const throw() {

        return "Index out of range!\n";
    }
};


#endif //PITRI_OUTOFRANGEEXCEPTION_H
