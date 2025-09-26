
uint pkey_ec_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  EC_KEY *key;
  EC_GROUP *pEVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  EC_KEY *src;
  
  puVar4 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 0x1002) {
    if ((EC_GROUP *)*puVar4 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0xc5,0x8b,"crypto/ec/ec_pmeth.c",0xf0);
      return 0;
    }
    EC_GROUP_set_asn1_flag((EC_GROUP *)*puVar4,param_3);
    return 1;
  }
  if (param_2 < 0x1003) {
    if (param_2 == 7) {
      return 1;
    }
    if (param_2 < 8) {
      if (param_2 == 2) {
        return 1;
      }
      if (param_2 == 5) {
        return 1;
      }
      if (param_2 == 1) {
        iVar2 = EVP_MD_type(param_4);
        if ((((((iVar2 != 0x40) && (iVar2 = EVP_MD_type(param_4), iVar2 != 0x1a0)) &&
              (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a3)) &&
             ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a0 &&
              (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a1)))) &&
            ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a2 &&
             ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x448 &&
              (iVar2 = EVP_MD_type(param_4), iVar2 != 0x449)))))) &&
           ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x44a &&
            (iVar2 = EVP_MD_type(param_4), iVar2 != 1099)))) {
          ERR_put_error(0x10,0xc5,0x8a,"crypto/ec/ec_pmeth.c",0x14b);
          return 0;
        }
        puVar4[1] = param_4;
        return 1;
      }
    }
    else {
      if (param_2 == 0xd) {
        param_4->type = puVar4[1];
        return 1;
      }
      if (param_2 == 0x1001) {
        pEVar1 = EC_GROUP_new_by_curve_name(param_3);
        if (pEVar1 == (EC_GROUP *)0x0) {
          ERR_put_error(0x10,0xc5,0x8d,"crypto/ec/ec_pmeth.c",0xe7);
          return 0;
        }
        EC_GROUP_free((EC_GROUP *)*puVar4);
        *puVar4 = pEVar1;
        return 1;
      }
      if (param_2 == 0xb) {
        return 1;
      }
    }
    return 0xfffffffe;
  }
  if (param_2 == 0x1006) {
    param_4->type = puVar4[4];
    return 1;
  }
  if (0x1006 < param_2) {
    if (param_2 == 0x1008) {
      param_4->type = puVar4[7];
      return 1;
    }
    if (param_2 < 0x1008) {
      if (param_3 < 1) {
        return 0xfffffffe;
      }
      puVar4[7] = param_3;
      return 1;
    }
    if (param_2 == 0x1009) {
      CRYPTO_free((void *)puVar4[5]);
      puVar4[5] = param_4;
      if (param_4 == (EVP_MD *)0x0) {
        puVar4[6] = 0;
        return 1;
      }
      puVar4[6] = param_3;
      return 1;
    }
    if (param_2 != 0x100a) {
      return 0xfffffffe;
    }
    uVar3 = puVar4[6];
    param_4->type = puVar4[5];
    return uVar3;
  }
  if (param_2 == 0x1004) {
    if (param_3 == -2) {
      return (uint)*(byte *)((int)puVar4 + 0xd);
    }
    if (1 < param_3 - 1U) {
      return 0xfffffffe;
    }
    *(char *)((int)puVar4 + 0xd) = (char)param_3;
    return 1;
  }
  if (0x1004 < param_2) {
    puVar4[4] = param_4;
    return 1;
  }
  if (param_3 == -2) {
    if ((int)*(char *)(puVar4 + 3) == 0xffffffff) {
      iVar2 = EC_KEY_get_flags(*(EC_KEY **)(*(int *)(param_1 + 8) + 0x18));
      return (uint)(iVar2 << 0x13) >> 0x1f;
    }
    return (int)*(char *)(puVar4 + 3);
  }
  if (2 < param_3 + 1U) {
    return 0xfffffffe;
  }
  *(char *)(puVar4 + 3) = (char)param_3;
  if (param_3 == -1) {
    EC_KEY_free((EC_KEY *)puVar4[2]);
    puVar4[2] = 0;
    return 1;
  }
  src = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
  iVar2 = *(int *)(src + 0xc);
  if (iVar2 == 0) {
    return 0xfffffffe;
  }
  iVar2 = BN_is_one(*(undefined4 *)(iVar2 + 0xc));
  if (iVar2 != 0) {
    return 1;
  }
  key = (EC_KEY *)puVar4[2];
  if (key == (EC_KEY *)0x0) {
    key = EC_KEY_dup(src);
    puVar4[2] = key;
    if (key == (EC_KEY *)0x0) {
      return 0;
    }
  }
  if (param_3 == 0) {
    EC_KEY_clear_flags(key,0x1000);
    return 1;
  }
  EC_KEY_set_flags(key,0x1000);
  return 1;
}

