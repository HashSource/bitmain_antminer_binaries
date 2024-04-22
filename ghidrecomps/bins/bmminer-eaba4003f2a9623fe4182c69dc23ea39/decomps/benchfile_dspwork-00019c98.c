
void benchfile_dspwork(work *work,uint nonce)

{
  uint nonce_local;
  work *work_local;
  char tmp42 [2048];
  char buf [1024];
  int i;
  uint dn;
  
  dn = 0;
  nonce_local = nonce;
  for (i = 0; i < 4; i = i + 1) {
    dn = dn * 0x100 + (nonce_local & 0xff);
    nonce_local = nonce_local >> 8;
  }
  __bin2hex(buf,work->data,0x80);
  if (((use_syslog != false) || (opt_log_output != false)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x800,"BENCHFILE nonce %u=0x%08x for work=%s",dn,dn,buf);
    _applog(3,tmp42,false);
  }
  return;
}

