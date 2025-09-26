
void flush_nonce(gold_nonce *nonce)

{
  size_t sVar1;
  gold_nonce *nonce_local;
  char szmsg [1024];
  char *sznonce;
  char *szdata;
  char *szmidstate;
  
  szmidstate = (char *)0x0;
  szdata = (char *)0x0;
  sznonce = (char *)0x0;
  if (nonce->count == 1) {
    if (fd_log == (FILE *)0x0) {
      fd_log = (FILE *)fopen("/mnt/card/worklog.txt","ab");
    }
    if ((nonce->asic == 0) &&
       (((nonce->nonce & 1) << 0x18 |
        nonce->nonce >> 0x18 | (nonce->nonce & 0xff0000) >> 8 | (nonce->nonce & 0xff00) << 8) <
        gmax_nonce_super)) {
      szmidstate = bin2hex((uchar *)nonce->midstate,0x20);
      szdata = bin2hex((uchar *)nonce->data,0xc);
      sznonce = bin2hex((uchar *)&nonce->nonce,4);
      memset(szmsg,0,0x400);
      sprintf(szmsg,"midstate %s data %s nonce %s coreid %d\r\n",szmidstate,szdata,sznonce,
              nonce->coreid);
      sVar1 = strlen(szmsg);
      fwrite(szmsg,sVar1,1,(FILE *)fd_log);
      fflush((FILE *)fd_log);
      if (g_asic_unique_nonce[nonce->coreid].count == 0) {
        if (fd_log0 == (FILE *)0x0) {
          fd_log0 = (FILE *)fopen("/mnt/card/worklog0.txt","ab");
        }
        memcpy(g_asic_unique_nonce[nonce->coreid].midstate,nonce->midstate,0x20);
        memcpy(g_asic_unique_nonce[nonce->coreid].data,nonce->data,0xc);
        g_asic_unique_nonce[nonce->coreid].nonce = nonce->nonce;
        g_asic_unique_nonce[nonce->coreid].coreid = nonce->coreid;
        g_asic_unique_nonce[nonce->coreid].asic = nonce->asic;
        g_asic_unique_nonce[nonce->coreid].count = 1;
        sVar1 = strlen(szmsg);
        fwrite(szmsg,sVar1,1,(FILE *)fd_log0);
        fflush((FILE *)fd_log0);
        printf("write unique nonce to file, core: %d\n",nonce->coreid);
      }
    }
    if (szmidstate != (char *)0x0) {
      free(szmidstate);
    }
    if (szdata != (char *)0x0) {
      free(szdata);
    }
    if (sznonce != (char *)0x0) {
      free(sznonce);
    }
  }
  else {
    nonce->coreid = 0;
    nonce->count = 0;
    nonce->nonce = 0;
    nonce->asic = 0;
    memset(nonce->midstate,0,0x20);
    memset(nonce->data,0,0xc);
  }
  return;
}

