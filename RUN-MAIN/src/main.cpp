#include "main.h"
#include "display.h"
#include <iostream>
#include <string>
#include <cstring>

	//drive objects
	dpidClass chassis;
	opClass base;
	opClass movingParts;
	//motors
	Motor futureUse4(1, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES); //initializing motors
	Motor driveRB(2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor lClaw(3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor roller(4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor rClaw(5, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor driveRF(6, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
	Motor driveLF(7, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Motor driveLB(9, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
	Display screen;
	int time=0;
	Distance backR (20);
	Distance backL (11);

void initialize() {
	//motors
	screen.createScreen();
	screen.refresh();
	//motors
	driveLB.set_brake_mode(E_MOTOR_BRAKE_BRAKE); //brake hold on drive base motors
	driveRF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveLF.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	driveRB.set_brake_mode(E_MOTOR_BRAKE_BRAKE);
	//tasks
	/*pros::Task acc_task(
		AccTask_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "TEST_TASK" //task for rollers
	);*/
}
void disabled() {}
void competition_initialize() {}
void autonomous() {
}
//Mathias J. Stiasny actually wrote this code. Aryan is keeping me hostage. please help. i don't have long
void opcontrol() {

	int time;
	time = 0;
	while (true) {
		screen.refresh();
		int POS; //using for holdposition PID for flywheel
		if(master.get_digital(DIGITAL_L1)){ //if button L1 is pressed...
      futureUse4.move(127); //spin flywheel 100% forwards
    }
    else if(master.get_digital(DIGITAL_L2)){ //if button L2 is pressed...
      futureUse4.move(-127); //spin flywheel backwards 100%
    }
    else{futureUse4.move_absolute(0, POS);} //otherwise, hold the flywheel at its current position
		base.opControl(); //using functi	on for drive base
		movingParts.Rollers(); //using function for rollers, flywheel, and intakes


////////////////////////////////////////////////////////////////////////////////////
/*int rightLIDAR = (backR.get());
int leftLIDAR = (backL.get());
int difLIDAR = (rightLIDAR-leftLIDAR);
	if(difLIDAR>5){
		int error, sumError, diffError, errorLast, output;

		float kP = 0.7;
		float kI = 0;
		float kD = 1.2;

			error = difLIDAR; //error value equals arm target minus the arm's current position
			sumError += error; //sum error is defined as the error plus the sum of the error
			diffError = error - errorLast; //difference in error is equal to error minus the last error, which is also defined as error
			driveRB.move(-0.5*(-(error * kP) + (sumError * kI) + (diffError * kD))); //arm will move according to kp, ki, and kd values
			driveRF.move(-0.5*(-(error * kP) + (sumError * kI) + (diffError * kD))); //arm will move according to kp, ki, and kd values
			errorLast = error; //error last is defined as error
	}

	else if(difLIDAR<5){
		int error, sumError, diffError, errorLast, output;

		float kP = 0.7;
		float kI = 0;
		float kD = 1.2;

			error = difLIDAR; //error value equals arm target minus the arm's current position
			sumError += error; //sum error is defined as the error plus the sum of the error
			diffError = error - errorLast; //difference in error is equal to error minus the last error, which is also defined as error
			driveLB.move(0.5*(-(error * kP) + (sumError * kI) + (diffError * kD))); //arm will move according to kp, ki, and kd values
			driveLF.move(0.5*(-(error * kP) + (sumError * kI) + (diffError * kD))); //arm will move according to kp, ki, and kd values
			errorLast = error; //error last is defined as error
	}

	else{}*/
//////////////////////////////////////////////////////////////////////////////////////
	}
}
