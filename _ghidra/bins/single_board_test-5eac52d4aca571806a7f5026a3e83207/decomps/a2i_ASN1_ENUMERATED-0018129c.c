
int a2i_ASN1_ENUMERATED(BIO *bp,ASN1_ENUMERATED *bs,char *buf,int size)

{
  int iVar1;
  uint extraout_r3;
  uint uVar2;
  
  iVar1 = a2i_ASN1_INTEGER(bp,bs,buf,size);
  uVar2 = extraout_r3;
  if (iVar1 == 1) {
    uVar2 = bs->type & 0x100U | 2;
  }
  if (iVar1 == 1) {
    bs->type = uVar2;
  }
  return iVar1;
}

