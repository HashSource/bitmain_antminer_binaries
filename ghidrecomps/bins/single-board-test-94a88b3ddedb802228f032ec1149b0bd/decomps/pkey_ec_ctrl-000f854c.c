
EC_GROUP * pkey_ec_ctrl(int param_1,int param_2,EC_GROUP *param_3,EVP_MD *param_4)

{
  EC_GROUP *pEVar1;
  EC_KEY *key;
  EC_KEY *src;
  int iVar2;
  EC_GROUP **ppEVar3;
  
  ppEVar3 = *(EC_GROUP ***)(param_1 + 0x14);
  if (param_2 == 0x1002) {
    if (*ppEVar3 == (EC_GROUP *)0x0) {
      ERR_put_error(0x10,0xc5,0x8b,DAT_000f8784,299);
      return (EC_GROUP *)0x0;
    }
    EC_GROUP_set_asn1_flag(*ppEVar3,(int)param_3);
    return (EC_GROUP *)0x1;
  }
  if (param_2 < 0x1003) {
    if (param_2 == 7) {
      return (EC_GROUP *)0x1;
    }
    if (param_2 < 8) {
      if (param_2 == 2) {
        return (EC_GROUP *)0x1;
      }
      if (param_2 == 5) {
        return (EC_GROUP *)0x1;
      }
      if (param_2 == 1) {
        iVar2 = EVP_MD_type(param_4);
        if ((((iVar2 != 0x40) && (iVar2 = EVP_MD_type(param_4), iVar2 != 0x1a0)) &&
            ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a3 &&
             ((iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a0 &&
              (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a1)))))) &&
           (iVar2 = EVP_MD_type(param_4), iVar2 != 0x2a2)) {
          ERR_put_error(0x10,0xc5,0x8a,DAT_000f8784,0x184);
          return (EC_GROUP *)0x0;
        }
        ppEVar3[1] = (EC_GROUP *)param_4;
        return (EC_GROUP *)0x1;
      }
    }
    else {
      if (param_2 == 0xd) {
        param_4->type = (int)ppEVar3[1];
        return (EC_GROUP *)0x1;
      }
      if (param_2 == 0x1001) {
        pEVar1 = EC_GROUP_new_by_curve_name((int)param_3);
        if (pEVar1 == (EC_GROUP *)0x0) {
          ERR_put_error(0x10,0xc5,0x8d,DAT_000f8784,0x121);
          return (EC_GROUP *)0x0;
        }
        if (*ppEVar3 != (EC_GROUP *)0x0) {
          EC_GROUP_free(*ppEVar3);
        }
        *ppEVar3 = pEVar1;
        return (EC_GROUP *)0x1;
      }
      if (param_2 == 0xb) {
        return (EC_GROUP *)0x1;
      }
    }
    return (EC_GROUP *)0xfffffffe;
  }
  if (param_2 == 0x1006) {
    param_4->type = (int)ppEVar3[4];
    return (EC_GROUP *)0x1;
  }
  if (0x1006 < param_2) {
    if (param_2 == 0x1008) {
      param_4->type = (int)ppEVar3[7];
      return (EC_GROUP *)0x1;
    }
    if (param_2 < 0x1008) {
      if ((int)param_3 < 1) {
        return (EC_GROUP *)0xfffffffe;
      }
      ppEVar3[7] = param_3;
      return (EC_GROUP *)0x1;
    }
    if (param_2 != 0x1009) {
      if (param_2 != 0x100a) {
        return (EC_GROUP *)0xfffffffe;
      }
      pEVar1 = ppEVar3[6];
      param_4->type = (int)ppEVar3[5];
      return pEVar1;
    }
    if (ppEVar3[5] != (EC_GROUP *)0x0) {
      CRYPTO_free(ppEVar3[5]);
    }
    ppEVar3[5] = (EC_GROUP *)param_4;
    if (param_4 == (EVP_MD *)0x0) {
      ppEVar3[6] = (EC_GROUP *)0x0;
      return (EC_GROUP *)0x1;
    }
    ppEVar3[6] = param_3;
    return (EC_GROUP *)0x1;
  }
  if (param_2 == 0x1004) {
    if (param_3 == (EC_GROUP *)0xfffffffe) {
      return (EC_GROUP *)(uint)*(byte *)((int)ppEVar3 + 0xd);
    }
    if ((EC_GROUP *)0x1 < param_3 + -1) {
      return (EC_GROUP *)0xfffffffe;
    }
    *(char *)((int)ppEVar3 + 0xd) = (char)param_3;
    return (EC_GROUP *)0x1;
  }
  if (0x1004 < param_2) {
    ppEVar3[4] = (EC_GROUP *)param_4;
    return (EC_GROUP *)0x1;
  }
  if (param_3 == (EC_GROUP *)0xfffffffe) {
    if ((EC_GROUP *)(int)*(char *)(ppEVar3 + 3) == (EC_GROUP *)0xffffffff) {
      iVar2 = EC_KEY_get_flags(*(EC_KEY **)(*(int *)(param_1 + 8) + 0x14));
      return (EC_GROUP *)((uint)(iVar2 << 0x13) >> 0x1f);
    }
    return (EC_GROUP *)(int)*(char *)(ppEVar3 + 3);
  }
  if ((EC_GROUP *)0x2 < param_3 + 1) {
    return (EC_GROUP *)0xfffffffe;
  }
  *(char *)(ppEVar3 + 3) = (char)param_3;
  if (param_3 == (EC_GROUP *)0xffffffff) {
    if ((EC_KEY *)ppEVar3[2] == (EC_KEY *)0x0) {
      return (EC_GROUP *)0x1;
    }
    EC_KEY_free((EC_KEY *)ppEVar3[2]);
    ppEVar3[2] = (EC_GROUP *)0x0;
    return (EC_GROUP *)0x1;
  }
  src = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x14);
  iVar2 = *(int *)(src + 4);
  if (iVar2 == 0) {
    return (EC_GROUP *)0xfffffffe;
  }
  if (((*(int *)(iVar2 + 0x20) == 1) && (**(int **)(iVar2 + 0x1c) == 1)) &&
     (*(int *)(iVar2 + 0x28) == 0)) {
    return (EC_GROUP *)0x1;
  }
  key = (EC_KEY *)ppEVar3[2];
  if (key == (EC_KEY *)0x0) {
    key = EC_KEY_dup(src);
    ppEVar3[2] = (EC_GROUP *)key;
    if (key == (EC_KEY *)0x0) {
      return (EC_GROUP *)0x0;
    }
  }
  if (param_3 == (EC_GROUP *)0x0) {
    EC_KEY_clear_flags(key,0x1000);
    return (EC_GROUP *)0x1;
  }
  EC_KEY_set_flags(key,0x1000);
  return (EC_GROUP *)0x1;
}

