
undefined4 pub_decode_gost94(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  uchar *puVar1;
  int iVar2;
  ASN1_OCTET_STRING *a;
  uchar *s;
  void *pvVar3;
  BIGNUM *pBVar4;
  uchar *puVar5;
  X509_ALGOR *local_28;
  uchar *local_24;
  ASN1_OBJECT *local_20;
  long local_1c [2];
  
  local_20 = (ASN1_OBJECT *)0x0;
  local_28 = (X509_ALGOR *)0x0;
  local_24 = (uchar *)0x0;
  iVar2 = X509_PUBKEY_get0_param(&local_20,&local_24,local_1c,&local_28,param_2);
  if (iVar2 != 0) {
    iVar2 = OBJ_obj2nid(local_20);
    EVP_PKEY_assign(param_1,iVar2,(void *)0x0);
    iVar2 = decode_gost_algor_params(param_1,local_28);
    if (iVar2 != 0) {
      a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_24,local_1c[0]);
      if (a != (ASN1_OCTET_STRING *)0x0) {
        s = (uchar *)CRYPTO_malloc(a->length,DAT_00115930,0x26b);
        if (0 < a->length) {
          puVar5 = s + a->length;
          iVar2 = 0;
          do {
            puVar1 = a->data + iVar2;
            iVar2 = iVar2 + 1;
            puVar5 = puVar5 + -1;
            *puVar5 = *puVar1;
          } while (iVar2 < a->length);
        }
        pvVar3 = EVP_PKEY_get0(param_1);
        pBVar4 = BN_bin2bn(s,a->length,(BIGNUM *)0x0);
        *(BIGNUM **)((int)pvVar3 + 0x18) = pBVar4;
        ASN1_OCTET_STRING_free(a);
        CRYPTO_free(s);
        return 1;
      }
      ERR_GOST_error(0x86,0x41,DAT_00115930,0x268);
      return 0;
    }
  }
  return 0;
}

