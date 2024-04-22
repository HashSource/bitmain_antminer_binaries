
undefined4 pkey_GOST94cp_encrypt(EVP_PKEY_CTX *param_1,int param_2,int *param_3,undefined4 param_4)

{
  int *piVar1;
  EVP_PKEY *pkey;
  void *pvVar2;
  EVP_PKEY *pkey_00;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  ASN1_OBJECT *pAVar6;
  DSA *key;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  ASN1_OBJECT **ppAVar10;
  bool bVar11;
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
  piVar1 = (int *)get_encryption_params(0);
  pkey = EVP_PKEY_CTX_get0_pkey(param_1);
  pvVar2 = EVP_PKEY_CTX_get_data(param_1);
  pkey_00 = EVP_PKEY_CTX_get0_peerkey(param_1);
  iVar3 = get_gost_engine_param(0);
  if ((iVar3 == 0) && (piVar1 == DAT_00115160)) {
    piVar1 = piVar1 + 3;
  }
  if (pkey_00 == (EVP_PKEY *)0x0) {
    if (local_10a4[0] != 0) {
      pkey_00 = EVP_PKEY_new();
      iVar3 = EVP_PKEY_base_id(pkey);
      key = DSA_new();
      EVP_PKEY_assign(pkey_00,iVar3,key);
      EVP_PKEY_copy_parameters(pkey_00,pkey);
      EVP_PKEY_get0(pkey_00);
      iVar3 = gost_sign_keygen();
      if (iVar3 == 0) {
        piVar5 = (int *)0x0;
        goto LAB_001150c2;
      }
      bVar11 = true;
      goto LAB_00114f78;
    }
    bVar11 = true;
LAB_00115110:
    puVar9 = *(undefined4 **)((int)pvVar2 + 8);
    if (puVar9 != (undefined4 *)0x0) {
      iVar3 = 0;
LAB_00114f98:
      local_109c = *puVar9;
      uStack_1098 = puVar9[1];
      goto LAB_00114fa2;
    }
  }
  else {
    iVar3 = gost_get0_priv_key(pkey_00);
    if (iVar3 == 0) {
      ERR_GOST_error(0x7b,0x79,DAT_0011515c,0x79);
      piVar5 = (int *)0x0;
      goto LAB_001150c2;
    }
    bVar11 = false;
LAB_00114f78:
    if (local_10a4[0] == 0) goto LAB_00115110;
    uVar4 = gost_get0_priv_key(pkey_00);
    make_cp_exchange_key(uVar4,pkey,auStack_1094);
    puVar9 = *(undefined4 **)((int)pvVar2 + 8);
    iVar3 = local_10a4[0];
    if (puVar9 != (undefined4 *)0x0) goto LAB_00114f98;
    if (local_10a4[0] == 0) goto LAB_00114fc0;
    iVar7 = RAND_bytes((uchar *)&local_109c,8);
    iVar3 = local_10a4[0];
    if (iVar7 < 1) {
      ERR_GOST_error(0x7b,0x7c,DAT_0011515c,0x8f);
      piVar5 = (int *)0x0;
      goto LAB_001150c2;
    }
LAB_00114fa2:
    if (iVar3 != 0) {
      gost_init(auStack_1048,piVar1[1]);
      keyWrapCryptoPro(auStack_1048,auStack_1094,&local_109c,param_4,auStack_1074);
    }
  }
LAB_00114fc0:
  piVar5 = (int *)GOST_KEY_TRANSPORT_new();
  if ((((piVar5 == (int *)0x0) ||
       (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(piVar5[1] + 8),&local_109c,8), iVar3 == 0))
      || (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)(*piVar5 + 4),auStack_104c,4), iVar3 == 0))
     || (iVar3 = ASN1_OCTET_STRING_set(*(ASN1_STRING **)*piVar5,auStack_106c,0x20), iVar3 == 0)) {
    if (bVar11) {
      EVP_PKEY_free(pkey_00);
    }
    ERR_GOST_error(0x7b,0x75,DAT_0011515c,199);
  }
  else {
    if (bVar11) {
      if (local_10a4[0] != 0) {
        pkey = pkey_00;
      }
      iVar3 = X509_PUBKEY_set((X509_PUBKEY **)(piVar5[1] + 4),pkey);
      if (iVar3 == 0) {
        ERR_GOST_error(0x7b,0x65,DAT_0011515c,0xaa);
        goto LAB_001150c2;
      }
      if (local_10a4[0] != 0) {
        EVP_PKEY_free(pkey_00);
      }
    }
    ASN1_OBJECT_free(*(ASN1_OBJECT **)piVar5[1]);
    ppAVar10 = (ASN1_OBJECT **)piVar5[1];
    pAVar6 = OBJ_nid2obj(*piVar1);
    *ppAVar10 = pAVar6;
    if (local_10a4[0] == 0) {
      piVar8 = (int *)0x0;
    }
    iVar3 = i2d_GOST_KEY_TRANSPORT(piVar5,piVar8);
    if (iVar3 < 1) {
      ERR_GOST_error(0x7b,0x67,DAT_0011515c,0xb5);
    }
    else {
      *param_3 = iVar3;
      if ((bVar11) || (iVar3 = EVP_PKEY_CTX_ctrl(param_1,-1,-1,2,3,(void *)0x0), 0 < iVar3)) {
        GOST_KEY_TRANSPORT_free(piVar5);
        return 1;
      }
      ERR_GOST_error(0x7b,0x84,DAT_0011515c,0xbd);
    }
  }
LAB_001150c2:
  GOST_KEY_TRANSPORT_free(piVar5);
  return 0xffffffff;
}

