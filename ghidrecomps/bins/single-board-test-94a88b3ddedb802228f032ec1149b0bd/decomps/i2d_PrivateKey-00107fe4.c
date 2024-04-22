
int i2d_PrivateKey(EVP_PKEY *a,uchar **pp)

{
  int iVar1;
  PKCS8_PRIV_KEY_INFO *a_00;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  
  pEVar2 = a->ameth;
  if (pEVar2 != (EVP_PKEY_ASN1_METHOD *)0x0) {
    if (*(code **)(pEVar2 + 0x60) != (code *)0x0) {
      iVar1 = (**(code **)(pEVar2 + 0x60))();
      return iVar1;
    }
    if (*(int *)(pEVar2 + 0x28) != 0) {
      a_00 = EVP_PKEY2PKCS8(a);
      iVar1 = i2d_PKCS8_PRIV_KEY_INFO(a_00,pp);
      PKCS8_PRIV_KEY_INFO_free(a_00);
      return iVar1;
    }
  }
  ERR_put_error(0xd,0xa3,0xa7,DAT_0010802c,0x4c);
  return -1;
}

