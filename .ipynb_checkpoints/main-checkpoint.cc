// =========================================================================
// Project: CoCsCube
// File: main.cc
// Author: nhargy
// Date: April 2025
// Brief: Cobalt-60 and Caesium-137 ER simulations
// =========================================================================

#include <iostream>

#include "G4RunManager.hh"
#include "G4UIExecutive.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4VisManager.hh"

#include "MyAction.hh"
#include "MyConstruction.hh"
#include "MyPhysics.hh"

int main(int argc, char **argv){
   
    G4RunManager* runManager = new G4RunManager();

    runManager->SetUserInitialization(new MyDetectorConstruction()); 
    runManager->SetUserInitialization(new MyPhysicsList()); 
    runManager->SetUserInitialization(new MyActionInitialization()); 

    //runManager->Initialize();

    // Initialize visualisation only if no macro is passed
    G4UIExecutive* ui = 0;
    if(argc==1){
       ui = new G4UIExecutive(argc, argv);
    }

    G4VisManager* visManager = new G4VisExecutive();
    visManager->Initialize();

    G4UImanager* uiManager = G4UImanager::GetUIpointer();

    if(ui){
        uiManager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();    
    }
    else{
        G4String command = "/control/execute ";
        G4String filename = argv[1];
        uiManager->ApplyCommand(command + filename);
    }
    
    return 0;
} 
