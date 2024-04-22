
undefined4 save_freq_badcores(undefined param_1,undefined4 param_2)

{
  AT24C02_write_bytes(0,param_2,param_1,0x80);
  return 0x80;
}

