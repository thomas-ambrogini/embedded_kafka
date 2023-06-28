#ifndef CONSUMERMETADATA_H
#define CONSUMERMETADATA_H


class ConsumerMetadata {
    private:
        int id;
    public:

        ConsumerMetadata() {}

        ConsumerMetadata(int value) : id(value) {}

        int getId() {
            return id;
        }

        void setId(int i) {
            id = i;
        }
};



#endif