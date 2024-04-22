
undefined4 read_disabled_cores(undefined param_1,undefined4 param_2)

{
  AT24C02_read_bytes(0xa0,param_2,param_1,0x10);
  return 0x10;
}

