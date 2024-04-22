
byte * create_hostcache_id(undefined4 param_1,undefined4 param_2)

{
  byte *pbVar1;
  __int32_t **pp_Var2;
  uint uVar3;
  byte *pbVar4;
  
  pbVar1 = (byte *)curl_maprintf(DAT_0003d530,param_1,param_2);
  if ((pbVar1 != (byte *)0x0) && (uVar3 = (uint)*pbVar1, uVar3 != 0 && uVar3 != 0x3a)) {
    pbVar4 = pbVar1 + -1;
    do {
      pp_Var2 = __ctype_tolower_loc();
      pbVar4[1] = (byte)(*pp_Var2)[uVar3];
      uVar3 = (uint)pbVar4[2];
      pbVar4 = pbVar4 + 1;
    } while (uVar3 != 0x3a && uVar3 != 0);
  }
  return pbVar1;
}

