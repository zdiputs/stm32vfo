/*
 * VFOController.h
 *
 *  Created on: Apr 1, 2018
 *      Author: lymes
 */

#ifndef VFO_VFOCONTROLLER_H_
#define VFO_VFOCONTROLLER_H_

#include "stm32f1xx_hal.h"
#include "GUIController.h"
#include "si5351/si5351.h"
#include "Configuration.h"


namespace VFO
{

class VFOController
{
	Configuration* _conf;
	GUIController* _gui;
	Si5351* _si5351;
	bool _si5351_enabled = true;

public:
	VFOController();
	virtual ~VFOController();
	void begin();

	Configuration *getConfig() { return _conf; }

	void menuKeyPressed();
	void pushEncoderIncrement(int16_t increment);

	void showSetup();
	void showMain();

	void reset();
	void setFrequency(uint32_t frequency);

	void checkMemoryState();
	void triggerMemoryWrite();

	void storeConfiguration();
};


} /* namespace VFO */




#endif /* VFO_VFOCONTROLLER_H_ */