#include <iostream>
#include <cmath>

class Field
{
    protected:
        double* value;
    public:
    /*THESE METHODS ARE FROM ASSIGNMENT 8*/
    Field ()
    {
        value = (double*)malloc(sizeof(double)*3);
        this->value[0] = 0;
        this ->value[1] = 0;
        this ->value[2] = 0;
    }
    Field (double x, double y, double z)
    {
        value = (double*)malloc(sizeof(double)*3);
        this->value[0] = x;
        this->value[1] = y;
        this->value[2] = z;
    }

    void printMagnitude()
    {
        std::cout<<"\nx: " <<value[0];
        std::cout<<" y: " <<value[1];
        std::cout<<" z: " <<value[2]<<std::endl;
    }

    /*THESE METHODS ARE FROM ASSIGNMENT 7*/
    void setx (double x)
    {
        this->value[0] = x;
    }
    void sety (double y)
    {
        this->value[1] = y;
    }
    void setz (double z)
    {
        this->value[2] = z;
    }

    //get individual vector values
    double getx ()
    {
        return value[0];
    }
    double gety ()
    {
        return value[1];
    }
    double getz ()
    {
        return value[2];
    }

    //calculate the magnitude of the field vector and return it
    double calculateMagnitude ()
    {
        return(sqrt((value[0]*value[0]) + (value[1]*value[1]) + (value[2]*value[2])));
    }
        //set all vector components simultaneously
    void setComponents (double x, double y, double z)
    {
        setx(x);
        sety(y);
        setz(z);

    }

};

//Electric Field Class
class Electric_Field : public Field
{

    /*THESE METHODS ARE FROM ASSIGNMETN 7*/
  public:
    ~Electric_Field ()
    {

        free(value);
        std::cout<< "destroyed Electric field" <<std::endl;

    }



    //calculate the inner product of the electric field with itself
    double innerProduct ()
    {
        return (value[0]*value[0] + value[1]*value[1] + value[2]*value[2]);
    }

    //print the inner product of the field to the console
    void printInnerProduct()
    {
        std::cout<<"Inner Product of Field vector: " <<innerProduct() <<std::endl;
    }
    
    /*THESE METHODS ARE FROM ASSIGNMENT 8*/
    void calculateSphericalEField(double Q, double r)
    {
        for (int i = 0; i < 3; i++)
        {
            value[i] = Q/(4*M_PI*r*r*(8.85*pow(10,-12)));
        }
        
    }

    Electric_Field operator+(Electric_Field EfieldToAdd)
    {
        Electric_Field sum;
        for (int i = 0; i < 3; i++)
        {
            sum.value[i] = this->value[i] + EfieldToAdd.value[i]; 
        }
        return sum;
        
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Electric_Field Efield)
    {
        os << Efield.value[0] << " " << Efield.value[1] << " " << Efield.value[2] << " " ;
        return os;
    }
};

//magnetic field class
class Magnetic_Field : public Field
{
  public:
    /*THESE METHODS ARE FROM ASSIGNMENT 7*/
    ~Magnetic_Field ()
    {

        free(value);
        std::cout<< "destroyed Magnetic field" <<std::endl;

    }

    //calculate the unit vector of the field and return it
    double* unitVector()
    {
        double* unitVec = (double*)malloc(sizeof(double)*3); 
        double mag = calculateMagnitude();

        unitVec[0] = value[0]/mag;
        unitVec[1] = value[1]/mag;
        unitVec[2] = value[2]/mag;

        return unitVec;
    }

    //print the unit vector of the field to the console
    void printUnitVector()
    {
        double* unitVec = unitVector();
        std::cout << "unit vector of Magnetic Field vector: (" << unitVec[0] << "," << unitVec[1] << "," << unitVec[2] <<")" <<std::endl;
    }

    /*THESE METHODS ARE FROM ASSIGNMENT 8*/
    void calculateWireMField(double I, double r)
    {
        for (int i = 0; i < 3; i++)
        {
            value[i] = I/(2*M_PI*r*(4*M_PI*pow(10,-7)));
        }
        
    }
    Magnetic_Field operator+(Magnetic_Field MfieldToAdd)
    {
        Magnetic_Field sum;
        for (int i = 0; i < 3; i++)
        {
            sum.value[i] = this->value[i] + MfieldToAdd.value[i]; 
        }
        return sum;
        
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Magnetic_Field Mfield)
    {
        os << Mfield.value[0] << " " << Mfield.value[1] << " " << Mfield.value[2] << " " ;
        return os;
    }
};
