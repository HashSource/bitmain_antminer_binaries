
int ENGINE_ctrl(ENGINE *e,int cmd,long i,void *p,f *f)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,DAT_000a6f5c,0xb7);
    pcVar1 = (code *)0x0;
  }
  else {
    CRYPTO_lock(9,0x1e,DAT_000a6f5c,0xba);
    iVar3 = *(int *)(e + 0x58);
    CRYPTO_lock(10,0x1e,DAT_000a6f5c,0xbc);
    pcVar2 = *(code **)(e + 0x40);
    pcVar1 = pcVar2;
    if (pcVar2 != (code *)0x0) {
      pcVar1 = (code *)0x1;
    }
    if (iVar3 < 1) {
      ERR_put_error(0x26,0x8e,0x82,DAT_000a6f5c,0xbf);
      pcVar1 = (code *)0x0;
    }
    else if (cmd != 10) {
      if ((cmd < 10) || (0x12 < cmd)) {
        if (pcVar1 == (code *)0x0) {
          ERR_put_error(0x26,0x8e,0x78,DAT_000a6f5c,0xe1);
          return 0;
        }
      }
      else {
        if (pcVar1 == (code *)0x0) {
          ERR_put_error(0x26,0x8e,0x78,DAT_000a6f5c,0xd4);
          return -1;
        }
        if (-1 < *(int *)(e + 0x54) << 0x1e) {
          iVar3 = int_ctrl_helper_isra_0(e,cmd,i,p);
          return iVar3;
        }
      }
      pcVar1 = (code *)(*pcVar2)(e,cmd,i,p,f);
    }
  }
  return (int)pcVar1;
}

