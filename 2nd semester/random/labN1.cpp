#include <iostream>
#include <string>

class Stradnieks
{
public:
    Stradnieks(const std::string &vards, const std::string &uzvards, const std::string &apliecNr)
        : vards(vards), uzvards(uzvards), apliecNr(apliecNr) {}

    virtual void print() const
    {
        std::cout << "Vards: " << vards << ", Uzvards: " << uzvards << ", Apliecibas numurs: " << apliecNr << std::endl;
    }

protected:
    std::string vards;
    std::string uzvards;
    std::string apliecNr;
};

class Vaditajs : public Stradnieks
{
public:
    Vaditajs(const std::string &vards, const std::string &uzvards, const std::string &apliecNr, const std::string &amats)
        : Stradnieks(vards, uzvards, apliecNr), amats(amats) {}

    void print() const
    {
        Stradnieks::print();
        std::cout << "Amats: " << amats << std::endl;
    }
private:
    std::string amats;
};

int main()
{
    Stradnieks stradnieks("Janis", "Berzins", "123456789");
    stradnieks.print();

    auto stradnieks2 = new Stradnieks("Anna", "Ozola", "987654321");
    stradnieks2->print();

    delete stradnieks2;
}