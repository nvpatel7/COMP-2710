/* 
* Nikhil Patel (nvp0005@auburn.edu)
* Project File: project2_Patel_nvp0005.cpp
*
* Complile: g++ project2_Patel_nvp0005.cpp -o p2.out 	
* Run: ./p2.out 
*/

# include <iostream> 
# include <stdlib.h> 
# include <assert.h> 
# include <ctime> 

using namespace std;

// constant variables
const float aaronHitRate = 0.333333333;
const float bobHitRate = 0.5;
const float charlieHitRate = 1;

// prototypes
bool at_least_two_alive(bool,bool,bool);
void Aaron_shoots1(bool&,bool&);
void Bob_shoots(bool&,bool&);
void Charlie_shoots(bool&,bool&);
void Aaron_shoots2(bool&,bool&);


// function for at least 2 alive 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
      return true;
   }
   else {
      return false;
   }
}

// function for Aaron shooting strat 1
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
    bool hitTarget = false;
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < (aaronHitRate * 100)) {
        hitTarget = true;
    }

    // Charlie dead
    if (C_alive == true && hitTarget == true) {
        C_alive = false;
    }

    // Bob dead
   else if (B_alive == true && hitTarget == true) {
        B_alive = false;
    }
}

// function for Bob shooting
void Bob_shoots(bool& A_alive, bool& C_alive) {
    bool hitTarget = false;
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < (bobHitRate * 100)) {
        hitTarget = true;
    }


    // Charlie dead
   if (C_alive == true && hitTarget == true) {
        C_alive = false;
    }

    // Aaron dead
    else if (A_alive == true && hitTarget == true) {
        A_alive = false;
    }
}

// function for Charlie shooting
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    bool hitTarget = false;
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < (charlieHitRate * 100)) {
        hitTarget = true;
    }

   if (B_alive == true && hitTarget == true) {
      B_alive = false;
   }
   else if (A_alive == true && hitTarget == true) {
      A_alive = false;
   }
}

// function for Aaron shooting strat 2
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    bool hitTarget = false;
    int shoot_target_result = rand() % 100;

    if (shoot_target_result < (aaronHitRate * 100)) {
        hitTarget = true;
    }

    if (B_alive == true && C_alive && true) {
        return;
    }

    else {
        if (C_alive == true && hitTarget == true) {
            C_alive = false;
        } 

        else if (B_alive == true && hitTarget == true) {
            B_alive = false;
        }
    }
}

// test prototypes 
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

//tests two are alive
void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout <<"\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";

    cout <<"\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";
}

// tests aaron shooting strat 1
void test_Aaron_shoots1(void) {
    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
    bool bob_a = true;
    bool charlie_a = true;

    cout << "\tCase 1: Bob alive, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_a, charlie_a);
    assert(true == bob_a);

    bob_a = false;
    charlie_a = true;
    cout << "\tCase 2: Bob dead, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_a, charlie_a);
    assert(false == bob_a);

    bob_a = true;
    charlie_a = false;
    cout << "\tCase 3: Bob alive, Charlie dead \n"
        << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bob_a, charlie_a);
    assert(false == charlie_a);
}

// tests bob shooting function
void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

    bool aaron_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Aaron alive, Charlie alive \n"
        << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_a, charlie_a);
    assert(true == aaron_a);

    aaron_a = false;
    charlie_a = true;
    cout << "\tCase 2: Aaron dead, Charlie alive \n"
        << "\t\tBob is shooting at Charlie\n";
    Bob_shoots(aaron_a, charlie_a);
    assert(false == aaron_a);

    aaron_a = true;
    charlie_a = false;
    cout << "\tCase 3: Aaron alive, Charlie dead \n"
        << "\t\tBob is shooting at Aaron\n";
    Bob_shoots(aaron_a, charlie_a);
    assert(false == charlie_a);
}

//tests charlie shooting
void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    bool aaron_a = true;
    bool bob_a = true;
    cout << "\tCase 1: Aaron alive, Bob alive \n"
        << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_a, bob_a);
    assert(true == aaron_a);

    aaron_a = false;
    bob_a = true;
    cout << "\tCase 1: Aaron dead, Bob alive \n"
        << "\t\tCharlie is shooting at Bob\n";
    Charlie_shoots(aaron_a, bob_a);
    assert(false == aaron_a);

    aaron_a = true;
    bob_a = false;
    cout << "\tCase 1: Aaron alive, Bob dead \n"
        << "\t\tCharlie is shooting at Aaron\n";
    Charlie_shoots(aaron_a, bob_a);
    assert(false == bob_a);
}

//tests aaron shooting strat 2
void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    bool bob_a = true;
    bool charlie_a = true;
    cout << "\tCase 1: Bob alive, Charlie alive \n"
        << "\t\tAaron intentionally misses his first shot\n"
        << "\t\tBoth Bob and Charlie are Alive.\n";
    Aaron_shoots2(bob_a, charlie_a);
    assert(true == bob_a && charlie_a);

    bob_a = false;
    charlie_a = true;
    cout << "\tCase 2: Bob dead, Charlie alive \n"
        << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(bob_a, charlie_a);
    assert(false == bob_a);

    bob_a = true;
    charlie_a = false;
    cout << "\tCase 3: Bob alive, Charlie dead \n"
        << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bob_a, charlie_a);
    assert(false == charlie_a);
}

//Simple method to implement pause function in linux 
void Press_any_key(void); 

// pause function 
void Press_any_key(void) {
   cout << "Press any key to continue...\n";
   cin.get();
}

//main method
int main() {
    // intro message
    cout << "*** Welcome to Nikhil's Duel Simulator ***\n";

    //initialize random time
    srand(time(0));

    // calls to prototype testers
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();

   // variable for total runs (10000) 
   const int TOTAL_RUNS = 10000;

   //ready to test strat 1
   cout << "Ready to test strategy 1 (run " << TOTAL_RUNS << " times):\n";

   Press_any_key();

   bool aaronAlive;
   bool bobAlive;
   bool charlieAlive;

   int aaronWins1 = 0;
   int bobWins1 = 0;
   int charlieWins1 = 0;

   for(int i = 0; i < TOTAL_RUNS; i++) {
       aaronAlive = true;
       bobAlive = true;
       charlieAlive= true;

       //duel
       while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
           if(aaronAlive) {
               Aaron_shoots1(bobAlive, charlieAlive);
           }

           if(bobAlive) {
               Bob_shoots(aaronAlive,charlieAlive);
           }

           if(charlieAlive) {
               Charlie_shoots(aaronAlive, bobAlive);
           }
       }

       // counts the wins
       if(aaronAlive) {
           aaronWins1++;
       }

       if(bobAlive) {
           bobWins1++;
       }

       if(charlieAlive) {
           charlieWins1++;
       }
   }

   cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / 
      TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bobWins1 << "/10000 duels or " << static_cast<double>(bobWins1) / TOTAL_RUNS 
      * 100 << "%\n" 
      << "Charlie won " << charlieWins1 << "/10000 duels or " << static_cast<double>(charlieWins1) / 
      TOTAL_RUNS * 100 << "%\n" << endl;

    //starts strategy 2 to run 10,000 times 
    cout << "Ready to test strategy 2 (run " << TOTAL_RUNS << " times):\n";

   Press_any_key();

   int aWins2 = 0;
   int bWins2 = 0;
   int cWins2 = 0;

   for(int i = 0; i < TOTAL_RUNS; i++) {

      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;

       //duel
       while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
           if(aaronAlive) {
               Aaron_shoots2(bobAlive, charlieAlive);
           }

           if(bobAlive) {
               Bob_shoots(aaronAlive,charlieAlive);
           }

           if(charlieAlive) {
               Charlie_shoots(aaronAlive, bobAlive);
           }
       }

       // counts the wins
       if(aaronAlive) {
           aWins2++;
       }

       if(bobAlive) {
           bWins2++;
       }

       if(charlieAlive) {
           cWins2++;
       }
   }


   cout << "Aaron won " << aWins2 << "/10000 duels or " << static_cast<double>(aWins2) / 
      TOTAL_RUNS * 100 << "%\n" 
      << "Bob won " << bWins2 << "/10000 duels or " << static_cast<double>(bWins2) / TOTAL_RUNS 
      * 100 << "%\n" 
      << "Charlie won " << cWins2 << "/10000 duels or " << static_cast<double>(cWins2) / 
      TOTAL_RUNS * 100 << "%\n" << endl;

    if(aWins2 < aaronWins1) {
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    else {
        cout << "Strategy 2 is better than strategy 1.\n";
    }

    return 0;


}