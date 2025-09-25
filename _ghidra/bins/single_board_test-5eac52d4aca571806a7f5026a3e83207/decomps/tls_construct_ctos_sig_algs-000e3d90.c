
undefined4 tls_construct_ctos_sig_algs(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined8 uVar2;
  undefined4 local_1c [2];
  
  iVar1 = *(int *)(param_1 + 0x504);
  if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
    if (iVar1 != 0x100 && iVar1 < 0xfefe) {
LAB_000e3dc8:
      uVar2 = tls12_get_psigalgs(param_1,1,local_1c);
      iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar2 >> 0x20),0xd,0,2);
      if ((((iVar1 != 0) && (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
          (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) &&
         (((iVar1 = tls12_copy_sigalgs(param_1,param_2,local_1c[0],(int)uVar2), iVar1 != 0 &&
           (iVar1 = WPACKET_close(param_2), iVar1 != 0)) &&
          (iVar1 = WPACKET_close(param_2), iVar1 != 0)))) {
        return 1;
      }
      ossl_statem_fatal(param_1,0x50,0x1dd,0x44,"ssl/statem/extensions_clnt.c",0x12a);
      return 0;
    }
  }
  else if (0x302 < iVar1) goto LAB_000e3dc8;
  return 2;
}

