
int ENGINE_set_ECDSA(ENGINE *e,ECDSA_METHOD *ecdsa_meth)

{
  *(ECDSA_METHOD **)(e + 0x18) = ecdsa_meth;
  return 1;
}

