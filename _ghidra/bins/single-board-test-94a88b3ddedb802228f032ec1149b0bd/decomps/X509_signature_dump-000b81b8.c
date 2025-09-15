
int X509_signature_dump(BIO *bp,ASN1_STRING *sig,int indent)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uchar *puVar4;
  int iVar5;
  
  iVar5 = sig->length;
  puVar4 = sig->data;
  if (0 < iVar5) {
    iVar3 = 0;
    while( true ) {
      if (iVar3 == (iVar3 / 0x12) * 0x12) {
        iVar2 = BIO_write(bp,"\n",1);
        if (iVar2 < 1) {
          return 0;
        }
        iVar2 = BIO_indent(bp,indent,indent);
        if (iVar2 < 1) {
          return 0;
        }
      }
      pbVar1 = puVar4 + iVar3;
      iVar3 = iVar3 + 1;
      if (iVar3 == iVar5) break;
      iVar2 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,":");
      if (iVar2 < 1) {
        return 0;
      }
    }
    iVar5 = BIO_printf(bp,"%02x%s",(uint)*pbVar1,&DAT_0013a6fc);
    if (iVar5 < 1) {
      return 0;
    }
  }
  iVar5 = BIO_write(bp,"\n",1);
  return (uint)(iVar5 == 1);
}

