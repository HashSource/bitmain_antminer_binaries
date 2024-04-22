
void OBJ_bsearch_ssl_cipher_id(void *param_1,void *param_2,int param_3)

{
  OBJ_bsearch_(param_1,param_2,param_3,0x30,ssl_cipher_id_cmp_BSEARCH_CMP_FN + 1);
  return;
}

