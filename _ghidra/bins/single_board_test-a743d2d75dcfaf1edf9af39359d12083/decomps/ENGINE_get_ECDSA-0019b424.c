
ECDSA_METHOD * ENGINE_get_ECDSA(ENGINE *e)

{
  return *(ECDSA_METHOD **)(e + 0x18);
}

