
int ENGINE_set_load_privkey_function(ENGINE *e,ENGINE_LOAD_KEY_PTR loadpriv_f)

{
  *(ENGINE_LOAD_KEY_PTR *)(e + 0x44) = loadpriv_f;
  return 1;
}

