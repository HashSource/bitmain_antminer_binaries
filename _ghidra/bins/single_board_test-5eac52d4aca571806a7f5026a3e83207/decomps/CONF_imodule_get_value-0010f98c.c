
char * CONF_imodule_get_value(CONF_IMODULE *md)

{
  return *(char **)(md + 8);
}

