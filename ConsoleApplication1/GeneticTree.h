//
// Created by miska on 2022/05/25.
//

#ifndef GENETICTREE_GENETICTREE_H
#define GENETICTREE_GENETICTREE_H

#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include "Member.h"

static std::vector<Member> family;


class GeneticTree {
    
private:
    Member member;
    GeneticTree* mother{};
    GeneticTree* father{};
    std::vector<Member> frontiers; //All nodes that do not have a child

public:
    GeneticTree(Member& const m, std::vector<Member>& fam);
    GeneticTree(Member& const m, GeneticTree& const moth, GeneticTree& const fath, std::vector<Member> & fam);
    Member getMember() const;
    GeneticTree* getMother() const;
    GeneticTree* getFather() const;

};


#endif //GENETICTREE_GENETICTREE_H
