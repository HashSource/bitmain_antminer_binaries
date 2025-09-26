
ENGINE_LOAD_KEY_PTR ENGINE_get_load_pubkey_function(ENGINE *e)

{
  return *(ENGINE_LOAD_KEY_PTR *)(e + 0x48);
}

