
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)node;
  iVar2 = indent + 2;
  BIO_printf(out,"%*sPolicy: ",indent,"");
  i2a_ASN1_OBJECT(out,(ASN1_OBJECT *)piVar3[1]);
  BIO_puts(out,"\n");
  if (*piVar3 << 0x1b < 0) {
    pcVar1 = "Critical";
  }
  else {
    pcVar1 = "Non Critical";
  }
  BIO_printf(out,"%*s%s\n",iVar2,"",pcVar1);
  if (piVar3[2] != 0) {
    print_qualifiers(out,piVar3[2],iVar2);
    return;
  }
  BIO_printf(out,"%*sNo Qualifiers\n",iVar2,"");
  return;
}

