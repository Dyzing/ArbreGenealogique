//
// Created by miska on 2022/05/25.
//

#include "Member.h"

std::ostream &operator<<(std::ostream &stream, const Member &member) {
    std::string output = member.firstName+" "+member.lastName+" ("+
            std::to_string(member.yearOfBirth)+", "+member.eyeColor+" )";
    stream<<output;
    return stream;
}

Member::Member()
    :firstName(""), lastName(""), yearOfBirth(2022), eyeColor("blind")
{
}

Member::Member(std::string fn, std::string ln, int yob, std::string ec)
    :firstName(fn), lastName(ln), yearOfBirth(yob), eyeColor(ec)
{
}

std::string Member::ToString()
{
    std::string res;
    res = firstName + " " + lastName + "\n" + std::to_string(yearOfBirth) + " " + eyeColor + "\n";
    return res;
}
