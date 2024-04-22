
/* WARNING: Unknown calling convention */

void set_temperature_offset_value(uint which_i2c,uchar which_chain,uchar *value)

{
  printf("\n--- %s\n",DAT_00023944);
  write_temperature_offset_PIC16F1704(which_i2c,which_chain,value);
  (*(code *)PTR_usleep_00030148)(100000);
  return;
}

