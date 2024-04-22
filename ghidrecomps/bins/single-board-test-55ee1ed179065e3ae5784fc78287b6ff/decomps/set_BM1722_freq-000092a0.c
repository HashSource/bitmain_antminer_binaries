
void set_BM1722_freq(float param_1,undefined param_2,undefined param_3,undefined param_4)

{
  float local_18;
  byte local_11;
  uint local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_11 = 0;
  local_c = 0;
  local_18 = 0.0;
  printf("\n--- %s: freq = %f\n","set_BM1722_freq",SUB84((double)param_1,0),
         (int)((ulonglong)(double)param_1 >> 0x20));
  local_c = get_pllparam_divider(param_1,&local_10,&local_11,&local_18);
  local_10 = local_10 | 0xc0000000;
  local_11 = local_11 - 1;
  printf("\n%s: pll_param = %08x, divider = %02x, pll_freq = %f\n","set_BM1722_freq",local_10,
         (uint)local_11,(double)local_18);
  set_BM1722_asic_register(param_2,param_3,0xc,param_4,local_10);
  usleep(1000);
  set_BM1722_asic_register(param_2,param_3,0x70,param_4,local_11);
  usleep(1000);
  set_BM1722_asic_register(param_2,param_3,0xc,param_4,local_10);
  return;
}

