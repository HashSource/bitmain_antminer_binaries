
undefined4 write_iic_of_S9_plus_power(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x18) = param_1;
  if (power_protocal_type != 2) {
    power_set_da_value_simple();
    return 0;
  }
  power_set_da_value();
  return 0;
}

