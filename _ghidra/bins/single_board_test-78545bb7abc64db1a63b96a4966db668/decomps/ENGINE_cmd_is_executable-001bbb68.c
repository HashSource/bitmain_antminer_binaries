
int ENGINE_cmd_is_executable(ENGINE *e,int cmd)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  uVar1 = ENGINE_ctrl(e,0x12,cmd,(void *)0x0,(f *)0x0);
  if ((int)uVar1 < 0) {
    ERR_put_error(0x26,0xaa,0x8a,"crypto/engine/eng_ctrl.c",0xb7);
  }
  else {
    uVar2 = uVar1 & 7;
    if (uVar2 != 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}

