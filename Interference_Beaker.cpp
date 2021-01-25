#include "Interference_Beaker.h"
using std::cout;
using std::endl;


void Beaker::pour_into(float ri, string nam)  {

    Solution* newLiquid = new Solution(ri, nam);

    if (top == NULL) {
        top = newLiquid;
        bottom = newLiquid;
        newLiquid->up = NULL;
        newLiquid->down = NULL;
    }
    else if (composition() == 3) {
        cout << "Beaker can only hold three different substances." << endl;
    }
    else {
        newLiquid->up = NULL;
        newLiquid->down = top;
        top = newLiquid;
    }

}

void Beaker::remove()
{
    if (top == NULL)
    {
        cout << "Beaker empty!" << endl;
    }
    // else if only one element is present
    // else: removes the top element
    /*
    
        
    */

}

void Beaker::traverse(/* ???*/)
{
    // check if list is empty (can apply anywhere)
    float phase_counter = 0; // Keeps track of how many phase changes happen 
    Solution* beam1 = top;
    while (beam1->down != NULL) {
        cout << beam1->name << ": " << beam1->refract_i << endl;
        if (beam1->refract_i <= beam1->down->refract_i)
            phase_counter += 0.5;
        beam1 = beam1->down;
    } 

    cout << beam1->name << ": " << beam1->refract_i << endl;  //  Last/Bottom Liquid

    cout << "\n";
    cout << "# of Phase Shifts: " << phase_counter << endl;
}
int Beaker::constr_int(int lambda)  // 0, λ, 2λ, 3λ ... nλ
{
    Solution* c_beam = top->down;

    if (c_beam->refract_i <= c_beam->down->refract_i) {
        return (lambda / (4 * c_beam->refract_i));
    }
    else {
        return (lambda / (2 * c_beam->refract_i));
    }
}

int Beaker::destr_int(int lambda)  // λ/2, 3λ/2, 5λ/2 ... (2n+1)λ/2
{
    Solution* c_beam = top->down;

    if (c_beam->refract_i <= c_beam->down->refract_i) {
        return (lambda / (2 * c_beam->refract_i));
    }
    else {
        return (lambda / (4 * c_beam->refract_i));
    }
}

int Beaker::composition()
{
    int item_count = 0;
    Solution* beam2 = top; 
     do {
        item_count += 1; 
        beam2 = beam2->down;
    } while (beam2 != NULL);
    return item_count;
}

bool Beaker::emptybeaker()
{
    return (top == NULL);
}


Solution Beaker::topliquid()
{
    if (top == NULL)
        cout << "Beaker empty!" << endl;
        // else return top element of beaker
}
