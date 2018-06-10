#pragma once

#include <sstream>
#include <iostream>
#include <string>

using namespace std;


class TestCase{
    
    private:
        string name;
        ostream c;
        int total, passed, failed;
        
    public:
        TestCase(string name, ostream& c):c(c.rdbuf()){
            this->name = name;
            total = passed = failed = 0;
        }
        
        template <typename T> TestCase& check_equal(const T a, const T b){
            this->total++;
            if(a!=b){
              c<<this->name<<": Failure in test #"<< total << a <<": should equal "<< b <<endl;
              failed++;
            } else{
               passed++;
            }
            return *this;
        } 
        
        template <typename T> TestCase& check_different (const T a, const T b){
            this->total++;
            if (a==b){
                c<<this->name<<": Failure in test #"<< total << a <<": should different "<< b <<endl;
                failed++;
            } else{
                passed++;
            }
            return *this;
        } 
        /*
        we need another tamplate variable in orfer to execute differents options on him.
        
        */
        template<typename Fun , typename T>
        TestCase& check_function(Fun func,const T a, const int b){
            int res = func(a);
            this->total++;
            if(res!=b){
                c<<this->name<<": Failure in test #"<< total << ": Function should return "<< b <<" but is "<<res<<"!"<<endl;
                failed++;
            } else{
               passed++;
            }
            return *this;
        } 
        
        
        template <typename T> TestCase& check_output(T a,string str){
            this->total++;
            ostringstream ss;
            ss << a;
            if(ss.str() != str){
                c<<this->name<<": Failure in test #"<< total << ": string value should be "<< str <<" but returned "<< a <<"!"<<endl;
                failed++;
            } else{
               passed++;
            }
            return *this;
        }
        TestCase& print(){
            c << name << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
            // c << "---" << endl;
            return *this;
        }
};