/*
** EPITECH PROJECT, 2020
** nanotekspace
** File description:
** Error
*/

#ifndef ERROR_HPP_
    #define ERROR_HPP_

    #include <string>

class Error : public std::exception {
    public:
        Error(std::string const &message,
                std::string const &component = "Unknown");
        ~Error();

        std::string const &getComponent() const;
        const char *what() const noexcept;
    protected:
    private:
        std::string _message;
        std::string _componant;

};

#endif /* !ERROR_HPP_ */
