
int tls_construct_server_certificate(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x264);
  if (iVar2 == 0) {
    ossl_statem_fatal(param_1,0x50,0x1ea,0x44,"ssl/statem/statem_srvr.c",0xed7);
    iVar2 = 0;
  }
  else if (((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
           (iVar1 = **(int **)(param_1 + 4), iVar1 == 0x10000 || iVar1 < 0x304)) ||
          (iVar1 = WPACKET_put_bytes__(param_2,param_2,0,0,1), iVar1 != 0)) {
    iVar2 = ssl3_output_cert_chain(param_1,param_2,iVar2);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
  }
  else {
    ossl_statem_fatal(param_1,0x50,0x1ea,0x44,"ssl/statem/statem_srvr.c",0xee1);
    iVar2 = 0;
  }
  return iVar2;
}

