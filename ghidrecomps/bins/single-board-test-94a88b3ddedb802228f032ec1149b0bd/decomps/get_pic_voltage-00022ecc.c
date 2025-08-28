
undefined4 get_pic_voltage(undefined1 param_1)

{
  undefined4 uVar1;
  
  uVar1 = AT24C02_read_voltage(param_1);
  return uVar1;
}

