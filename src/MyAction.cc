#include "MyAction.hh"
#include "MyGenerator.hh"
#include "MyTracking.hh"

MyActionInitialization::MyActionInitialization(){
};

MyActionInitialization::~MyActionInitialization(){
};

void MyActionInitialization::Build() const{
    SetUserAction(new PrimaryGeneratorAction);
    SetUserAction(new MyRunAction());
    SetUserAction(new MyTrackingAction());
};
