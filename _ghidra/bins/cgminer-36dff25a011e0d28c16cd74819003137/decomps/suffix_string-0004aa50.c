
void suffix_string(uint64_t val,char *buf,size_t bufsiz,int sigdigits)

{
  bool bVar1;
  bool bVar2;
  double dVar3;
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
  _Bool decimal;
  double dval;
  
  suffix[0] = '\0';
  suffix[1] = '\0';
  bVar1 = true;
  val_local._0_4_ = (uint)val;
  val_local._4_4_ = (uint)(val >> 0x20);
  bVar2 = 0xde0b6b2 < val_local._4_4_;
  if (val_local._4_4_ == 0xde0b6b3) {
    bVar2 = 0xa763ffff < (uint)val_local;
  }
  if (bVar2) {
    uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,0xa4c68000,0x38d7e);
    dVar3 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
    dval = dVar3 / 1000.0;
    suffix[0] = 'E';
    suffix[1] = '\0';
  }
  else {
    bVar2 = 0x38d7d < val_local._4_4_;
    if (val_local._4_4_ == 0x38d7e) {
      bVar2 = 0xa4c67fff < (uint)val_local;
    }
    if (bVar2) {
      uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,0xd4a51000,0xe8);
      dVar3 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
      dval = dVar3 / 1000.0;
      suffix[0] = 'P';
      suffix[1] = '\0';
    }
    else {
      bVar2 = 0xe7 < val_local._4_4_;
      if (val_local._4_4_ == 0xe8) {
        bVar2 = 0xd4a50fff < (uint)val_local;
      }
      if (bVar2) {
        uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,1000000000,0);
        dVar3 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        dval = dVar3 / 1000.0;
        suffix[0] = 'T';
        suffix[1] = '\0';
      }
      else if (val_local._4_4_ == 0 && (uint)val_local < 1000000000) {
        if (val_local._4_4_ == 0 && (uint)val_local < 1000000) {
          if (val_local._4_4_ == 0 && (uint)val_local < 1000) {
            dval = (double)__floatundidf((uint)val_local,val_local._4_4_);
            bVar1 = false;
          }
          else {
            dVar3 = (double)__floatundidf((uint)val_local,val_local._4_4_);
            dval = dVar3 / 1000.0;
            suffix[0] = 'K';
            suffix[1] = '\0';
          }
        }
        else {
          uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,1000,0);
          dVar3 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
          dval = dVar3 / 1000.0;
          suffix[0] = 'M';
          suffix[1] = '\0';
        }
      }
      else {
        uVar4 = __aeabi_uldivmod((uint)val_local,val_local._4_4_,1000000,0);
        dVar3 = (double)__floatundidf((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
        dval = dVar3 / 1000.0;
        suffix[0] = 'G';
        suffix[1] = '\0';
      }
    }
  }
  if (sigdigits == 0) {
    if (bVar1) {
      snprintf(buf,bufsiz,"%.3g%s",dval._4_4_,dval._0_4_,dval._4_4_,suffix);
    }
    else {
      snprintf(buf,bufsiz,"%d%s",(uint)(0.0 < dval) * (int)(longlong)dval,suffix);
    }
  }
  else {
    if (dval <= 0.0) {
      dVar3 = 0.0;
    }
    else {
      dVar3 = log10(dval);
      dVar3 = floor(dVar3);
    }
    snprintf(buf,bufsiz,"%*.*f%s",sigdigits + 1,
             (int)(longlong)((double)(longlong)(sigdigits + -1) - dVar3));
  }
  return;
}

