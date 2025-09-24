
DSA_METHOD * ENGINE_get_DSA(ENGINE *e)

{
  return *(DSA_METHOD **)(e + 0xc);
}

