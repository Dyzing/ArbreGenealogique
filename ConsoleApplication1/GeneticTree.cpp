//
// Created by miska on 2022/05/25.
//

#include "GeneticTree.h"


GeneticTree::GeneticTree(Member& const m, std::vector<Member>& fam)
{
	father = nullptr;
	mother = nullptr;
	member = m;
	fam.push_back(m);
}

GeneticTree::GeneticTree(Member& const m, GeneticTree& const moth, GeneticTree& const fath, std::vector<Member>& fam)
{
	father = &fath;
	mother = &moth;
	member = m;
	fam.push_back(m);
}

Member GeneticTree::getMember() const
{
	return member;
}

GeneticTree* GeneticTree::getMother() const
{
	return mother;
}

GeneticTree* GeneticTree::getFather() const
{
	return father;
}





