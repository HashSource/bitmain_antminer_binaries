
ENGINE_PKEY_METHS_PTR ENGINE_get_pkey_meths(ENGINE *e)

{
  return *(ENGINE_PKEY_METHS_PTR *)(e + 0x2c);
}

