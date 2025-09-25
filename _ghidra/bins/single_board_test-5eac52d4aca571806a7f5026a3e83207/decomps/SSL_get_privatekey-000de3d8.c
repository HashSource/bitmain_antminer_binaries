
evp_pkey_st * SSL_get_privatekey(SSL *ssl)

{
  evp_pkey_st *peVar1;
  
  peVar1 = (evp_pkey_st *)ssl[2].error;
  if (peVar1 != (evp_pkey_st *)0x0) {
    peVar1 = *(evp_pkey_st **)(peVar1->type + 4);
  }
  return peVar1;
}

