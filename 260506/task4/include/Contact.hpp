#pragma once

class Contact {

    char *name, *homePhone, *workPhone, *info;

public:

    Contact(const char* n, const char* hp, const char* wp, const char* i);

    Contact() : Contact(nullptr, nullptr, nullptr, nullptr) {}

    Contact(const Contact &other) : Contact(other.name, other.homePhone, other.workPhone, other.info) {}; 

    ~Contact() {
        delete[] name;
        delete[] homePhone;
        delete[] workPhone;
        delete[] info;
    }

    char* getName() const;

    char* getHomePhone() const;

    char* getWorkPhone() const;

    char* getInfo() const;

    void setName(const char* init_name);

    void setHomePhone(const char* init_homePhone);

    void setWorkPhone(const char* init_workPhone);

    void setInfo(const char* init_info);
};