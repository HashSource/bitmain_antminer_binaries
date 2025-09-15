
RSA_METHOD * ENGINE_get_RSA(ENGINE *e)

{
  return *(RSA_METHOD **)(e + 8);
}

