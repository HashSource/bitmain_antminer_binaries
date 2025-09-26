
void * CONF_module_get_usr_data(CONF_MODULE *pmod)

{
  return *(void **)(pmod + 0x14);
}

