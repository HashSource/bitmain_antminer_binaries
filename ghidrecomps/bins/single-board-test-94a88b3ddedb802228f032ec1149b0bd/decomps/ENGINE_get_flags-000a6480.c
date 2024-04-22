
int ENGINE_get_flags(ENGINE *e)

{
  return *(int *)(e + 0x54);
}

