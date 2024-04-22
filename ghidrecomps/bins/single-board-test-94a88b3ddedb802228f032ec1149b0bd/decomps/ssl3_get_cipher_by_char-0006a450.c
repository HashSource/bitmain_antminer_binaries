
void ssl3_get_cipher_by_char(byte *param_1)

{
  undefined auStack_38 [8];
  uint local_30;
  
  local_30 = param_1[1] | 0x3000000 | (uint)*param_1 << 8;
  OBJ_bsearch_ssl_cipher_id(auStack_38,&ssl3_ciphers,0x8c);
  return;
}

