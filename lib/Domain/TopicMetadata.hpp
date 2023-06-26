#ifndef TOPICMETADATA_H
#define TOPICMETADATA_H



class TopicMetadata {
    private:
        char* name;
    public:
        char * getName() {
            return name;
        }

        void setName(char * n) {
            name = n;
        }
};



#endif