
void tls13_generate_master_secret
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int *param_5)

{
  EVP_MD *md;
  int iVar1;
  
  md = (EVP_MD *)ssl_handshake_md();
  iVar1 = EVP_MD_size(md);
  *param_5 = iVar1;
  tls13_generate_secret(param_1,md,param_3,0,0,param_2);
  return;
}

