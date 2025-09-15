
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  uint *puVar1;
  char *pcVar2;
  
  puVar1 = *(uint **)node;
  BIO_printf(out,"%*sPolicy: ",indent,&DAT_0013a6fc);
  i2a_ASN1_OBJECT(out,(ASN1_OBJECT *)puVar1[1]);
  BIO_puts(out,"\n");
  pcVar2 = "Critical";
  if ((*puVar1 & 0x10) == 0) {
    pcVar2 = "Non Critical";
  }
  BIO_printf(out,"%*s%s\n",indent + 2,&DAT_0013a6fc,pcVar2);
  if (puVar1[2] != 0) {
    print_qualifiers();
    return;
  }
  BIO_printf(out,"%*sNo Qualifiers\n",indent + 2,&DAT_0013a6fc);
  return;
}

