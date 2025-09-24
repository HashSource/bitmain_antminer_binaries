
undefined4 tls12_sigalg_allowed_part_16(SSL *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  stack_st_SSL_CIPHER *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  short sVar9;
  bool bVar10;
  undefined4 local_24;
  
  if (-1 < *(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c) {
    iVar6 = *(int *)param_1->type;
    if ((iVar6 != 0x10000 && 0x303 < iVar6) && (*(int *)(param_3 + 0x10) == 0x74)) {
      return 0;
    }
    if ((param_1->in_handshake == 0) && (0x303 < *(int *)(param_1->mac_flags + 0x2a8))) {
      if (*(int *)(param_3 + 0x10) == 0x74) {
        return 0;
      }
      uVar7 = *(uint *)(param_3 + 0xc);
      bVar10 = 9 < uVar7;
      if (uVar7 != 10) {
        bVar10 = uVar7 != 0;
      }
      if (!bVar10 || (uVar7 == 10 || uVar7 == 1)) {
        return 0;
      }
    }
  }
  iVar6 = ssl_cert_is_disabled(*(undefined4 *)(param_3 + 0x14));
  if (iVar6 != 0) {
    return 0;
  }
  uVar7 = *(uint *)(param_3 + 0x10);
  bVar10 = 0x32a < uVar7;
  if (uVar7 != 0x32b) {
    bVar10 = uVar7 != 0x3d3;
  }
  if (!bVar10 || (uVar7 == 0x32b || uVar7 == 0x3d4)) {
    piVar8 = (int *)param_1->type;
    if (param_1->in_handshake == 0) {
      if ((*piVar8 == 0x10000) && (0x303 < *(int *)(param_1->mac_flags + 0x2ac))) {
        if (0x303 < *(int *)(param_1->mac_flags + 0x2a8)) {
          return 0;
        }
        psVar2 = SSL_get_ciphers(param_1);
        if (psVar2 == (stack_st_SSL_CIPHER *)0x0) {
          return 0;
        }
        iVar3 = OPENSSL_sk_num();
        iVar6 = 0;
        if (iVar3 < 1) {
          if (iVar3 == 0) {
            return 0;
          }
        }
        else {
          while( true ) {
            iVar4 = OPENSSL_sk_value(psVar2,iVar6);
            iVar6 = iVar6 + 1;
            iVar5 = ssl_cipher_disabled(param_1,iVar4,0x10001,0);
            if ((iVar5 == 0) && (*(int *)(iVar4 + 0x10) << 0x1b < 0)) break;
            if (iVar3 == iVar6) {
              return 0;
            }
          }
        }
      }
    }
    else if ((-1 < *(int *)(piVar8[0x19] + 0x30) << 0x1c) && (*piVar8 != 0x10000 && 0x303 < *piVar8)
            ) {
      return 0;
    }
  }
  local_24 = (EVP_MD *)0x0;
  iVar6 = tls1_lookup_md(param_3,&local_24);
  if (iVar6 == 0) {
    sVar9 = *(short *)(param_3 + 4);
    iVar6 = 0;
  }
  else if (local_24 == (EVP_MD *)0x0) {
    sVar9 = *(short *)(param_3 + 4);
    if (sVar9 == 0x807) {
      iVar6 = 0x80;
    }
    else if (sVar9 == 0x808) {
      iVar6 = 0xe0;
    }
    else {
      iVar6 = 0;
    }
  }
  else {
    iVar6 = EVP_MD_size(local_24);
    sVar9 = *(short *)(param_3 + 4);
    iVar6 = iVar6 << 2;
  }
  local_24 = (EVP_MD *)CONCAT31(CONCAT21(local_24._2_2_,(char)sVar9),(char)((ushort)sVar9 >> 8));
  uVar1 = ssl_security(param_1,param_2,iVar6,*(undefined4 *)(param_3 + 8),&local_24);
  return uVar1;
}

