#include "TestCase.hpp"

TestCase::TestCase(string name, ostream& c) : c(c.rdbuf()) {
            _name = name;
            total = passed = failed = 0;
}

void TestCase::print(){
    
    c << _name << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
    c << "---" << endl;
}