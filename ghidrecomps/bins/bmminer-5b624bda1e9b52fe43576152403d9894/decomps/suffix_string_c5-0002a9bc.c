
void suffix_string_c5(uint64_t val,char *buf,size_t bufsiz,int sigdigits,_Bool display)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  double dVar4;
  char suffix [2];
  
  iVar2 = (int)(val >> 0x20);
  uVar1 = (uint)val;
  bVar3 = iVar2 == 0;
  if (iVar2 == 0) {
    bVar3 = uVar1 < 1000000000;
  }
  suffix[0] = '\0';
  suffix[1] = '\0';
  if (bVar3) {
    bVar3 = iVar2 == 0;
    if (iVar2 == 0) {
      bVar3 = uVar1 < 1000000;
    }
    if (bVar3) {
      if (iVar2 == 0 && uVar1 < 1000) {
        dVar4 = (double)__aeabi_ul2d();
        if (sigdigits == 0) {
          snprintf(buf,bufsiz,"%d%s",(uint)(0.0 < dVar4) * (int)(longlong)dVar4,suffix);
          return;
        }
        goto LAB_0002aa54;
      }
      dVar4 = (double)__aeabi_ul2d();
      suffix[0] = 'K';
      suffix[1] = '\0';
      dVar4 = dVar4 / 1000.0;
    }
    else {
      __aeabi_uldivmod(uVar1,iVar2,1000,0);
      dVar4 = (double)__aeabi_ul2d();
      suffix[0] = 'M';
      suffix[1] = '\0';
      dVar4 = dVar4 / 1000.0;
    }
  }
  else {
    __aeabi_uldivmod(uVar1,iVar2,1000000,0);
    dVar4 = (double)__aeabi_ul2d();
    suffix[0] = 'G';
    suffix[1] = '\0';
    dVar4 = dVar4 / 1000.0;
  }
  if (sigdigits == 0) {
    snprintf(buf,bufsiz,"%.3g%s",suffix,dVar4,suffix);
    return;
  }
LAB_0002aa54:
  if (dVar4 <= 0.0) {
    dVar4 = 0.0;
  }
  else {
    dVar4 = log10(dVar4);
    dVar4 = floor(dVar4);
  }
  snprintf(buf,bufsiz,"%*.*f",sigdigits + 1,
           (int)(longlong)((double)(longlong)(sigdigits + -1) - dVar4));
  return;
}

