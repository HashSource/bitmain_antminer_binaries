
undefined4 pkey_siphash_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  void *data;
  ASN1_STRING *str;
  ASN1_STRING *dst;
  int iVar1;
  undefined4 *puVar2;
  uchar *puVar3;
  long lVar4;
  ASN1_STRING *pAVar5;
  ASN1_STRING *pAVar6;
  undefined4 uVar7;
  
  data = (void *)CRYPTO_zalloc(0x50,"crypto/siphash/siphash_pmeth.c",0x1f);
  if (data != (void *)0x0) {
    *(undefined4 *)((int)data + 4) = 4;
    EVP_PKEY_CTX_set_data(param_1,data);
    EVP_PKEY_CTX_set0_keygen_info(param_1,(int *)0x0,0);
    str = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_2);
    dst = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_1);
    iVar1 = ASN1_STRING_get0_data(str);
    if ((iVar1 == 0) || (iVar1 = ASN1_STRING_copy(dst,str), iVar1 != 0)) {
      pAVar5 = str + 1;
      do {
        pAVar6 = pAVar5 + 1;
        iVar1 = pAVar5->type;
        puVar3 = pAVar5->data;
        lVar4 = pAVar5->flags;
        dst[1].length = pAVar5->length;
        dst[1].type = iVar1;
        dst[1].data = puVar3;
        dst[1].flags = lVar4;
        pAVar5 = pAVar6;
        dst = dst + 1;
      } while (pAVar6 != str + 5);
      uVar7 = 1;
    }
    else {
      puVar2 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      uVar7 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        CRYPTO_clear_free(puVar2[2],*puVar2,"crypto/siphash/siphash_pmeth.c",0x2f);
        CRYPTO_clear_free(puVar2,0x50,"crypto/siphash/siphash_pmeth.c",0x30);
        EVP_PKEY_CTX_set_data(param_1,(void *)0x0);
      }
    }
    return uVar7;
  }
  ERR_put_error(0xf,0x7d,0x41,"crypto/siphash/siphash_pmeth.c",0x20);
  return 0;
}

