
undefined4 rsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  int penclen;
  ASN1_OBJECT *aobj;
  void *obj;
  ASN1_STRING *pAVar1;
  undefined4 uVar2;
  int iVar3;
  uchar *local_20;
  ASN1_OCTET_STRING *local_1c [2];
  
  local_20 = (uchar *)0x0;
  local_1c[0] = (ASN1_STRING *)0x0;
  if (**(int **)(param_2 + 0xc) == 0x390) {
    obj = (void *)((*(RSA **)(param_2 + 0x18))->ex_data).dummy;
    if (obj != (void *)0x0) {
      pAVar1 = ASN1_item_pack(obj,(ASN1_ITEM *)RSA_PSS_PARAMS_it,local_1c);
      if (pAVar1 == (ASN1_STRING *)0x0) {
        return 0;
      }
      penclen = i2d_RSAPrivateKey(*(RSA **)(param_2 + 0x18),&local_20);
      iVar3 = 0x10;
      goto joined_r0x0014deac;
    }
    iVar3 = -1;
  }
  else {
    iVar3 = 5;
  }
  penclen = i2d_RSAPrivateKey(*(RSA **)(param_2 + 0x18),&local_20);
joined_r0x0014deac:
  if (penclen < 1) {
    uVar2 = 0;
    ERR_put_error(4,0x8a,0x41,"crypto/rsa/rsa_ameth.c",0xa6);
    ASN1_STRING_free(local_1c[0]);
  }
  else {
    aobj = OBJ_nid2obj(**(int **)(param_2 + 0xc));
    iVar3 = PKCS8_pkey_set0(param_1,aobj,0,iVar3,local_1c[0],local_20,penclen);
    if (iVar3 == 0) {
      ERR_put_error(4,0x8a,0x41,"crypto/rsa/rsa_ameth.c",0xad);
      ASN1_STRING_free(local_1c[0]);
      return 0;
    }
    uVar2 = 1;
  }
  return uVar2;
}

