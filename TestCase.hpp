#pragma once

#include <sstream>
#include <iostream>
using namespace std;


class TestCase{
    
    private:
        int total, passed, failed;
        string _name;
        ostream c;
        
        
        
    public:
    
        TestCase(string name, ostream& c);
        void print();
        
        template <typename T> TestCase& check_equal(T a, T b){
            
            total++;
            
            if(a == b){
                passed++;
            } 
            else{
                c << _name << ": Failure in test #" <<  total << ": " << a << " should equal " << b << "!" << endl;
                failed++;
            }
            
            return *this;
        } 
        
        template <typename T> TestCase& check_different (T a, T b){
            
            total++;
            
            if (a != b){
                passed++;
            } 
            else{
                c << _name << ": Failure in test #" << total << ": " << a << " should not equal " << b << "!" << endl;
                failed++;
            }
            
            return *this;
        } 
        
        /*
        we need another tamplate variable in orfer to execute differents options on him.
        
        */
        template<typename Fun , typename T> TestCase& check_function(Fun func,const T a, const int b){
            
            total++;
            int res = (*func)(a);
            
            if(res == b){
                passed++;
            } 
            else{
               c << _name << ": Failure in test #" << total << ": Function should return " << b << " but returned " << res << "!" << endl;
                failed++;
            }
            
            return *this;
        } 
        
        
        template <typename T> TestCase& check_output(T a,string str){
            
            total++;
            ostringstream ss;
            ss << a;
            
            if(ss.str() == str){
                passed++;
            } 
            else{
               c << _name << ": Failure in test #" << total << ": string value should be " << str << " but is " << ss.str() << "!" << endl;
                failed++;
            }
            
            return *this;
        }
        
        
        // TestCase& print(){
            
        //     c << _name << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
        //     c << "---" << endl;
        //     return *this;
        // }
};