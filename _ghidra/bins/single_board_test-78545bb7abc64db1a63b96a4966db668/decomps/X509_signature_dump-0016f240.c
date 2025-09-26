
int X509_signature_dump(BIO *bp,ASN1_STRING *sig,int indent)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = sig->length;
  if (0 < iVar4) {
    pbVar3 = sig->data + -1;
    iVar2 = 0;
    while( true ) {
      bVar5 = iVar2 == (iVar2 / 0x12) * 0x12;
      iVar2 = iVar2 + 1;
      if (bVar5) {
        iVar1 = BIO_write(bp,"\n",1);
        if (iVar1 < 1) {
          return 0;
        }
        iVar1 = BIO_indent(bp,indent,indent);
        if (iVar1 < 1) {
          return 0;
        }
      }
      pbVar3 = pbVar3 + 1;
      if (iVar4 == iVar2) break;
      iVar1 = BIO_printf(bp,"%02x%s",(uint)*pbVar3,":");
      if (iVar1 < 1) {
        return 0;
      }
    }
    iVar4 = BIO_printf(bp,"%02x%s",(uint)*pbVar3,"");
    if (iVar4 < 1) {
      return 0;
    }
  }
  iVar4 = BIO_write(bp,"\n",1);
  return (uint)(iVar4 == 1);
}

