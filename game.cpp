#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;
int main()
{
    srand(static_cast<unsigned int>(time(0)));

    vector<string> HPpotionBelt;
    HPpotionBelt.push_back("HP Potion");
    vector<string> season;
    season.push_back("spring");
    season.push_back("summer");
    season.push_back("fall");
    season.push_back("winter");
    vector<string> jobclass;
    jobclass.push_back("warrior");
    jobclass.push_back("mage");
    jobclass.push_back("thief");
    jobclass.push_back(("godmode"));
    string myClass;
    vector<string> help;
    help.push_back("HP = Hit points");
    help.push_back("MP = Mana points");
    help.push_back("Str = Strength");
    help.push_back("Int = Intelligence");
    help.push_back("Agl = Agility");
    help.push_back("Att = Attack");
    help.push_back("Spl Dmg = Spell Damage");
    help.push_back("Mass = Unit Weight");
    help.push_back("Crit = Critical Chance");
// base stats for classes
    const int baseHealth = 50;
    const int baseMana = 50;
    const int baseStr = 15;
    const int baseInt = 15;
    const int baseAgl = 15;
    const int baseMass = 5;
    const int baseAtt =  5;
    const int baseSplDmg = 5;
    const int baseDef = 5;
    const int baseCrit = 10;
    int heroLevel = 1;
    int heroHealth, heroMana = baseHealth;
    int heroMaxHealth = 0;
    int heroMaxMana = 0;
    int heroStr, heroInt, heroAgl = baseStr;
    int heroMass = baseMass;
    int heroCrit = baseCrit;
// stats for attack spell damage and defense
    int heroAtt = heroStr / 3;
    int heroAttDmg = 0;
    int heroSplDmg = heroInt / 2;
    int heroDef = baseDef;

    string heroName;
    int randomNumber = (rand() % season.size());

// orc stats
    const int orcBaseHealth = 200;
    const int orcBaseMana = 150;
    const int orcBaseStr = 70;
    const int orcBaseInt = 10;
    const int orcBaseAgl = 45;
    const int orcBaseSplDmg = 10;
    const int orcBaseMass = 50;
    const int orcBaseCrit = 10;
    int orcHealth = orcBaseHealth;
    int orcMana = orcBaseMana;
    int orcStr = orcBaseStr;
    int orcInt = orcBaseInt;
    int orcAgl = orcBaseAgl;
    int orcSplDmg = orcBaseSplDmg;
    int orcMass = orcBaseMass;
    int orcCrit = orcBaseCrit;

// rat stats
    int ratsKilled = 0;
    const int ratBaseHealth = 10;
    const int ratBaseStr = 5;
    const int ratBaseAtt = 10;
    const int ratBaseDef = 2;
    const int ratBaseAgl = 10;
    const int ratBaseMass = 1;
    int ratHealth = ratBaseHealth;
    int ratStr = ratBaseStr;
    int ratAtt = 10;
    int ratDef = ratBaseDef;
    int ratAgl = ratBaseAgl;
    int ratMass = ratBaseMass;

// spider stats
    const int spiderBaseHealth = 25;
    const int spiderBaseStr = 5;
    const int spiderBaseAtt = 15;
    const int spiderBaseDef = 5;
    const int spiderBaseAgl = 15;
    const int spiderBaseMass = 1;
    int spidersKilled = 0;
    int spiderHealth = spiderBaseHealth;
    int spiderStr = spiderBaseStr;
    int spiderAtt = spiderBaseAtt;
    int spiderDef = spiderBaseDef;
    int spiderAgl = spiderBaseAgl;
    int spiderMass = spiderBaseMass;

// potion stuff
    bool firstHPupgrade = false;
    int potionStrBase = 20;
    int potionStr = potionStrBase;
    int HPpotCost = 20;
// misc information camps, season, other features



// exp table generator for the levels
         vector<int> expTable;
            int expReq = 1;
            for (int i = 1; i < 25; ++i)
            {
                expReq += i * 75;
                expTable.push_back(expReq);

            }

    string currentSeason = season[randomNumber];

    int moneyFoundBase = 10;
    int moneyFound = moneyFoundBase;

    const int NUM_CAMPS = 4;
    int campsDestroyed = 0;
    const int CAMPS[NUM_CAMPS] = {0, 1, 2, 3};
    int experience = 1;
    int money = 0;
// enter name loop
    bool nameSelect = false;
    char nameFinal;
    cout << "\t\t Welcome to Fancy RPG!\n\n";
    while (nameSelect == false)
    {

        cout << "Enter your name: " << endl;
        cin >> heroName;
        cout << "Is this your characters name?: " << heroName << "\n(y/n): ";
        cin >> nameFinal;
        cout << "\n\n";

        if (nameFinal == 'n')
        {
            nameSelect = false;
        }
        else if (nameFinal == 'y')
        {
            nameSelect = true;
        }
        else
        {
            cout << "Not a valid selection." << endl;
        }

    }



    bool classLoop = true;
    while (classLoop == true)
    {
// this chunk resets everything back to zero so its not addd to it self each time user rejects
        heroHealth = baseHealth;
        heroMana = baseMana;
        heroStr = baseStr;
        heroAgl= baseAgl;
        heroInt = baseInt;
        heroAtt = baseAtt;
        heroDef = baseDef;
        heroMass = baseMass;
        heroCrit = baseCrit;
        cout << "Choose your class: \n";
        cout << "\n1 - Warrior\n2 - Mage\n3 - Thief\n4 - Help" << "\n\n";
        int classChoice = 0;
        cin >> classChoice;
// assign job class and do rolls for health, mana, ect. confirm from user
        if (classChoice == 1)
        {   myClass = jobclass[0]; // warrior class
            randomNumber = rand();
            heroHealth += (rand() % (baseHealth/2));
            heroMaxHealth = heroHealth;
            heroMana += (rand() % (baseMana/5));
            heroMaxMana = heroMana;
            heroStr += (rand() % (baseStr + 10));
            heroInt += (rand() % baseInt % 10);
            heroAgl += (rand() % (baseAgl));
            heroAtt = (heroStr + (rand() % (heroStr - 5)));
            heroSplDmg = (rand() % (heroInt / 2));
            heroMass = ((rand() % 5) + (baseMass * 5));
            heroDef = ((heroStr / 2) + baseDef + (heroMass / 2) - 3);
            heroCrit = baseCrit;

        }
        else if (classChoice == 2) //mageclass
        {   myClass = jobclass[1];
            heroHealth += (rand() % baseHealth/5);
            heroMana += (rand() % baseMana/2);

            heroStr += (rand() % baseStr);
            heroInt += (rand() % baseInt + 15);
            heroAgl += (rand() % baseAgl);
            heroSplDmg = (heroInt + (rand() % (heroInt - 5)));

            heroAtt = (heroStr + (rand() % (heroStr - 5)));
            heroMass = (baseMass + (rand() % 3));
            heroDef = ((heroStr / 2) + baseDef + (heroMass / 2) - 10);
            heroCrit = baseCrit / 2;
        }
        else if (classChoice == 3)// thief class
        {   myClass = jobclass[2];
            heroHealth += (rand() % baseHealth/3);
            heroMana += (rand() % baseMana/3);
            heroStr += (rand() % baseStr + 10);
            heroInt += (rand() % baseInt);
            heroAgl += (rand() % baseAgl + 10);
            heroSplDmg = (heroInt + (rand() % (heroInt - 5)));

            heroAtt = (heroStr + (rand() % (heroStr - 5)));

            heroMass = (baseMass * 2) + (rand() % 3);
            heroDef = ((heroStr / 2) + baseDef + (heroMass / 2) - 8);
            heroCrit = baseCrit * 2;
        }

                else if (classChoice == 9) //cheatClass
        {   myClass = jobclass[3];
            heroHealth = 9999;
            heroMana = 9999;

            heroStr = 9999;
            heroInt = 9999;
            heroAgl = 9999;
            heroSplDmg = 9999;

            heroAtt = 9999;
            heroMass = 9999;
            heroDef = 9999;
            heroCrit = 9999;
            heroName = "GodMode";
            money = 99999;
        }
        else if (classChoice == 4)//help menu
        {
            for(unsigned int i = 0; i < help.size(); ++i)
            {
                cout << help[i] << endl;
            }
        }
        if (classChoice != 4)
        {
        cout << "\nHP: " << heroHealth << "\nMP: " << heroMana << "\nStr: " << heroStr;
        cout << "\nInt: " << heroInt << "\nAgl: " << heroAgl << "\nDef: " << heroDef;
        cout << "\nAtt: " << heroAtt << "\nSplDmg: " << heroSplDmg;
        cout << "\nMass: " << heroMass << "\nCrit: " << heroCrit << endl;

        cout << "\nIs this roll ok?\n(y/n)" << endl;
        char classYn;
        cin >> classYn;
        if (classYn == 'y')
        {
            classLoop = false;
        }
    }

        cout <<"\n\n\n\n";


  } // class loop bracket

// after character creation
    cout << "\n\n";
    cout << "=========================================================================================================================================================" << endl;
    cout << "You arrive at a village surrounded by a forest. As you approach the entrance,\nthey nearly pelt you with arrows." << endl;
    cout << "They offer you gold if you destroy the 3 orc camps in the forest" << endl;
    cout << "surrounding the village. You accept their offer" << endl;
    cout << "=========================================================================================================================================================" << endl;
    cout <<"\n\nYou enter the village." << "\n\n";
    bool alive = true;
    bool inVillage = true;
    int currentCamp = 1;
    int lvl1SewKills = 0;

    while (alive == true )
    {
        cout <<"________________________________________________________________" << endl;
        cout << "\n1 - Train in Sewers\n2 - Shop\n3 - Status\n4 - Attack Camp " << currentCamp << endl;


        bool inShop = true;
        bool inSewer = true;
        int villageChoice = 0;
        cin >> villageChoice;

        if(villageChoice == 1)
        {
            while (inSewer == true && alive == true)
            {
            cout <<"\t __________________________" << endl;
            cout << "\tYou have entered the sewers." << "\n\n";
            villageChoice = 0; // setting to zero so it dont loop...hopefully
            int sewChoice = 0; // for choosing different level sewers after kill# is met.
            cout << "\n1 - Sewers L1" << endl;
            cout << "Enter 1 to continue or 2 to go back." << endl;
            int goBack = 0;

            cin >> goBack;
                    if (goBack == 2)
                    {
                        villageChoice = 0;

                        inSewer = false;
                    }

            if (lvl1SewKills >= 0 && inSewer == true)
            {
                int randCreatlvl1 = (rand() % 2)+1;

                cout << "\n\n======================\n";
                cout << "       Sewers L1" << endl;
                cout << "======================\n\n";

                int ratHealth, ratStr, ratAgl, ratMass = 0;
                int ratAttDmg = 0;

                ratHealth = (rand() % ratBaseHealth) + 2;
                int ratMaxHealth = ratHealth;
                ratStr = (rand() % ratBaseStr)+ 5;
                ratAgl = (rand() % ratBaseAgl)+1;
                ratMass = (rand() % ratBaseMass)+1;
                ratDef = (rand() % ratBaseDef)+1;
                ratAtt = (rand() % (ratBaseAtt + ratStr) + 5);
                bool ratAlive = true;
                alive = true;

                bool firstStrike = true;
                bool ratKingInt = true;
                if (randCreatlvl1 == 1)
                    {
                     while(ratAlive == true && alive == true)
                     {

                        if (ratAgl > heroAgl && firstStrike == true)
                        {
                            cout << "\t\tYou've encountered a rat!" << "\n\n";
                            ratAttDmg = (rand() % (ratAtt - heroDef));
                            cout << "The rat strikes first for " << ratAttDmg << " damage." << endl;
                            heroHealth = heroHealth - ratAttDmg;
                            firstStrike = false;
                        }

                        if (ratsKilled == 50 && ratKingInt == true)
                        {


                            cout << "You have encountered the King Rat!!!!!" << endl;
                            cout << "It turns from its feast on a dog and glares at you before charging." << endl;
                            ratHealth = 500;
                            ratMaxHealth = 500;
                            ratKingInt = false;

                        }


                        cout << "HP: " << heroHealth << "/" << heroMaxHealth;
                        cout << "\tMP: " << heroMana << "/" << heroMaxMana;
                        cout << "\nRat HP: " << ratHealth << "/" << ratMaxHealth << endl;
                        cout <<"===================================";
                        cout << "\n\n1 - Attack\n2 - Magic\n3 - Potion Belt" << endl;
                        int battleOpt = 0;
                        cin >> battleOpt;

                        if(battleOpt == 1)
                        {

                            heroAttDmg = 0;
                            heroAttDmg += (rand() % (heroAtt - ratDef));
                            if (heroAttDmg < 0)
                            {
                                heroAttDmg = 0;
                            }
                            ratHealth -= heroAttDmg;
                            if (ratHealth < 0 || ratHealth == 0)
                            {
                                experience += ratMaxHealth;
                                ratHealth = 0;
                                moneyFound = rand() % moneyFoundBase;
                                if (ratKingInt  == false)
                                {
                                    potionStr += 20;
                                    moneyFound = 500;
                                    cout << "You gained 500 exp!!" << endl;
                                    cout << "Potions are now twice as effective!!" << endl;
                                }
                                money += moneyFound;
                                ratsKilled += 1;
                                ratAlive = false;

                            }
                            cout << heroName << " hits the rat for " << heroAttDmg << " damage." << endl;
                        }
                        if(battleOpt == 2)
                        {
                            cout << "Magic isnt completed yet." << endl;
                        }

                        if(battleOpt == 3)
                        {
                            bool potEmpty = false;
                            bool isMaxHealth = false;
                            if (heroHealth == heroMaxHealth)
                            {
                                isMaxHealth = true;
                            }
                            if (isMaxHealth == true)
                            {
                                cout << "\n*You have full health.*\n" << endl;
                            }

                            if(HPpotionBelt.empty()) // include mana potions
                            {
                            cout <<"\nYou dont have any potions to use." << endl;
                            potEmpty = true;

                           }
                            if (!potEmpty && !isMaxHealth)
                           {


                            cout << "\nUse:\n1 - HP Potion Belt\n2 - MP Potion Belt" << endl;
                            int potMenu = 0;
                            cin >> potMenu;
                            if (potMenu == 1)
                            {
                                for (int i = 0; i < HPpotionBelt.size(); ++i)
                                {
                                    cout << i + 1 << ". " << "Potion - " << HPpotionBelt[i] << endl;
                                }
                                int potChoice = 0;
                                cin >> potChoice;
                                potChoice -= 1;
                                for (int i = 0; i < 1 ; ++i)
                                    {
                                        int x = potChoice;

                                        heroHealth += potionStr;

                                        if (heroHealth > heroMaxHealth)
                                        {
                                            int overHeal = 0;
                                            overHeal = heroMaxHealth - heroHealth;
                                            heroHealth = heroMaxHealth;
                                            cout << " " << overHeal << "\n**HP has been restored!**\n" << endl;
                                        }
                                        else
                                        {
                                        cout << "\n"  << potionStr << "**HP has been restored!**\n" << endl;
                                        }
                                        HPpotionBelt.erase(HPpotionBelt.begin()+ x);
                                    }
                            }

                           }//ELSE POTION basically, yourable to use potions


                        }//battleopt3 end loop AKA items

//while rat alive loop

                        ratAttDmg = (rand() % (ratAtt - heroDef));
                        if( ratHealth <= 0)
                        {
                            ratAttDmg = 0;
                            cout << "The Rat falls over." << endl;
                            cout << "You found " << moneyFound << " Gold." << endl;
                        }
                        else
                        {
                            heroHealth = heroHealth - ratAttDmg;

                            cout << "The rat bites you for " << ratAttDmg << " damage." << endl;
                        }
                        if (heroHealth <= 0)
                        {
                            heroHealth = 0;
                            alive = false;
                        }


                     }// ratlive while loop copy to here for capypasta


                    }// lvl1  random creature sewers lvl loop

////////////////////////////////////////////SPIDERSPIDERSPIDERSPIDER

                int spiderAttDmg = 0;

                spiderHealth = (rand() % spiderBaseHealth) + 10;
                int spiderMaxHealth = spiderHealth;
                spiderStr = (rand() % spiderBaseStr)+ 5;
                spiderAgl = (rand() % spiderBaseAgl)+1;
                spiderMass = (rand() % spiderBaseMass)+1;
                spiderDef = (rand() % spiderBaseDef)+1;
                spiderAtt = (rand() % (spiderBaseAtt + spiderStr) + 5);
                bool spiderAlive = true;
                alive = true;

                firstStrike = true;

                if (randCreatlvl1 == 2)
                    {
                     while(spiderAlive == true)
                     {

                        if (spiderAgl > heroAgl && firstStrike == true)
                        {
                            cout << "\t\tYou've encountered a giant spider!" << "\n\n";
                            spiderAttDmg = (rand() % (spiderAtt - heroDef));
                            cout << "The spider strikes first for " << spiderAttDmg << " damage." << endl;
                            heroHealth = heroHealth - spiderAttDmg;
                            firstStrike = false;
                        }




                        cout << "HP: " << heroHealth << "/" << heroMaxHealth;
                        cout << "\tMP: " << heroMana << "/" << heroMaxMana;
                        cout << "\nSpider HP: " << spiderHealth << "/" << spiderMaxHealth << endl;
                        cout <<"===================================";
                        cout << "\n\n1 - Attack\n2 - Magic\n3 - Potion Belt" << endl;
                        int battleOpt = 0;
                        cin >> battleOpt;

                        if(battleOpt == 1)
                        {

                            heroAttDmg = 0;
                            heroAttDmg += (rand() % (heroAtt - spiderDef));
                            if (heroAttDmg < 0)
                            {
                                heroAttDmg = 0;
                            }
                            spiderHealth -= heroAttDmg;
                            if (spiderHealth < 0 || spiderHealth == 0)
                            {
                                experience += spiderMaxHealth;
                                spiderHealth = 0;
                                moneyFound = (rand() % moneyFoundBase) + 5;
                                money += moneyFound;
                                spiderAlive = false;

                            }
                            cout << heroName << " hits the spider for" << heroAttDmg << " damage." << endl;
                        }
                        if(battleOpt == 2)
                        {
                            cout << "Magic isnt completed yet." << endl;
                        }

                        if(battleOpt == 3)
                        {
                            bool isMaxHealth = false;
                            if (heroMaxHealth == heroHealth)
                            {
                                isMaxHealth = true;
                            }
                            if (isMaxHealth == true)
                            {
                                cout << "\n*You have full health.*\n" << endl;
                            }

                           else if(HPpotionBelt.empty()) // include mana potions
                           {
                            cout <<"\nYou dont have any potions to use." << endl;
                           }
                           else
                           {


                            cout << "\nUse:\n1 - HP Potion Belt\n2 - MP Potion Belt" << endl;
                            int potMenu = 0;
                            cin >> potMenu;
                            if (potMenu == 1)
                            {
                                for (int i = 0; i < HPpotionBelt.size(); ++i)
                                {
                                    cout << i + 1 << ". " << "Potion - " << HPpotionBelt[i] << endl;
                                }
                                int potChoice = 0;
                                cin >> potChoice;
                                potChoice -= 1;
                                for (int i = 0; i < 1 ; ++i)
                                    {
                                        int x = potChoice;
                                        heroHealth += potionStr;
                                        cout << " "  << potionStr << "\n**HP has been restored!**\n" << endl;
                                        HPpotionBelt.erase(HPpotionBelt.begin()+ x);
                                    }
                            }

                           }//ELSE POTION basically, yourable to use potions


                        }//battleopt3 end loop AKA items

//while rat alive loop

                        spiderAttDmg = (rand() % (spiderAtt - heroDef));
                        if( spiderHealth <= 0)
                        {
                            spiderAttDmg = 0;
                            cout << "The giant spider curls up." << endl;
                            cout << "You found " << moneyFound << " Gold." << endl;
                        }
                        else
                        {
                            heroHealth = heroHealth - spiderAttDmg;

                            cout << "The spider bites you for " << spiderAttDmg << " damage." << endl;
                        }
                        if (heroHealth <= 0)
                        {
                            heroHealth = 0;
                            alive = false;
                        }


                     }// spiderlive while loop copy to here for capypasta


                    }// 2  random creature sewers lvl loop







            }//lvl 1 sewer kills > = and inswer true
            }//end of village choice 1
}




    if (villageChoice == 2) //the one stop shop
    {
        while (inShop == true)
        {

        cout << "\n\nWelcome to the Village Store!" << endl;
        cout << "___________________________________________" << endl;
        cout << "\n1 - Weapons/Armor\n2 - Potions\n3 - Misc\n4 - Exit" << endl;
        int shopChoice = 0;
        cin >> shopChoice;
        if (shopChoice == 1)
        {
            cout << "\n1 - Weapon\n2 - Armor\n3 - Exit" << endl;
            int wepArmChoice = 0;
            cin >> wepArmChoice;
            if(wepArmChoice == 1)
            {
                cout << " \nAxe , sword, mace, ect" << endl;
            }
            if(wepArmChoice == 2)
            {
                cout << " \nChainmail, Plate, shield, ect" << endl;
            }

        }
        if (shopChoice == 2)
        {
            cout <<"\n1 - HP Potion " << HPpotCost << "G\n2 - MP Potion 15G\n3 - Exp Potion 500G" << endl;
            int potChoice = 0;
            cin >> potChoice;
            if (potChoice == 1)
            {
                cout << " How many? " << endl;
                int potAmount = 0;
                cin >> potAmount;
                int tempMoney = money;

                                if (firstHPupgrade == false && ratsKilled > 50)
                            {
                                    HPpotCost = 50;
                                    firstHPupgrade = true;
                            }
                int totalPrice = potAmount * HPpotCost;
                if(money < totalPrice)
                {
                    cout <<"You don't have enough money for that!\nEnter to continue..." << endl;
                }
                else
                {
                  for (int x = 0; x < potAmount; ++x)
                  {
                    HPpotionBelt.push_back("HP Potion");

                    money -= HPpotCost;
                  }

                }
            }// pot choice 1

        }//shop Choice 2
        if (shopChoice == 3)
        {
            cout <<"\nMisc items not done yet" << endl;
        }

        if (shopChoice == 4)
        {
            inShop = false;
        }
    }// while in shop

   }//village choice 2

    bool inStatus = true;

    if (villageChoice == 3) // status
    {
        while (inStatus == true)
        {

                    int requiredExp = expTable[heroLevel];
        cout << "=======================================================" << endl;
        cout << "\tName: " << heroName << endl;
        cout << "\nHP:    " << heroHealth << "/" << heroMaxHealth << "\tMP:   " << heroMana << "/" << heroMaxMana;
        cout << "\nAtt:   " << heroAtt << "\tDef:  " << heroDef << "\nStr:   " << heroStr;
        cout << "\tInt:  " << heroInt << " \tAgl:  " << heroAgl;
        cout << "\nMass:  " << heroMass << " \tCrit: " << heroCrit << endl;
        cout << "\n\tGold: " << money << endl;
        cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        cout << "Level: " << heroLevel <<  "\tExperience: " << experience << "/" << requiredExp << endl;
        cout << "\n1 - Level Up\n2 - Inventory\n3 - Items\n4 - Exit" << endl;
        int statusChoice = 0;
        cin >> statusChoice;
        if (statusChoice == 1)
        {
            int preLvl = heroLevel;   // does a check so it gives response if not enough exp
// $exptable


            int requiredExp = expTable[heroLevel];


            if (experience >= requiredExp)
            {
                experience -= requiredExp;
                heroLevel += 1;
                if (myClass == jobclass[0])
                {
                    heroMaxHealth += 10;
                    cout <<"Health increased by: 10" << endl;
                    heroMaxMana +=3;
                    cout <<"Mana increased by: 3" << endl;
                    heroStr += 5;
                    cout <<"Str increased by: 5" << endl;
                    heroAgl += 3;
                    cout <<"Agl increased by 3" << endl;
                    heroInt += 1;
                    cout <<"Int increased by 1" << endl;
                    heroDef += 2;
                    cout <<"Def increased by 2" << endl;
                    heroAtt += 3;
                    cout <<"Att increased by 3" << endl;
                    heroHealth = heroMaxHealth;
                    heroMana = heroMaxMana;
                    cout <<"\nYou have been fully replenished." << endl;

                }
            }

        if (preLvl == heroLevel)
        {
            cout << "  *****You do not have enough experience to level up.*****" << endl;
        }
// $experience`
    } // new bracket for statusChoice 1

    else if (statusChoice == 2)
    {
        if (!HPpotionBelt.empty())
        {
            cout << "Potion Belt:\n\n " << endl;
            for(unsigned int i = 0; i < HPpotionBelt.size(); ++i)
            {
                cout << "*********************" << endl;
                cout << HPpotionBelt[i];
                cout << " x " << i + 1 << endl;
                cout << "*********************" << endl;
            }
        }
    }
// this was normally an "else if" to put else if on this one to display that ur on full health


    else if (statusChoice == 3)
    {
    ////////////




    cout << "\nUse:\n1 - HP Potion Belt\n2 - MP Potion Belt" << endl;

                            int potMenu = 0;
                            cin >> potMenu;
                            if (potMenu == 1 && heroHealth != heroMaxHealth)
                            {
                            if (!HPpotionBelt.empty())
                            {
                                for (int i = 0; i < HPpotionBelt.size(); ++i)
                                {
                                    cout << i + 1 << ". " << "Potion - " << HPpotionBelt[i] << endl;
                                }
                                int potChoice = 0;
                                cin >> potChoice;
                                potChoice -= 1;

                                heroHealth += potionStr;

                                for (int i = 0; i < 1 ; ++i)
                                    {
                                        int x = potChoice;
                                        if (heroHealth > heroMaxHealth && !HPpotionBelt.empty())
                                        {
                                            int overHeal = heroHealth - heroMaxHealth;
                                            heroHealth = heroMaxHealth;


                                        cout << "\n** ("  << overHeal << ") HP has been restored!**\n" << endl;
                                        }
                                        else
                                        {
                                            cout << "\n** ("  << potionStr << ") HP has been restored!**\n" << endl;
                                        }

                                        HPpotionBelt.erase(HPpotionBelt.begin()+ x);


                                    }
                            } else {cout <<"You have no potions" << endl;}


        }else {cout <<"You are already at maximum health" << endl;}


    }//status choice 3

                    if (statusChoice == 4)
                        {
                            inStatus = false;
                        }

    // villagechoice 3 *status* *delete this* ???
}
    if (villageChoice == 4)
    {

    }

     // the undo is village choice == 1 bracket







}//while inStatus = true



}// while alive == true

 cout << "Sorry, you died." << endl;
}
