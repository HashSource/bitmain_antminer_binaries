
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  uint *puVar1;
  undefined4 uVar2;
  
  puVar1 = *(uint **)node;
  BIO_printf(out,DAT_000ca61c,indent,DAT_000ca618);
  i2a_ASN1_OBJECT(out,(ASN1_OBJECT *)puVar1[1]);
  BIO_puts(out,DAT_000ca620);
  uVar2 = DAT_000ca624;
  if ((*puVar1 & 0x10) == 0) {
    uVar2 = DAT_000ca630;
  }
  BIO_printf(out,DAT_000ca628,indent + 2,DAT_000ca618,uVar2);
  if (puVar1[2] != 0) {
    print_qualifiers();
    return;
  }
  BIO_printf(out,DAT_000ca62c,indent + 2,DAT_000ca618);
  return;
}

