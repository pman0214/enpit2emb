ASM_OBJ += 

CXX_OBJ += $(MBED_LIB_DIR)/Zumo/Zumo.o
CXX_OBJ += $(MBED_LIB_DIR)/Zumo/LSM303D_I2C.o

INCLUDE_PATHS += -I$(MBED_LIB_DIR)/Zumo

CDEFS += 
