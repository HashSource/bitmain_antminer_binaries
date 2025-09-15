
int ENGINE_set_load_pubkey_function(ENGINE *e,ENGINE_LOAD_KEY_PTR loadpub_f)

{
  *(ENGINE_LOAD_KEY_PTR *)(e + 0x48) = loadpub_f;
  return 1;
}

