
void AT24C02_save_voltage(undefined param_1,byte param_2)

{
  printf("\n--- %s\n","AT24C02_save_voltage");
  AT24C02_write_one_byte(0x90,param_2,param_1);
  printf("%s: voltage = 0x%02x\n","AT24C02_save_voltage",(uint)param_2);
  return;
}

