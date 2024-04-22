
int ENGINE_ctrl_cmd(ENGINE *e,char *cmd_name,long i,void *p,f *f,int cmd_optional)

{
  int iVar1;
  
  if (e == (ENGINE *)0x0 || cmd_name == (char *)0x0) {
    ERR_put_error(0x26,0xb2,0x43,DAT_000a7004,0xfd);
    iVar1 = 0;
  }
  else if ((*(int *)(e + 0x40) == 0) || (iVar1 = ENGINE_ctrl_constprop_1(), iVar1 < 1)) {
    if (cmd_optional == 0) {
      ERR_put_error(0x26,0xb2,0x89,DAT_000a7004,0x110);
      iVar1 = 0;
    }
    else {
      ERR_clear_error();
      iVar1 = 1;
    }
  }
  else {
    iVar1 = ENGINE_ctrl(e,iVar1,i,p,f);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
  return iVar1;
}

