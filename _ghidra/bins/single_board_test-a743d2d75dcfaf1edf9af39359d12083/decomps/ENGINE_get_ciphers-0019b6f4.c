
ENGINE_CIPHERS_PTR ENGINE_get_ciphers(ENGINE *e)

{
  return *(ENGINE_CIPHERS_PTR *)(e + 0x24);
}

