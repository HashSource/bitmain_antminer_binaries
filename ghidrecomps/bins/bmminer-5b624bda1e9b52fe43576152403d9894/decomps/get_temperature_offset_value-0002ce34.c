
/* WARNING: Unknown calling convention */

void get_temperature_offset_value(uchar chain,uchar *value)

{
  uchar which_iic;
  
  if (fpga_version < 0xe) {
    AT24C02_read_bytes(0x98,value,chain / 3,'\b');
    return;
  }
  if (chain - 1 < 0xd) {
    which_iic = CSWTCH_824[(chain - 1) * 4];
  }
  else {
    which_iic = '\0';
  }
  AT24C02_read_bytes(0x98,value,which_iic,'\b');
  return;
}

