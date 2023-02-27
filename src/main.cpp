/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES Este es un cambio  ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LadoDerecho          motor_group   1, 2            
// LadoIzquierdo        motor_group   11, 12
// ServoLanzador        motor         5             
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
//funciones autonomas

void MoverAdelante(int tiempomovimiento)
{
  LadoDerecho.spin(forward);
  LadoIzquierdo.spin(forward);
  Controller1.Screen.print("Adelante");
  task::sleep(tiempomovimiento);
  Controller1.Screen.clearLine();
  LadoDerecho.stop();
  LadoIzquierdo.stop();
}
void MoverAtras(int tiempomovimiento)
{
  LadoDerecho.spin(reverse);
  LadoIzquierdo.spin(reverse);
  Controller1.Screen.print("Atras");
  task::sleep(tiempomovimiento);
  Controller1.Screen.clearLine();
  LadoDerecho.stop();
  LadoIzquierdo.stop();
}
void MoverDerecha(int tiempomovimiento)
{
  LadoDerecho.spin(forward);
  LadoIzquierdo.spin(reverse);
  Controller1.Screen.print("Derecha");
  task::sleep(tiempomovimiento);
  Controller1.Screen.clearLine();
  LadoDerecho.stop();
  LadoIzquierdo.stop();
}
void MoverIzquierda(int tiempomovimiento)
{
  LadoDerecho.spin(reverse);
  LadoIzquierdo.spin(forward);
  Controller1.Screen.print("Izquierda");
  task::sleep(tiempomovimiento);
  Controller1.Screen.clearLine();
  LadoDerecho.stop();
  LadoIzquierdo.stop();
}

void DetenerMovimiento()
{
  LadoDerecho.stop();
  LadoIzquierdo.stop();
}
void MoverLanzador()
{

}


void LanzaServo()
{

}


void DispararPrecarga(int speedServoLanzador, int speedLanzador,int intermedio, int velocidad)
{
  Lanzador.setVelocity(velocidad,percent);
  Lanzador.spin(forward, speedLanzador, pct);
  task::sleep(intermedio+500);
  Controller1.Screen.print("pimer disparo");
  ServoLanzador.rotateTo(-45,deg,speedServoLanzador,velocityUnits::pct);
  task::sleep(200);
  Controller1.Screen.clearLine();
  ServoLanzador.rotateTo(0,deg,speedServoLanzador,velocityUnits::pct);
  task::sleep(intermedio);
  Controller1.Screen.print("segundo disparo");
  ServoLanzador.rotateTo(-45,deg,speedServoLanzador,velocityUnits::pct);
  task::sleep(200);
  ServoLanzador.rotateTo(0,deg,speedServoLanzador,velocityUnits::pct);
  Controller1.Screen.clearLine();
  Lanzador.stop();
  task::sleep(200);
}

void DetenerLanzadores()
{
  Lanzador.stop();
  ServoLanzador.stop();
}


void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................



//Bender.driveFor(reverse, 40, inches);
/*
LadoDerecho.setVelocity(80, percent);
LadoIzquierdo.setVelocity(80, percent);
*/
MoverAtras(3300);
MoverDerecha(400);
//Bender.turnFor(-30, degrees);
//Controller1.Screen.print("vuelta");
//Bender.stop();
//Controller1.Screen.clearLine();

DispararPrecarga(100, 80, 2000, 50); // speedServoLanzador, speedLanzador, velocidad del tiempo intermedio entre lanzamientos para maximizar potencia de disparo, velocidad del lanzador

}

  int AvanzarRecogedor = 0;
  int RetrocederRecogedor = 0;
  int AvanzarLanzador = 0, RetrocederLanzador=0;
  int Direccion = 0; 
  int ContadorVelocidad = 0;
  int ServoMover = 0;
  int RodilloMover = 0;
  int LanzamientoFinal = 0;

// Controller functions

void CambiarDireccion()
{
  Direccion++;
}

void CambiarVelocidad()
{
  ContadorVelocidad++;
}

void AvanceRecogedor()
{
  AvanzarRecogedor++;
  RetrocederRecogedor=0;
}

void AtrasRecogedor()
{
  RetrocederRecogedor++;
  AvanzarRecogedor=0;
}

void AvanceLanzador()
{
  AvanzarLanzador++;
  RetrocederLanzador=0;
}

void AtrasLanzador()
{
  RetrocederLanzador++;
  AvanzarLanzador=0;
}

void MoverServo()
{
  ServoMover++;
}

void MoverRodillo()
{
  RodilloMover++;
}

void LanzarFinal()
{
  LanzamientoFinal++;
}

int VelocidadRecogedor=100;
int VelocidadLanzador=100;
void SubirVelocidadRecogedor()
{
  if(VelocidadRecogedor==100)
  {VelocidadRecogedor=0;}
  else
  {VelocidadRecogedor=VelocidadRecogedor+10;}
}
void SubirVelocidadLanzador()
{
  if(VelocidadLanzador==100)
  {VelocidadLanzador=0;}
  else
  {VelocidadLanzador=VelocidadLanzador+10;}
}
void BajarVelocidadRecogedor()
{
  if(VelocidadRecogedor==0)
  {VelocidadRecogedor=100;}
  else
  {VelocidadRecogedor=VelocidadRecogedor-10;}
}
void BajarVelocidadLanzador()
{
  if(VelocidadLanzador==0)
  {VelocidadLanzador=100;}
  else
  {VelocidadLanzador=VelocidadLanzador-10;}
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) 
{
  //User declared variables

  // User control code here, inside the loop


  //rutinas de botones
  Controller1.ButtonR1.pressed(AvanceRecogedor);
  Controller1.ButtonR2.pressed(AtrasRecogedor);
  Controller1.ButtonL1.pressed(AvanceLanzador);
  Controller1.ButtonL2.pressed(MoverServo);
  Controller1.ButtonA.pressed(CambiarDireccion);
  Controller1.ButtonB.pressed(CambiarVelocidad);
  Controller1.ButtonX.pressed(MoverRodillo);


// Para probar en autonomo la velocidad del lanzador correcta

//Comentar estas lineas en caso de no necesitar hacer ajustes adicionales

  Controller1.ButtonDown.pressed(BajarVelocidadLanzador);
  Controller1.ButtonLeft.pressed(BajarVelocidadRecogedor);
  Controller1.ButtonUp.pressed(SubirVelocidadLanzador);
  Controller1.ButtonRight.pressed(SubirVelocidadRecogedor);

  //rutinas de botones direccionales

  while (true) {
    //boton de Recogedor
    //---Control de Recogedor---
      int deadband = 5;
      int VelocidadMotorIzquierdo = 0;
      int VelocidadMotorDerecho = 0;



    Recogedor.setVelocity(VelocidadRecogedor, percent);
    Lanzador.setVelocity(VelocidadLanzador, percent);

  //instrucciones para mover los botones R y L

    if(AvanzarRecogedor==0&&RetrocederRecogedor==0)
    {
      Recogedor.stop();
    }
    else if(AvanzarRecogedor==1)
    {
      Recogedor.spin(forward);
    }
    else if(AvanzarRecogedor==2)
    {
      AvanzarRecogedor=0;
    }
    if (RetrocederRecogedor==1)
    {
      Recogedor.spin(reverse);
    }
    else if(RetrocederRecogedor==2)
    {
      RetrocederRecogedor=0;
    }

    if(AvanzarLanzador==0&&RetrocederLanzador==0)
    {
      Lanzador.stop();
    }
    else if(AvanzarLanzador==1)
    {
      Lanzador.spin(forward);
    }
    else if(AvanzarLanzador==2)
    {
      AvanzarLanzador=0;
    }
    if (RetrocederLanzador==1)
    {
      Lanzador.spin(reverse);
    }
    else if(RetrocederLanzador==2)
    {
      RetrocederLanzador=0;
    }
    //se agrega modificador de velocidad en caso que el rodillo no tenga mucho control
    
    if (RodilloMover==1)
    {
      if (ContadorVelocidad==0){
        Rodillo.setVelocity(100, percent);
        }
      else if (ContadorVelocidad==1) {
        Rodillo.setVelocity(50, percent);
        }
      Rodillo.spin(forward);
    }
    else if(RodilloMover==2)
    {
      RodilloMover=0;
    }
    
  //configurador del endgame con idea preliminar
  if(LanzamientoFinal==1)
  {
    SelenoideFinal.set(1);
    task::sleep(250);
    SelenoideFinal.set(0);
  }
  else if(LanzamientoFinal==2)
  {
    LanzamientoFinal=0;
  }


  // Programación de joysticks.

/*
LadoIzquierdo.setStopping(hold);
LadoDerecho.setStopping(hold);
*/

  //Si la variable Direccion es igual a 0 el sentido de los motores izquierdos es negativo con Axis4  
    if (Direccion==0){
      if (ContadorVelocidad==0){
        // Get the velocity percentage of the left motor. (Axis3 + Axis4)
        VelocidadMotorIzquierdo = Controller1.Axis3.position() + Controller1.Axis4.position();
        // Get the velocity percentage of the right motor. (Axis3 - Axis4)
        VelocidadMotorDerecho = Controller1.Axis3.position() - Controller1.Axis4.position();
      }
       else if (ContadorVelocidad==1){
        // Get the velocity percentage in 1/2
        VelocidadMotorIzquierdo = (Controller1.Axis3.position() + Controller1.Axis4.position())/2;
        VelocidadMotorDerecho = (Controller1.Axis3.position() - Controller1.Axis4.position())/2;
      }
    }
    //Tambien si la variable Direccion es igual a 1 el sentido de los motores derecho es negativo con Axis4  
    else if (Direccion==1)
    {
        if(ContadorVelocidad==0)
        {
          // Get the velocity percentage of the left motor. (Axis3 - Axis4)
          VelocidadMotorIzquierdo = Controller1.Axis3.position() - Controller1.Axis4.position();
          // Get the velocity percentage of the right motor. (Axis3 + Axis4)
          VelocidadMotorDerecho = Controller1.Axis3.position() + Controller1.Axis4.position();     
        }
        else if(ContadorVelocidad==1)
        {
          // Get the velocity percentage in 1/2
          VelocidadMotorIzquierdo = Controller1.Axis3.position() - Controller1.Axis4.position()/2;
          VelocidadMotorDerecho = Controller1.Axis3.position() + Controller1.Axis4.position()/2;     
        }
 
      }

    // Programación de inversión de giro.
    else if (Direccion==2)
    {
      Direccion = 0;
    }

    // Programación de reducir / aumentar velocidad
    if (ContadorVelocidad==2)
    {
      ContadorVelocidad=0;
    } 

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.

    //print the current speed of the 
    Controller1.Screen.setCursor(1,2);
    Controller1.Screen.print("L%d R%d D%d V%d",VelocidadLanzador, VelocidadRecogedor, Direccion, ContadorVelocidad);
    


    if (abs(VelocidadMotorIzquierdo) < deadband) {
      // Set the speed to zero.
      LadoIzquierdo.setVelocity(0, percent);
    } else {
      // Set the speed to VelocidadMotorIzquierdo
      LadoIzquierdo.setVelocity(VelocidadMotorIzquierdo, percent);
    }
    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    
    if (abs(VelocidadMotorDerecho) < deadband) {
      // Set the speed to zero
      LadoDerecho.setVelocity(0, percent);
    } if (abs(VelocidadMotorDerecho) > deadband){
      // Set the speed to VelocidadMotorDerecho
      LadoDerecho.setVelocity(VelocidadMotorDerecho, percent);
    }
      
    //---Inversor de sentido (cambio de frente)---
    if(Direccion==0)
    {
      // Spin both motors in the forward direction.
      LadoDerecho.spin(forward);
      LadoIzquierdo.spin(forward);  
    }
    else if(Direccion==1)
    {
      // Spin both motors in the forward direction.
      LadoDerecho.spin(reverse);
      LadoIzquierdo.spin(reverse);  
    }


    if(Controller1.ButtonL2.pressing())
  {
    /*ServoLanzador.setPosition(80, degrees);
    task::sleep(200);
    ServoLanzador.resetPosition();*/
    ServoLanzador.rotateTo(-45,rotationUnits::deg,50,velocityUnits::pct,100);
  }

  else
  {
    ServoLanzador.rotateTo(0,rotationUnits::deg,50,velocityUnits::pct,100);
  }


    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(25, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
