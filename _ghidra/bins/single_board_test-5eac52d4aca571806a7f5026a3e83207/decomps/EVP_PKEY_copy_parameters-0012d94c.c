
int EVP_PKEY_copy_parameters(EVP_PKEY *to,EVP_PKEY *from)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (to->type == 0) {
    iVar1 = EVP_PKEY_set_type(to,from->type);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = EVP_PKEY_missing_parameters(from);
  }
  else {
    if (to->type != from->type) {
      ERR_put_error(6,0x67,0x65,"crypto/evp/p_lib.c",0x51);
      return 0;
    }
    iVar1 = EVP_PKEY_missing_parameters(from);
  }
  if (iVar1 != 0) {
    ERR_put_error(6,0x67,0x67,"crypto/evp/p_lib.c",0x56);
    return 0;
  }
  iVar1 = EVP_PKEY_missing_parameters(to);
  if (iVar1 == 0) {
    iVar1 = EVP_PKEY_cmp_parameters(to,from);
    if (iVar1 != 1) {
      ERR_put_error(6,0x67,0x99,"crypto/evp/p_lib.c",0x5d);
      return 0;
    }
    return 1;
  }
  if ((from->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(from->ameth + 0x48), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x0012d982. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(to,from);
    return iVar1;
  }
  return 0;
}

