/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
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
  task::sleep(tiempomovimiento);
}
void MoverAtras(int tiempomovimiento)
{
  LadoDerecho.spin(reverse);
  LadoIzquierdo.spin(reverse);
  task::sleep(tiempomovimiento);
}
void MoverDerecha(int tiempomovimiento)
{
  LadoDerecho.spin(forward);
  LadoIzquierdo.spin(reverse);
  task::sleep(tiempomovimiento);
}
void MoverIzquierda(int tiempomovimiento)
{
  LadoDerecho.spin(reverse);
  LadoIzquierdo.spin(forward);
  task::sleep(tiempomovimiento);
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


void DispararPrecarga(int tiempolanzador,int speedServoLanzador, int speedLanzador)
{
  Lanzador.spin(forward, speedLanzador, pct);
  task::sleep(200);
  ServoLanzador.rotateTo(-45,deg,speedServoLanzador,velocityUnits::pct);
  task::sleep(200);
  ServoLanzador.rotateTo(0,deg,speedServoLanzador,velocityUnits::pct);
  task::sleep(tiempolanzador);
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
MoverAdelante(2);
DispararPrecarga(2, 50, 100);

}

  int AvanzarRecogedor = 0;
  int RetrocederRecogedor = 0;
  int AvanzarLanzador = 0, RetrocederLanzador=0;
  int Direccion = 0; 
  int ContadorVelocidad = 0;
  int ServoMover = 0;

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

  //rutinas de botones direccionales

  while (true) {
    //boton de Recogedor
    //---Control de Recogedor---
      int deadband = 5;
      int VelocidadMotorIzquierdo = 0;
      int VelocidadMotorDerecho = 0;
      int VelocidadRecogedor=100;
      int VelocidadLanzador=100;


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
  
  // Programación de joysticks.

LadoIzquierdo.setStopping(hold);
LadoDerecho.setStopping(hold);

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
    Controller1.Screen.print("%d %d",Direccion, ContadorVelocidad);
    


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
