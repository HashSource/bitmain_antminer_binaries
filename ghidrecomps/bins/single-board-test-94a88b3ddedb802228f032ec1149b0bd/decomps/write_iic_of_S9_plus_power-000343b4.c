
undefined4 write_iic_of_S9_plus_power(byte param_1,int param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_2 + 0x18) = (uint)param_1;
  uVar1 = power_set_voltage(param_1);
  return uVar1;
}

