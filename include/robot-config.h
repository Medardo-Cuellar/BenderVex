using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor_group LadoDerecho;
extern motor_group LadoIzquierdo;
extern motor Recogedor;
extern motor ServoLanzador;
extern motor_group Lanzador;
extern drivetrain Bender;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );