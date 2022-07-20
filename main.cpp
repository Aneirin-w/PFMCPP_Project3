/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */











 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
        This technique of having multiple functions with the same name and different function arguments is known as 'function overloading' or 'overloaded functions'.
        This topic will be covered in Chapter 4 Part 7.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) replace your main() with the main() below.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.
    Do not change any values being passed into the functions.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!





*/

#include <iostream>

int main()
{   
    //testing instruction 0
    HeapA heapA; 

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

        // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;
       
    std::cout << "---------------------\n" << std::endl; 
    
    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl; 
    
    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl; 

    std::cout << "good to go!\n";

    return 0;
}



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
