
void suffix_string_soc(uint64_t val,char *buf,size_t bufsiz,int sigdigits,_Bool display)

{
  bool bVar1;
  double dVar2;
  undefined4 uVar3;
  undefined8 uVar4;
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
  
  suffix[0] = '\0';
  suffix[1] = '\0';
  bVar1 = true;
  val_local._0_4_ = (uint)val;
  val_local._4_4_ = (int)(val >> 0x20);
  if (val_local._4_4_ == 0 && (uint)val_local < 1000000000) {
    if (val_local._4_4_ == 0 && (uint)val_local < 1000000) {
      if (val_local._4_4_ == 0 && (uint)val_local < 1000) {
        dval = (double)__floatundidf((uint)val_local,val_local._4_4_);
        bVar1 = false;
      }
      else {
        dVar2 = (double)__floatundidf((uint)val_local,val_local._4_4_);
        dval = dVar2 / 1000.0;
        suffix[0] = 'K';
        suffix[1] = '\0';
      }
    }
    else {
      uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,1000,0);
      dVar2 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      dval = dVar2 / 1000.0;
      suffix[0] = 'M';
      suffix[1] = '\0';
    }
  }
  else {
    uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,1000000,0);
    dVar2 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    dval = dVar2 / 1000.0;
    suffix[0] = 'G';
    suffix[1] = '\0';
  }
  if (sigdigits == 0) {
    if (bVar1) {
      snprintf(buf,bufsiz,"%.3g%s",dval._0_4_,dval._0_4_,dval._4_4_,suffix);
    }
    else {
      snprintf(buf,bufsiz,"%d%s",(uint)(0.0 < dval) * (int)(longlong)dval,suffix);
    }
  }
  else {
    if (dval <= 0.0) {
      dVar2 = 0.0;
    }
    else {
      dVar2 = log10(dval);
      dVar2 = floor(dVar2);
    }
    uVar3 = (undefined4)(longlong)((double)(longlong)(sigdigits + -1) - dVar2);
    if (display) {
      snprintf(buf,bufsiz,"%*.*f%s",sigdigits + 1,uVar3);
    }
    else {
      snprintf(buf,bufsiz,"%*.*f",sigdigits + 1,uVar3);
    }
  }
  return;
}

