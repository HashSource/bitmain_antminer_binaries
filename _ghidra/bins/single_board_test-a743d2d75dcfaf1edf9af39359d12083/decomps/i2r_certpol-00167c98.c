
undefined4 i2r_certpol(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = param_4;
  while( true ) {
    iVar1 = sk_num(param_2);
    iVar4 = iVar3 + 1;
    if (iVar1 <= iVar3) break;
    puVar2 = (undefined4 *)sk_value(param_2,iVar3);
    BIO_printf(param_3,"%*sPolicy: ",param_4,"",iVar5);
    i2a_ASN1_OBJECT(param_3,(ASN1_OBJECT *)*puVar2);
    BIO_puts(param_3,"\n");
    iVar3 = iVar4;
    if (puVar2[1] != 0) {
      print_qualifiers(param_3,puVar2[1],param_4 + 2);
    }
  }
  return 1;
}

