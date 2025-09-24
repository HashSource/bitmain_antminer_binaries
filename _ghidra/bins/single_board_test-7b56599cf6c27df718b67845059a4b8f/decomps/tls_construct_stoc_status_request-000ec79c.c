
undefined4
tls_construct_stoc_status_request
          (int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((param_3 == 0x4000) || (*(int *)(param_1 + 0x548) == 0)) {
    return 2;
  }
  if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
     (iVar1 = **(int **)(param_1 + 4), param_5 != 0 && (iVar1 != 0x10000 && 0x303 < iVar1))) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,5,0,2);
  if ((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) {
    uVar3 = 0x5e9;
  }
  else {
    if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
      iVar2 = **(int **)(param_1 + 4);
      iVar1 = iVar2 + -0x10000;
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      if (iVar2 < 0x304) {
        iVar1 = 0;
      }
      if ((iVar1 != 0) && (iVar1 = tls_construct_cert_status_body(param_1,param_2), iVar1 == 0)) {
        return 0;
      }
    }
    iVar1 = WPACKET_close(param_2);
    if (iVar1 != 0) {
      return 1;
    }
    uVar3 = 0x5f8;
  }
  ossl_statem_fatal(param_1,0x50,0x1cd,0x44,"ssl/statem/extensions_srvr.c",uVar3);
  return 0;
}

