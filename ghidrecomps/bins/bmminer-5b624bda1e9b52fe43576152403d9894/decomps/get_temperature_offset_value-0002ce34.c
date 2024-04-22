
/* WARNING: Unknown calling convention */

void get_temperature_offset_value(uchar chain,uchar *value)

{
  uchar which_iic;
  
  if (*DAT_0002ce78 < 0xe) {
    AT24C02_read_bytes(0x98,value,chain / 3,'\b');
    return;
  }
  if (chain - 1 < 0xd) {
    which_iic = *(uchar *)(DAT_0002ce7c + (chain - 1) * 4 + 0x9b8);
  }
  else {
    which_iic = '\0';
  }
  AT24C02_read_bytes(0x98,value,which_iic,'\b');
  return;
}

