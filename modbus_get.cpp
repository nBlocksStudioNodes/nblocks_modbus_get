#include "modbus_get.h"

nBlock_MODBUS_GET::nBlock_MODBUS_GET(uint32_t register_index) {
    _reg_index = register_index;
	_received_data = 0;
}
void nBlock_MODBUS_GET::triggerInput(nBlocks_Message message) {
	// Only first input is   valid
	if (message.inputNumber == 0) {
		// Only array data type is valid
		if (message.dataType == OUTPUT_TYPE_ARRAY) {
			// Get the entire register array into a variable
			uint16_t regs[] = (uint16_t *)(message.pointerValue);
			// Extract the value we are interested and save into output
			output[0] = regs[_req_index];
			// Flag we are outputting data next frame
			available[0] = 1;
		}
	}
}
void nBlock_MODBUS_GET::endFrame(void) {
	// Clear the received flag
    _received_data = 0;
}

