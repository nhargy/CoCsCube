#ifndef MY_CONSTRUCTION_HH
#define MY_CONSTRUCTION_HH

#include "G4Box.hh"
#include "G4GenericMessenger.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Tubs.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"

#include "G4Colour.hh"
#include "G4VisAttributes.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction{
    public:
        MyDetectorConstruction();        
        ~MyDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

    private:
        // World  := Mother volume
        // Holder := Circular plastic crystal holder
        // Block  := Lead blocks making up the shielding
        // Floor  := Concrete floot
        // Cube   := The LiF cube detector

        G4Box *solidWorld, *solidBlock, *solidFloor, *solidCube; 
        G4Tubs *solidHolder;

        G4LogicalVolume *logicWorld, *logicBlock, *logicFloor, *logicCube;
        G4LogicalVolume *logicHolder;

        G4VPhysicalVolume *physWorld, *physBlock, *physFloor, *physCube;
        G4VPhysicalVolume *physHolder; 

        // Material definitions
        G4Material *Air, *LiF, *Pb, *PLA, *Concrete;

        void DefineMaterials();
};

#endif
