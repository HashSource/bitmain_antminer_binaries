
int dtls1_dispatch_alert(undefined4 *param_1)

{
  undefined4 extraout_r2;
  undefined4 uVar1;
  undefined4 extraout_r2_00;
  int iVar2;
  code *pcVar3;
  undefined1 local_1c;
  undefined1 local_1b;
  
  iVar2 = param_1[0x16];
  local_1c = *(undefined1 *)(iVar2 + 400);
  local_1b = *(undefined1 *)(iVar2 + 0x191);
  *(undefined4 *)(iVar2 + 0x18c) = 0;
  if (*(int *)(iVar2 + 0x108) == 0) {
    iVar2 = do_dtls1_write_part_2(param_1,0x15,&local_1c,2,0);
    uVar1 = extraout_r2;
  }
  else {
    OpenSSLDie("d1_pkt.c",0x5e1,"0");
    iVar2 = ssl3_write_pending(param_1,0x15,&local_1c,2);
    uVar1 = extraout_r2_00;
  }
  if (iVar2 < 1) {
    uVar1 = 1;
  }
  if (iVar2 < 1) {
    *(undefined4 *)(param_1[0x16] + 0x18c) = uVar1;
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
                CONCAT11(*(undefined1 *)(param_1[0x16] + 400),*(undefined1 *)(param_1[0x16] + 0x191)
                        ));
    }
  }
  return iVar2;
}

