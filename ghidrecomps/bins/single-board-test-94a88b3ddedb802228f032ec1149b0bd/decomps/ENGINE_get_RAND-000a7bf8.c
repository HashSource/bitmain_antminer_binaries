
RAND_METHOD * ENGINE_get_RAND(ENGINE *e)

{
  return *(RAND_METHOD **)(e + 0x1c);
}

