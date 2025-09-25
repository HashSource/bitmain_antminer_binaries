
int ENGINE_set_RSA(ENGINE *e,RSA_METHOD *rsa_meth)

{
  *(RSA_METHOD **)(e + 8) = rsa_meth;
  return 1;
}

