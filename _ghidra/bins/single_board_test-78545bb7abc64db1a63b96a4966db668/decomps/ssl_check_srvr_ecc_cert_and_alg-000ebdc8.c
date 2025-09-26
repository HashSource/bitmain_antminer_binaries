
bool ssl_check_srvr_ecc_cert_and_alg(undefined4 param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  
  if (-1 < *(int *)(*(int *)(*(int *)(param_2 + 0x7c) + 0x210) + 0x14) << 0x1c) {
    return true;
  }
  uVar1 = X509_get_key_usage();
  bVar2 = (uVar1 & 0x80) != 0;
  if (!bVar2) {
    ERR_put_error(0x14,0x117,0x13e,"ssl/ssl_lib.c",0xda1);
  }
  return bVar2;
}

