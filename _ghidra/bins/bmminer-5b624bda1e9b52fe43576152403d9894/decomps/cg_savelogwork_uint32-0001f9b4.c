
/* WARNING: Unknown calling convention */

void cg_savelogwork_uint32(work *work,uint nonce)

{
  uchar nonce_bin [5];
  
  nonce_bin[4] = '\0';
  nonce_bin._0_4_ = nonce;
  cg_savelogwork(work,nonce_bin);
  return;
}

