
rsa_st * EVP_PKEY_get1_RSA(EVP_PKEY *pkey)

{
  rsa_st *prVar1;
  
  if (pkey->type == 6) {
    RSA_up_ref((pkey->pkey).rsa);
    prVar1 = (rsa_st *)(pkey->pkey).ptr;
  }
  else {
    ERR_put_error(6,0x79,0x7f,DAT_000b20d4,0x117);
    prVar1 = (rsa_st *)0x0;
  }
  return prVar1;
}

