
undefined4 tls_construct_ctos_key_share(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  uint uVar5;
  EVP_PKEY *pkey;
  int iVar6;
  undefined8 uVar7;
  uint local_2c;
  int local_28;
  void *local_24 [2];
  
  local_2c = 0;
  local_28 = 0;
  iVar1 = WPACKET_put_bytes__(param_2,0,0x33,0,2);
  if (((iVar1 == 0) || (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) ||
     (iVar1 = WPACKET_start_sub_packet_len__(param_2,2), iVar1 == 0)) {
    uVar2 = 0x2a1;
  }
  else {
    tls1_get_supported_groups(param_1,&local_28,&local_2c);
    iVar1 = *(int *)(param_1 + 0x7c);
    sVar4 = *(short *)(iVar1 + 0x356);
    if (sVar4 == 0) {
      uVar5 = 0;
      if (local_2c != 0) {
        do {
          iVar6 = uVar5 * 2;
          iVar1 = uVar5 * 2;
          uVar5 = uVar5 + 1;
          iVar1 = tls_curve_allowed(param_1,*(undefined2 *)(local_28 + iVar1),0x20004);
          if (iVar1 != 0) {
            sVar4 = *(short *)(local_28 + iVar6);
            if (sVar4 != 0) {
              iVar1 = *(int *)(param_1 + 0x7c);
              goto LAB_000e44e8;
            }
            break;
          }
        } while (uVar5 < local_2c);
      }
      uVar2 = 0x2ba;
      uVar3 = 0x65;
      goto LAB_000e4474;
    }
LAB_000e44e8:
    pkey = *(EVP_PKEY **)(iVar1 + 0x214);
    local_24[0] = (void *)0x0;
    if (pkey == (EVP_PKEY *)0x0) {
      pkey = (EVP_PKEY *)ssl_generate_pkey_group(param_1,sVar4);
      if (pkey == (EVP_PKEY *)0x0) {
        return 0;
      }
    }
    else if (*(int *)(param_1 + 0x44c) != 1) {
      ossl_statem_fatal(param_1,0x50,0x200,0x44,"ssl/statem/extensions_clnt.c",0x260);
      return 0;
    }
    uVar7 = EVP_PKEY_get1_tls_encodedpoint(pkey,local_24);
    if ((int)uVar7 == 0) {
      uVar3 = 0x273;
      uVar2 = 0x10;
LAB_000e4514:
      ossl_statem_fatal(param_1,0x50,0x200,uVar2,"ssl/statem/extensions_clnt.c",uVar3);
      if (*(int *)(*(int *)(param_1 + 0x7c) + 0x214) == 0) {
        EVP_PKEY_free(pkey);
      }
      CRYPTO_free(local_24[0]);
      return 0;
    }
    iVar1 = WPACKET_put_bytes__(param_2,(int)((ulonglong)uVar7 >> 0x20),sVar4,0,2);
    if ((iVar1 == 0) || (iVar1 = WPACKET_sub_memcpy__(param_2,local_24[0],(int)uVar7,2), iVar1 == 0)
       ) {
      uVar3 = 0x27b;
      uVar2 = 0x44;
      goto LAB_000e4514;
    }
    iVar1 = *(int *)(param_1 + 0x7c);
    *(EVP_PKEY **)(iVar1 + 0x214) = pkey;
    *(short *)(iVar1 + 0x356) = sVar4;
    CRYPTO_free(local_24[0]);
    iVar1 = WPACKET_close(param_2);
    if ((iVar1 != 0) && (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
      return 1;
    }
    uVar2 = 0x2c5;
  }
  uVar3 = 0x44;
LAB_000e4474:
  ossl_statem_fatal(param_1,0x50,0x1d6,uVar3,"ssl/statem/extensions_clnt.c",uVar2);
  return 0;
}

