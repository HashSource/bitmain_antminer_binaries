
undefined4 tls_construct_ctos_use_srtp(SSL *param_1,undefined4 param_2)

{
  stack_st_SRTP_PROTECTION_PROFILE *psVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined8 uVar6;
  
  psVar1 = SSL_get_srtp_profiles(param_1);
  if (psVar1 == (stack_st_SRTP_PROTECTION_PROFILE *)0x0) {
    return 2;
  }
  iVar2 = WPACKET_put_bytes__(param_2);
  if (((iVar2 == 0) || (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) ||
     (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) {
    uVar4 = 0x1ba;
  }
  else {
    iVar2 = OPENSSL_sk_num(psVar1);
    if (0 < iVar2) {
      iVar3 = 0;
      do {
        iVar5 = iVar3 + 1;
        uVar6 = OPENSSL_sk_value(psVar1,iVar3);
        if (((int)uVar6 == 0) ||
           (iVar3 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),
                                        *(undefined4 *)((int)uVar6 + 4),0,2), iVar3 == 0)) {
          uVar4 = 0x1c5;
          goto LAB_000e40e4;
        }
        iVar3 = iVar5;
      } while (iVar5 != iVar2);
    }
    uVar6 = WPACKET_close(param_2);
    if ((((int)uVar6 != 0) &&
        (iVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar6 >> 0x20),0,0,1), iVar2 != 0)) &&
       (iVar2 = WPACKET_close(param_2), iVar2 != 0)) {
      return 1;
    }
    uVar4 = 0x1ce;
  }
LAB_000e40e4:
  ossl_statem_fatal(param_1,0x50,0x1e2,0x44,"ssl/statem/extensions_clnt.c",uVar4);
  return 0;
}

