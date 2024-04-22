
undefined4
read_disabled_cores(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  AT24C02_read_bytes_part_7(0xa0,param_2,param_1,0x10,param_4);
  return 0x10;
}

