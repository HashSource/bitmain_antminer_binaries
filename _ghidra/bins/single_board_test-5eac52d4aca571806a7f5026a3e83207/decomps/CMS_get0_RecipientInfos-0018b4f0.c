
stack_st_CMS_RecipientInfo * CMS_get0_RecipientInfos(CMS_ContentInfo *cms)

{
  stack_st_CMS_RecipientInfo *psVar1;
  
  psVar1 = (stack_st_CMS_RecipientInfo *)cms_get0_enveloped(cms);
  if (psVar1 != (stack_st_CMS_RecipientInfo *)0x0) {
    psVar1 = *(stack_st_CMS_RecipientInfo **)(psVar1 + 8);
  }
  return psVar1;
}

