
undefined4 tls_construct_stoc_session_ticket(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x55c) == 0) || (iVar1 = tls_use_ticket(), iVar1 == 0)) {
    *(undefined4 *)(param_1 + 0x55c) = 0;
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,0x23,0,2);
  if ((iVar1 != 0) && (iVar1 = WPACKET_put_bytes__(param_2,param_2,0,0,2), iVar1 != 0)) {
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x1cc,0x44,"ssl/statem/extensions_srvr.c",0x5d0);
  return 0;
}

