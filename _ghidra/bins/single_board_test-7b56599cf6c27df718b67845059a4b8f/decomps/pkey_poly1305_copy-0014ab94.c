
undefined4 pkey_poly1305_copy(EVP_PKEY_CTX *param_1,EVP_PKEY_CTX *param_2)

{
  void *data;
  ASN1_STRING *str;
  ASN1_STRING *dst;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  data = (void *)CRYPTO_zalloc(0x100,"crypto/poly1305/poly1305_pmeth.c",0x1f);
  if (data != (void *)0x0) {
    *(undefined4 *)((int)data + 4) = 4;
    EVP_PKEY_CTX_set_data(param_1,data);
    EVP_PKEY_CTX_set0_keygen_info(param_1,(int *)0x0,0);
    str = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_2);
    dst = (ASN1_STRING *)EVP_PKEY_CTX_get_data(param_1);
    iVar1 = ASN1_STRING_get0_data(str);
    if ((iVar1 == 0) || (iVar1 = ASN1_STRING_copy(dst,str), iVar1 != 0)) {
      uVar3 = 1;
      memcpy(dst + 1,str + 1,0xf0);
    }
    else {
      puVar2 = (undefined4 *)EVP_PKEY_CTX_get_data(param_1);
      uVar3 = 0;
      if (puVar2 != (undefined4 *)0x0) {
        CRYPTO_clear_free(puVar2[2],*puVar2,"crypto/poly1305/poly1305_pmeth.c",0x2f);
        CRYPTO_clear_free(puVar2,0x100,"crypto/poly1305/poly1305_pmeth.c",0x30);
        EVP_PKEY_CTX_set_data(param_1,(void *)0x0);
      }
    }
    return uVar3;
  }
  ERR_put_error(0xf,0x7c,0x41,"crypto/poly1305/poly1305_pmeth.c",0x20);
  return 0;
}

