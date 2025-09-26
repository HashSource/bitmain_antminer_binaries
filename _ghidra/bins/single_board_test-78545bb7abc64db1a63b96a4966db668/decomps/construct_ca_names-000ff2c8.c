
undefined4 construct_ca_names(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  X509_NAME *a;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uchar *puStack_24;
  
  iVar1 = WPACKET_start_sub_packet_len__(param_3,2);
  if (iVar1 == 0) {
    uVar4 = 0x920;
  }
  else {
    if (param_2 != 0) {
      iVar1 = 0;
      while( true ) {
        iVar3 = OPENSSL_sk_num(param_2);
        if (iVar3 <= iVar1) break;
        a = (X509_NAME *)OPENSSL_sk_value(param_2,iVar1);
        if ((((a == (X509_NAME *)0x0) || (iVar3 = i2d_X509_NAME(a,(uchar **)0x0), iVar3 < 0)) ||
            (iVar2 = WPACKET_sub_allocate_bytes__(param_3,iVar3,&puStack_24,2), iVar2 == 0)) ||
           (iVar2 = i2d_X509_NAME(a,&puStack_24), iVar1 = iVar1 + 1, iVar3 != iVar2)) {
          ossl_statem_fatal(param_1,0x50,0x228,0x44,"ssl/statem/statem_lib.c",0x932);
          return 0;
        }
      }
    }
    iVar1 = WPACKET_close(param_3);
    if (iVar1 != 0) {
      return 1;
    }
    uVar4 = 0x93a;
  }
  ossl_statem_fatal(param_1,0x50,0x228,0x44,"ssl/statem/statem_lib.c",uVar4);
  return 0;
}

