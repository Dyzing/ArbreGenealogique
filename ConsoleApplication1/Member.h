//
// Created by miska on 2022/05/25.
//

#ifndef GENETICTREE_MEMBER_H
#define GENETICTREE_MEMBER_H

#include <iostream>
#include <string>

class Member {
public:
    std::string firstName;
    std::string lastName;
    int yearOfBirth;
    std::string eyeColor;

    friend std::ostream &operator<<(std::ostream &stream, const Member &member);
    Member();
    Member(std::string fn, std::string ln, int yob, std::string ec);
    std::string ToString();

};

#endif //GENETICTREE_MEMBER_H
