
undefined4 tls_construct_stoc_etm(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x5a8) == 0) {
    return 2;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
  if ((*(int *)(iVar1 + 0x1c) != 0x40) &&
     (iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0x40000 && (iVar1 != 4 && iVar1 != 0x400))) {
    uVar2 = WPACKET_put_bytes__(param_2,param_2,0x16,0,2);
    if (((int)uVar2 != 0) &&
       (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),0,0,2), iVar1 != 0)) {
      return 1;
    }
    ossl_statem_fatal(param_1,0x50,0x1c7,0x44,"ssl/statem/extensions_srvr.c",0x661);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x5a8) = 0;
  return 2;
}

