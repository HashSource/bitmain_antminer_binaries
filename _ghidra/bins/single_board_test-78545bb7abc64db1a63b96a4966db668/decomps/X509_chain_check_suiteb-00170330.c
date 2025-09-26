
int X509_chain_check_suiteb(uint *param_1,int param_2,int param_3,uint param_4)

{
  EVP_PKEY *pkey;
  int iVar1;
  EC_KEY *pEVar2;
  EC_GROUP *pEVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  uint local_2c;
  
  if ((param_4 & 0x30000) == 0) {
    return 0;
  }
  bVar7 = param_2 == 0;
  if (bVar7) {
    param_2 = OPENSSL_sk_value(param_3);
  }
  uVar6 = (uint)bVar7;
  pkey = (EVP_PKEY *)X509_get0_pubkey(param_2);
  if (param_3 == 0) {
    if ((pkey == (EVP_PKEY *)0x0) || (iVar1 = EVP_PKEY_id(pkey), iVar1 != 0x198)) {
      return 0x39;
    }
    pEVar2 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
    pEVar3 = EC_KEY_get0_group(pEVar2);
    if (pEVar3 == (EC_GROUP *)0x0) {
      return 0x39;
    }
    iVar1 = EC_GROUP_get_curve_name(pEVar3);
    if (iVar1 == 0x2cb) {
      iVar1 = param_4 << 0xe;
    }
    else {
      if (iVar1 != 0x19f) {
        return 0x3a;
      }
      iVar1 = param_4 << 0xf;
    }
    if (iVar1 < 0) {
      return 0;
    }
    return 0x3c;
  }
  iVar1 = X509_get_version(param_2);
  if (iVar1 != 2) {
    iVar1 = 0x38;
    uVar6 = 0;
    goto LAB_00170364;
  }
  if ((pkey == (EVP_PKEY *)0x0) || (iVar1 = EVP_PKEY_id(pkey), iVar1 != 0x198)) {
    iVar1 = 0x39;
    uVar6 = 0;
    goto LAB_00170364;
  }
  pEVar2 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
  pEVar3 = EC_KEY_get0_group(pEVar2);
  if (pEVar3 == (EC_GROUP *)0x0) {
    iVar1 = 0x39;
LAB_001703f8:
    uVar6 = 0;
    goto LAB_00170364;
  }
  iVar1 = EC_GROUP_get_curve_name(pEVar3);
  if (iVar1 == 0x2cb) {
    uVar5 = param_4 & 0x20000;
    if (uVar5 != 0) {
      local_2c = param_4 & 0xfffeffff;
LAB_0017042a:
      for (; iVar1 = OPENSSL_sk_num(param_3), (int)uVar6 < iVar1; uVar6 = uVar6 + 1) {
        iVar1 = X509_get_signature_nid(param_2);
        param_2 = OPENSSL_sk_value(param_3,uVar6);
        iVar4 = X509_get_version();
        if (iVar4 != 2) {
          iVar1 = 0x38;
          goto LAB_00170364;
        }
        pkey = (EVP_PKEY *)X509_get0_pubkey(param_2);
        if ((pkey == (EVP_PKEY *)0x0) || (iVar4 = EVP_PKEY_id(pkey), iVar4 != 0x198))
        goto LAB_00170462;
        pEVar2 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
        pEVar3 = EC_KEY_get0_group(pEVar2);
        if (pEVar3 == (EC_GROUP *)0x0) goto LAB_00170462;
        iVar4 = EC_GROUP_get_curve_name(pEVar3);
        if (iVar4 == 0x2cb) {
          if (iVar1 != -1 && iVar1 != 0x31b) goto LAB_00170496;
          if (-1 < (int)(local_2c << 0xe)) goto LAB_001704c0;
          local_2c = local_2c & 0xfffeffff;
        }
        else {
          if (iVar4 != 0x19f) goto LAB_00170484;
          if (iVar1 != -1 && iVar1 != 0x31a) goto LAB_00170496;
          if (-1 < (int)(local_2c << 0xf)) goto LAB_001704c0;
        }
      }
      iVar1 = X509_get_signature_nid(param_2);
      iVar4 = EVP_PKEY_id(pkey);
      if (iVar4 == 0x198) {
        pEVar2 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
        pEVar3 = EC_KEY_get0_group(pEVar2);
        if (pEVar3 != (EC_GROUP *)0x0) {
          iVar4 = EC_GROUP_get_curve_name(pEVar3);
          if (iVar4 == 0x2cb) {
            if (iVar1 == -1 || iVar1 == 0x31b) {
              iVar1 = local_2c << 0xe;
              goto joined_r0x0017053c;
            }
LAB_00170496:
            iVar1 = 0x3b;
          }
          else {
            if (iVar4 != 0x19f) {
LAB_00170484:
              iVar1 = 0x3a;
              goto LAB_00170364;
            }
            if ((iVar1 != -1) && (iVar1 != 0x31a)) goto LAB_00170496;
            iVar1 = local_2c << 0xf;
joined_r0x0017053c:
            if (iVar1 < 0) {
              return 0;
            }
LAB_001704c0:
            iVar1 = 0x3c;
          }
          if (uVar6 != 0) {
            uVar6 = uVar6 - 1;
          }
          if ((iVar1 == 0x3c) && (param_4 != local_2c)) {
            iVar1 = 0x3d;
          }
          goto LAB_00170364;
        }
      }
LAB_00170462:
      iVar1 = 0x39;
      goto LAB_00170364;
    }
  }
  else {
    if (iVar1 != 0x19f) {
      iVar1 = 0x3a;
      goto LAB_001703f8;
    }
    uVar5 = param_4 & 0x10000;
    local_2c = param_4;
    if (uVar5 != 0) goto LAB_0017042a;
  }
  iVar1 = 0x3c;
  uVar6 = uVar5;
LAB_00170364:
  if (param_1 != (uint *)0x0) {
    *param_1 = uVar6;
  }
  return iVar1;
}

