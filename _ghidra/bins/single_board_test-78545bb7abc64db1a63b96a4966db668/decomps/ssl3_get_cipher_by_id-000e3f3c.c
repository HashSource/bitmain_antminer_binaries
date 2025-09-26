
void ssl3_get_cipher_by_id(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_50 [12];
  undefined4 local_44;
  
  local_44 = param_1;
  iVar1 = OBJ_bsearch_ssl_cipher_id(auStack_50,&tls13_ciphers,5);
  if ((iVar1 == 0) && (iVar1 = OBJ_bsearch_ssl_cipher_id(auStack_50,ssl3_ciphers,0xa4), iVar1 == 0))
  {
    OBJ_bsearch_ssl_cipher_id(auStack_50,ssl3_scsvs,2);
  }
  return;
}

