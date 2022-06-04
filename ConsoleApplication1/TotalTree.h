#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "GeneticTree.h"

class TotalTree {

private:
	std::vector<GeneticTree> totalTree;
public:
	int getNumberofFamilyMembers() const {
		return family.size();
	}
	std::vector<GeneticTree> getTotalTree() const { return totalTree; };
	void addMember(GeneticTree const & gt);
	int getNumberOfMemberWholeFamilyEyeColor(std::string const & ec) const;
	int getNumberOfDescendanceHavingSameEyeColor(std::string const & ec, std::string const& fn, std::string const& ln);
	void getNumberOfDescendanceHavingSameEyeColor_rec(std::string const& ec, GeneticTree const & gt, int & compteur);
	int getMeanOld() const;
	void getDescendancePreOrder(std::string const& fn, std::string const& ln) const;
	void getDescendancePreOrder_rec(GeneticTree const& gt) const;
	
};