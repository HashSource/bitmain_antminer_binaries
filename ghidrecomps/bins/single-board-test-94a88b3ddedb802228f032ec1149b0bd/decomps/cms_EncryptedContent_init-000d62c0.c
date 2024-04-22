
undefined4
cms_EncryptedContent_init
          (ASN1_OBJECT **param_1,ASN1_OBJECT *param_2,void *param_3,ASN1_OBJECT *param_4)

{
  ASN1_OBJECT *pAVar1;
  
  param_1[3] = param_2;
  if (param_3 != (void *)0x0) {
    pAVar1 = (ASN1_OBJECT *)CRYPTO_malloc((int)param_4,DAT_000d62fc,0xdb);
    param_1[4] = pAVar1;
    if (pAVar1 == (ASN1_OBJECT *)0x0) {
      return 0;
    }
    memcpy(pAVar1,param_3,(size_t)param_4);
  }
  param_1[5] = param_4;
  if (param_2 != (ASN1_OBJECT *)0x0) {
    pAVar1 = OBJ_nid2obj(0x15);
    *param_1 = pAVar1;
  }
  return 1;
}

