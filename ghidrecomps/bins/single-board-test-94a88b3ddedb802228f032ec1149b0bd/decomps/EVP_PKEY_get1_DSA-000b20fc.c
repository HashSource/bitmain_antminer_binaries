
dsa_st * EVP_PKEY_get1_DSA(EVP_PKEY *pkey)

{
  dsa_st *pdVar1;
  
  if (pkey->type == 0x74) {
    DSA_up_ref((DSA *)(pkey->pkey).rsa);
    pdVar1 = (dsa_st *)(pkey->pkey).ptr;
  }
  else {
    ERR_put_error(6,0x78,0x81,DAT_000b212c,299);
    pdVar1 = (dsa_st *)0x0;
  }
  return pdVar1;
}

