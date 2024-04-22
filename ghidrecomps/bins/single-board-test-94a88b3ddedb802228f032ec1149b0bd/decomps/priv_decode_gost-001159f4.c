
int priv_decode_gost(EVP_PKEY *param_1,PKCS8_PRIV_KEY_INFO *param_2)

{
  uchar *puVar1;
  int iVar2;
  ASN1_INTEGER *ai;
  BIGNUM *prv;
  ASN1_OCTET_STRING *a;
  DSA *key;
  BIGNUM *pBVar3;
  EC_KEY *key_00;
  uchar *puVar4;
  int iVar5;
  uchar *local_4c;
  uchar *local_48;
  long local_44;
  X509_ALGOR *local_40;
  ASN1_OBJECT *local_3c;
  undefined auStack_38 [31];
  uchar local_19 [5];
  
  iVar5 = 0;
  local_3c = (ASN1_OBJECT *)0x0;
  local_4c = (uchar *)0x0;
  local_48 = (uchar *)0x0;
  local_44 = 0;
  local_40 = (X509_ALGOR *)0x0;
  iVar2 = PKCS8_pkey_get0(&local_3c,&local_4c,&local_44,&local_40,param_2);
  if (iVar2 == 0) {
    return 0;
  }
  local_48 = local_4c;
  iVar2 = decode_gost_algor_params(param_1,local_40);
  if (iVar2 == 0) {
    return 0;
  }
  if (*local_48 == '\x04') {
    a = d2i_ASN1_OCTET_STRING((ASN1_OCTET_STRING **)0x0,&local_48,local_44);
    if ((a == (ASN1_OCTET_STRING *)0x0) || (a->length != 0x20)) {
      ERR_GOST_error(0x84,0x72,DAT_00115b4c,0x13f);
      return 0;
    }
    puVar4 = local_19 + 1;
    do {
      puVar1 = a->data + iVar5;
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + -1;
      *puVar4 = *puVar1;
    } while (iVar5 != 0x20);
    ASN1_STRING_free(a);
    prv = (BIGNUM *)getbnfrombuf(auStack_38,0x20);
  }
  else {
    ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&local_48,local_44);
    if (ai == (ASN1_INTEGER *)0x0) {
      return 0;
    }
    prv = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
    ASN1_INTEGER_free(ai);
    if (prv == (BIGNUM *)0x0) {
      ERR_GOST_error(0x84,0x72,DAT_00115b4c,0x14e);
      return 0;
    }
  }
  iVar2 = EVP_PKEY_base_id(param_1);
  if (iVar2 == 0x32b) {
    key_00 = (EC_KEY *)EVP_PKEY_get0(param_1);
    if (key_00 == (EC_KEY *)0x0) {
      key_00 = EC_KEY_new();
      iVar2 = EVP_PKEY_base_id(param_1);
      EVP_PKEY_assign(param_1,iVar2,key_00);
    }
    iVar2 = EC_KEY_set_private_key(key_00,prv);
    if (iVar2 == 0) goto LAB_00115a72;
    iVar2 = EVP_PKEY_missing_parameters(param_1);
    if (iVar2 == 0) {
      iVar2 = 1;
      gost2001_compute_public(key_00);
      goto LAB_00115a72;
    }
  }
  else if (iVar2 == 0x32c) {
    key = (DSA *)EVP_PKEY_get0(param_1);
    if (key == (DSA *)0x0) {
      key = DSA_new();
      iVar2 = EVP_PKEY_base_id(param_1);
      EVP_PKEY_assign(param_1,iVar2,key);
    }
    pBVar3 = BN_dup(prv);
    *(BIGNUM **)&key->field_0x1c = pBVar3;
    iVar2 = EVP_PKEY_missing_parameters(param_1);
    if (iVar2 == 0) {
      iVar2 = 1;
      gost94_compute_public(key);
      goto LAB_00115a72;
    }
  }
  iVar2 = 1;
LAB_00115a72:
  BN_free(prv);
  return iVar2;
}

