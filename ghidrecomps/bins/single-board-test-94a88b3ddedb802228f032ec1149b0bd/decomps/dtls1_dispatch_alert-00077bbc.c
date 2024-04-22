
int dtls1_dispatch_alert(undefined4 *param_1)

{
  undefined *puVar1;
  int iVar2;
  code *pcVar3;
  undefined local_1c;
  undefined local_1b;
  
  iVar2 = param_1[0x16];
  local_1c = *(undefined *)(iVar2 + 400);
  local_1b = *(undefined *)(iVar2 + 0x191);
  *(undefined4 *)(iVar2 + 0x18c) = 0;
  if (*(int *)(iVar2 + 0x108) == 0) {
    puVar1 = &local_1c;
    iVar2 = do_dtls1_write_part_2(param_1,0x15,puVar1,2,0);
  }
  else {
    OpenSSLDie(DAT_00077c7c,0x5e1,DAT_00077c80);
    puVar1 = &local_1c;
    iVar2 = ssl3_write_pending(param_1,0x15,puVar1,2);
  }
  if (iVar2 < 1) {
    puVar1 = (undefined *)0x1;
  }
  if (iVar2 < 1) {
    *(undefined **)(param_1[0x16] + 0x18c) = puVar1;
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
  return iVar2;
}

