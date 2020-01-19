# Main code file to compile
IN = main.c drivers/st7789.c drivers/vibrator.c drivers/button.c

# Output binary to upload to device
OUT = program.bin

DEFINE = -DNRF52832_XXAA

# https://stackoverflow.com/questions/19419782/exit-c-text0x18-undefined-reference-to-exit-when-using-arm-none-eabi-gcc
CFLAG = --specs=nosys.specs

# GCC executable
CC = arm-none-eabi-gcc

# Directories to include according to the nrfx documentation
INCLUDE = -ICMSIS/Include -Inrfx/ -Inrfx/drivers/include -Inrfx/mdk -Idrivers/

main:${OBJ}
	${CC} ${CFLAG} ${DEFINE} ${INCLUDE} -o ${OUT} ${IN} ${LIBS}

clean:
	rm -f ${OUT}

