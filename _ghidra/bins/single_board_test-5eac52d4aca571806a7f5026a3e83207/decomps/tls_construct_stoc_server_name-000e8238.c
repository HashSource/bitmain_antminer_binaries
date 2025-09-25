
undefined4 tls_construct_stoc_server_name(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((*(int *)(param_1 + 0x5cc) == 1) &&
     ((*(int *)(param_1 + 0x8c) == 0 ||
      ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c &&
       (iVar2 = **(int **)(param_1 + 4), 0x303 < iVar2 && iVar2 != 0x10000)))))) {
    uVar3 = WPACKET_put_bytes__(param_2,param_2,0,0,2);
    if (((int)uVar3 == 0) ||
       (iVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar3 >> 0x20),0,0,2), iVar2 == 0)) {
      ossl_statem_fatal(param_1,0x50,0x1cb,0x44,"ssl/statem/extensions_srvr.c",0x546);
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}

