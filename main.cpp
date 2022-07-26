 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int age;
    int height;
    float hairlength;
    float GPA;
    unsigned int SATScore;
    int distanceTravelled;
    int totalTime;

    struct Foot
    {
    int strideDistance = 3;
    int avgStepSize;

    void stepForward();
    int stepSize();
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
    {
    }
int Person::Foot::stepSize()
    {
        return avgStepSize;
    }

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTravelled += leftFoot.stepSize() + rightFoot.stepSize();
    howFast = distanceTravelled / totalTime;
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

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
void::BuildSpecification::describeMaterialUsed()
    {
    }
double::BuildSpecification::displayWeightOfShip(double weightOfMaterials, int avgWeightOfPassengers, int maxCapacityOfPassengers)
    {
        double weightOfShip = weightOfMaterials + avgWeightOfPassengers + maxCapacityOfPassengers;
        return weightOfShip;
    }
void::BuildSpecification::showBuildingProjectDate(std::string startDate, std::string endDate)
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
        else     
        {
            std::string cancellation = "Performance Cancelled";
            return cancellation;
        }
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

auto::SafetyProcedure::informSafetyInformation(bool broadcastedOnPA)
    {
        if (broadcastedOnPA == true)
        {
            std::string done = "It is safe";
            return done;
        }
        else
        {
            std::string notDone = "It is NOT safe";
            return notDone;
        }
    }
void::SafetyProcedure::displayFloorplan()
    {
    }
void::SafetyProcedure::displayExitRoute()
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

void::CruiseShip::travelFor10DaysWithoutStopovers()
    {
    }
void::CruiseShip::ferry5000Passengers()
    {
    }
void::CruiseShip::sink(bool crashedIntoSomething)
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
    std::cout << "good to go!" << std::endl;
}
