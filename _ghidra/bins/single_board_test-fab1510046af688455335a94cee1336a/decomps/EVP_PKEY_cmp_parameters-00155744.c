
int EVP_PKEY_cmp_parameters(EVP_PKEY *a,EVP_PKEY *b)

{
  int iVar1;
  code *pcVar2;
  
  if (a->type != b->type) {
    return -1;
  }
  if ((a->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar2 = *(code **)(a->ameth + 0x48), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)();
    return iVar1;
  }
  return -2;
}

