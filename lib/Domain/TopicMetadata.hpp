#ifndef TOPICMETADATA_H
#define TOPICMETADATA_H



class TopicMetadata {
    private:
        const char* name;
    public:
        TopicMetadata () {}
        TopicMetadata (const char * n) : name(n) {}

        const char * getName() {
            return name;
        }

};



#endif