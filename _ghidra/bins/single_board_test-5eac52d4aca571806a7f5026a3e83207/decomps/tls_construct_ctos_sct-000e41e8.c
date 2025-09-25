
undefined4 tls_construct_ctos_sct(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  undefined8 uVar2;
  
  if (param_4 != 0) {
    param_4 = 1;
  }
  if (*(int *)(param_1 + 0x5d0) == 0) {
    param_4 = param_4 | 1;
  }
  if (param_4 == 0) {
    uVar2 = WPACKET_put_bytes__(param_2,param_2,0x12,0,2);
    if (((int)uVar2 != 0) &&
       (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),0,0,2), iVar1 != 0)) {
      return 1;
    }
    ossl_statem_fatal(param_1,0x50,0x1da,0x44,"ssl/statem/extensions_clnt.c",500);
    return 0;
  }
  return 2;
}

