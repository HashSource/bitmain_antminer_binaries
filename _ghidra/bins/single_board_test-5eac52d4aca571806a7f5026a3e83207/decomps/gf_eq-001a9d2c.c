
int gf_eq(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 uStack_10;
  
  uStack_10 = param_4;
  gf_sub(&local_60,param_1,param_2);
  gf_strong_reduce(&local_60);
  local_24 = local_24 |
             local_28 |
             local_2c |
             local_30 |
             local_38 |
             local_3c |
             local_44 | local_4c | local_50 | local_58 | local_5c | local_60 | local_54 | local_48 |
             local_40 | local_34;
  return (int)(local_24 - 1 & ~local_24) >> 0x1f;
}

