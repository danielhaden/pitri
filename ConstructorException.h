//
// Created by hadend on 12/6/18.
//

#ifndef PITRI_CONSTRUCTOREXCEPTION_H
#define PITRI_CONSTRUCTOREXCEPTION_H


class ConstructorException {

    const char * what() const throw() {

        return "Unrecognized graph type. Object not created!\n";
    }
};


#endif //PITRI_CONSTRUCTOREXCEPTION_H
