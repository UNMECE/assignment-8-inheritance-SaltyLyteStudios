#include "fieldClasses.h"

int main ()
{
    //test printMagnitude()
    Electric_Field Efield;
    Efield.printMagnitude();

    //test CalculateSphericalEField()
    Efield.calculateSphericalEField(1,1);
    Efield.printMagnitude();

    //test overloaded '+' operator
    Electric_Field E1, E2;
    E1.setComponents(1,1,1);
    E2.setComponents(2,2,2);
    Electric_Field Esum = E1+E2;

    //test overloaded '<<' operator
    Esum.printMagnitude();
    std::cout<<E1<<std::endl;

    //test Magnetic versions of previous functionality

    //test printMagnitude()
    Magnetic_Field Mfield;
    Mfield.printMagnitude();

    //test CalculateWireMField()
    Mfield.calculateWireMField(1,1);
    Mfield.printMagnitude();

    //test overloaded '+' operator
    Magnetic_Field M1, M2;
    M1.setComponents(1,1,1);
    M2.setComponents(2,2,2);
    Magnetic_Field Msum = M1+M2;

    //test overloaded '<<' operator
    Msum.printMagnitude();
    std::cout<<M1<<std::endl;


    return 0;
}