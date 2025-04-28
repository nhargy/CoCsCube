#include "MyConstruction.hh"

MyDetectorConstruction::MyDetectorConstruction(){

    DefineMaterials();
}

MyDetectorConstruction::~MyDetectorConstruction(){
}

void MyDetectorConstruction::DefineMaterials(){

    G4NistManager *nist = G4NistManager::Instance(); 
    
    Air = nist->FindOrBuildMaterial("G4_AIR"); 
    LiF = nist->FindOrBuildMaterial("G4_LITHIUM_FLUORIDE");
    Pb  = nist->FindOrBuildMaterial("G4_Pb");
    Concrete = nist->FindOrBuildMaterial("G4_CONCRETE");

    PLA = new G4Material("PLA", 1.25*g/cm3, 3);
    PLA->AddElement(nist->FindOrBuildElement("C"), 3);
    PLA->AddElement(nist->FindOrBuildElement("H"), 4);
    PLA->AddElement(nist->FindOrBuildElement("O"), 2);

}

G4VPhysicalVolume *MyDetectorConstruction::Construct(){
   
    // Build World 
    G4double xWorld = 0.5*m;
    G4double yWorld = 0.5*m;
    G4double zWorld = 0.5*m;

    solidWorld = new G4Box("solidWorld",
                           xWorld,
                           yWorld,
                           zWorld); 

    logicWorld = new G4LogicalVolume(solidWorld,
                                    Air,
                                    "logicWorld");

    physWorld  = new G4PVPlacement(0,
                                   G4ThreeVector(0.,0.,0.),
                                   logicWorld,
                                   "physWorld",
                                   0,
                                   false,
                                   0,
                                   true); 

    // Build Holder
    G4VisAttributes* visAttributesHolder = new G4VisAttributes(G4Colour(1., 0.8, 0.6));
    visAttributesHolder->SetVisibility(true);
    visAttributesHolder->SetForceSolid(true);

    G4double holderInnerRadius = 1.4*cm;
    G4double holderOuterRadius = 5*cm;
    G4double holderHeight      = 0.4*cm;

    solidHolder = new G4Tubs("solidholder",
                               holderInnerRadius,
                               holderOuterRadius,
                               holderHeight,
                               0.*deg,
                               360.*deg
                              );

    logicHolder = new G4LogicalVolume(solidHolder,
                                      PLA,
                                      "logicHolder");

    physHolder = new G4PVPlacement(0,
                                   G4ThreeVector(0.,0., holderHeight+5*cm),
                                   logicHolder,
                                   "physHolder",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 

    
    logicHolder->SetVisAttributes(visAttributesHolder);

    // Build Blocks

    G4VisAttributes* visAttributesBlock = new G4VisAttributes(G4Colour(0.1, 0.1, 1.));
    visAttributesBlock->SetVisibility(true);
    visAttributesBlock->SetForceSolid(true);

    solidBlock = new G4Box("solidBlock",
                            15*cm,
                            15*cm,
                            2.5*cm);

    logicBlock = new G4LogicalVolume(solidBlock,
                                     Pb,
                                     "logicBlock");

    physBlock = new G4PVPlacement(0,
                                   G4ThreeVector(0,0,2.5*cm),
                                   logicBlock,
                                   "physBlock",
                                   logicWorld,
                                   false,
                                   0,
                                   true); 

    logicBlock->SetVisAttributes(visAttributesBlock);

    // Build Floor

    G4VisAttributes* visAttributesFloor = new G4VisAttributes(G4Colour(0.3, 0.3, 0.3));
    visAttributesFloor->SetVisibility(true);
    visAttributesFloor->SetForceSolid(true);


    solidFloor = new G4Box("solidFloor",
                           xWorld,
                           yWorld,
                           0.25*m
                          );

    logicFloor = new G4LogicalVolume(solidFloor,
                                     Concrete,
                                     "logicFloor"
                                    );

    physFloor = new G4PVPlacement(0,
                                  G4ThreeVector(0., 0., -0.25*m),
                                  logicFloor,
                                  "physFloor",
                                  logicWorld,
                                  false,
                                  0,
                                  true
                                 );

    logicFloor->SetVisAttributes(visAttributesFloor);


    // Build Cube



    return physWorld;
}

// void MyDetectorConstruction::ConstructSDandField(){
// }
