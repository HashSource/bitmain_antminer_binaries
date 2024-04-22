
void suffix_string(uint64_t val,char *buf,size_t bufsiz,int sigdigits)

{
  bool bVar1;
  size_t in_r3;
  bool bVar2;
  double dVar3;
  undefined8 uVar4;
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
  _Bool decimal;
  double dval;
  
  suffix[0] = '\0';
  suffix[1] = '\0';
  bVar1 = true;
  bVar2 = DAT_00018754 <= bufsiz;
  if (bufsiz == DAT_00018754) {
    bVar2 = DAT_00018750 <= buf;
  }
  if (bVar2) {
    uVar4 = __aeabi_uldivmod(buf,bufsiz,DAT_00018748,DAT_0001874c);
    dVar3 = (double)__aeabi_ul2d((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    dval = dVar3 / 1000.0;
    suffix[0] = 'E';
    suffix[1] = '\0';
  }
  else {
    bVar2 = DAT_0001874c <= bufsiz;
    if (bufsiz == DAT_0001874c) {
      bVar2 = DAT_00018748 <= buf;
    }
    if (bVar2) {
      uVar4 = __aeabi_uldivmod(buf,bufsiz,DAT_00018740,DAT_00018744);
      dVar3 = (double)__aeabi_ul2d((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      dval = dVar3 / 1000.0;
      suffix[0] = 'P';
      suffix[1] = '\0';
    }
    else {
      bVar2 = DAT_00018744 <= bufsiz;
      if (bufsiz == DAT_00018744) {
        bVar2 = DAT_00018740 <= buf;
      }
      if (bVar2) {
        uVar4 = __aeabi_uldivmod(buf,bufsiz,DAT_00018738,DAT_0001873c);
        dVar3 = (double)__aeabi_ul2d((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        dval = dVar3 / 1000.0;
        suffix[0] = 'T';
        suffix[1] = '\0';
      }
      else {
        bVar2 = DAT_0001873c <= bufsiz;
        if (bufsiz == DAT_0001873c) {
          bVar2 = DAT_00018738 <= buf;
        }
        if (bVar2) {
          uVar4 = __aeabi_uldivmod(buf,bufsiz,1000000,0);
          dVar3 = (double)__aeabi_ul2d((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
          dval = dVar3 / 1000.0;
          suffix[0] = 'G';
          suffix[1] = '\0';
        }
        else if (bufsiz == 0 && buf < nonce_num[6][0x55] + 0x2d) {
          if (bufsiz == 0 && buf < (char *)0x3e8) {
            dval = (double)__aeabi_ul2d(buf,bufsiz);
            bVar1 = false;
          }
          else {
            dVar3 = (double)__aeabi_ul2d(buf,bufsiz);
            dval = dVar3 / 1000.0;
            suffix[0] = 'K';
            suffix[1] = '\0';
          }
        }
        else {
          uVar4 = __aeabi_uldivmod(buf,bufsiz,1000,0);
          dVar3 = (double)__aeabi_ul2d((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
          dval = dVar3 / 1000.0;
          suffix[0] = 'M';
          suffix[1] = '\0';
        }
      }
    }
  }
  if ((int)val == 0) {
    if (bVar1) {
      snprintf((char *)sigdigits,in_r3,"%.3g%s",suffix,dval._0_4_,dval._4_4_,suffix);
    }
    else {
      snprintf((char *)sigdigits,in_r3,"%d%s",(uint)(0.0 < dval) * (int)(longlong)dval,suffix);
    }
  }
  else {
    dVar3 = DAT_00018730;
    if (dval != 0.0 && dval < 0.0 == NAN(dval)) {
      log10((double)CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
      dVar3 = floor((double)CONCAT44(in_stack_ffffff74,in_stack_ffffff70));
    }
    snprintf((char *)sigdigits,in_r3,"%*.*f%s",(int)val + 1,
             (int)(longlong)((double)(longlong)((int)val + -1) - dVar3));
  }
  return;
}

