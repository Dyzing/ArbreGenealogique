#include "TotalTree.h"

void TotalTree::addMember(GeneticTree const& gt)
{
	totalTree.push_back(gt);
}

int TotalTree::getNumberOfMemberWholeFamilyEyeColor(std::string const & ec) const
{
	int compteur = 0;
	for (GeneticTree gt : totalTree)
	{
		if (gt.getMember().eyeColor == ec)
			++compteur;
	}
	return compteur;
}

int TotalTree::getNumberOfDescendanceHavingSameEyeColor(std::string const & ec, std::string const & fn, std::string const& ln)
{
	int compteur = 0;

	for (GeneticTree gt : totalTree)
	{
		if ((gt.getMember().firstName == fn) && (gt.getMember().lastName == ln))
		{
			getNumberOfDescendanceHavingSameEyeColor_rec(ec, gt, compteur);
		}
	}

	return compteur;
}

void TotalTree::getNumberOfDescendanceHavingSameEyeColor_rec(std::string const& ec, GeneticTree const& gt, int & compteur)
{
	if (gt.getMember().eyeColor == ec)
		++compteur;
	if (gt.getFather() != nullptr)
	{
		GeneticTree gt_father = *gt.getFather();
		getNumberOfDescendanceHavingSameEyeColor_rec(ec, gt_father, compteur);
	}
	if (gt.getMother() != nullptr)
	{
		GeneticTree gt_mother = *gt.getMother();
		getNumberOfDescendanceHavingSameEyeColor_rec(ec, gt_mother, compteur);
	}
	else
	{
		return;
	}
}


int TotalTree::getMeanOld() const
{
	int res = 0;

	int ageTotal = 0;
	for (GeneticTree gt : totalTree)
	{
		ageTotal +=  2022 - gt.getMember().yearOfBirth;
	}

	res = float(ageTotal) / float(getNumberofFamilyMembers());
	return res;
}

void TotalTree::getDescendancePreOrder(std::string const& fn, std::string const& ln) const
{
	for (GeneticTree gt : totalTree)
	{
		if ((gt.getMember().firstName == fn) && (gt.getMember().lastName == ln))
		{
			getDescendancePreOrder_rec(gt);
		}
	}
}

void TotalTree::getDescendancePreOrder_rec(GeneticTree const& gt) const
{
	if (gt.getFather() != nullptr)
	{
		GeneticTree gt_father = *gt.getFather();
		std::cout << gt_father.getMember().firstName + " " + gt_father.getMember().lastName + " \n" << std::endl;
		getDescendancePreOrder_rec(gt_father);
	}
	if (gt.getMother() != nullptr)
	{
		GeneticTree gt_mother = *gt.getMother();
		getNumberOfDescendanceHavingSameEyeColor_rec(ec, gt_mother, compteur);
	}
	else
	{
		return;
	}
}
