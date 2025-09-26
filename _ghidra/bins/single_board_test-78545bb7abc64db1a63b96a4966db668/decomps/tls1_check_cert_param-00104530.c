
undefined4 tls1_check_cert_param(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  EVP_PKEY *pkey;
  int iVar2;
  EC_KEY *pEVar3;
  EC_GROUP *pEVar4;
  point_conversion_form_t pVar5;
  EC_METHOD *meth;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  int *piVar9;
  char *pcVar10;
  
  pkey = (EVP_PKEY *)X509_get0_pubkey(param_2);
  if (pkey == (EVP_PKEY *)0x0) {
    return 0;
  }
  iVar2 = EVP_PKEY_id(pkey);
  if (iVar2 != 0x198) {
    return 1;
  }
  iVar2 = EVP_PKEY_id(pkey);
  if (iVar2 == 0x198) {
    pEVar3 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
    pEVar4 = EC_KEY_get0_group(pEVar3);
    pVar5 = EC_KEY_get_conv_form(pEVar3);
    if (pVar5 == POINT_CONVERSION_UNCOMPRESSED) {
      cVar1 = '\0';
    }
    else {
      if ((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
         (iVar2 = **(int **)(param_1 + 4), iVar2 != 0x10000 && 0x303 < iVar2)) goto LAB_00104578;
      meth = EC_GROUP_method_of(pEVar4);
      iVar2 = EC_METHOD_get_field_type(meth);
      if (iVar2 == 0x196) {
        cVar1 = '\x01';
      }
      else {
        if (iVar2 != 0x197) {
          return 0;
        }
        cVar1 = '\x02';
      }
    }
    pcVar10 = *(char **)(param_1 + 0x56c);
    if (pcVar10 != (char *)0x0) {
      if (*(int *)(param_1 + 0x568) == 0) {
        return 0;
      }
      if (*pcVar10 != cVar1) {
        pcVar7 = pcVar10 + *(int *)(param_1 + 0x568);
        do {
          pcVar10 = pcVar10 + 1;
          if (pcVar7 == pcVar10) {
            return 0;
          }
        } while (*pcVar10 != cVar1);
      }
    }
  }
LAB_00104578:
  pEVar3 = (EC_KEY *)EVP_PKEY_get0_EC_KEY(pkey);
  if (pEVar3 != (EC_KEY *)0x0) {
    pEVar4 = EC_KEY_get0_group(pEVar3);
    iVar2 = EC_GROUP_get_curve_name(pEVar4);
    iVar6 = 0;
    uVar8 = 0;
    do {
      piVar9 = (int *)((int)&nid_list + iVar6);
      uVar8 = uVar8 + 1;
      iVar6 = iVar6 + 0xc;
      if (iVar2 == *piVar9) {
        uVar8 = uVar8 & 0xffff;
        goto LAB_00104554;
      }
    } while (uVar8 != 0x1e);
  }
  uVar8 = 0;
LAB_00104554:
  iVar2 = tls1_check_group_id(param_1,uVar8,*(int *)(param_1 + 0x1c) == 0);
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_3 != 0) && ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) != 0)) {
    if (uVar8 == 0x17) {
      iVar2 = 0x31a;
    }
    else {
      if (uVar8 != 0x18) {
        return 0;
      }
      iVar2 = 0x31b;
    }
    if (*(int *)(param_1 + 0xf8c) == 0) {
      return 0;
    }
    piVar9 = *(int **)(param_1 + 0xf88);
    if (iVar2 != *(int *)(*piVar9 + 0x18)) {
      iVar6 = 0;
      do {
        iVar6 = iVar6 + 1;
        if (iVar6 == *(int *)(param_1 + 0xf8c)) {
          return 0;
        }
        piVar9 = piVar9 + 1;
      } while (iVar2 != *(int *)(*piVar9 + 0x18));
    }
  }
  return 1;
}

