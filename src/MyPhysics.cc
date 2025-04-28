#include "MyPhysics.hh"

MyPhysicsList::MyPhysicsList(){
    RegisterPhysics (new G4EmStandardPhysics());
};

MyPhysicsList::~MyPhysicsList(){
};
