
int32_t get_vol_comp(int32_t env_temp)

{
  int32_t iVar1;
  int32_t env_temp_local;
  int32_t vol_comp;
  
  if (env_temp < 0x1f) {
    iVar1 = 10;
  }
  else if (env_temp < 0x20) {
    iVar1 = 7;
  }
  else if (env_temp < 0x21) {
    iVar1 = 5;
  }
  else if (env_temp < 0x23) {
    iVar1 = 3;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

