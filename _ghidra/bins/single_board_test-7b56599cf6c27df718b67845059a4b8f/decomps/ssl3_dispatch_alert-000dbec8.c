
int ssl3_dispatch_alert(undefined4 *param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  
  iVar1 = param_1[0x1f];
  *(undefined4 *)(iVar1 + 0xe8) = 0;
  local_20 = 2;
  iVar1 = do_ssl3_write(param_1,0x15,iVar1 + 0xec,&local_20,1,0,auStack_1c);
  if (iVar1 < 1) {
    *(undefined4 *)(param_1[0x1f] + 0xe8) = 1;
    return iVar1;
  }
  BIO_ctrl((BIO *)param_1[3],0xb,0,(void *)0x0);
  if ((code *)param_1[0x21] != (code *)0x0) {
    (*(code *)param_1[0x21])(1,*param_1,0x15,param_1[0x1f] + 0xec,2,param_1,param_1[0x22]);
  }
  pcVar2 = (code *)param_1[0x12d];
  if ((pcVar2 != (code *)0x0) || (pcVar2 = *(code **)(param_1[0x134] + 0xa0), pcVar2 != (code *)0x0)
     ) {
    (*pcVar2)(param_1,0x4008,
              *(ushort *)(param_1[0x1f] + 0xec) << 8 | *(ushort *)(param_1[0x1f] + 0xec) >> 8);
  }
  return iVar1;
}

