
int pub_encode_gost01(X509_PUBKEY *param_1,EVP_PKEY *param_2)

{
  EC_KEY *key;
  int iVar1;
  ASN1_OBJECT *aobj;
  BIGNUM *order;
  EC_GROUP *pEVar2;
  EC_POINT *p;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar3;
  void *__s;
  ASN1_OCTET_STRING *str;
  uchar *puVar4;
  uchar *puVar5;
  uchar *puVar6;
  uchar *puVar7;
  size_t __n;
  void *local_38;
  int local_34;
  uchar *local_2c [2];
  
  local_2c[0] = (uchar *)0x0;
  key = (EC_KEY *)EVP_PKEY_get0(param_2);
  iVar1 = EVP_PKEY_base_id(param_2);
  aobj = OBJ_nid2obj(iVar1);
  if (param_2->save_parameters == 0) {
    local_34 = -1;
    local_38 = (void *)0x0;
  }
  else {
    local_34 = 0x10;
    local_38 = (void *)encode_gost_algor_params(param_2);
  }
  order = BN_new();
  pEVar2 = EC_KEY_get0_group(key);
  EC_GROUP_get_order(pEVar2,order,(BN_CTX *)0x0);
  p = EC_KEY_get0_public_key(key);
  if (p == (EC_POINT *)0x0) {
    ERR_GOST_error(0x87,0x7a,DAT_00116150,0x2e4);
    iVar1 = 0;
  }
  else {
    a = BN_new();
    a_00 = BN_new();
    if (a == (BIGNUM *)0x0 || a_00 == (BIGNUM *)0x0) {
      ERR_GOST_error(0x87,0x41,DAT_00116150,0x2ea);
      if (a != (BIGNUM *)0x0) {
        BN_free(a);
      }
      if (a_00 != (BIGNUM *)0x0) {
        BN_free(a_00);
      }
      BN_free(order);
      iVar1 = 0;
    }
    else {
      pEVar2 = EC_KEY_get0_group(key);
      iVar1 = EC_POINT_get_affine_coordinates_GFp(pEVar2,p,a,a_00,(BN_CTX *)0x0);
      if (iVar1 == 0) {
        ERR_GOST_error(0x87,0x44,DAT_00116150,0x2f2);
        BN_free(a);
        BN_free(a_00);
        BN_free(order);
        iVar1 = 0;
      }
      else {
        iVar3 = BN_num_bits(order);
        iVar1 = iVar3 + 0xe;
        if (-1 < iVar3 + 7) {
          iVar1 = iVar3 + 7;
        }
        iVar1 = iVar1 >> 3;
        __n = iVar1 * 2;
        BN_free(order);
        __s = CRYPTO_malloc(__n,DAT_00116150,0x2fa);
        memset(__s,0,__n);
        store_bignum(a,(int)__s + iVar1,iVar1);
        store_bignum(a_00,__s,iVar1);
        BN_free(a);
        BN_free(a_00);
        str = ASN1_OCTET_STRING_new();
        ASN1_STRING_set(str,(void *)0x0,__n);
        puVar4 = ASN1_STRING_data(str);
        if (0 < (int)__n) {
          puVar7 = (uchar *)((int)__s + __n);
          puVar5 = puVar4;
          do {
            puVar7 = puVar7 + -1;
            puVar6 = puVar5 + 1;
            *puVar5 = *puVar7;
            puVar5 = puVar6;
          } while (puVar6 != puVar4 + __n);
        }
        CRYPTO_free(__s);
        iVar1 = i2d_ASN1_OCTET_STRING(str,local_2c);
        ASN1_BIT_STRING_free(str);
        if (iVar1 < 0) {
          iVar1 = 0;
        }
        else {
          iVar1 = X509_PUBKEY_set0_param(param_1,aobj,local_34,local_38,local_2c[0],iVar1);
        }
      }
    }
  }
  return iVar1;
}

