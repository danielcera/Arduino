// 
//    FILE: hmc6352.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.00
// PURPOSE: HMC6352 library for Arduino
//
// DETAILS: see cpp file
// 
// Released to the public domain
//

//#ifndef hmc6352_h
//#define hmc6352_h

#include "Wprogram.h"

#define HMC_LIB_VERSION 	"0.1.00"

#define HMC_GET_DATA		0x41
#define HMC_WAKE			0x57
#define HMC_SLEEP			0x53
#define HMC_SAVE_OP_MODE	0x4C
#define HMC_CALLIBRATE_ON	0x43
#define HMC_CALLIBRATE_OFF	0x45
#define HMC_UPDATE_OFFSETS	0x4F
#define HMC_WRITE_RAM		0x47
#define HMC_READ_RAM		0x67
#define HMC_WRITE_EEPROM	0x77
#define HMC_READ_EEPROM		0x72

enum hmcMode { STANDBY=0, QUERY=1, CONT=2, ERROR};

class hmc6352
{
	public:
    hmc6352(uint8_t device);    

    int direction(void);
    int qry(void);
    int wakeUp(void);
    int sleep(void);
	
	int UserCallibrationOn(void);
	int UserCallibrationOff(void);

	int factoryReset();
	
	int setOperationalModus(hmcMode m, uint8_t freq, bool periodicReset);
	int getOperationalModus();
	int setOutputModus(uint8_t om);
	int getOutputModus();
	
	int setI2Caddress(uint8_t address);
	int getI2Caddress();

	int setTimeDelay(uint8_t msec);
	int getTimeDelay();
	
	int setMeasurementSumming(uint8_t ms);
	int getMeasurementSumming();

	int SaveOpMode(void);
	int UpdateOffsets(void);
	
	int writeEEPROM(uint8_t address, uint8_t data);
	int readEEPROM(uint8_t address);
	int writeRAM(uint8_t address, uint8_t data);
	int readRAM(uint8_t address);

  private:
	int cmd(uint8_t c);
	int readCmd(uint8_t c, uint8_t address);
	int writeCmd(uint8_t c, uint8_t address, uint8_t data);

	uint8_t _device;
};

//#endif
