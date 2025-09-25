
undefined4 tls_construct_ctos_etm(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  if (*(int *)(param_1 + 0x4ec) << 0xc < 0) {
    return 2;
  }
  uVar2 = WPACKET_put_bytes__(param_2,param_2,0x16,0,2);
  if (((int)uVar2 != 0) &&
     (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),0,0,2), iVar1 != 0)) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x1d5,0x44,"ssl/statem/extensions_clnt.c",0x1df);
  return 0;
}

