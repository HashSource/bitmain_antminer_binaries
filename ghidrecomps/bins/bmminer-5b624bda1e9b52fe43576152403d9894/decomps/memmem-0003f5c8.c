
void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
  size_t sVar1;
  uchar *haystack;
  void *pvVar2;
  size_t __n;
  int iVar3;
  size_t j;
  uchar *needle;
  uint uVar4;
  char *pcVar5;
  size_t i;
  uint uVar6;
  int iVar7;
  uint uVar9;
  uint uVar10;
  size_t memory;
  size_t period;
  int iVar8;
  
  if (__needlelen == 0) {
    return __haystack;
  }
  if (__needlelen <= __haystacklen) {
    if (0x1f < __needlelen) {
      pvVar2 = two_way_long_needle((uchar *)__haystack,__haystacklen,(uchar *)__needle,__needlelen);
      return pvVar2;
    }
                    /* WARNING: Load size is inaccurate */
    pvVar2 = rpl_memchr(__haystack,(uint)*__needle,__haystacklen);
    if (__needlelen == 1 || pvVar2 == (void *)0x0) {
      return pvVar2;
    }
    uVar9 = (int)__haystack + (__haystacklen - (int)pvVar2);
    if (uVar9 < __needlelen) {
      return (void *)0x0;
    }
    if (__needlelen < 3) {
      __n = __needlelen - 1;
      period = 1;
    }
    else {
      __n = critical_factorization((uchar *)__needle,__needlelen,&period);
    }
    sVar1 = period;
    iVar3 = memcmp(__needle,(void *)((int)__needle + period),__n);
    if (iVar3 == 0) {
      uVar4 = __n - 1;
      j = 0;
      memory = 0;
      do {
        i = memory;
        if (memory < __n) {
          i = __n;
        }
        if (i < __needlelen) {
          pcVar5 = (char *)((int)__needle + i);
          if (*(char *)((int)__needle + i) == *(char *)((int)pvVar2 + j + i)) {
            do {
              i = i + 1;
              if (__needlelen <= i) goto LAB_0003f682;
              pcVar5 = pcVar5 + 1;
            } while (*(char *)((int)pvVar2 + i + j) == *pcVar5);
          }
          memory = 0;
          j = (1 - __n) + j + i;
        }
        else {
LAB_0003f682:
          uVar10 = __n;
          if ((memory < __n) &&
             (*(char *)((int)__needle + uVar4) == *(char *)((int)pvVar2 + uVar4 + j))) {
            uVar6 = uVar4;
            pcVar5 = (char *)((int)__needle + uVar4);
            do {
              uVar10 = uVar6;
              if (pcVar5 == (char *)((int)__needle + memory)) break;
              pcVar5 = pcVar5 + -1;
              uVar6 = uVar10 - 1;
            } while (*pcVar5 == *(char *)((int)pvVar2 + (uVar10 - 1) + j));
          }
          if (uVar10 < memory + 1) {
            return (void *)((int)pvVar2 + j);
          }
          j = j + sVar1;
          memory = __needlelen - sVar1;
        }
      } while (j <= uVar9 - __needlelen);
    }
    else {
      iVar3 = __n - 1;
      uVar4 = __needlelen - __n;
      if (__needlelen - __n < __n) {
        uVar4 = __n;
      }
      uVar10 = 0;
      do {
        if (__n < __needlelen) {
          pcVar5 = (char *)((int)__needle + __n);
          uVar6 = __n;
          if (*(char *)((int)__needle + __n) == *(char *)((int)pvVar2 + __n + uVar10)) {
            do {
              uVar6 = uVar6 + 1;
              if (__needlelen <= uVar6) goto LAB_0003f73a;
              pcVar5 = pcVar5 + 1;
            } while (*(char *)((int)pvVar2 + uVar6 + uVar10) == *pcVar5);
          }
          uVar10 = (1 - __n) + uVar10 + uVar6;
        }
        else {
LAB_0003f73a:
          if (iVar3 == -1) {
LAB_0003f764:
            return (void *)((int)pvVar2 + uVar10);
          }
          iVar8 = iVar3;
          if (*(char *)((int)__needle + iVar3) == *(char *)((int)pvVar2 + uVar10 + iVar3)) {
            do {
              iVar7 = iVar8 + -1;
              if (iVar8 == 0) goto LAB_0003f764;
              iVar8 = iVar7;
            } while (*(char *)((int)__needle + iVar7) == *(char *)((int)pvVar2 + iVar7 + uVar10));
          }
          uVar10 = uVar10 + uVar4 + 1;
        }
      } while (uVar10 <= uVar9 - __needlelen);
    }
  }
  return (void *)0x0;
}

