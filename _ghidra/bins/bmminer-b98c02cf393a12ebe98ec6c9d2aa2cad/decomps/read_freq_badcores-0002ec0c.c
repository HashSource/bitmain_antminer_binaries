
undefined4
read_freq_badcores(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  AT24C02_read_bytes_part_7(0,param_2,param_1,0x80,param_4);
  return 0x80;
}

