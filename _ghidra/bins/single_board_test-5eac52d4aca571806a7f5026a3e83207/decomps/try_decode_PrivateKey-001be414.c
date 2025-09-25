
int try_decode_PrivateKey
              (EVP_PKEY_ASN1_METHOD *param_1,undefined4 param_2,uchar *param_3,long param_4,
              undefined4 param_5,int *param_6)

{
  int iVar1;
  EVP_PKEY *pEVar2;
  EVP_PKEY_ASN1_METHOD *pEVar3;
  ENGINE *e;
  ENGINE_PKEY_ASN1_METHS_PTR pEVar4;
  int iVar5;
  int iVar6;
  EVP_PKEY *local_44;
  uchar *local_3c [2];
  EVP_PKEY_ASN1_METHOD *local_34;
  EVP_PKEY_ASN1_METHOD *local_30;
  uchar *local_2c [2];
  
  local_3c[0] = param_3;
  if (param_1 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    e = ENGINE_get_first();
    if (e == (ENGINE *)0x0) {
      local_44 = (EVP_PKEY *)0x0;
    }
    else {
      local_44 = (EVP_PKEY *)0x0;
      do {
        pEVar4 = ENGINE_get_pkey_asn1_meths(e);
        if ((pEVar4 != (ENGINE_PKEY_ASN1_METHS_PTR)0x0) &&
           (local_34 = param_1,
           iVar1 = (*pEVar4)(e,(EVP_PKEY_ASN1_METHOD **)0x0,(int **)&local_34,0), 0 < iVar1)) {
          iVar6 = 0;
          do {
            while( true ) {
              local_2c[0] = local_3c[0];
              local_30 = param_1;
              iVar5 = (*pEVar4)(e,&local_30,(int **)0x0,*(int *)(local_34 + iVar6 * 4));
              if ((((iVar5 == 0) || (local_30 == (EVP_PKEY_ASN1_METHOD *)0x0)) ||
                  ((*(uint *)(local_30 + 8) & 1) != 0)) ||
                 (pEVar2 = d2i_PrivateKey(*(int *)local_30,(EVP_PKEY **)0x0,local_2c,param_4),
                 pEVar2 == (EVP_PKEY *)0x0)) break;
              if (local_44 != (EVP_PKEY *)0x0) {
                EVP_PKEY_free(pEVar2);
                pEVar2 = local_44;
              }
              local_44 = pEVar2;
              iVar6 = iVar6 + 1;
              *param_6 = *param_6 + 1;
              if (iVar1 == iVar6) goto LAB_001be54c;
            }
            iVar6 = iVar6 + 1;
          } while (iVar1 != iVar6);
        }
LAB_001be54c:
        e = ENGINE_get_next(e);
      } while (e != (ENGINE *)0x0);
    }
    for (iVar1 = 0; iVar6 = EVP_PKEY_asn1_get_count(), iVar1 < iVar6; iVar1 = iVar1 + 1) {
      local_2c[0] = local_3c[0];
      pEVar3 = EVP_PKEY_asn1_get0(iVar1);
      if (((*(uint *)(pEVar3 + 8) & 1) == 0) &&
         (pEVar2 = d2i_PrivateKey(*(int *)pEVar3,(EVP_PKEY **)0x0,local_2c,param_4),
         pEVar2 != (EVP_PKEY *)0x0)) {
        if (local_44 != (EVP_PKEY *)0x0) {
          EVP_PKEY_free(pEVar2);
          pEVar2 = local_44;
        }
        *param_6 = *param_6 + 1;
        local_44 = pEVar2;
      }
    }
    if (1 < *param_6) {
      EVP_PKEY_free(local_44);
      return 0;
    }
  }
  else {
    iVar1 = strcmp((char *)param_1,"PRIVATE KEY");
    if (iVar1 == 0) {
      pEVar2 = (EVP_PKEY *)d2i_PKCS8_PRIV_KEY_INFO((PKCS8_PRIV_KEY_INFO **)0x0,local_3c,param_4);
      *param_6 = 1;
      local_44 = pEVar2;
      if (pEVar2 != (EVP_PKEY *)0x0) {
        local_44 = EVP_PKCS82PKEY((PKCS8_PRIV_KEY_INFO *)pEVar2);
      }
      PKCS8_PRIV_KEY_INFO_free((PKCS8_PRIV_KEY_INFO *)pEVar2);
    }
    else {
      iVar1 = pem_check_suffix(param_1,"PRIVATE KEY");
      if (iVar1 < 1) {
        return 0;
      }
      pEVar3 = EVP_PKEY_asn1_find_str((ENGINE **)0x0,(char *)param_1,iVar1);
      if (pEVar3 == (EVP_PKEY_ASN1_METHOD *)0x0) {
        return 0;
      }
      *param_6 = 1;
      local_44 = d2i_PrivateKey(*(int *)pEVar3,(EVP_PKEY **)0x0,local_3c,param_4);
    }
  }
  if (local_44 == (EVP_PKEY *)0x0) {
    return 0;
  }
  iVar1 = OSSL_STORE_INFO_new_PKEY(local_44);
  if (iVar1 == 0) {
    EVP_PKEY_free(local_44);
  }
  return iVar1;
}

