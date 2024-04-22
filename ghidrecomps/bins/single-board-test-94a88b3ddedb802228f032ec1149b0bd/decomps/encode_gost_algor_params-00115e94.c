
ASN1_STRING * encode_gost_algor_params(EVP_PKEY *param_1)

{
  int *piVar1;
  ASN1_STRING *a;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  void *pvVar5;
  EC_KEY *key;
  EC_GROUP *group;
  char *str;
  int iVar6;
  ASN1_STRING *pAVar7;
  int n;
  BIGNUM *local_1c [2];
  
  a = ASN1_STRING_new();
  ppAVar2 = (ASN1_OBJECT **)GOST_KEY_PARAMS_new();
  if (a == (ASN1_STRING *)0x0 || ppAVar2 == (ASN1_OBJECT **)0x0) {
    ERR_GOST_error(100,0x41,DAT_00115f9c,0x2d);
    pAVar7 = (ASN1_STRING *)0x0;
    ASN1_STRING_free(a);
  }
  else {
    n = 0;
    iVar3 = EVP_PKEY_base_id(param_1);
    piVar1 = DAT_00115f98;
    iVar6 = 0x32b;
    if (iVar3 == 0x32b) {
      key = (EC_KEY *)EVP_PKEY_get0(param_1);
      group = EC_KEY_get0_group(key);
      n = EC_GROUP_get_curve_name(group);
    }
    else if (iVar3 == 0x32c) {
      pvVar5 = EVP_PKEY_get0(param_1);
      local_1c[0] = BN_new();
      str = (char *)piVar1[3];
      while (str != (char *)0x0) {
        BN_dec2bn(local_1c,str);
        iVar3 = BN_cmp(local_1c[0],*(BIGNUM **)((int)pvVar5 + 0x10));
        if (iVar3 == 0) {
          BN_free(local_1c[0]);
          n = *piVar1;
          if (n != 0) goto LAB_00115ecc;
          goto LAB_00115f54;
        }
        str = (char *)piVar1[7];
        HintPreloadData(piVar1 + 0x23);
        piVar1 = piVar1 + 4;
      }
      BN_free(local_1c[0]);
LAB_00115f54:
      ERR_GOST_error(100,0x6d,DAT_00115f9c,0x3d);
      pAVar7 = (ASN1_STRING *)0x0;
      ASN1_STRING_free(a);
      goto LAB_00115ef2;
    }
LAB_00115ecc:
    pAVar4 = OBJ_nid2obj(n);
    *ppAVar2 = pAVar4;
    pAVar4 = OBJ_nid2obj(0x336);
    ppAVar2[1] = pAVar4;
    iVar3 = i2d_GOST_KEY_PARAMS(ppAVar2,&a->data);
    a->length = iVar3;
    if (0 < iVar3) {
      iVar6 = 0x10;
    }
    if (iVar3 < 1) {
      ERR_GOST_error(100,0x41,DAT_00115f9c,0x4b);
      pAVar7 = (ASN1_STRING *)0x0;
      ASN1_STRING_free(a);
    }
    else {
      a->type = iVar6;
      pAVar7 = a;
    }
  }
LAB_00115ef2:
  GOST_KEY_PARAMS_free(ppAVar2);
  return pAVar7;
}

