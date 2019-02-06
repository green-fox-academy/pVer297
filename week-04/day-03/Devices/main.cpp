#include <iostream>
#include <vector>
#include "printer.h"
#include "printer2D.h"
#include "printer3D.h"
#include "scanner.h"
#include "copier.h"

int main()
{
    std::vector<Printer*> printers;

    Printer2D canonPhotoPrinter(8, 10);
    Printer2D canonA4Printer(21, 30);
    Printer2D epsonA5Printer(15, 21);

    Printer3D creality(20, 20, 23);
    Printer3D makerBot(30, 30, 45);

    Copier sharpCopier(21, 30, 20);

    printers.push_back(&canonPhotoPrinter);
    printers.push_back(&canonA4Printer);
    printers.push_back(&epsonA5Printer);
    printers.push_back(&creality);
    printers.push_back(&makerBot);
    printers.push_back(&sharpCopier);

    for (Printer* printer : printers) {
        printer->print();
    }

    std::cout << std::endl;

    std::vector<Scanner*> scanners;

    Scanner hpScanner(7);
    Scanner brotherScanner(10);

    Copier xeroxCopier(21, 30, 15);
    Copier toshibaCopier(30, 420, 5);

    scanners.push_back(&hpScanner);
    scanners.push_back(&brotherScanner);
    scanners.push_back(&xeroxCopier);
    scanners.push_back(&toshibaCopier);

    for (Scanner* scanner : scanners) {
        scanner->scan();
    }

    std::cout << std::endl;

    Copier anotherXeroxCopier(21, 30, 10);
    anotherXeroxCopier.copy();
    return 0;
}