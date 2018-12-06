//
// Created by hadend on 12/6/18.
//

#ifndef PITRI_IDCOLLISIONEXCEPTION_H
#define PITRI_IDCOLLISIONEXCEPTION_H


class IDCollisionException {

    const char * what() const throw() {

        return "Vertex ID collision! ID already in graph!\n";
    }
};


#endif //PITRI_IDCOLLISIONEXCEPTION_H
