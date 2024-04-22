
bool i2r_object(undefined4 param_1,ASN1_OBJECT *param_2,BIO *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = BIO_printf(param_3,DAT_000cc274,param_4,DAT_000cc278,param_4);
  if (iVar1 < 1) {
    return false;
  }
  iVar1 = i2a_ASN1_OBJECT(param_3,param_2);
  return 0 < iVar1;
}

