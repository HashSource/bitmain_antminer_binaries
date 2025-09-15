
undefined4 rsa_pub_encode(X509_PUBKEY *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  ASN1_OBJECT *aobj;
  uchar *local_14;
  
  local_14 = (uchar *)0x0;
  iVar1 = i2d_RSAPublicKey(*(RSA **)(param_2 + 0x14),&local_14);
  if (iVar1 < 1) {
    uVar2 = 0;
  }
  else {
    aobj = OBJ_nid2obj(6);
    iVar1 = X509_PUBKEY_set0_param(param_1,aobj,5,(void *)0x0,local_14,iVar1);
    uVar2 = 1;
    if (iVar1 == 0) {
      CRYPTO_free(local_14);
      uVar2 = 0;
    }
  }
  return uVar2;
}

