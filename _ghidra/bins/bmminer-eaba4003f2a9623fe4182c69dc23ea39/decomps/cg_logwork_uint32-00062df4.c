
void cg_logwork_uint32(work *work,uint nonce,_Bool ok)

{
  _Bool ok_local;
  uint nonce_local;
  work *work_local;
  uchar nonce_bin [5];
  
  if (opt_logwork_path != (char *)0x0) {
    nonce_bin[0] = '\0';
    nonce_bin[1] = '\0';
    nonce_bin[2] = '\0';
    nonce_bin[3] = '\0';
    nonce_bin[4] = '\0';
    nonce_local = nonce;
    work_local = work;
    memcpy(nonce_bin,&nonce_local,4);
    cg_logwork(work_local,nonce_bin,ok);
  }
  return;
}

