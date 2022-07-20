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


/* Thing 1) Audio Interface
5 properties:
    1) number of ADAT inputs (int)
    2) number of XLR inputs (int)
    3) number of headphone outputs (int)
    4) percentage of THD at 1kHz of the line outputs (float)
    5) amount of watts required to operate (float)
3 things it can do:
    1) link analogue channel 1 and 2 together
    2) adjust the playback level of main
    3) mute the main monitors
*/
#include <iostream>
#include <string>

struct AudioInterface
{
    // number of ADAT inputs
    int numOfAdatInput = 2;
    // number of XLR inputs
    int numOfXlrInputs = 4;
    // number of headphone outputs
    int numOfHeadphonesOutputs = 6;
    // percentage of THD at 1kHz of the line outputs
    float percentageOfTHD = 0.0001f;
    // amount of watts required to operate
    float amountOfWattsRequired = 29.5f;

    // link analogue channel 1 and 2 together
    void linkAnalogueChannels1And2();
    // adjust the playback level of main
    void mainsPlaybackLevel(int displayLevel);
    // mute the main monitors
    void muteMainMonitors(bool pressMuteButton);
};

/*
Thing 2) cafe
5 properties:
    1) number of staff working (int)
    2) number of tables used (int)
    3) amount of food wastage in KG (double)
    4) soup of the day (std::string)
    5) average cost of a meal in dollars (double)
3 things it can do:
    1) serve speciality drinks
    2) provide table service
    3) serve vegan food
 */

struct Cafe 
{
    // number of staff working
    int numOfStaffWorking = 25;
    // number of tables used
    int numOfTablesUsed = 100;
    // amount of food wastage in KG
    double amountOfFoodWastageInKg = 3;
    // soup of the day (std::string)
    std::string soupOfTheDay = "Onion Soup";
    // average cost of a meal in dollars (double)
    double avgCostPerMealInDollars = 12.99;

    struct RentalCost
    {
        int areaInMetreCube = 10000;
        bool doesItNeedRenovation = true;
        double expectedNumOfCustomersPerDay = 73.5;
        std::string address = "Sesame Street";
        std::string minimumTenancyPeriod = "5 Years";
        double costToRenovate(); //returns the cost of renovation
        void expectedTime(int numOfWorkers = 10, int numOfHoursWorkedPerDay = 10, int offDays = 6);
    };

    // serve speciality drinks
    void serveSpecalityDrinks (int price, bool drinkIsAvailable);
    // provide table service
    void provideTableService (RentalCost price, int serviceCharge, double waiterTips);
    // serve vegan food
    void serveVeganFood (double additionalCharge);
};

/*
Thing 3) iphone
5 properties:
    1) amount of storage space (float)
    2) screen refresh rate (int)
    3) number of speakers (int)
    4) value of camera megapixels (double)
    5) cost of the phone (double)
3 things it can do:
    1) make a phone call
    2) browse the internet
    3) download mobile applications
 */

struct Iphone
{
    // amount of storage space
    float StorageSpaceInTeraByte = 3.44f;
    // screen refresh rate (int)
    int screenRefreshRate = 1000;
    // number of speakers
    int numOfSpeakers = 3;
    // value of camera megapixels
    double cameraMegapixel = 20.2;
    // cost of the phone
    double costOfPhone = 5003.99;

    // make a phone call
    void makePhoneCall(bool overseasCall);
    // browse the internet
    void browseTheInternet();
    // download mobile applications
    auto downloadMobileApplication(std::string mobileAppName); //returns name of mobile application to download.
};

/*
Thing 4) midi keyboard
5 properties:
    1) velocity of keybeds (int)
    2) number of keys (int)
    3) brand (std::string)
    4) number of rotary control (int)
    5) weight (double)
3 things it can do:
    1) use it as a classic keyboard
    2) transpose in octaves
    3) midi link to other midi devices
*/

struct MidiKeyboard
{
    // velocity of keybeds
    int velocityOfKeybeds = 127;
    // number of keys
    int numOfKeys = 88;
    // brand
    std::string brand = "Roland";
    // number of rotary control
    int numOfRotaryControl = 10;
    // weight
    double weightInKg = 2.5;

    // use it as a classic keyboard
    void useAsKeyboard(bool pianoSound);
    // transpose in octaves
    int transposeInOctaves(int octave); //returns how many octave it transposes.
    // midi link to other midi devices
    void midiLinkToOtherDevice(bool externallMidiDeviceConnected);
};

/*
Thing 5) Staff
5 properties:
    1) number of engineering staff (int)
    2) colour of uniform (std::string)
    3) age (int)
    4) gender (bool)
    5) wages (double)
3 things it can do:
    1) fix technical issues on board
    2) serve customers
    3) purchase with staff discount
 */

struct Staff
{
    // number of engineering staff
    int numOfEngineeringStaff = 30;
    // colour of uniform
    std::string colourOfUniform = "Dark Blue";
    // age
    int age = 30;
    // gender
    bool genderIsMale = 1;
    // wages
    double wages = 2222.22;

    struct StaffWelfare
    {   
        int numberOfMealsPerDay = 4;
        bool didTheyWorkMoreThan6Hours = true;
        int numOfOffDays = 2;

        int percentageOfTips(int customersServed, int hoursWorked); //returns percentage of tips the staff can earn.
        void sickDays(int daysStatedInContract);
    };
    
    // fix technical issues on board
    void fixTechnialIssuesOnBoard (int numOfStaffRequired);
    // serve customers
    void serveCustomers();
    // purchase with staff discount
    void purchaseWithStaffDiscount(StaffWelfare discount);
};

/*
Thing 6) BuildSpecification
5 properties:
    1) tons of steel used (double)
    2) company materials were bought from (std::string)
    3) volume of ship in m3 (float)
    4) total weight in tons (double)
    5) imported materials (std::string)
3 things it can do:
    1) describe material used
    2) describe weight of ship
    3) show building project date
 */

struct BuildSpecification
{
    // tons of steel used
    double tonsOfSteelUsed = 23.59;
    // company materials were bought from
    std::string companyMaterialsWereBoughtFrom = "Very good stuff";
    // volume of ship in m3
    float volOfShipInMetreCube = 59834.34f;
    // total weight in tons 
    double totalWeightInTons = 493.34;
    // imported materials
    std::string importedMaterials = "aluminium";

    // describe material used
    void describeMaterialUsed();
    // describe weight of ship
    double displayWeightOfShip(double weightOfMaterials, int avgWeightOfPassengers, int maxCapacityOfPassengers);
    // show building project date 
    void showBuildingProjectDate(std::string startDate, std::string endDate);
};

/*
Thing 7) Entertainment
5 properties:
    1) name of act (std::string)
    2) cost of hire (double)
    3) allocated time (std::string)
    4) number of performers (int)
    5) location of performance (std::string)
3 things it can do:
    1) do acrobats
    2) perform with audience
    3) work for long haul
 */

struct Entertainment
{
    // name of act
    std::string nameOfAct = "WOW";
    // cost of hire
    double costOfHire = 2359.23;
    // allocated time
    std::string allocatedTime = "2pm - 5pm everyday";
    // number of performers
    int numOfPerformers = 7;
    // location of performance
    std::string locationOfPerformance = "Sky Deck";

    // do acrobats
    bool doAcrobats(bool safetyEquipmentIsPresent); //returns if they are able to perform acrobats.
    // perform with audience
    void performWithAudience();
    // work for long haul
    void workForLongHaul();
};

/*
Thing 8) Facilities
5 properties:
    1) size of swimming pool in hectars (float)
    2) number of shops opened 24/7 (int)
    3) opening hours of spa (std::string)
    4) number of gym equipment (int)
    5) number of restauruants available (int)
3 things it can do:
    1) keep passengers busy
    2) entertain children
    3) allow passengers to relax
 */

struct Facilities
{
    // size of swimming pool in hectars
    float sizeOfPoolInHectars = 200;
    // number of shops opened 24/7
    int numOfShopsOpened24_7 = 20;
    // opening hours of spa
    std::string openingHoursOfSpa = "10am - 10pm";
    // number of gym equipment
    int numOfGymEquipment = 40;
    // number of restauruants available
    int numOfRestauruantsAvailable = 25;

    // keep passengers busy
    void keepPassengersBusy(int activitiesPlanned);
    // entertain children
    void entertainChildren(int dayCareServiceSlots);
    // allow passengers to relax
    void allowPassengersToRelax(int numOfRelaxingSongInPlaylist);
};

/*
Thing 9) SafetyProcedure
5 properties:
    1) number of floors (int)
    2) number of personnel on board (int)
    3) number of lifeboats (int)
    4) helpline number (int)
    5) meeting point (char)
3 things it can do:
    1) inform crew and passengers safety information
    2) display floorplan
    3) display exit route
 */

struct SafetyProcedure
{
    // number of floors
    int numOfFloors = 6;
    // number of personnel on board
    int numOfPersonnelOnBoard = 1500;
    // number of lifeboats
    int numOfLifeboats = 80;
    // helpline number (int)
    int helplineNum = 10291092;
    // meeting point
    char meetingPoint = 'C';

    // inform crew and passengers safety information
    bool informSafetyInformation(bool SentViaEmail, bool broadcastedOnPA); //returns if information has been shared.
    // display floorplan
    bool displayFloorplan(); //returns if floorplan has been displayed.
    // display exit route
    bool displayExitRoute(); //returns if exit route has been displayed.
};

/*
Thing 10) Cruise Ship
5 properties:
    1) Staff
    2) BuildSpecifications
    3) Entertainment
    4) Facilities
    5) SafetyProcedure
3 things it can do:
    1) travel for 10 days without stopovers
    2) ferry 5000 passengers
    3) sink
 */

struct CruiseShip
{
    Staff name;
    BuildSpecification buildSpecsOfShip;
    Entertainment typeOfEntertainment;
    Facilities typeOfFacilities;
    SafetyProcedure shipSafetyProcedure;

    // travel for 10 days without stopovers
    void travelFor10DaysWithoutStopovers();
    // ferry 5000 passengers
    void ferry5000Passengers();
    // sink
    void sink(bool crashedIntoSomething);
};


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
