
bool gost_digests(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  undefined1 *puVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = &gost_digest_nids;
    return (bool)2;
  }
  if (param_4 == 0x329) {
    *param_2 = &digest_gost;
    return true;
  }
  if (param_4 == 0x32f) {
    puVar1 = imit_gost_cpa;
  }
  else {
    puVar1 = (undefined1 *)0x0;
  }
  *param_2 = puVar1;
  return param_4 == 0x32f;
}

