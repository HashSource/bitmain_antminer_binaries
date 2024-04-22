
/* WARNING: Unknown calling convention */

void AT24C02_save_voltage(uchar which_iic,uchar voltage)

{
  undefined4 uVar1;
  
  uVar1 = DAT_0002ced0;
  printf("\n--- %s\n",DAT_0002ced0);
  AT24C02_write_one_byte(0x90,voltage,which_iic);
                    /* WARNING: Could not recover jumptable at 0x0000a420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_LAB_0005f294)("%s: voltage = 0x%02x\n",uVar1,voltage);
  return;
}

