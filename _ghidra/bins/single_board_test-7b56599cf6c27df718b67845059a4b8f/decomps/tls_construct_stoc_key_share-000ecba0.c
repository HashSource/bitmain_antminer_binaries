
undefined4 tls_construct_stoc_key_share(int param_1,undefined4 param_2)

{
  int iVar1;
  EVP_PKEY *pkey;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  void *local_24 [2];
  
  iVar4 = *(int *)(*(int *)(param_1 + 0x7c) + 0x358);
  if (*(int *)(param_1 + 0x44c) == 1) {
    if (iVar4 != 0) {
      return 2;
    }
    iVar4 = WPACKET_put_bytes__(param_2,param_2,0x33,0,2);
    if (iVar4 != 0) {
      uVar5 = WPACKET_start_sub_packet_len__(param_2,2);
      if ((((int)uVar5 != 0) &&
          (iVar4 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar5 >> 0x20),
                                       *(undefined2 *)(*(int *)(param_1 + 0x7c) + 0x356),0,2),
          iVar4 != 0)) && (iVar4 = WPACKET_close(param_2), iVar4 != 0)) {
        return 1;
      }
    }
    uVar2 = 0x6a4;
  }
  else if (iVar4 == 0) {
    if ((*(int *)(param_1 + 0x8c) != 0) &&
       (iVar4 = tls13_generate_handshake_secret(param_1,0,0), iVar4 != 0)) {
      return 2;
    }
    uVar2 = 0x6af;
  }
  else {
    if ((*(int *)(param_1 + 0x8c) != 0) && (-1 < *(int *)(param_1 + 0x5a4) << 0x1e)) {
      return 2;
    }
    iVar1 = WPACKET_put_bytes__(param_2,param_2,0x33,0,2);
    if (iVar1 != 0) {
      uVar5 = WPACKET_start_sub_packet_len__(param_2,2);
      if (((int)uVar5 != 0) &&
         (iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar5 >> 0x20),
                                      *(undefined2 *)(*(int *)(param_1 + 0x7c) + 0x356),0,2),
         iVar1 != 0)) {
        pkey = (EVP_PKEY *)ssl_generate_pkey(iVar4);
        if (pkey != (EVP_PKEY *)0x0) {
          iVar1 = EVP_PKEY_get1_tls_encodedpoint(pkey,local_24);
          if (iVar1 == 0) {
            ossl_statem_fatal(param_1,0x50,0x1c8,0x10,"ssl/statem/extensions_srvr.c",0x6cf);
            EVP_PKEY_free(pkey);
            return 0;
          }
          iVar1 = WPACKET_sub_memcpy__(param_2,local_24[0],iVar1,2);
          if ((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
            CRYPTO_free(local_24[0]);
            *(EVP_PKEY **)(*(int *)(param_1 + 0x7c) + 0x214) = pkey;
            iVar4 = ssl_derive(param_1,pkey,iVar4,1);
            if (iVar4 != 0) {
              return 1;
            }
            return 0;
          }
          ossl_statem_fatal(param_1,0x50,0x1c8,0x44,"ssl/statem/extensions_srvr.c",0x6d7);
          EVP_PKEY_free(pkey);
          CRYPTO_free(local_24[0]);
          return 0;
        }
        uVar2 = 0x6c7;
        uVar3 = 0x41;
        goto LAB_000ecc0c;
      }
    }
    uVar2 = 0x6c0;
  }
  uVar3 = 0x44;
LAB_000ecc0c:
  ossl_statem_fatal(param_1,0x50,0x1c8,uVar3,"ssl/statem/extensions_srvr.c",uVar2);
  return 0;
}

