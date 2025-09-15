
int _get_target_chip_temp_t11a(_Bool is_low_temp_env,int min_entrance_pcb_temp)

{
  int iVar1;
  int min_entrance_pcb_temp_local;
  _Bool is_low_temp_env_local;
  
  if (min_entrance_pcb_temp < 0x16) {
    iVar1 = 0x55;
  }
  else if (min_entrance_pcb_temp < 0x1a) {
    if (is_low_temp_env) {
      iVar1 = 0x55;
    }
    else {
      iVar1 = 0x3e;
    }
  }
  else if (min_entrance_pcb_temp < 0x1f) {
    iVar1 = 0x3e;
  }
  else if (min_entrance_pcb_temp < 0x2d) {
    iVar1 = ((min_entrance_pcb_temp + -0x1e) * 0xe) / 0xf + 0x3e;
  }
  else {
    iVar1 = 0x4c;
  }
  return iVar1;
}

