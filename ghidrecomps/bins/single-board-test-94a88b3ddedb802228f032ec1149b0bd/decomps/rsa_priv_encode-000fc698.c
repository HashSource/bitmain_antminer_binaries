
undefined4 rsa_priv_encode(PKCS8_PRIV_KEY_INFO *param_1,int param_2)

{
  int iVar1;
  ASN1_OBJECT *aobj;
  undefined4 uVar2;
  uchar *local_14;
  
  local_14 = (uchar *)0x0;
  iVar1 = i2d_RSAPrivateKey(*(RSA **)(param_2 + 0x14),&local_14);
  if (iVar1 < 1) {
    ERR_put_error(4,0x8a,0x41,DAT_000fc6fc,0x8a);
    uVar2 = 0;
  }
  else {
    aobj = OBJ_nid2obj(6);
    iVar1 = PKCS8_pkey_set0(param_1,aobj,0,5,(void *)0x0,local_14,iVar1);
    uVar2 = 1;
    if (iVar1 == 0) {
      ERR_put_error(4,0x8a,0x41,DAT_000fc6fc,0x90);
      uVar2 = 0;
    }
  }
  return uVar2;
}

