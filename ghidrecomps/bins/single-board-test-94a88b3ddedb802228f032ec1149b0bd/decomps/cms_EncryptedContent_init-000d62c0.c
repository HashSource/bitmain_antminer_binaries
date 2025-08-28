
undefined4 cms_EncryptedContent_init(undefined4 *param_1,int param_2,void *param_3,size_t param_4)

{
  void *__dest;
  ASN1_OBJECT *pAVar1;
  
  param_1[3] = param_2;
  if (param_3 != (void *)0x0) {
    __dest = CRYPTO_malloc(param_4,"cms_enc.c",0xdb);
    param_1[4] = __dest;
    if (__dest == (void *)0x0) {
      return 0;
    }
    memcpy(__dest,param_3,param_4);
  }
  param_1[5] = param_4;
  if (param_2 != 0) {
    pAVar1 = OBJ_nid2obj(0x15);
    *param_1 = pAVar1;
  }
  return 1;
}

