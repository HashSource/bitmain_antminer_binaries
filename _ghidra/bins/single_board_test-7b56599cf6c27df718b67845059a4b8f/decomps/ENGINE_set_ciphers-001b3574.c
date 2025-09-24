
int ENGINE_set_ciphers(ENGINE *e,ENGINE_CIPHERS_PTR f)

{
  *(ENGINE_CIPHERS_PTR *)(e + 0x1c) = f;
  return 1;
}

