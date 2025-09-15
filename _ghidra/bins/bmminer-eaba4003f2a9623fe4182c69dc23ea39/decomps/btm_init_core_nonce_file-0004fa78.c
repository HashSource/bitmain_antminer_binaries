
void btm_init_core_nonce_file(uint num)

{
  uint num_local;
  char tmp [100];
  
  memset(tmp,0,100);
  snprintf(tmp,100,"/tmp/core_nonce[%d].txt",num);
  fd_core = (FILE *)fopen(tmp,"w");
  if (fd_core != (FILE *)0x0) {
    fclose((FILE *)fd_core);
  }
  return;
}

