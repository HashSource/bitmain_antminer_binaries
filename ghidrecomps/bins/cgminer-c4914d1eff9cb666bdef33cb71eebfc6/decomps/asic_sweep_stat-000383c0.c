
void asic_sweep_stat(int chain,int chip,int level,_Bool failed)

{
  int iVar1;
  _Bool failed_local;
  int level_local;
  int chip_local;
  int chain_local;
  int offset;
  
  if ((asic_sweep_state != (uint8_t *)0x0) &&
     (iVar1 = chip * 0x28 + chain * 0x960 + level, iVar1 < 0x9600)) {
    asic_sweep_state[iVar1] = failed;
  }
  return;
}

