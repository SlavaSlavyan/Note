#pragma once

class Report {

    bool status;
    unsigned int id, vetId, clientId, animalId;
    char * anamnesis, * diagnosis, * date;

    char* SetString(const char* data);

    void Print(const char* data) const;

public:

    Report();

    Report(const Report& other);

    ~Report();

    bool GetStatus() const { return status; }

    unsigned int GetId() const { return id; }

    unsigned int GetVetId() const { return vetId; }

    unsigned int GetClientId() const { return clientId; }

    unsigned int GetAnimalId() const { return animalId; }

    const char* GetAnamnesis() const { return anamnesis; }

    const char* GetDiagnosis() const { return diagnosis; }

    const char* GetDate() const { return date; }

    void SetStatus(bool newStatus) { status = newStatus; }

    void SetId(unsigned int newId) { id = newId; }

    void SetVetId(unsigned int newVetId) { vetId = newVetId; }

    void SetClientId(unsigned int newClientId) { clientId = newClientId; }

    void SetAnimalId(unsigned int newAnimalId) { animalId = newAnimalId; }

    void SetAnamnesis(const char* newAnamnesis) {
        if (anamnesis) delete[] anamnesis;
        anamnesis = SetString(newAnamnesis);
    }

    void SetDiagnosis(const char* newDiagnosis) {
        if (diagnosis) delete[] diagnosis;
        diagnosis = SetString(newDiagnosis);
    }

    void SetDate(const char* newDate) {
        if (date) delete[] date;
        date = SetString(newDate);
    }

    void PrintDiagnosis();

    void PrintAnamnesis();
};