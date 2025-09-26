
DH_METHOD * ENGINE_get_DH(ENGINE *e)

{
  return *(DH_METHOD **)(e + 0x10);
}

