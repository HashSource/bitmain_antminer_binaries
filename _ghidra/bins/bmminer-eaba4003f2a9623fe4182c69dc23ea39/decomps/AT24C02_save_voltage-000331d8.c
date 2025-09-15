
void AT24C02_save_voltage(uchar which_iic,uchar voltage)

{
  uchar voltage_local;
  uchar which_iic_local;
  
  AT24C02_write_one_byte(0x90,voltage,which_iic);
  return;
}

