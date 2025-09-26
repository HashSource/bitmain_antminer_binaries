
stack_st_CONF_VALUE * _CONF_get_section_values(CONF *conf,char *section)

{
  stack_st_CONF_VALUE *psVar1;
  char *local_14;
  undefined4 local_10;
  
  if (conf == (CONF *)0x0 || section == (char *)0x0) {
    psVar1 = (stack_st_CONF_VALUE *)0x0;
  }
  else {
    local_10 = 0;
    local_14 = section;
    psVar1 = (stack_st_CONF_VALUE *)lh_retrieve((_LHASH *)conf->data,&local_14);
    if (psVar1 != (stack_st_CONF_VALUE *)0x0) {
      psVar1 = (stack_st_CONF_VALUE *)(psVar1->stack).sorted;
    }
  }
  return psVar1;
}

