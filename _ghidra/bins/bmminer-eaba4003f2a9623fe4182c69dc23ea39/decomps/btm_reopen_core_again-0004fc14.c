
void btm_reopen_core_again(int asic,int core,int chain)

{
  size_t __size;
  int chain_local;
  int core_local;
  int asic_local;
  char tmp [200];
  
  memset(tmp,0,200);
  if ((((asic < 0) || (0x6c < asic)) || (core < 0)) ||
     (((0xd0 < core || (chain < 0)) || (0x10 < chain)))) {
    printf("[%s] asic[%d]-core[%d]-chain[%d] input error!!","btm_reopen_core_again",asic,core,chain)
    ;
  }
  else if (dev->chain_exist[chain] == 1) {
    printf("[%02d][%02d][%03d] open again\n",chain,asic,core);
    btm_enable_one_corebyasic((uchar)core,'\0',(uchar)chain,(char)asic * dev->addrInterval);
    fd_open = (FILE *)fopen("/tmp/open_again.txt","a+");
    if (fd_open != (FILE *)0x0) {
      sprintf(tmp,"Chain[%02d]-Asic[%02d]-Core[%03d] open again\n",chain,asic,core);
      __size = strlen(tmp);
      fwrite(tmp,__size,1,(FILE *)fd_open);
      fclose((FILE *)fd_open);
    }
  }
  else {
    printf("[%s] chain num is not exist\n","btm_reopen_core_again",chain);
  }
  return;
}

