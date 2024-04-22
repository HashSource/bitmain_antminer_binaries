
int ssl3_dispatch_alert(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = param_1[0x16];
  *(undefined4 *)(iVar2 + 0x18c) = 0;
  iVar2 = iVar2 + 400;
  iVar1 = do_ssl3_write(param_1,0x15,iVar2,2,0);
  if (iVar1 < 1) {
    iVar2 = 1;
  }
  if (iVar1 < 1) {
    *(int *)(param_1[0x16] + 0x18c) = iVar2;
  }
  else {
    if (*(char *)(param_1[0x16] + 400) == '\x02') {
      BIO_ctrl((BIO *)param_1[4],0xb,0,(void *)0x0);
    }
    if ((code *)param_1[0x19] != (code *)0x0) {
      (*(code *)param_1[0x19])(1,*param_1,0x15,param_1[0x16] + 400,2,param_1,param_1[0x1a]);
    }
    pcVar3 = (code *)param_1[0x34];
    if ((pcVar3 != (code *)0x0) ||
       (pcVar3 = *(code **)(param_1[0x39] + 0x9c), pcVar3 != (code *)0x0)) {
      (*pcVar3)(param_1,0x4008,
                CONCAT11(*(undefined *)(param_1[0x16] + 400),*(undefined *)(param_1[0x16] + 0x191)))
      ;
    }
  }
  return iVar1;
}

