#ifndef __NB_MODBUS_GET
#define __NB_MODBUS_GET

#include "nworkbench.h"

class nBlock_MODBUS_GET: public nBlockSimpleNode<1> {
public:
    nBlock_MODBUS_GET(uint32_t register_index);
    void triggerInput(nBlocks_Message message);
    void endFrame(void);
private:
	uint32_t _reg_index;
	uint32_t _received_data;
};

#endif


