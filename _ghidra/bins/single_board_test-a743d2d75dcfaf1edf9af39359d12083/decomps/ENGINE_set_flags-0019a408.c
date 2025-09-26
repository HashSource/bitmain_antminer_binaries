
int ENGINE_set_flags(ENGINE *e,int flags)

{
  *(int *)(e + 0x54) = flags;
  return 1;
}

