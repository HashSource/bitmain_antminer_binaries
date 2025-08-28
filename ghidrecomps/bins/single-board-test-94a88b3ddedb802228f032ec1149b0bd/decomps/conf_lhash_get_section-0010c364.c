
stack_st_CONF_VALUE * conf_lhash_get_section(lhash_st_CONF_VALUE *conf,char *section)

{
  CONF CStack_1c;
  
  if (conf != (lhash_st_CONF_VALUE *)0x0) {
    if (default_CONF_method == (CONF_METHOD *)0x0) {
      default_CONF_method = NCONF_default();
    }
    (*default_CONF_method->init)(&CStack_1c);
    CStack_1c.data = conf;
    if (section == (char *)0x0) {
      ERR_put_error(0xe,0x6c,0x6b,"conf_lib.c",0x12d);
      conf = (lhash_st_CONF_VALUE *)0x0;
    }
    else {
      conf = (lhash_st_CONF_VALUE *)_CONF_get_section_values(&CStack_1c,section);
    }
  }
  return (stack_st_CONF_VALUE *)conf;
}

