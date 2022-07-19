/*
Project 3 - Part 1e / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3.  
Part1 will be broken up into 5 separate steps
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

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

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

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

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function.  it has multiple arguments, some with default values.
        //the parameter names are related to the work the function will perform.
        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};

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
    3) they can swim
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
    // they can swim
    void theyCanSwim(StaffWelfare swim);
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
    void materialUsed();
    // describe weight of ship
    double weightOfShip(double weightOfMaterials, int avgWeightOfPassengers, int maxCapacityOfPassengers);
    // show building project date 
    void buildingProjectDate(std::string startDate, std::string endDate);
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
    2) family friendly
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
    // family friendly
    void familyFriendly();
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
    3) shopping complex opens all day
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
    // shopping complex opens all day
    void shoppingComplexOpensAllDay();
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
