#ifndef CONTACT_HPP
#define CONTACT_HPP

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        Contact();      // constructor
        ~Contact();     // destructor

        // Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getNickName();
        std::string getPhoneNumber();
        std::string getDarkestSecret();
        // Setters
        void setFirstName(std::string firstname);
        void setLastName(std::string lastname);
        void setNickName(std::string nickename);
        void setPhoneNumber(std::string phonenumber);
        void setDarkestSecret(std::string darkestsecret);
};
#endif // CONTACT_HPP
