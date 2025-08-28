
/* WARNING: Unknown calling convention */

void AT24C02_save_voltage(uchar which_iic,uchar voltage)

{
  printf("\n--- %s\n","AT24C02_save_voltage");
  AT24C02_write_one_byte(0x90,voltage,which_iic);
  (*(code *)(undefined *)0x0)("%s: voltage = 0x%02x\n","AT24C02_save_voltage",voltage);
  return;
}

