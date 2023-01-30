#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);

motor LadoDerechoMotorA = motor(PORT1, ratio18_1, false);
motor LadoDerechoMotorB = motor(PORT2, ratio18_1, true);
motor LadoDerechoMotorC = motor(PORT3, ratio18_1, true);
motor LadoDerechoMotorD = motor(PORT4, ratio18_1, false);
motor_group LadoDerecho = motor_group(LadoDerechoMotorA, LadoDerechoMotorB,LadoDerechoMotorC,LadoDerechoMotorD);

motor LadoIzquierdoMotorA = motor(PORT11, ratio18_1, true);
motor LadoIzquierdoMotorB = motor(PORT12, ratio18_1, false);
motor LadoIzquierdoMotorC = motor(PORT13, ratio18_1, false);
motor LadoIzquierdoMotorD = motor(PORT14, ratio18_1, true);
motor_group LadoIzquierdo = motor_group(LadoIzquierdoMotorA, LadoIzquierdoMotorB,LadoIzquierdoMotorC, LadoIzquierdoMotorD);

motor Recogedor = motor(PORT9, ratio18_1, false);

motor Servo = motor(PORT5, ratio18_1,false);
motor MotorTraseroIzquierdo(PORT8, ratio18_1,false);



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