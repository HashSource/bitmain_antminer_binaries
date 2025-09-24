
dsa_st * EVP_PKEY_get1_DSA(EVP_PKEY *pkey)

{
  DSA *r;
  
  r = (DSA *)EVP_PKEY_get0_DSA(pkey);
  if (r != (DSA *)0x0) {
    DSA_up_ref(r);
  }
  return r;
}

