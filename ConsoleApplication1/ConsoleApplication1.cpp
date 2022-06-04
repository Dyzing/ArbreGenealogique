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


    /*std::cout << mamie_paternel.ToString() << std::endl;
    std::cout << papy_paternel.ToString() << std::endl;
    std::cout << pere.ToString() << std::endl;
    
    std::cout << mamie_maternel.ToString() << std::endl;
    std::cout << papy_maternel.ToString() << std::endl;
    std::cout << mere.ToString() << std::endl;*/

    for (GeneticTree gt : totalTree.getTotalTree())
    {
        std::cout << gt.getMember().ToString() << std::endl;
    }

    std::cout << "Family cardinal : " + std::to_string(totalTree.getNumberofFamilyMembers()) + "\n" << std::endl;
    std::cout << "Green color in family : " + std::to_string(totalTree.getNumberOfMemberWholeFamilyEyeColor("green")) << std::endl;
    std::cout << "Brown color in family : " + std::to_string(totalTree.getNumberOfMemberWholeFamilyEyeColor("brown")) << std::endl;
    std::cout << "Blue color in family : " + std::to_string(totalTree.getNumberOfMemberWholeFamilyEyeColor("blue")) + "\n" << std::endl;
    std::cout << "Mean Family year old : " + std::to_string(totalTree.getMeanOld()) + "\n" << std::endl;
    std::cout << "Same color of green eye from Charlotte Matagne : " + std::to_string(totalTree.getNumberOfDescendanceHavingSameEyeColor("green", "Charlotte", "Matagne")) + "\n" << std::endl;

    std::cout << "Descendance of Charlotte Matagne : "  << std::endl;
    totalTree.getDescendancePreOrder("Charlotte", "Matagne");

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
