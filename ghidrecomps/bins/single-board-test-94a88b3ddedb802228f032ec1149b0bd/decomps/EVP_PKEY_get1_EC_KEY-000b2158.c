
ec_key_st * EVP_PKEY_get1_EC_KEY(EVP_PKEY *pkey)

{
  ec_key_st *peVar1;
  
  if (pkey->type == 0x198) {
    EC_KEY_up_ref((EC_KEY *)(pkey->pkey).rsa);
    peVar1 = (ec_key_st *)(pkey->pkey).ptr;
  }
  else {
    ERR_put_error(6,0x83,0x8e,DAT_000b2188,0x140);
    peVar1 = (ec_key_st *)0x0;
  }
  return peVar1;
}

