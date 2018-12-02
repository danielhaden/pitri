//
// Created by hadend on 12/1/18.
//

#ifndef PITRI_MULTIEDGEEXCEPTION_H
#define PITRI_MULTIEDGEEXCEPTION_H


struct MultiedgeException {

    const char * what() const throw() {

        return "Can't add multiedges to the graph!";
    }
};


#endif //PITRI_MULTIEDGEEXCEPTION_H
