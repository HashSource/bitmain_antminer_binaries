
undefined4 pub_decode_gost01(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  uchar *puVar1;
  int iVar2;
  EC_KEY *pEVar3;
  EC_GROUP *group;
  ASN1_OCTET_STRING *a;
  void *ptr;
  BIGNUM *y;
  BIGNUM *x;
  EC_POINT *p;
  int iVar4;
  uchar *puVar5;
  X509_ALGOR *local_30;
  uchar *local_2c;
  ASN1_OBJECT *local_28;
  long local_24;
  
  local_28 = (ASN1_OBJECT *)0x0;
  local_30 = (X509_ALGOR *)0x0;
  local_2c = (uchar *)0x0;
  iVar2 = X509_PUBKEY_get0_param(&local_28,&local_2c,&local_24,&local_30,param_2);
  if (iVar2 != 0) {
    iVar2 = OBJ_obj2nid(local_28);
    EVP_PKEY_assign(param_1,iVar2,(void *)0x0);
    iVar2 = decode_gost_algor_params(param_1,local_30);
    if (iVar2 != 0) {
      pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_1);
      group = EC_KEY_get0_group(pEVar3);
      a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_2c,local_24);
      if (a == (ASN1_OCTET_STRING *)0x0) {
        ERR_GOST_error(0x85,0x41,DAT_0011563c,0x2ad);
        return 0;
      }
      ptr = CRYPTO_malloc(a->length,DAT_0011563c,0x2b0);
      iVar2 = a->length;
      if (0 < iVar2) {
        puVar5 = (uchar *)((int)ptr + iVar2);
        iVar4 = 0;
        do {
          puVar1 = a->data + iVar4;
          iVar4 = iVar4 + 1;
          puVar5 = puVar5 + -1;
          *puVar5 = *puVar1;
          iVar2 = a->length;
        } while (iVar4 < iVar2);
      }
      iVar2 = iVar2 / 2;
      ASN1_OCTET_STRING_free(a);
      y = (BIGNUM *)getbnfrombuf(ptr,iVar2);
      x = (BIGNUM *)getbnfrombuf((int)ptr + iVar2,iVar2);
      CRYPTO_free(ptr);
      p = EC_POINT_new(group);
      iVar2 = EC_POINT_set_affine_coordinates_GFp(group,p,x,y,(BN_CTX *)0x0);
      if (iVar2 != 0) {
        BN_free(x);
        BN_free(y);
        pEVar3 = (EC_KEY *)EVP_PKEY_get0(param_1);
        iVar2 = EC_KEY_set_public_key(pEVar3,p);
        if (iVar2 != 0) {
          EC_POINT_free(p);
          return 1;
        }
        ERR_GOST_error(0x85,0x10,DAT_0011563c,0x2c5);
        EC_POINT_free(p);
        return 0;
      }
      ERR_GOST_error(0x85,0x10,DAT_0011563c,700);
      EC_POINT_free(p);
      BN_free(x);
      BN_free(y);
      return 0;
    }
  }
  return 0;
}

