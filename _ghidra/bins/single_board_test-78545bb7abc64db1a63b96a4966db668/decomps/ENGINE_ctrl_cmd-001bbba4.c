
int ENGINE_ctrl_cmd(ENGINE *e,char *cmd_name,long i,void *p,f *f,int cmd_optional)

{
  int iVar1;
  
  if (cmd_name == (char *)0x0 || e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0xb2,0x43,"crypto/engine/eng_ctrl.c",199);
    return 0;
  }
  if ((*(int *)(e + 0x38) != 0) && (iVar1 = ENGINE_ctrl(e,0xd,0,cmd_name,(f *)0x0), 0 < iVar1)) {
    iVar1 = ENGINE_ctrl(e,iVar1,i,p,f);
    return (uint)(0 < iVar1);
  }
  if (cmd_optional == 0) {
    ERR_put_error(0x26,0xb2,0x89,"crypto/engine/eng_ctrl.c",0xd9);
    return 0;
  }
  ERR_clear_error();
  return 1;
}

