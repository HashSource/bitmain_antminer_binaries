
/* WARNING: Unknown calling convention */

float get_miner_power(void)

{
  float fVar1;
  
  fVar1 = bitmain_get_power_ac_power();
  return fVar1;
}

