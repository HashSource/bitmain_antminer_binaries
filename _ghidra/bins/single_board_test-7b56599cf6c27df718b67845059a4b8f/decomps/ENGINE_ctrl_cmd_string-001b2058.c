
int ENGINE_ctrl_cmd_string(ENGINE *e,char *cmd_name,char *arg,int cmd_optional)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  long i;
  uint uVar4;
  char *local_1c;
  
  if (cmd_name == (char *)0x0 || e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xab,0x43,"crypto/engine/eng_ctrl.c",0xed);
    return 0;
  }
  uVar4 = 0;
  if ((*(int *)(e + 0x38) == 0) || (iVar1 = ENGINE_ctrl(e,0xd,0,cmd_name,(f *)0x0), iVar1 < 1)) {
    if (cmd_optional != 0) {
      ERR_clear_error();
      return 1;
    }
    ERR_put_error(0x26,0xab,0x89,"crypto/engine/eng_ctrl.c",0xff);
    uVar4 = 0;
  }
  else {
    iVar2 = ENGINE_cmd_is_executable(e,iVar1);
    if (iVar2 == 0) {
      ERR_put_error(0x26,0xab,0x86,"crypto/engine/eng_ctrl.c",0x104);
      return 0;
    }
    uVar3 = ENGINE_ctrl(e,0x12,iVar1,(void *)0x0,(f *)0x0);
    if ((int)uVar3 < 0) {
      ERR_put_error(0x26,0xab,0x6e,"crypto/engine/eng_ctrl.c",0x10f);
    }
    else if ((uVar3 & 4) == 0) {
      if (arg == (char *)0x0) {
        ERR_put_error(0x26,0xab,0x87,"crypto/engine/eng_ctrl.c",0x128);
        uVar4 = 0;
      }
      else {
        if ((int)(uVar3 << 0x1e) < 0) {
          i = 0;
        }
        else {
          if ((uVar3 & 1) == 0) {
            ERR_put_error(0x26,0xab,0x6e,"crypto/engine/eng_ctrl.c",0x13a);
            return 0;
          }
          i = strtol(arg,&local_1c,10);
          if ((arg == local_1c) || (*local_1c != '\0')) {
            ERR_put_error(0x26,0xab,0x85,"crypto/engine/eng_ctrl.c",0x140);
            return 0;
          }
          arg = (char *)0x0;
        }
        iVar1 = ENGINE_ctrl(e,iVar1,i,arg,(f *)0x0);
        uVar4 = (uint)(0 < iVar1);
      }
    }
    else if (arg == (char *)0x0) {
      iVar1 = ENGINE_ctrl(e,iVar1,0,(void *)0x0,(f *)0x0);
      uVar4 = (uint)(0 < iVar1);
    }
    else {
      ERR_put_error(0x26,0xab,0x88,"crypto/engine/eng_ctrl.c",0x118);
    }
  }
  return uVar4;
}

