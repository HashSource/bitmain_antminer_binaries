
EVP_PKEY_METHOD * ENGINE_get_pkey_meth(ENGINE *e,int nid)

{
  int iVar1;
  EVP_PKEY_METHOD *local_c;
  
  if ((*(code **)(e + 0x2c) == (code *)0x0) ||
     (iVar1 = (**(code **)(e + 0x2c))(e,&local_c,0,nid), iVar1 == 0)) {
    ERR_put_error(0x26,0xc0,0x65,DAT_000a7f54,0x80);
    local_c = (EVP_PKEY_METHOD *)0x0;
  }
  return local_c;
}

