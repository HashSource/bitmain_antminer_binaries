
uint pkey_ec_ctrl(int param_1,int param_2,int param_3,EVP_MD *param_4)

{
  uint uVar1;
  EC_KEY *key;
  EC_GROUP *pEVar2;
  EC_KEY *src;
  int iVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_1 + 0x14);
  if (param_2 == 0x1002) {
    if ((EC_GROUP *)*puVar4 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0xc5,0x8b,"ec_pmeth.c",299);
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
        iVar3 = EVP_MD_type(param_4);
        if ((((iVar3 != 0x40) && (iVar3 = EVP_MD_type(param_4), iVar3 != 0x1a0)) &&
            ((iVar3 = EVP_MD_type(param_4), iVar3 != 0x2a3 &&
             ((iVar3 = EVP_MD_type(param_4), iVar3 != 0x2a0 &&
              (iVar3 = EVP_MD_type(param_4), iVar3 != 0x2a1)))))) &&
           (iVar3 = EVP_MD_type(param_4), iVar3 != 0x2a2)) {
          ERR_put_error(0x10,0xc5,0x8a,"ec_pmeth.c",0x184);
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
        pEVar2 = EC_GROUP_new_by_curve_name(param_3);
        if (pEVar2 == (EC_GROUP *)0x0) {
          ERR_put_error(0x10,0xc5,0x8d,"ec_pmeth.c",0x121);
          return 0;
        }
        if ((EC_GROUP *)*puVar4 != (EC_GROUP *)0x0) {
          EC_GROUP_free((EC_GROUP *)*puVar4);
        }
        *puVar4 = pEVar2;
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
    if (param_2 != 0x1009) {
      if (param_2 != 0x100a) {
        return 0xfffffffe;
      }
      uVar1 = puVar4[6];
      param_4->type = puVar4[5];
      return uVar1;
    }
    if ((void *)puVar4[5] != (void *)0x0) {
      CRYPTO_free((void *)puVar4[5]);
    }
    puVar4[5] = param_4;
    if (param_4 == (EVP_MD *)0x0) {
      puVar4[6] = 0;
      return 1;
    }
    puVar4[6] = param_3;
    return 1;
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
      iVar3 = EC_KEY_get_flags(*(EC_KEY **)(*(int *)(param_1 + 8) + 0x14));
      return (uint)(iVar3 << 0x13) >> 0x1f;
    }
    return (int)*(char *)(puVar4 + 3);
  }
  if (2 < param_3 + 1U) {
    return 0xfffffffe;
  }
  *(char *)(puVar4 + 3) = (char)param_3;
  if (param_3 == -1) {
    if ((EC_KEY *)puVar4[2] == (EC_KEY *)0x0) {
      return 1;
    }
    EC_KEY_free((EC_KEY *)puVar4[2]);
    puVar4[2] = 0;
    return 1;
  }
  src = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  iVar3 = *(int *)(src + 4);
  if (iVar3 == 0) {
    return 0xfffffffe;
  }
  if (((*(int *)(iVar3 + 0x20) == 1) && (**(int **)(iVar3 + 0x1c) == 1)) &&
     (*(int *)(iVar3 + 0x28) == 0)) {
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

