#include <string>

template <typename T>
class TestCase{
    
    private:
    string name;
    cerr c;
    int total, passed, failed;
    
    public:
        TestCase(string name, cerr c){
            this->name = name;
            this->c = c;    
            total = passed = failed = 0;
        }
        
        TestCase& check_equal(const T a, const T b) const{
            this->total++;
            if(a!=b){
              c<<this->name<<": Failure in test #"<< total << a <<": should equal "<< b <<endl;
              failed++;
            } else{
               passed++;
            }
        } 
        
        TestCase& check_different (const T a, const T b) const{
            this->total++;
            if (a==b){
                c<<this->name<<": Failure in test #"<< total << a <<": should different "<< b <<endl;
                failed++;
            } else{
                passed++;
            }
        } 
        /*
        we need another tamplate viriable in orfer to execute differents options on him.
        
        */
        template<typename R>
        TestCase& check_function((int)func(R val),const R a, const T b) const{
            int res = func(a);
            this->total++;
            if(res!=b){
                c<<this->name<<": Failure in test #"<< total << ": function should return "<< b <<" but returned "<<res<<"!"<<endl;
                failed++;
            } else{
               passed++;
            }
        } 
        
        TestCase& check_output(T a,string str){
            this->total++;
            if(string(a)!=(str)){
                c<<this->name<<": Failure in test #"<< total << ": string value should be "<< str <<" but returned "<<stirng(a)<<"!"<<endl;
                failed++;
            } else{
               passed++;
            }

        }
        TestCase& print(){
            c << name << ": " << failed << " failed, " << passed << " passed, " << total << " total." << endl;
            c << "---" << endl;
        }
};