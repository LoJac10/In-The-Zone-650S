//------------------------------------------------------------------------------------------
// FUNCTION: LCD DISPLAY CORTEX AND POWER EXPANDER BATTERY VOLTAGES
//------------------------------------------------------------------------------------------

// Modified from Kypyro's post <https://www.vexforum.com/index.php/31293-power-expander-battery-voltage/0>
// would need a separate func to display 9-VOLT BATTERY info

void
monitorPower(){
	// turn on LCD backlight
	bLCDBacklight = true;
	// declare string vars to hold battery volt values
	string cortexBattery, expanderBattery;

	// Builds the value to be displayed
	// Value is typecast as 'FLOAT' var type
	// CHANGE: two places of data are added after decimal and the 'c' is a character ref to be replaced with the 'V' for Volt
	sprintf(cortexBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
	// KYPYRO FORM OF LINE ABOVE: sprintf(cortexBattery, "%f Volts", (float)nImmediateBatteryLevel/1000.0);
	// with the typecast redefine '%1.2f%c' there does not need to be an explicit type recast --> ie (float)
	// the value is taken from stream and recast with (2) needed decimal places
	// if you want 3 decimal places, plan for extra space, and use '%1.3f%c'

	// Expander has sensor port that connects to Analog Sensor port #2 on cortex
	// Analog Sensor port #2 is named as "power"

	// Builds Value to be Displayed
	// Value is typecast as 'FLOAT' var type
	// CHANGE: two places of data are added after decimal and the 'c' is a character ref to be replaced with the 'V' for Volt
	sprintf(expanderBattery,"%1.2f%c", ((SensorValue[power])/270.0), 'V');
	// KYPYRO FORM OF LINE ABOVE: sprintf(expanderBattery, "%f Volts", (float)SensorValue[power]/270.0);
	// with the typecast redefine '%1.2f%c' there does not need to be an explicit type recast --> ie (float)
	// the value is taken from stream and recast with (2) needed decimal places
	// if you want 3 decimal places, plan for extra space, and use '%1.3f%c'

	// clear LCD
	clearLCDLine(0);
	clearLCDLine(1);

	// displays cortex battery info on LCD Lines 1
	displayLCDString(0,0,"Cortex:");
	displayLCDString(0,8, cortexBattery);
	// displays power expander battery info on LCD line 2
	displayLCDString(1,0,"Expander:");
	displayLCDString(1,10,expanderBattery);

	// Short delay for refresh rate
	wait1Msec(1000);
	// turn off LCD backlight
	bLCDBacklight = false;
}
