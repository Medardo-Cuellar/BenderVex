#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor LadoDerechoMotorA = motor(PORT4, ratio18_1, true);
motor LadoDerechoMotorB = motor(PORT5, ratio18_1, false);
motor LadoDerechoMotorC = motor(PORT6, ratio18_1, true);
motor_group LadoDerecho = motor_group(LadoDerechoMotorA, LadoDerechoMotorB,LadoDerechoMotorC);

motor LadoIzquierdoMotorA = motor(PORT1, ratio18_1, false);
motor LadoIzquierdoMotorB = motor(PORT2, ratio18_1, true);
motor LadoIzquierdoMotorC = motor(PORT3, ratio18_1, false);

motor_group LadoIzquierdo = motor_group(LadoIzquierdoMotorA, LadoIzquierdoMotorB,LadoIzquierdoMotorC);

motor Recogedor = motor(PORT10, ratio18_1, true);

motor ServoLanzador = motor(PORT8, ratio18_1,false);

motor MotorLanzador1 = motor(PORT16, ratio18_1, false);
motor MotorLanzador2 = motor(PORT17, ratio18_1, true);
motor_group Lanzador = motor_group(MotorLanzador1,MotorLanzador2);

motor Rodillo = motor(PORT15, ratio18_1, true);

digital_out SelenoideFinal = digital_out(Brain.ThreeWirePort.H);



drivetrain Bender = drivetrain(LadoIzquierdo,LadoDerecho,12.56637061,5,5.5,distanceUnits::in);


// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}