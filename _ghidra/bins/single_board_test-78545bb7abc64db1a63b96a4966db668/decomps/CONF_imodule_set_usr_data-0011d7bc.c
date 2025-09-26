
void CONF_imodule_set_usr_data(CONF_IMODULE *md,void *usr_data)

{
  *(void **)(md + 0x10) = usr_data;
  return;
}

