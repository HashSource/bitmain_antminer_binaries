
undefined4 AT24C02_read_voltage(undefined param_1)

{
  undefined4 uVar1;
  
  uVar1 = AT24C02_read_one_byte(0x90,param_1);
  return uVar1;
}

