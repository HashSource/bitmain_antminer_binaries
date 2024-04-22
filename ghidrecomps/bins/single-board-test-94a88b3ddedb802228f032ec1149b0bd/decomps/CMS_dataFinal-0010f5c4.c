
int CMS_dataFinal(CMS_ContentInfo *cms,BIO *bio)

{
  ASN1_OCTET_STRING **ppAVar1;
  int iVar2;
  BIO *bp;
  long len;
  void *local_1c;
  
  ppAVar1 = CMS_get0_content(cms);
  if (ppAVar1 == (ASN1_OCTET_STRING **)0x0) {
    return 0;
  }
  if ((*ppAVar1 != (ASN1_OCTET_STRING *)0x0) && ((*ppAVar1)->flags << 0x1a < 0)) {
    bp = BIO_find_type(bio,0x401);
    if (bp == (BIO *)0x0) {
      ERR_put_error(0x2e,0x6e,0x69,DAT_0010f690,0xa9);
      return 0;
    }
    len = BIO_ctrl(bp,3,0,&local_1c);
    BIO_set_flags(bp,0x200);
    BIO_ctrl(bp,0x82,0,(void *)0x0);
    ASN1_STRING_set0(*ppAVar1,local_1c,len);
    (*ppAVar1)->flags = (*ppAVar1)->flags & 0xffffffdf;
  }
  iVar2 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar2 == 0x17) {
LAB_0010f626:
    iVar2 = 1;
  }
  else {
    if (iVar2 < 0x18) {
      if (iVar2 == 0x15) goto LAB_0010f626;
      if (iVar2 == 0x16) {
        iVar2 = cms_SignedData_final(cms,bio);
        return iVar2;
      }
    }
    else {
      if ((iVar2 == 0x1a) || (iVar2 == 0x312)) goto LAB_0010f626;
      if (iVar2 == 0x19) {
        iVar2 = cms_DigestedData_do_final(cms,bio,0);
        return iVar2;
      }
    }
    ERR_put_error(0x2e,0x6e,0x9c,DAT_0010f690,0xc4);
    iVar2 = 0;
  }
  return iVar2;
}

