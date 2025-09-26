
undefined4 i2r_ocsp_serviceloc(undefined4 param_1,undefined4 *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = BIO_printf(param_3,"%*sIssuer: ",param_4,"");
  if ((0 < iVar1) &&
     (iVar1 = X509_NAME_print_ex(param_3,(X509_NAME *)*param_2,0,0x82031f), 0 < iVar1)) {
    iVar1 = 0;
    do {
      iVar3 = sk_num((_STACK *)param_2[1]);
      if (iVar3 <= iVar1) {
        return 1;
      }
      puVar2 = (undefined4 *)sk_value((_STACK *)param_2[1],iVar1);
      iVar3 = BIO_printf(param_3,"\n%*s",param_4 << 1,"");
    } while ((((0 < iVar3) && (iVar3 = i2a_ASN1_OBJECT(param_3,(ASN1_OBJECT *)*puVar2), 0 < iVar3))
             && (iVar3 = BIO_puts(param_3," - "), 0 < iVar3)) &&
            (iVar3 = GENERAL_NAME_print(param_3,(GENERAL_NAME *)puVar2[1]), iVar1 = iVar1 + 1,
            0 < iVar3));
  }
  return 0;
}

