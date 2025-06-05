#pragma once
/*
    This interface is NOT meant for <*State.h> files
    It should be implemented in every <*Simmulation.h>
    file inside simm directory
    
    This interface contains no .cpp pair file
*/

class BaseSimmulation {
    public:
        virtual ~BaseSimmulation();
        virtual void RunSimmulation();
}