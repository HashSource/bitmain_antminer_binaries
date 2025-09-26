
ECDH_METHOD * ENGINE_get_ECDH(ENGINE *e)

{
  return *(ECDH_METHOD **)(e + 0x14);
}

