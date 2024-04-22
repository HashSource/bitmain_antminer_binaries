
stack_st_CMS_SignerInfo * CMS_get0_SignerInfos(CMS_ContentInfo *cms)

{
  int iVar1;
  stack_st_CMS_SignerInfo *psVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x16) {
    psVar2 = *(stack_st_CMS_SignerInfo **)(cms + 4);
    if (psVar2 != (stack_st_CMS_SignerInfo *)0x0) {
      psVar2 = (stack_st_CMS_SignerInfo *)psVar2[1].stack.num;
    }
  }
  else {
    ERR_put_error(0x2e,0x85,0x6c,DAT_001103a8,0x48);
    psVar2 = (stack_st_CMS_SignerInfo *)0x0;
  }
  return psVar2;
}

