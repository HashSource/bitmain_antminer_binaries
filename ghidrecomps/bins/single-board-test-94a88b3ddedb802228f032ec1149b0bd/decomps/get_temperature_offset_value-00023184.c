
void get_temperature_offset_value(undefined1 param_1,undefined4 param_2)

{
  AT24C02_read_bytes(0x98,param_2,param_1,8);
  return;
}

