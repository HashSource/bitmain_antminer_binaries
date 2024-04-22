
/* WARNING: Unknown calling convention */

void AT24C02_save_voltage(uchar which_iic,uchar which_chain,uint voltage)

{
  undefined4 uVar1;
  undefined4 in_r3;
  
  uVar1 = DAT_00024adc;
  printf("\n--- %s\n",DAT_00024adc);
  AT24C02_write_one_byte(0x90,(uchar)voltage,which_iic,which_chain);
  AT24C02_write_one_byte(0x91,(uchar)(voltage >> 8),which_iic,which_chain);
  (*(code *)PTR_printf_00030118)("%s: voltage = 0x%02x\n",uVar1,voltage,in_r3);
  return;
}

