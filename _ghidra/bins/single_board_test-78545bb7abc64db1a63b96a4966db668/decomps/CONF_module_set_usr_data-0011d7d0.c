
void CONF_module_set_usr_data(CONF_MODULE *pmod,void *usr_data)

{
  *(void **)(pmod + 0x14) = usr_data;
  return;
}

