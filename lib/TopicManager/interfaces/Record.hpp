#ifndef RECORD_H
#define RECORD_H

class Record {
    private:
        char*         data;
        char*         key;
    public:
        Record(char* d, char* k) : data(d), key(k) {}

        char* getData() {
            return data;
        }
		
};



#endif