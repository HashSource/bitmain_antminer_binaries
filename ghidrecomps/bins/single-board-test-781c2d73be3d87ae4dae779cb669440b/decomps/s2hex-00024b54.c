
/* WARNING: Unknown calling convention */

int s2hex(uchar *dst,uchar *src,int inlen)

{
  uchar uVar1;
  byte bVar2;
  uchar uVar3;
  uint unaff_r4;
  uchar *high;
  uchar *puVar4;
  int iVar5;
  uchar low;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  bVar7 = (int)dst < 0;
  bVar8 = dst == (uchar *)0x0;
  if (!bVar8) {
    bVar7 = inlen < 0;
  }
  if ((bVar8 || inlen == 0) || bVar7) {
    unaff_r4 = 1;
  }
  if ((!bVar8 && inlen != 0) && !bVar7) {
    unaff_r4 = 0;
  }
  if (src == (uchar *)0x0) {
    unaff_r4 = unaff_r4 | 1;
  }
  if (unaff_r4 == 0) {
    iVar5 = inlen >> 1;
    if (iVar5 != 0) {
      pbVar6 = dst + -1;
      high = src;
      do {
        uVar3 = high[1];
        puVar4 = high + 2;
        uVar1 = c2hex(*high);
        bVar2 = c2hex(uVar3);
        pbVar6 = pbVar6 + 1;
        *pbVar6 = bVar2 ^ uVar1 << 4;
        high = puVar4;
      } while (puVar4 != src + iVar5 * 2);
    }
    if ((inlen & 1U) != 0) {
      uVar3 = c2hex(src[iVar5 * 2]);
      printf("input value error: %c\n",0);
      dst[iVar5] = ~(uVar3 << 4);
    }
    iVar5 = iVar5 + (inlen & 1U);
  }
  else {
    printf("s2hex para error dst(%p), src(%p), inlen(%d)\n",dst,src,inlen);
    iVar5 = -1;
  }
  return iVar5;
}

