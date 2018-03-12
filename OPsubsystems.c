//////////////////////////////////////////////////////////////////////////////////////////
//
//                         USER DEFINED FUNCTIONS				
//				FOR ROBOT CONTROL
//
// 	Insert the functions that control different aspects of your robot	
//
//////////////////////////////////////////////////////////////////////////////////////////


//------------------------------------------------------------------------------------------ FUNCTION: DRIVE TRAIN CONTROL
void
driveTrain_func(){

	motor[driveR] = abs(vexRT[Ch2]) > DEADBAND ? -vexRT[Ch2] : 0;
	motor[driveL] = abs(vexRT[Ch3]) > DEADBAND ? vexRT[Ch3] : 0;

	/* TRADITIONAL
	while(true){
		motor[driveL] = vexRT(Ch3);
		motor[driveR] = vexRT(Ch2);
	}
	*/
}

//------------------------------------------------------------------------------------------ FUNCTION: TOWER ELEVATOR LIFT
void
towerLift_func(){
		 while(true){
	// raise tower
	if(vexRT[Btn5U] == 1){
    		motor[elevatorL] = -SPEED393_STANDARD;
    		motor[elevatorR] = SPEED393_STANDARD;}
    	// lower tower lift
    	else if(vexRT[Btn5D] == 1){
    		motor[elevatorL] = SPEED393_STANDARD;
    		motor[elevatorR] = -SPEED393_STANDARD;}
    	// hold steady
    	else
    	{motor[elevatorL] = 0;
    	 motor[elevatorR] = 0;}
  	}
}

//------------------------------------------------------------------------------------------ FUNCTION: ARM LIFT
void
armLift_func(){
		 while(true){
		// raise arm lift
    	 	if(vexRT[Btn6U] == 1){
	    		motor[armL] = -ARMSPEED_STANDARD;
	    		motor[armR] = ARMSPEED_STANDARD;
	    		}
	    	// lower arm lift
	    	else if(vexRT[Btn6D] == 1){
	    		motor[armL] = ARMSPEED_STANDARD;
	    		motor[armR] = -ARMSPEED_STANDARD;
	    		}
	    	// hold steady
	    	else
	    	{motor[armL] = 0;
	    	 motor[armR] = 0;
	    	}
  	}
}

//------------------------------------------------------------------------------------------	FUNCTION: MOBILE LIFT
void
shovelLift_func(){
    while(true){
	// raise mogo lift
    	if(vexRT[Btn7U] == 1){
    		motor[mogoL] = -MOGOSPEED_STANDARD;
    		motor[mogoR] = MOGOSPEED_STANDARD;}

    	// lower mogo lift
    	else if(vexRT[Btn7D] == 1){
    		motor[mogoL] = MOGOSPEED_STANDARD;
    		motor[mogoR] = -MOGOSPEED_STANDARD;}

    	// hold steady
    	else
    	{motor[mogoL] = 0;
    	 motor[mogoR] = 0;}
  	}
}

//------------------------------------------------------------------------------------------	FUNCTION: CLAW
void
claw_func(){
    while(true){
	// open claw
    	if(vexRT[Btn8R] == 1){
    		motor[claw] = CLAWSPEED_STANDARD;
    		}
    	// close claw
    	else if(vexRT[Btn8L] == 1){
    		motor[claw] = -CLAWSPEED_STANDARD;
    		}
    	// hold steady
    	else{
    		motor[claw] = 0;
    		}
  	}
}
