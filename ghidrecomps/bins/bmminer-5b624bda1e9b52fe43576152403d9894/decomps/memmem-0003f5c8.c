
void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
  size_t sVar1;
  uint uVar2;
  void *pvVar3;
  size_t __n;
  int iVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar12;
  size_t local_2c [2];
  int iVar11;
  
  if (__needlelen == 0) {
    return __haystack;
  }
  if (__needlelen <= __haystacklen) {
    if (0x1f < __needlelen) {
      pvVar3 = two_way_long_needle((uchar *)__haystack,__haystacklen,(uchar *)__needle,__needlelen);
      return pvVar3;
    }
                    /* WARNING: Load size is inaccurate */
    pvVar3 = rpl_memchr(__haystack,(uint)*__needle,__haystacklen);
    if (__needlelen == 1 || pvVar3 == (void *)0x0) {
      return pvVar3;
    }
    uVar12 = (int)__haystack + (__haystacklen - (int)pvVar3);
    if (uVar12 < __needlelen) {
      return (void *)0x0;
    }
    if (__needlelen < 3) {
      __n = __needlelen - 1;
      local_2c[0] = 1;
    }
    else {
      __n = critical_factorization((uchar *)__needle,__needlelen,local_2c);
    }
    sVar1 = local_2c[0];
    iVar4 = memcmp(__needle,(void *)((int)__needle + local_2c[0]),__n);
    if (iVar4 == 0) {
      uVar6 = __n - 1;
      uVar5 = 0;
      uVar9 = 0;
      do {
        uVar8 = uVar9;
        if (uVar9 < __n) {
          uVar8 = __n;
        }
        if (uVar8 < __needlelen) {
          pcVar7 = (char *)((int)__needle + uVar8);
          if (*(char *)((int)__needle + uVar8) == *(char *)((int)pvVar3 + uVar5 + uVar8)) {
            do {
              uVar8 = uVar8 + 1;
              if (__needlelen <= uVar8) goto LAB_0003f682;
              pcVar7 = pcVar7 + 1;
            } while (*(char *)((int)pvVar3 + uVar8 + uVar5) == *pcVar7);
          }
          uVar9 = 0;
          uVar5 = (1 - __n) + uVar5 + uVar8;
        }
        else {
LAB_0003f682:
          uVar8 = __n;
          if ((uVar9 < __n) &&
             (*(char *)((int)__needle + uVar6) == *(char *)((int)pvVar3 + uVar6 + uVar5))) {
            uVar2 = uVar6;
            pcVar7 = (char *)((int)__needle + uVar6);
            do {
              uVar8 = uVar2;
              if (pcVar7 == (char *)((int)__needle + uVar9)) break;
              pcVar7 = pcVar7 + -1;
              uVar2 = uVar8 - 1;
            } while (*pcVar7 == *(char *)((int)pvVar3 + (uVar8 - 1) + uVar5));
          }
          if (uVar8 < uVar9 + 1) {
            return (void *)((int)pvVar3 + uVar5);
          }
          uVar5 = uVar5 + sVar1;
          uVar9 = __needlelen - sVar1;
        }
      } while (uVar5 <= uVar12 - __needlelen);
    }
    else {
      iVar4 = __n - 1;
      uVar9 = __needlelen - __n;
      if (__needlelen - __n < __n) {
        uVar9 = __n;
      }
      uVar5 = 0;
      do {
        if (__n < __needlelen) {
          pcVar7 = (char *)((int)__needle + __n);
          uVar6 = __n;
          if (*(char *)((int)__needle + __n) == *(char *)((int)pvVar3 + __n + uVar5)) {
            do {
              uVar6 = uVar6 + 1;
              if (__needlelen <= uVar6) goto LAB_0003f73a;
              pcVar7 = pcVar7 + 1;
            } while (*(char *)((int)pvVar3 + uVar6 + uVar5) == *pcVar7);
          }
          uVar5 = (1 - __n) + uVar5 + uVar6;
        }
        else {
LAB_0003f73a:
          if (iVar4 == -1) {
LAB_0003f764:
            return (void *)((int)pvVar3 + uVar5);
          }
          iVar11 = iVar4;
          if (*(char *)((int)__needle + iVar4) == *(char *)((int)pvVar3 + uVar5 + iVar4)) {
            do {
              iVar10 = iVar11 + -1;
              if (iVar11 == 0) goto LAB_0003f764;
              iVar11 = iVar10;
            } while (*(char *)((int)__needle + iVar10) == *(char *)((int)pvVar3 + iVar10 + uVar5));
          }
          uVar5 = uVar5 + uVar9 + 1;
        }
      } while (uVar5 <= uVar12 - __needlelen);
    }
  }
  return (void *)0x0;
}

