
BIGNUM * BN_bin2bn(uchar *s,int len,BIGNUM *ret)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar5;
  int iVar6;
  BIGNUM *a;
  byte *pbVar4;
  
  a = (BIGNUM *)0x0;
  if ((ret != (BIGNUM *)0x0) || (ret = BN_new(), a = ret, ret != (BIGNUM *)0x0)) {
    if ((0 < len) && (*s == '\0')) {
      pbVar4 = s + 1;
      do {
        s = pbVar4;
        len = len + -1;
        if (len == 0) goto LAB_0011a522;
        pbVar4 = s + 1;
      } while (*s == 0);
    }
    if (len == 0) {
LAB_0011a522:
      ret->top = 0;
    }
    else {
      uVar5 = len - 1U & 7;
      iVar6 = (len - 1U >> 3) + 1;
      iVar1 = bn_wexpand(ret,iVar6);
      if (iVar1 != 0) {
        uVar2 = 0;
        ret->top = iVar6;
        ret->neg = 0;
        pbVar4 = s;
        do {
          while( true ) {
            pbVar3 = pbVar4 + 1;
            uVar2 = (uint)*pbVar4 | uVar2 << 8;
            pbVar4 = pbVar3;
            if (uVar5 != 0) break;
            iVar6 = iVar6 + -1;
            ret->d[iVar6] = uVar2;
            uVar5 = 7;
            uVar2 = 0;
            if (pbVar3 == s + len) goto LAB_0011a57c;
          }
          uVar5 = uVar5 - 1;
        } while (pbVar3 != s + len);
LAB_0011a57c:
        bn_correct_top(ret);
        return ret;
      }
      BN_free(a);
      ret = (BIGNUM *)0x0;
    }
  }
  return ret;
}

