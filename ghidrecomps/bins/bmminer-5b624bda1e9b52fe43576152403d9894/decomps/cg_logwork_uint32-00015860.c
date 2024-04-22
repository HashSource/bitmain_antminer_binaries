
/* WARNING: Unknown calling convention */

void cg_logwork_uint32(work *work,uint nonce,_Bool ok)

{
  uchar nonce_bin [5];
  
  if (*DAT_00015880 != 0) {
    nonce_bin[4] = '\0';
    nonce_bin._0_4_ = nonce;
    cg_logwork(work,nonce_bin,ok);
  }
  return;
}

