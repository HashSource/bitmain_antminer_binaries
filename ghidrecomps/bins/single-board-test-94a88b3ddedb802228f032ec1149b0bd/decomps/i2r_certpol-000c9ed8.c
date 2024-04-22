
undefined4 i2r_certpol(undefined4 param_1,_STACK *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = param_4;
  while( true ) {
    iVar1 = sk_num(param_2);
    iVar4 = iVar3 + 1;
    if (iVar1 <= iVar3) break;
    ppAVar2 = (ASN1_OBJECT **)sk_value(param_2,iVar3);
    BIO_printf(param_3,DAT_000c9f38,param_4,DAT_000c9f34,iVar5);
    i2a_ASN1_OBJECT(param_3,*ppAVar2);
    BIO_puts(param_3,DAT_000c9f3c);
    iVar3 = iVar4;
    if (ppAVar2[1] != (ASN1_OBJECT *)0x0) {
      print_qualifiers(param_3,ppAVar2[1],param_4 + 2);
    }
  }
  return 1;
}

