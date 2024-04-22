
int ENGINE_ctrl_cmd_string(ENGINE *e,char *cmd_name,char *arg,int cmd_optional)

{
  int iVar1;
  uint uVar2;
  long lVar3;
  char *local_1c;
  
  if (e == (ENGINE *)0x0 || cmd_name == (char *)0x0) {
    ERR_put_error(0x26,0xab,0x43,DAT_000a7190,0x124);
    iVar1 = 0;
  }
  else if ((*(int *)(e + 0x40) == 0) || (iVar1 = ENGINE_ctrl_constprop_1(), iVar1 < 1)) {
    if (cmd_optional == 0) {
      ERR_put_error(0x26,0xab,0x89,DAT_000a7190,0x137);
      iVar1 = 0;
    }
    else {
      ERR_clear_error();
      iVar1 = 1;
    }
  }
  else {
    uVar2 = ENGINE_ctrl_constprop_2(e,0x12,iVar1);
    if ((int)uVar2 < 0) {
      ERR_put_error(0x26,0xaa,0x8a,DAT_000a7190,0xed);
    }
    else if ((uVar2 & 7) != 0) {
      uVar2 = ENGINE_ctrl_constprop_2(e,0x12,iVar1);
      if ((int)uVar2 < 0) {
        ERR_put_error(0x26,0xab,0x6e,DAT_000a7190,0x146);
        return 0;
      }
      if ((uVar2 & 4) != 0) {
        if (arg != (char *)0x0) {
          ERR_put_error(0x26,0xab,0x88,DAT_000a7190,0x14f);
          return 0;
        }
        iVar1 = ENGINE_ctrl(e,iVar1,0,(void *)0x0,(f *)0x0);
        return (uint)(0 < iVar1);
      }
      if (arg == (char *)0x0) {
        ERR_put_error(0x26,0xab,0x87,DAT_000a7190,0x15f);
        return 0;
      }
      if (-1 < (int)(uVar2 << 0x1e)) {
        if (-1 < (int)(uVar2 << 0x1f)) {
          ERR_put_error(0x26,0xab,0x6e,DAT_000a7190,0x171);
          return 0;
        }
        lVar3 = strtol(arg,&local_1c,10);
        if ((arg != local_1c) && (*local_1c == '\0')) {
          iVar1 = ENGINE_ctrl_constprop_2(e,iVar1,lVar3);
          return (uint)(0 < iVar1);
        }
        ERR_put_error(0x26,0xab,0x85,DAT_000a7190,0x177);
        return 0;
      }
      iVar1 = ENGINE_ctrl(e,iVar1,0,arg,(f *)0x0);
      return (uint)(0 < iVar1);
    }
    ERR_put_error(0x26,0xab,0x86,DAT_000a7190,0x13c);
    iVar1 = 0;
  }
  return iVar1;
}

