
void ssl2_get_cipher_by_char(byte *param_1)

{
  undefined auStack_40 [8];
  uint local_38;
  
  local_38 = param_1[2] | 0x2000000 | (uint)*param_1 << 0x10 | (uint)param_1[1] << 8;
  OBJ_bsearch_ssl_cipher_id(auStack_40,&ssl2_ciphers,7);
  return;
}

