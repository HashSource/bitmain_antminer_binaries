
int ENGINE_set_digests(ENGINE *e,ENGINE_DIGESTS_PTR f)

{
  *(ENGINE_DIGESTS_PTR *)(e + 0x28) = f;
  return 1;
}

