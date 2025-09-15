
ENGINE_DIGESTS_PTR ENGINE_get_digests(ENGINE *e)

{
  return *(ENGINE_DIGESTS_PTR *)(e + 0x28);
}

