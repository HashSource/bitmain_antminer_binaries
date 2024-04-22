
int EVP_PKEY_print_params(BIO *out,EVP_PKEY *pkey,int indent,ASN1_PCTX *pctx)

{
  int iVar1;
  char *pcVar2;
  code *pcVar3;
  
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar3 = *(code **)(pkey->ameth + 0x4c), pcVar3 != (code *)0x0)) {
    iVar1 = (*pcVar3)();
    return iVar1;
  }
  BIO_indent(out,indent,0x80);
  pcVar2 = OBJ_nid2ln(pkey->type);
  BIO_printf(out,DAT_000b2338,DAT_000b233c,pcVar2);
  return 1;
}

