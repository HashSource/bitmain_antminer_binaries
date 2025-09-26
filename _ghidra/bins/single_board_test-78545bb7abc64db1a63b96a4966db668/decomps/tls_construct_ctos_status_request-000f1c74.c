
undefined4
tls_construct_ctos_status_request(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  OCSP_RESPID *a;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  uchar *apuStack_24 [2];
  
  if (param_4 != 0) {
    return 2;
  }
  if (*(int *)(param_1 + 0x53c) != 1) {
    return 2;
  }
  iVar1 = WPACKET_put_bytes__(param_2,param_2,5,0,2);
  if (iVar1 != 0) {
    uVar5 = WPACKET_start_sub_packet_len__(param_2,2);
    if ((((int)uVar5 != 0) &&
        (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar5 >> 0x20),1,0,1), iVar1 != 0)) &&
       (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 != 0)) {
      iVar1 = 0;
      do {
        iVar3 = OPENSSL_sk_num(*(undefined4 *)(param_1 + 0x54c));
        if (iVar3 <= iVar1) {
          iVar1 = WPACKET_close(param_2);
          if ((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) {
            uVar4 = 0x15b;
            goto LAB_000f1cbe;
          }
          if (*(X509_EXTENSIONS **)(param_1 + 0x550) != (X509_EXTENSIONS *)0x0) {
            iVar1 = i2d_X509_EXTENSIONS(*(X509_EXTENSIONS **)(param_1 + 0x550),(uchar **)0x0);
            if (iVar1 < 0) {
              uVar4 = 0x165;
              goto LAB_000f1cbe;
            }
            iVar3 = WPACKET_allocate_bytes(param_2,iVar1,apuStack_24);
            if ((iVar3 == 0) ||
               (iVar3 = i2d_X509_EXTENSIONS(*(X509_EXTENSIONS **)(param_1 + 0x550),apuStack_24),
               iVar1 != iVar3)) {
              uVar4 = 0x16d;
              goto LAB_000f1cbe;
            }
          }
          iVar1 = WPACKET_close(param_2);
          if ((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
            return 1;
          }
          uVar4 = 0x173;
          goto LAB_000f1cbe;
        }
        a = (OCSP_RESPID *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x54c),iVar1);
        iVar3 = i2d_OCSP_RESPID(a,(uchar **)0x0);
      } while (((0 < iVar3) &&
               (iVar2 = WPACKET_sub_allocate_bytes__(param_2,iVar3,apuStack_24,2), iVar2 != 0)) &&
              (iVar2 = i2d_OCSP_RESPID(a,apuStack_24), iVar1 = iVar1 + 1, iVar3 == iVar2));
      uVar4 = 0x154;
      goto LAB_000f1cbe;
    }
  }
  uVar4 = 0x146;
LAB_000f1cbe:
  ossl_statem_fatal(param_1,0x50,0x1df,0x44,"ssl/statem/extensions_clnt.c",uVar4);
  return 0;
}

