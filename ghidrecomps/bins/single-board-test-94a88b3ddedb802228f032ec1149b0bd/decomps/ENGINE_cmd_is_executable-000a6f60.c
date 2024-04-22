
int ENGINE_cmd_is_executable(ENGINE *e,int cmd)

{
  uint uVar1;
  
  uVar1 = ENGINE_ctrl_constprop_2(e,0x12,cmd);
  if ((int)uVar1 < 0) {
    ERR_put_error(0x26,0xaa,0x8a,DAT_000a6f90,0xed);
    uVar1 = 0;
  }
  else {
    uVar1 = uVar1 & 7;
    if (uVar1 != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}

