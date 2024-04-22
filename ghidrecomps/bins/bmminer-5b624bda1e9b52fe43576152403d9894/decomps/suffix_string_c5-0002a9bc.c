
void suffix_string_c5(uint64_t val,char *buf,size_t bufsiz,int sigdigits,_Bool display)

{
  uint __maxlen;
  bool bVar1;
  double dVar2;
  double dVar3;
  double in_stack_ffffffb8;
  char suffix [2];
  
  dVar2 = DAT_0002aaf0;
  __maxlen = (uint)display;
  bVar1 = bufsiz <= DAT_0002ab10;
  if (DAT_0002ab10 == bufsiz) {
    bVar1 = buf <= DAT_0002ab0c;
  }
  suffix[0] = '\0';
  suffix[1] = '\0';
  if (bVar1) {
    bVar1 = bufsiz == 0;
    if (bufsiz == 0) {
      bVar1 = buf < cgpu.results[0x1d] + 0xe4f;
    }
    if (bVar1) {
      if (bufsiz == 0 && buf < (char *)0x3e8) {
        dVar3 = (double)__aeabi_ul2d();
        if ((int)val == 0) {
          snprintf((char *)sigdigits,__maxlen,DAT_0002ab08,
                   (uint)(0.0 < dVar3) * (int)(longlong)dVar3,suffix);
          return;
        }
        goto LAB_0002aa54;
      }
      dVar3 = (double)__aeabi_ul2d();
      suffix[0] = 'K';
      suffix[1] = '\0';
      dVar3 = dVar3 / dVar2;
    }
    else {
      __aeabi_uldivmod(buf,bufsiz,1000,0);
      dVar3 = (double)__aeabi_ul2d();
      suffix[0] = 'M';
      suffix[1] = '\0';
      dVar3 = dVar3 / dVar2;
    }
  }
  else {
    __aeabi_uldivmod(buf,bufsiz,1000000,0);
    dVar3 = (double)__aeabi_ul2d();
    suffix[0] = 'G';
    suffix[1] = '\0';
    dVar3 = dVar3 / dVar2;
  }
  if ((int)val == 0) {
    snprintf((char *)sigdigits,__maxlen,DAT_0002ab00,suffix,dVar3,suffix);
    return;
  }
LAB_0002aa54:
  dVar2 = DAT_0002aaf8;
  if (dVar3 != 0.0 && dVar3 < 0.0 == NAN(dVar3)) {
    log10(in_stack_ffffffb8);
    dVar2 = floor(in_stack_ffffffb8);
  }
  snprintf((char *)sigdigits,__maxlen,DAT_0002ab04,(int)val + 1,
           (int)(longlong)((double)(longlong)((int)val + -1) - dVar2));
  return;
}

