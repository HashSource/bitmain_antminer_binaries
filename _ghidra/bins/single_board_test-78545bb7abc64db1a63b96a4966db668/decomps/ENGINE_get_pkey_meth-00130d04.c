
EVP_PKEY_METHOD * ENGINE_get_pkey_meth(ENGINE *e,int nid)

{
  ENGINE_PKEY_METHS_PTR pEVar1;
  int iVar2;
  EVP_PKEY_METHOD *local_14;
  
  pEVar1 = ENGINE_get_pkey_meths(e);
  if ((pEVar1 != (ENGINE_PKEY_METHS_PTR)0x0) &&
     (iVar2 = (*pEVar1)(e,&local_14,(int **)0x0,nid), iVar2 != 0)) {
    return local_14;
  }
  ERR_put_error(0x26,0xc0,0x65,"crypto/engine/tb_pkmeth.c",0x4c);
  return (EVP_PKEY_METHOD *)0x0;
}

