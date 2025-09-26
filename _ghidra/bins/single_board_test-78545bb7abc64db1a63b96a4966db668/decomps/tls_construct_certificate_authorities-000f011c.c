
undefined4 tls_construct_certificate_authorities(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  iVar1 = get_ca_names();
  if (iVar1 != 0) {
    uVar4 = OPENSSL_sk_num();
    if ((int)uVar4 != 0) {
      iVar2 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar4 >> 0x20),0x2f,0,2);
      if ((iVar2 == 0) || (iVar2 = WPACKET_start_sub_packet_len__(param_2,2), iVar2 == 0)) {
        uVar3 = 0x4dc;
      }
      else {
        iVar1 = construct_ca_names(param_1,iVar1,param_2);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = WPACKET_close(param_2);
        if (iVar1 != 0) {
          return 1;
        }
        uVar3 = 0x4e8;
      }
      ossl_statem_fatal(param_1,0x50,0x21e,0x44,"ssl/statem/extensions.c",uVar3);
      return 0;
    }
  }
  return 2;
}

