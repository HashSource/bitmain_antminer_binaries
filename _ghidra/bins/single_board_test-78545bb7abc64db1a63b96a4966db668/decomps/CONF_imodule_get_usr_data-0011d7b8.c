
void * CONF_imodule_get_usr_data(CONF_IMODULE *md)

{
  return *(void **)(md + 0x10);
}

