
int EVP_PKEY_copy_parameters(EVP_PKEY *to,EVP_PKEY *from)

{
  int iVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  
  if (to->type != from->type) {
    ERR_put_error(6,0x67,0x65,DAT_000b1f90,0x7d);
    return 0;
  }
  pEVar2 = from->ameth;
  if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return 0;
  }
  if (*(code **)(pEVar2 + 0x40) != (code *)0x0) {
    iVar1 = (**(code **)(pEVar2 + 0x40))(from);
    if (iVar1 != 0) {
      ERR_put_error(6,0x67,0x67,DAT_000b1f90,0x82);
      return 0;
    }
    pEVar2 = from->ameth;
    if (pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) {
      return 0;
    }
  }
  if (*(code **)(pEVar2 + 0x44) == (code *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(pEVar2 + 0x44))(to,from);
  return iVar1;
}

