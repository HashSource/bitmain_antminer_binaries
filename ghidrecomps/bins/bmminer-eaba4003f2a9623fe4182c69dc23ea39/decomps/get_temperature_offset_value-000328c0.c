
void get_temperature_offset_value(uchar chain,uchar *value)

{
  uchar *value_local;
  uchar chain_local;
  
  AT24C02_read_bytes(0x98,value,chain,'\b');
  return;
}

