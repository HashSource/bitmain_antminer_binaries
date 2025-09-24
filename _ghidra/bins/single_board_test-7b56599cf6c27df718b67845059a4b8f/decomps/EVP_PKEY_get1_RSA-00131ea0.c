
rsa_st * EVP_PKEY_get1_RSA(EVP_PKEY *pkey)

{
  RSA *r;
  
  r = (RSA *)EVP_PKEY_get0_RSA(pkey);
  if (r != (RSA *)0x0) {
    RSA_up_ref(r);
  }
  return r;
}

