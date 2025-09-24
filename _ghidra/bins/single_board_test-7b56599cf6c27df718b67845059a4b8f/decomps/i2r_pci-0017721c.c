
undefined4 i2r_pci(undefined4 param_1,undefined4 *param_2,BIO *param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  BIO_printf(param_3,"%*sPath Length Constraint: ",param_4,"");
  if ((ASN1_INTEGER *)*param_2 == (ASN1_INTEGER *)0x0) {
    BIO_printf(param_3,"infinite");
  }
  else {
    i2a_ASN1_INTEGER(param_3,(ASN1_INTEGER *)*param_2);
  }
  BIO_puts(param_3,"\n");
  BIO_printf(param_3,"%*sPolicy Language: ",param_4,"");
  i2a_ASN1_OBJECT(param_3,*(ASN1_OBJECT **)param_2[1]);
  BIO_puts(param_3,"\n");
  puVar1 = *(undefined4 **)(param_2[1] + 4);
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[2] != 0)) {
    BIO_printf(param_3,"%*sPolicy Text: %.*s\n",param_4,"",*puVar1,puVar1[2]);
  }
  return 1;
}

