
int pkey_GOST01cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,int *param_3,undefined4 param_4)

{
  EVP_PKEY *pkey;
  void *pvVar1;
  int *piVar2;
  EVP_PKEY *pkey_00;
  int iVar3;
  EC_KEY *pEVar4;
  EC_POINT *pEVar5;
  int *piVar6;
  ASN1_OBJECT *pAVar7;
  int *piVar8;
  ASN1_OBJECT **ppAVar9;
  bool bVar10;
  undefined4 *puVar11;
  bool bVar12;
  int local_10a4 [2];
  undefined4 local_109c;
  undefined4 uStack_1098;
  undefined auStack_1094 [32];
  undefined auStack_1074 [8];
  undefined auStack_106c [32];
  undefined auStack_104c [4];
  undefined auStack_1048 [4132];
  
  piVar8 = local_10a4;
  local_10a4[0] = param_2;
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar1 = EVP_PKEY_CTX_get_data(param_1);
  piVar2 = (int *)get_encryption_params(0);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  puVar11 = *(undefined4 **)((int)pvVar1 + 8);
  if (puVar11 == (undefined4 *)0x0) {
    if ((local_10a4[0] != 0) && (iVar3 = RAND_bytes((uchar *)&local_109c,8), iVar3 < 1)) {
      ERR_GOST_error(0x77,0x7c,DAT_00112268,0x86);
      return 0;
    }
  }
  else {
    local_109c = *puVar11;
    uStack_1098 = puVar11[1];
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    if (local_10a4[0] == 0) {
LAB_0011218e:
      bVar10 = true;
      bVar12 = true;
      iVar3 = get_gost_engine_param(0);
      goto joined_r0x0011219c;
    }
    pkey_00 = EVP_PKEY_new();
    iVar3 = EVP_PKEY_base_id(pkey);
    pEVar4 = EC_KEY_new();
    EVP_PKEY_assign(pkey_00,iVar3,pEVar4);
    EVP_PKEY_copy_parameters(pkey_00,pkey);
    EVP_PKEY_get0(pkey_00);
    iVar3 = gost2001_keygen();
    if (iVar3 != 0) goto LAB_0011218e;
    bVar10 = true;
    piVar6 = (int *)0x0;
  }
  else {
    iVar3 = gost_get0_priv_key(pkey_00);
    if (iVar3 == 0) {
      ERR_GOST_error(0x77,0x79,DAT_00112268,0x8f);
      piVar6 = (int *)0x0;
      goto LAB_001121be;
    }
    bVar10 = false;
    bVar12 = false;
    iVar3 = get_gost_engine_param(0);
joined_r0x0011219c:
    if ((iVar3 == 0) && (piVar2 == DAT_00112264)) {
      piVar2 = piVar2 + 3;
    }
    if (local_10a4[0] != 0) {
      pEVar4 = (EC_KEY *)EVP_PKEY_get0(pkey);
      pEVar5 = EC_KEY_get0_public_key(pEVar4);
      pvVar1 = EVP_PKEY_get0(pkey_00);
      VKO_compute_key_isra_0(auStack_1094,pEVar5,pvVar1,&local_109c);
      gost_init(auStack_1048,piVar2[1]);
      keyWrapCryptoPro(auStack_1048,auStack_1094,&local_109c,param_4,auStack_1074);
    }
    piVar6 = (int *)GOST_KEY_TRANSPORT_new();
    if ((((piVar6 != (int *)0x0) &&
         (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar6[1] + 8),&local_109c,8), iVar3 != 0)
         ) && (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar6 + 4),auStack_104c,4),
              iVar3 != 0)) &&
       (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar6,auStack_106c,0x20), iVar3 != 0)) {
      if (!bVar12) {
        ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar6[1]);
        ppAVar9 = (ASN1_OBJECT **)piVar6[1];
        pAVar7 = OBJ_nid2obj(*piVar2);
        *ppAVar9 = pAVar7;
        iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0);
        if (0 < iVar3) goto LAB_00112126;
        ERR_GOST_error(0x77,0x84,DAT_00112268,0xc6);
        goto LAB_001121be;
      }
      if (local_10a4[0] != 0) {
        pkey = pkey_00;
      }
      iVar3 = X509_PUBKEY_set((X509_PUBKEY **)(piVar6[1] + 4),pkey);
      if (iVar3 != 0) {
        ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar6[1]);
        ppAVar9 = (ASN1_OBJECT **)piVar6[1];
        pAVar7 = OBJ_nid2obj(*piVar2);
        *ppAVar9 = pAVar7;
        if ((pkey_00 != (EVP_PKEY *)0x0) && (bVar10)) {
          EVP_PKEY_free(pkey_00);
        }
LAB_00112126:
        if (local_10a4[0] == 0) {
          piVar8 = (int *)0x0;
        }
        iVar3 = i2d_GOST_KEY_TRANSPORT(piVar6,piVar8);
        *param_3 = iVar3;
        if (iVar3 != 0) {
          iVar3 = 1;
        }
        GOST_KEY_TRANSPORT_free(piVar6);
        return iVar3;
      }
      ERR_GOST_error(0x77,0x65,DAT_00112268);
      bVar10 = true;
    }
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    bVar10 = false;
  }
  if (bVar10) {
    EVP_PKEY_free(pkey_00);
  }
LAB_001121be:
  GOST_KEY_TRANSPORT_free(piVar6);
  return -1;
}

