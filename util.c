// util.c -- utility function file

//------------------------------------------------------------------------------------------	FUNCTION: CLEAR ENCODERS
void
clearEncodersQuad_func(){
	// Command for 393 Quad Encoder to Reset Encoder Counts to Zero
	SensorValue[quadL] = 0;
	SensorValue[quadR] = 0;
}

void
clearEncodersIME_func(){
// Command for 393 Integrated Motor Encoder to Reset Encoder Counts to Zero
	SensorValue[imeL] = 0;  				
	SensorValue[imeR] = 0;				  
}

//------------------------------------------------------------------------------------------ FUNCTION: CLEAR LCD
void
clearLCD(){
	//clears 1st & 2nd lines of the LCD
	clearLCDLine(0);	// 1st line of LCD
	clearLCDLine(1);	// 2nd line of LCD
}
