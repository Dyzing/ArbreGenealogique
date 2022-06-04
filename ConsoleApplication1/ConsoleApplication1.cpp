// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "GeneticTree.h"
#include "Member.h"
#include "TotalTree.h"

int main()
{
    TotalTree totalTree;
    Member mamie_paternel = Member("Sylvette", "Liegeheim", 1950, "brown");
    GeneticTree descendance_mamie_paternel =  GeneticTree(mamie_paternel, family);
    totalTree.addMember(descendance_mamie_paternel);

    Member papy_paternel = Member("Sylvain", "Matagne", 1952, "green");
    GeneticTree descendance_papy_paternel = GeneticTree(papy_paternel, family);
    totalTree.addMember(descendance_papy_paternel);

    Member pere = Member("Didier", "Matagne", 1970, "brown");
    GeneticTree descendance_pere = GeneticTree(pere, descendance_mamie_paternel, descendance_papy_paternel, family);
    totalTree.addMember(descendance_pere);

    // ----------------------------------------------------------------------------------

    Member mamie_maternel = Member("Arlette", "Ensisheim", 1945, "green");
    GeneticTree descendance_mamie_maternel = GeneticTree(mamie_maternel, family);
    totalTree.addMember(descendance_mamie_maternel);

    Member papy_maternel = Member("Jean-Benjamin", "Prist", 1939, "blue");
    GeneticTree descendance_papy_maternel = GeneticTree(papy_maternel, family);
    totalTree.addMember(descendance_papy_maternel);

    Member mere = Member("Murielle", "Prist", 1965, "green");
    GeneticTree descendance_mere = GeneticTree(mere, descendance_mamie_maternel, descendance_papy_maternel, family);
    totalTree.addMember(descendance_mere);

    // ----------------------------------------------------------------------------------

    Member soeur = Member("Charlotte", "Matagne", 2000, "brown");
    GeneticTree descendance_soeur = GeneticTree(soeur, descendance_mere, descendance_pere, family);
    totalTree.addMember(descendance_soeur);

    Member frere = Member("Ben", "Matagne", 1993, "green");
    GeneticTree descendance_frere = GeneticTree(frere, descendance_mere, descendance_pere, family);
    totalTree.addMember(descendance_frere);

    // ----------------------------------------------------------------------------------

    std::cout << "Member of family : \n" << std::endl;

    for (GeneticTree gt : totalTree.getTotalTree())
    {
        std::cout << gt.getMember().ToString() << std::endl;
    }


    int choice = -1;
    std::string fn, ln, ec, yesOrno;
    std::string mother_fn, mother_ln, father_fn, father_ln;
    int yOb;
    std::string order;
    do {
        std::cout << "\nSelect operation:\n"
            "(1) Add a member\n"
            "(2) Cardinal of family\n"
            "(3) Moyenne age\n"
            "(4) Pour une couleur de yeux entree par utilisateur, lister les personnes ayant cette couleur\n"
            "(5) Pour une couleur de yeux entree par utilisateur, permet de lister tous les ancetres(ainsi que lui - meme) qui ont la meme couleur.\n"
            "(6) Lister la descendance de une personne (in-order, pre-order and post-order)\n"
            "(0) Quit\n" << std::endl;
        std::cin >> choice;
        switch (choice) {
        case 1: //Add a member
            std::cout << "\n Enter the firstname of the member" << std::endl;
            std::cin >> fn;
            std::cout << "\n Enter the lastname of the member" << std::endl;
            std::cin >> ln;
            std::cout << "\n Enter the year of birth of the member" << std::endl;
            std::cin >> yOb;
            std::cout << "\n Enter the eye color of the member" << std::endl;
            std::cin >> ec;
            do {
                std::cout << "\n Does the member has parents ? Enter (yes) or (no)" << std::endl;
                std::cin >> yesOrno;
                if (yesOrno == "yes")
                {
                    std::cout << "\n Enter the firstname of the mother" << std::endl;
                    std::cin >> mother_fn;
                    std::cout << "\n Enter the lastname of the mother" << std::endl;
                    std::cin >> mother_ln;
                    GeneticTree gt_mother;
                    for (GeneticTree gt : totalTree.getTotalTree())
                    {
                        if ((gt.getMember().firstName == mother_fn) && (gt.getMember().lastName == mother_ln))
                        {
                            gt_mother = gt;
                            break;
                        }
                    }

                    std::cout << "\n Enter the firstname of the father" << std::endl;
                    std::cin >> father_fn;
                    std::cout << "\n Enter the lastname of the father" << std::endl;
                    std::cin >> father_ln;
                    GeneticTree gt_father;
                    for (GeneticTree gt : totalTree.getTotalTree())
                    {
                        if ((gt.getMember().firstName == father_fn) && (gt.getMember().lastName == father_ln))
                        {
                            gt_father = gt;
                            break;
                        }
                    }

                    Member member_with_parents = Member(fn, ln, yOb, ec);
                    GeneticTree descendance_member_with_parents = GeneticTree(member_with_parents, gt_mother, gt_father, family);
                    totalTree.addMember(descendance_member_with_parents);
                    std::cout << "\n Member " + fn + " " + ln + " added to the family tree\n" << std::endl;
                }
                else if (yesOrno == "no")
                {
                    Member member_without_parents = Member(fn, ln, yOb, ec);
                    GeneticTree descendance_member_without_parents = GeneticTree(member_without_parents, family);
                    totalTree.addMember(descendance_member_without_parents);
                    std::cout << "\n Member " + fn + " " + ln + " added to the family tree\n" << std::endl;
                }
            } while (yesOrno != "yes" && yesOrno != "no");           
            break;
        case 2: //Cardinal of family
            std::cout << "\n Family cardinal : " + std::to_string(totalTree.getNumberofFamilyMembers()) + "\n" << std::endl;
            break;
        case 3: //Moyenne age
            std::cout << "\n Mean Family year old : " + std::to_string(totalTree.getMeanOld()) + "\n" << std::endl;
            break;
        case 4: //Pour une couleur d’yeux entrée par l’utilisateur, lister les personnes ayant cette couleur
            std::cout << "\n Enter the eye color of the member" << std::endl;
            std::cin >> ec;
            std::cout << "\n" + ec + " color eye in family : " + std::to_string(totalTree.getNumberOfMemberWholeFamilyEyeColor(ec)) + "\n" << std::endl;
            break;
        case 5: //Pour une couleur d’yeux entrée par l’utilisateur, permet de lister tous les ancetres(ainsi que lui - meme) qui ont la meme couleur.
            std::cout << "\n Enter the firstname of the member" << std::endl;
            std::cin >> fn;
            std::cout << "\n Enter the lastname of the member" << std::endl;
            std::cin >> ln;
            std::cout << "\n Enter the eye color of the member" << std::endl;
            std::cin >> ec;
            std::cout << "\n Same color of " + ec + " eye from " + fn + " " + ln + " : " + std::to_string(totalTree.getNumberOfDescendanceHavingSameEyeColor(ec, fn, ln)) + "\n" << std::endl;
            break;
        case 6: //Lister la descendance d’une personne (in-order, pre-order and post-order)
            std::cout << "\n Enter the firstname of the member" << std::endl;
            std::cin >> fn;
            std::cout << "\n Enter the lastname of the member" << std::endl;
            std::cin >> ln;
            do
            {
                std::cout << "\n What order ? Enter (pre) or (in) or (post)" << std::endl;
                std::cin >> order;
                if (order == "pre")
                {
                    std::cout << "\n Descendance of " + fn + " " + ln + " : " << std::endl;
                    totalTree.getDescendancePreOrder(fn, ln);
                }
                else if (order == "in")
                {

                }
                else
                {

                }
            } while (order != "pre" && order != "in" && order != "post");
            break;
        default:
            break;
        }
    } while (choice != 0);

    std::cout << "\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
