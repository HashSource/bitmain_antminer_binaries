
stack_st_CONF_VALUE * _CONF_get_section_values(CONF *conf,char *section)

{
  CONF_VALUE *pCVar1;
  
  pCVar1 = _CONF_get_section(conf,section);
  if (pCVar1 != (CONF_VALUE *)0x0) {
    pCVar1 = (CONF_VALUE *)pCVar1->value;
  }
  return (stack_st_CONF_VALUE *)pCVar1;
}

