
/* WARNING: Unknown calling convention */
/* Local variable vol_value:int[r0:4] conflicts with parameter, skipped. */

int getVoltageLimitedFromHashrate(int hashrate_GHz)

{
  int iVar1;
  
  if (11999 < hashrate_GHz) {
    return 0x32a;
  }
  if (0x2ceb < hashrate_GHz) {
    return 0x33e;
  }
  if (10999 < hashrate_GHz) {
    return 0x352;
  }
  if (0x2903 < hashrate_GHz) {
    return 0x366;
  }
  if (9999 < hashrate_GHz) {
    return 0x37a;
  }
  if (hashrate_GHz < 0x251c) {
    iVar1 = 0x3a2;
  }
  else {
    iVar1 = 0x398;
  }
  return iVar1;
}

