
void suffix_string(uint64_t val,char *buf,size_t bufsiz,int sigdigits)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  double dVar4;
  char suffix [2];
  
  uVar2 = (uint)(val >> 0x20);
  uVar1 = (uint)val;
  bVar3 = uVar2 < 0xde0b6b4;
  if (uVar2 == 0xde0b6b3) {
    bVar3 = uVar1 < 0xa7640000;
  }
  suffix[0] = '\0';
  suffix[1] = '\0';
  if (bVar3) {
    bVar3 = uVar2 < 0x38d7f;
    if (uVar2 == 0x38d7e) {
      bVar3 = uVar1 < 0xa4c68000;
    }
    if (bVar3) {
      bVar3 = uVar2 < 0xe9;
      if (uVar2 == 0xe8) {
        bVar3 = uVar1 < 0xd4a51000;
      }
      if (bVar3) {
        bVar3 = uVar2 == 0;
        if (uVar2 == 0) {
          bVar3 = uVar1 < 1000000000;
        }
        if (bVar3) {
          bVar3 = uVar2 == 0;
          if (uVar2 == 0) {
            bVar3 = uVar1 < 1000000;
          }
          if (bVar3) {
            if (uVar2 == 0 && uVar1 < 1000) {
              dVar4 = (double)__aeabi_ul2d();
              if (sigdigits == 0) {
                snprintf(buf,bufsiz,"%d%s",(uint)(0.0 < dVar4) * (int)(longlong)dVar4,suffix);
                return;
              }
              goto LAB_0001dd24;
            }
            dVar4 = (double)__aeabi_ul2d();
            suffix[0] = 'K';
            suffix[1] = '\0';
            dVar4 = dVar4 / 1000.0;
          }
          else {
            __aeabi_uldivmod(uVar1,uVar2,1000,0);
            dVar4 = (double)__aeabi_ul2d();
            suffix[0] = 'M';
            suffix[1] = '\0';
            dVar4 = dVar4 / 1000.0;
          }
        }
        else {
          __aeabi_uldivmod(uVar1,uVar2,1000000,0);
          dVar4 = (double)__aeabi_ul2d();
          suffix[0] = 'G';
          suffix[1] = '\0';
          dVar4 = dVar4 / 1000.0;
        }
      }
      else {
        __aeabi_uldivmod(uVar1,uVar2,1000000000,0);
        dVar4 = (double)__aeabi_ul2d();
        suffix[0] = 'T';
        suffix[1] = '\0';
        dVar4 = dVar4 / 1000.0;
      }
    }
    else {
      __aeabi_uldivmod(uVar1,uVar2,0xd4a51000,0xe8);
      dVar4 = (double)__aeabi_ul2d();
      suffix[0] = 'P';
      suffix[1] = '\0';
      dVar4 = dVar4 / 1000.0;
    }
  }
  else {
    __aeabi_uldivmod(uVar1,uVar2,0xa4c68000,0x38d7e);
    dVar4 = (double)__aeabi_ul2d();
    suffix[0] = 'E';
    suffix[1] = '\0';
    dVar4 = dVar4 / 1000.0;
  }
  if (sigdigits == 0) {
    snprintf(buf,bufsiz,"%.3g%s",suffix,dVar4,suffix);
    return;
  }
LAB_0001dd24:
  if (dVar4 <= 0.0) {
    dVar4 = 0.0;
  }
  else {
    dVar4 = log10(dVar4);
    dVar4 = floor(dVar4);
  }
  snprintf(buf,bufsiz,"%*.*f%s",sigdigits + 1,
           (int)(longlong)((double)(longlong)(sigdigits + -1) - dVar4));
  return;
}

