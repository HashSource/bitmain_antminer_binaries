
undefined4 rsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  int penclen;
  ASN1_OBJECT *aobj;
  void *obj;
  ASN1_STRING *pAVar1;
  RSA *a;
  int iVar2;
  uchar *local_20;
  ASN1_OCTET_STRING *local_1c [2];
  
  a = *(RSA **)(param_2 + 0x18);
  local_20 = (uchar *)0x0;
  local_1c[0] = (ASN1_OCTET_STRING *)0x0;
  if (**(int **)(param_2 + 0xc) == 0x390) {
    obj = (void *)(a->ex_data).dummy;
    if (obj == (void *)0x0) {
      iVar2 = -1;
    }
    else {
      pAVar1 = ASN1_item_pack(obj,(ASN1_ITEM *)RSA_PSS_PARAMS_it,local_1c);
      if (pAVar1 == (ASN1_STRING *)0x0) {
        return 0;
      }
      a = *(RSA **)(param_2 + 0x18);
      iVar2 = 0x10;
    }
  }
  else {
    iVar2 = 5;
  }
  penclen = i2d_RSAPublicKey(a,&local_20);
  if (0 < penclen) {
    aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
    iVar2 = X509_PUBKEY_set0_param(param_1,aobj,iVar2,local_1c[0],local_20,penclen);
    if (iVar2 != 0) {
      return 1;
    }
    CRYPTO_free(local_20);
  }
  return 0;
}

