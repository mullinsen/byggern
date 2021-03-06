#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

#include "bit_macros.h"
#include "SPI_driver.h"
#include "MCP2515.h"

char MCP2515_read(char addr_byte)
{
    clear_bit(PORTB, PB7);

    SPI_transmission(MCP_READ);
    SPI_transmission(addr_byte);
    char data = SPI_transmission(0x00);

    set_bit(PORTB,PB7);

    return data;
}

void MCP2515_write(char addr_byte, char cData)
{
    clear_bit(PORTB,PB7);

    SPI_transmission(MCP_WRITE);
    SPI_transmission(addr_byte);
    SPI_transmission(cData);


    set_bit(PORTB , PB7);
}

void MCP2515_request_to_send(char instr_data){
    clear_bit(PORTB, PB7);

    SPI_transmission(instr_data);

    set_bit(PORTB , PB7);

}

char MCP2515_read_status(){
    clear_bit(PORTB , PB7);

    SPI_transmission(MCP_READ_STATUS);

    char status = SPI_transmission(0x00);

    set_bit(PORTB , PB7);

    return status;
}

void MCP2515_bit_modify (char address, char mask, char data){
    clear_bit(PORTB,PB7);

    SPI_transmission(MCP_BITMOD);
    SPI_transmission(address);
    SPI_transmission(mask);
    SPI_transmission(data);

    set_bit(PORTB , PB7);
}

void MCP2515_reset(void){
    clear_bit(PORTB , PB7);

    SPI_transmission(MCP_RESET);

    set_bit(PORTB , PB7);


    _delay_ms(50);
}
