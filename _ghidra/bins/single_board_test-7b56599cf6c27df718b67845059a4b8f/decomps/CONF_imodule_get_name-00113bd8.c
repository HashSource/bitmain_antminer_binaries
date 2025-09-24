
char * CONF_imodule_get_name(CONF_IMODULE *md)

{
  return *(char **)(md + 4);
}

