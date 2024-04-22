
int ENGINE_set_pkey_meths(ENGINE *e,ENGINE_PKEY_METHS_PTR f)

{
  *(ENGINE_PKEY_METHS_PTR *)(e + 0x2c) = f;
  return 1;
}

