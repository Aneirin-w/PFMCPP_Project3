/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




#include <iostream>
#include <string>

struct AudioInterface
{
    int numOfAdatInput = 2;
    int numOfXlrInputs = 4;
    int numOfHeadphonesOutputs = 6;
    float percentageOfTHD = 0.0001f;
    float amountOfWattsRequired = 29.5f;
    float levelControl = 10.f;

    void linkAnalogueChannels1And2();
    float mainsPlaybackLevel(float displayLevel);
    void muteMainMonitors();
};

void AudioInterface::linkAnalogueChannels1And2()
{
}
float AudioInterface::mainsPlaybackLevel(float displayLevel)
{
    displayLevel = amountOfWattsRequired * levelControl;
    return displayLevel;
}
void AudioInterface::muteMainMonitors()
{
}

struct Cafe 
{
    int numOfStaffWorking = 25;
    int numOfTablesUsed = 100;
    double amountOfFoodWastageInKg = 3;
    std::string soupOfTheDay = "Onion Soup";
    double avgCostPerMealInDollars = 12.99;
    double foodPrice;
    struct RentalCost
    {
        int areaInMetreCube = 10000;
        bool doesItNeedRenovation = true;
        double expectedNumOfCustomersPerDay = 73.5;
        std::string address = "Sesame Street";
        std::string minimumTenancyPeriod = "5 Years";

        int expectedTime(int numOfWorkers = 10, int numOfHoursWorkedPerDay = 10, int offDays = 6, int numOfDays = 50);
    };

    int serveSpecalityDrinks (int price, bool drinkIsAvailable);
    void provideTableService ();
    double serveVeganFood (double additionalCharge);
};

int Cafe::RentalCost::expectedTime(int numOfWorkers, int numOfHoursWorkedPerDay, int offDays, int numOfDays)
{
    int timeTaken = (numOfHoursWorkedPerDay * numOfDays) / numOfWorkers - offDays;
    return timeTaken;
}
int Cafe::serveSpecalityDrinks (int drinkPrice, bool drinkIsAvailable)
{
    if (drinkIsAvailable == true)
    {
        drinkPrice = 10;
    }
    else
    {
        drinkPrice = 0;
    }
    return drinkPrice;
}
void Cafe::provideTableService ()
{   
}
double Cafe::serveVeganFood (double additionalCharge)
{
    additionalCharge = 2.55 + foodPrice;
    return additionalCharge;
}

struct Iphone
{
    float StorageSpaceInTeraByte = 3.44f;
    int screenRefreshRate = 1000;
    int numOfSpeakers = 3;
    double cameraMegapixel = 20.2;
    double costOfPhone = 5003.99;
    int totalCharge;

    struct phoneBill
    {
        int bill = 13;

        int additionalCharge();
        int totalCharge();
    };

    phoneBill bill;

    int makePhoneCall(bool overseasCall);
    void browseTheInternet();
    auto downloadMobileApplication(std::string mobileAppName);
};

int Iphone::phoneBill::additionalCharge()
{
    bill += 5;
    return bill;
}
int Iphone::phoneBill::totalCharge()
{
    return bill;
}
int Iphone::makePhoneCall(bool overseasCall)
{
    if (overseasCall == true)
    {
        bill.additionalCharge();
    }
    else 
    {
        bill.totalCharge();
    }
    totalCharge = bill.totalCharge() + bill.additionalCharge();
    return totalCharge;
}
void Iphone::browseTheInternet()
{
}
auto Iphone::downloadMobileApplication(std::string mobileAppName)
{
    mobileAppName = "Angry Bird";
}

struct MidiKeyboard
{
    int velocityOfKeybeds = 127;
    int numOfKeys = 88;
    std::string brand = "Roland";
    int numOfRotaryControl = 10;
    double weightInKg = 2.5;

    void useAsKeyboard(bool pianoSound);
    int transposeInOctaves(int octave);
    void midiLinkToOtherDevice(bool externallMidiDeviceConnected);
};

void MidiKeyboard::useAsKeyboard(bool pianoSound)
{
    pianoSound = true;
}
int MidiKeyboard::transposeInOctaves(int octave)
{
    octave += 1;
    return octave;
}
void midiLinkToOtherDevice(bool externallMidiDeviceConnected)
{
    externallMidiDeviceConnected = true;
}

struct Staff
{
    int numOfEngineeringStaff = 30;
    std::string colourOfUniform = "Dark Blue";
    int age = 30;
    bool genderIsMale = 1;
    double wages = 2222.22;

    struct StaffWelfare
    {   
        int numberOfMealsPerDay = 4;
        bool didTheyWorkMoreThan6Hours = true;
        int numOfOffDays = 2;

        int percentageOfTips(int customersServed, int hoursWorked);
        void sickDays(int daysStatedInContract);
    };
    
    void fixTechnialIssuesOnBoard (int numOfStaffRequired);
    void serveCustomers();
    void purchaseWithStaffDiscount(int discount);
};

int Staff::StaffWelfare::percentageOfTips(int customersServed, int hoursWorked)
{
    customersServed = 20;
    hoursWorked = 30;
    int tips = customersServed / hoursWorked;
    return tips;
}
void Staff::StaffWelfare::sickDays(int daysStatedInContract)
{
    daysStatedInContract = 10;
}
void Staff::fixTechnialIssuesOnBoard (int numOfStaffRequired)
{
    numOfStaffRequired = 5;
}
void Staff::serveCustomers()
{
}
void Staff::purchaseWithStaffDiscount(int discount)
{
    discount = 30;
}

struct BuildSpecification
{
    double tonsOfSteelUsed = 23.59;
    std::string companyMaterialsWereBoughtFrom = "Very good stuff";
    float volOfShipInMetreCube = 59834.34f;
    double totalWeightInTons = 493.34;
    std::string importedMaterials = "aluminium";

    void describeMaterialUsed();
    double displayWeightOfShip(double weightOfMaterials, int avgWeightOfPassengers, int maxCapacityOfPassengers);
    void showBuildingProjectDate(std::string startDate, std::string endDate);
};
void BuildSpecification::describeMaterialUsed()
{
}
double BuildSpecification::displayWeightOfShip(double weightOfMaterials, int avgWeightOfPassengers, int maxCapacityOfPassengers)
{
    double weightOfShip = weightOfMaterials + avgWeightOfPassengers + maxCapacityOfPassengers;
    return weightOfShip;
}
void BuildSpecification::showBuildingProjectDate(std::string startDate, std::string endDate)
{
    startDate = "20th Feb 2000";
    endDate = "31st Nov 2005";
}

struct Entertainment
{
    std::string nameOfAct = "WOW";
    double costOfHire = 2359.23;
    std::string allocatedTime = "2pm - 5pm everyday";
    int numOfPerformers = 7;
    std::string locationOfPerformance = "Sky Deck";

    auto doAcrobats(bool safetyEquipmentIsPresent);
    void performWithAudience();
    void workForLongHaul();
};
auto Entertainment::doAcrobats(bool safetyEquipmentIsPresent)
{
    if (safetyEquipmentIsPresent == true)
    {
        return nameOfAct;
    }
    std::string cancellation = "Performance Cancelled";
    return cancellation;
}
void Entertainment::performWithAudience()
{
}
void Entertainment::workForLongHaul()
{
}

struct Facilities
{
    float sizeOfPoolInHectars = 200;
    int numOfShopsOpened24_7 = 20;
    std::string openingHoursOfSpa = "10am - 10pm";
    int numOfGymEquipment = 40;
    int numOfRestauruantsAvailable = 25;

    void keepPassengersBusy(int activitiesPlanned);
    void entertainChildren(int dayCareServiceSlots);
    void allowPassengersToRelax(int numOfRelaxingSongInPlaylist);
};

void Facilities::keepPassengersBusy(int activitiesPlanned)
{
    activitiesPlanned = 20;
}
void Facilities::entertainChildren(int dayCareServiceSlots)
{
    dayCareServiceSlots = 5;
}
void Facilities::allowPassengersToRelax(int numOfRelaxingSongInPlaylist)
{
    numOfRelaxingSongInPlaylist = 200;
}

struct SafetyProcedure
{
    int numOfFloors = 6;
    int numOfPersonnelOnBoard = 1500;
    int numOfLifeboats = 80;
    int helplineNum = 10291092;
    char meetingPoint = 'C';

    auto informSafetyInformation(bool broadcastedOnPA);
    void displayFloorplan();
    void displayExitRoute();
};

auto SafetyProcedure::informSafetyInformation(bool broadcastedOnPA)
{
    if (broadcastedOnPA == true)
    {
        std::string done = "It is safe";
        return done;
    }
        
    std::string notDone = "It is NOT safe";
    return notDone;

}
void SafetyProcedure::displayFloorplan()
{
}
void SafetyProcedure::displayExitRoute()
{ 
}

struct CruiseShip
{
    Staff name;
    BuildSpecification buildSpecsOfShip;
    Entertainment typeOfEntertainment;
    Facilities typeOfFacilities;
    SafetyProcedure shipSafetyProcedure;

    void travelFor10DaysWithoutStopovers();
    void ferry5000Passengers();
    void sink(bool crashedIntoSomething);
};

void CruiseShip::travelFor10DaysWithoutStopovers()
{
}
void CruiseShip::ferry5000Passengers()
{
}
void CruiseShip::sink(bool crashedIntoSomething)
{
    if(crashedIntoSomething == true)
    {
        std::cout << "help help!";
    }
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
