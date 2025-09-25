
undefined4 dane_match_isra_1(int param_1,int *param_2,X509 *param_3,int param_4)

{
  int iVar1;
  byte *pbVar2;
  X509_PUBKEY *a;
  int iVar3;
  int *piVar4;
  EVP_MD *type;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint local_98;
  uchar *local_94;
  uint local_90;
  size_t local_8c;
  uchar *local_84;
  uint local_70;
  uchar *local_6c;
  uchar auStack_68 [68];
  
  if (param_4 != 0) {
    uVar5 = 1;
  }
  else {
    uVar5 = 2;
  }
  if (param_4 != 0) {
    uVar12 = 5;
  }
  else {
    uVar12 = 10;
  }
  if (param_1 <= param_4) {
    uVar12 = uVar5;
  }
  if (-1 < param_2[6]) {
    uVar12 = uVar12 & 0xfffffffc;
  }
  local_70 = 0;
  if (((uVar12 & param_2[5]) == 0) || (iVar1 = OPENSSL_sk_num(param_2[1]), iVar1 < 1)) {
    uVar6 = 0;
    local_94 = (uchar *)0x0;
  }
  else {
    uVar10 = 0x100;
    local_90 = 0x100;
    local_98 = 0x100;
    local_8c = 0;
    iVar7 = 0;
    local_84 = (uchar *)0x0;
    local_94 = (uchar *)0x0;
    uVar5 = 0x100;
    do {
      pbVar2 = (byte *)OPENSSL_sk_value(param_2[1],iVar7);
      uVar8 = (uint)*pbVar2;
      if ((int)((uVar12 >> uVar8) << 0x1f) < 0) {
        if (uVar8 != uVar5) {
          uVar10 = 0x100;
          local_90 = (uint)*(byte *)(*(int *)(*param_2 + 4) + (uint)pbVar2[2]);
        }
        uVar9 = (uint)pbVar2[1];
        uVar5 = uVar8;
        if (uVar9 == local_98) {
          uVar11 = (uint)pbVar2[2];
          if ((uVar11 == 0) || (local_90 <= *(byte *)(*(int *)(*param_2 + 4) + uVar11))) {
            if (uVar10 != uVar11) {
              piVar4 = (int *)*param_2;
              goto LAB_001643de;
            }
            local_98 = uVar9;
            if (local_70 != *(size_t *)(pbVar2 + 8)) goto LAB_0016440e;
            goto LAB_00164438;
          }
        }
        else {
          CRYPTO_free(local_94);
          local_6c = (uchar *)0x0;
          if (uVar9 == 0) {
            local_8c = i2d_X509(param_3,&local_6c);
          }
          else {
            if (uVar9 != 1) {
              ERR_put_error(0xb,0x6b,0x85,"crypto/x509/x509_vfy.c",0xa34);
              return 0xffffffff;
            }
            a = (X509_PUBKEY *)X509_get_X509_PUBKEY(param_3);
            local_8c = i2d_X509_PUBKEY(a,&local_6c);
          }
          if (((int)local_8c < 0) || (local_94 = local_6c, local_6c == (uchar *)0x0)) {
            ERR_put_error(0xb,0x6b,0x41,"crypto/x509/x509_vfy.c",0xa39);
            return 0xffffffff;
          }
          piVar4 = (int *)*param_2;
          uVar11 = (uint)pbVar2[2];
          local_90 = (uint)*(byte *)(piVar4[1] + uVar11);
LAB_001643de:
          type = *(EVP_MD **)(*piVar4 + uVar11 * 4);
          local_70 = local_8c;
          if (type == (EVP_MD *)0x0) {
            local_84 = local_94;
          }
          else {
            iVar3 = EVP_Digest(local_94,local_8c,auStack_68,&local_70,type,(ENGINE *)0x0);
            local_84 = auStack_68;
            if (iVar3 == 0) {
              uVar6 = 0xffffffff;
              goto LAB_0016431c;
            }
          }
          uVar10 = uVar11;
          local_98 = uVar9;
          if (local_70 == *(size_t *)(pbVar2 + 8)) {
LAB_00164438:
            iVar3 = memcmp(local_84,*(void **)(pbVar2 + 4),local_70);
            local_98 = uVar9;
            if (iVar3 == 0) {
              if ((0xcU >> uVar8 & 1) == 0) {
                uVar6 = 0;
                if (-1 < param_2[6]) goto LAB_0016431c;
              }
              else {
                uVar6 = 1;
              }
              param_2[6] = param_4;
              param_2[3] = (int)pbVar2;
              CRYPTO_free((void *)param_2[4]);
              param_2[4] = (int)param_3;
              X509_up_ref(param_3);
              goto LAB_0016431c;
            }
          }
        }
      }
LAB_0016440e:
      iVar7 = iVar7 + 1;
    } while (iVar1 != iVar7);
    uVar6 = 0;
  }
LAB_0016431c:
  CRYPTO_free(local_94);
  return uVar6;
}

