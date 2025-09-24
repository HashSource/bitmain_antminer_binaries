
int ENGINE_set_flags(ENGINE *e,int flags)

{
  *(int *)(e + 0x4c) = flags;
  return 1;
}

