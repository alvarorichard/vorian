#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

class Debug {
    private:
    static void report(int,const std::string&, const std::string&);

    public:
    inline static bool hadError = false;
    static void error(int line, const std::string&);


};



#endif
