
ASN1_STRING * encode_gost_algor_params(EVP_PKEY *param_1)

{
  int *piVar1;
  ASN1_STRING *a;
  undefined4 *puVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  void *pvVar5;
  EC_KEY *key;
  EC_GROUP *group;
  char *str;
  int extraout_r3;
  ASN1_STRING *pAVar6;
  int iVar7;
  BIGNUM *local_1c [2];
  
  a = ASN1_STRING_new();
  puVar2 = (undefined4 *)GOST_KEY_PARAMS_new();
  if (a == (ASN1_STRING *)0x0 || puVar2 == (undefined4 *)0x0) {
    ERR_GOST_error(100,0x41,"gost_ameth.c",0x2d);
    pAVar6 = (ASN1_STRING *)0x0;
    ASN1_STRING_free(a);
  }
  else {
    iVar7 = 0;
    iVar3 = EVP_PKEY_base_id(param_1);
    if (iVar3 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(param_1);
      group = EC_KEY_get0_group(key);
      iVar7 = EC_GROUP_get_curve_name(group);
    }
    else if (iVar3 == 0x32c) {
      pvVar5 = EVP_PKEY_get0(param_1);
      local_1c[0] = BN_new();
      piVar1 = (int *)R3410_paramset;
      str = (char *)R3410_paramset._12_4_;
      while (str != (char *)0x0) {
        BN_dec2bn(local_1c,str);
        iVar3 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar5 + 0x10));
        if (iVar3 == 0) {
          BN_free(local_1c[0]);
          iVar7 = *piVar1;
          if (iVar7 != 0) goto LAB_00115ecc;
          goto LAB_00115f54;
        }
        str = (char *)piVar1[7];
        HintPreloadData(piVar1 + 0x23);
        piVar1 = piVar1 + 4;
      }
      BN_free(local_1c[0]);
LAB_00115f54:
      ERR_GOST_error(100,0x6d,"gost_ameth.c",0x3d);
      pAVar6 = (ASN1_STRING *)0x0;
      ASN1_STRING_free(a);
      goto LAB_00115ef2;
    }
LAB_00115ecc:
    pAVar4 = OBJ_nid2obj(iVar7);
    *puVar2 = pAVar4;
    pAVar4 = OBJ_nid2obj(0x336);
    puVar2[1] = pAVar4;
    iVar7 = i2d_GOST_KEY_PARAMS(puVar2,&a->data);
    a->length = iVar7;
    iVar3 = extraout_r3;
    if (0 < iVar7) {
      iVar3 = 0x10;
    }
    if (iVar7 < 1) {
      ERR_GOST_error(100,0x41,"gost_ameth.c",0x4b);
      pAVar6 = (ASN1_STRING *)0x0;
      ASN1_STRING_free(a);
    }
    else {
      a->type = iVar3;
      pAVar6 = a;
    }
  }
LAB_00115ef2:
  GOST_KEY_PARAMS_free(puVar2);
  return pAVar6;
}

