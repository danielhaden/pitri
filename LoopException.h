//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_LOOPEXCEPTION_H
#define PITRI_LOOPEXCEPTION_H

#include <exception>

struct LoopException : public std::exception {

    const char * what() const throw() {

        return "Can't add loops to the graph!\n";
    }
};


#endif //PITRI_LOOPEXCEPTION_H
