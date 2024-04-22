
stack_st_CMS_RecipientInfo * CMS_get0_RecipientInfos(CMS_ContentInfo *cms)

{
  int iVar1;
  stack_st_CMS_RecipientInfo *psVar2;
  
  iVar1 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
  if (iVar1 == 0x17) {
    psVar2 = *(stack_st_CMS_RecipientInfo **)(cms + 4);
    if (psVar2 != (stack_st_CMS_RecipientInfo *)0x0) {
      psVar2 = *(stack_st_CMS_RecipientInfo **)(psVar2 + 8);
    }
  }
  else {
    ERR_put_error(0x2e,0x83,0x6b,DAT_000d5638,0x4f);
    psVar2 = (stack_st_CMS_RecipientInfo *)0x0;
  }
  return psVar2;
}

