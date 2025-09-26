
int dtls1_dispatch_alert(undefined4 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 auStack_1c [8];
  
  iVar2 = param_1[0x1f];
  local_20 = *(undefined1 *)(iVar2 + 0xec);
  local_1f = *(undefined1 *)(iVar2 + 0xed);
  *(undefined4 *)(iVar2 + 0xe8) = 0;
  iVar2 = do_dtls1_write(param_1,0x15,&local_20,2,0,auStack_1c);
  if (iVar2 < 1) {
    *(undefined4 *)(param_1[0x1f] + 0xe8) = 1;
    return iVar2;
  }
  BIO_ctrl((BIO *)param_1[3],0xb,0,(void *)0x0);
  if ((code *)param_1[0x21] != (code *)0x0) {
    (*(code *)param_1[0x21])(1,*param_1,0x15,param_1[0x1f] + 0xec,2,param_1,param_1[0x22]);
  }
  pcVar1 = (code *)param_1[0x12d];
  if ((pcVar1 != (code *)0x0) || (pcVar1 = *(code **)(param_1[0x134] + 0xa0), pcVar1 != (code *)0x0)
     ) {
    (*pcVar1)(param_1,0x4008,
              *(ushort *)(param_1[0x1f] + 0xec) << 8 | *(ushort *)(param_1[0x1f] + 0xec) >> 8);
  }
  return iVar2;
}

