
dh_st * EVP_PKEY_get1_DH(EVP_PKEY *pkey)

{
  dh_st *pdVar1;
  
  if (pkey->type == 0x398 || pkey->type == 0x1c) {
    DH_up_ref((DH *)(pkey->pkey).rsa);
    pdVar1 = (dh_st *)(pkey->pkey).ptr;
  }
  else {
    ERR_put_error(6,0x77,0x80,DAT_000b21e4,0x155);
    pdVar1 = (dh_st *)0x0;
  }
  return pdVar1;
}

