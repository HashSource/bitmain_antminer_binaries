
void suffix_string_soc(uint64_t val,char *buf,size_t bufsiz,int sigdigits,_Bool display)

{
  undefined4 uVar1;
  bool bVar2;
  uint __maxlen;
  bool bVar3;
  double dVar4;
  undefined8 uVar5;
  undefined4 in_stack_ffffff70;
  undefined4 in_stack_ffffff74;
  size_t bufsiz_local;
  char *buf_local;
  uint64_t val_local;
  char suffix [2];
  int ndigits;
  uint64_t exa;
  uint64_t peta;
  uint64_t tera;
  uint64_t giga;
  uint64_t mega;
  uint64_t kilo;
  double dkilo;
  double dval;
  _Bool decimal;
  
  __maxlen = (uint)display;
  suffix[0] = '\0';
  suffix[1] = '\0';
  bVar2 = true;
  bVar3 = DAT_0003a8f4 <= bufsiz;
  if (bufsiz == DAT_0003a8f4) {
    bVar3 = DAT_0003a8f0 <= buf;
  }
  if (bVar3) {
    uVar5 = __aeabi_uldivmod(buf,bufsiz,1000000,0);
    dVar4 = (double)__aeabi_ul2d((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    dval = dVar4 / 1000.0;
    suffix[0] = 'G';
    suffix[1] = '\0';
  }
  else if (bufsiz == 0 && buf < nonce_num[6][0x55] + 0x2d) {
    if (bufsiz == 0 && buf < (char *)0x3e8) {
      dval = (double)__aeabi_ul2d(buf,bufsiz);
      bVar2 = false;
    }
    else {
      dVar4 = (double)__aeabi_ul2d(buf,bufsiz);
      dval = dVar4 / 1000.0;
      suffix[0] = 'K';
      suffix[1] = '\0';
    }
  }
  else {
    uVar5 = __aeabi_uldivmod(buf,bufsiz,1000,0);
    dVar4 = (double)__aeabi_ul2d((int)uVar5,(int)((ulonglong)uVar5 >> 0x20));
    dval = dVar4 / 1000.0;
    suffix[0] = 'M';
    suffix[1] = '\0';
  }
  if ((int)val == 0) {
    if (bVar2) {
      snprintf((char *)sigdigits,__maxlen,"%.3g%s",suffix,dval._0_4_,dval._4_4_,suffix);
    }
    else {
      snprintf((char *)sigdigits,__maxlen,"%d%s",(uint)(0.0 < dval) * (int)(longlong)dval,suffix);
    }
  }
  else {
    dVar4 = DAT_0003a8e8;
    if (dval != 0.0 && dval < 0.0 == NAN(dval)) {
      log10((double)CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
      dVar4 = floor((double)CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
    }
    uVar1 = (undefined4)(longlong)((double)(longlong)((int)val + -1) - dVar4);
    if (val._4_1_ == '\0') {
      snprintf((char *)sigdigits,__maxlen,"%*.*f",(int)val + 1,uVar1);
    }
    else {
      snprintf((char *)sigdigits,__maxlen,"%*.*f%s",(int)val + 1,uVar1);
    }
  }
  return;
}

