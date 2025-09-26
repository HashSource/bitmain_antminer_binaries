
int ENGINE_set_ECDH(ENGINE *e,ECDH_METHOD *ecdh_meth)

{
  *(ECDH_METHOD **)(e + 0x14) = ecdh_meth;
  return 1;
}

