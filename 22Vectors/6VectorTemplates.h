// Vector 06 - Templates

template <typename T>
class vector{
    int cs;
    int ms;
    T *arr;

public:
    vector(){
        cs = 0;
        ms = 1;
        arr = new T[ms];
    }

    void push_back(const T d){
        // if array is full
        if(cs == ms){
            T *oldArr = arr;
            arr = new T[2*ms];
            ms *= 2;
            
            for(int i=0; i<cs; i++){
                arr[i] = oldArr[i];
            }
            
            //clear the old array
            delete [] oldArr;
        }
        arr[cs] = d;
        cs++;
    }

    void pop_back(){
        cs--;
    }

    T front() const{
        return arr[0];
    }

    T back() const{
        return arr[cs-1];
    }

    bool empty() const{
        return cs==0;
    }

    int capacity() const{
        return ms;
    }

    T at(const int i){
        return arr[i];
    }

    T operator[](const int i){
        return arr[i];
    }

    int size(){
        return cs;
    }
};