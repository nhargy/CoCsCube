#include "MyAction.hh"
#include "MyGenerator.hh"

MyActionInitialization::MyActionInitialization(){
};

MyActionInitialization::~MyActionInitialization(){
};

void MyActionInitialization::Build() const{
    SetUserAction(new PrimaryGeneratorAction);
};
