
void suffix_string(uint64_t val,char *buf,size_t bufsiz,int sigdigits)

{
  size_t in_r3;
  bool bVar1;
  double dVar2;
  double dVar3;
  double in_stack_ffffffb0;
  char suffix [2];
  
  dVar2 = DAT_0001de58;
  bVar1 = bufsiz <= DAT_0001dea0;
  if (DAT_0001dea0 == bufsiz) {
    bVar1 = buf <= DAT_0001de9c;
  }
  suffix[0] = '\0';
  suffix[1] = '\0';
  if (bVar1) {
    bVar1 = bufsiz <= DAT_0001de64;
    if (DAT_0001de64 == bufsiz) {
      bVar1 = buf <= DAT_0001de60;
    }
    if (bVar1) {
      bVar1 = bufsiz <= DAT_0001de74;
      if (DAT_0001de74 == bufsiz) {
        bVar1 = buf <= DAT_0001de70;
      }
      if (bVar1) {
        bVar1 = bufsiz <= DAT_0001de7c;
        if (DAT_0001de7c == bufsiz) {
          bVar1 = buf <= DAT_0001de78;
        }
        if (bVar1) {
          bVar1 = bufsiz == 0;
          if (bufsiz == 0) {
            bVar1 = buf < cgpu.results[0x1d] + 0xe4f;
          }
          if (bVar1) {
            if (bufsiz == 0 && buf < (char *)0x3e8) {
              dVar3 = (double)__aeabi_ul2d();
              if ((int)val == 0) {
                snprintf((char *)sigdigits,in_r3,DAT_0001de98,
                         (uint)(0.0 < dVar3) * (int)(longlong)dVar3,suffix);
                return;
              }
              goto LAB_0001dd24;
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
      }
      else {
        __aeabi_uldivmod(buf,bufsiz,DAT_0001de88,DAT_0001de8c);
        dVar3 = (double)__aeabi_ul2d();
        suffix[0] = 'T';
        suffix[1] = '\0';
        dVar3 = dVar3 / dVar2;
      }
    }
    else {
      __aeabi_uldivmod(buf,bufsiz,DAT_0001de68,DAT_0001de6c);
      dVar3 = (double)__aeabi_ul2d();
      suffix[0] = 'P';
      suffix[1] = '\0';
      dVar3 = dVar3 / dVar2;
    }
  }
  else {
    __aeabi_uldivmod(buf,bufsiz,DAT_0001dea4,DAT_0001dea8);
    dVar3 = (double)__aeabi_ul2d();
    suffix[0] = 'E';
    suffix[1] = '\0';
    dVar3 = dVar3 / dVar2;
  }
  if ((int)val == 0) {
    snprintf((char *)sigdigits,in_r3,DAT_0001de90,suffix,dVar3,suffix);
    return;
  }
LAB_0001dd24:
  dVar2 = DAT_0001de80;
  if (dVar3 != 0.0 && dVar3 < 0.0 == NAN(dVar3)) {
    log10(in_stack_ffffffb0);
    dVar2 = floor(in_stack_ffffffb0);
  }
  snprintf((char *)sigdigits,in_r3,DAT_0001de94,(int)val + 1,
           (int)(longlong)((double)(longlong)((int)val + -1) - dVar2));
  return;
}

