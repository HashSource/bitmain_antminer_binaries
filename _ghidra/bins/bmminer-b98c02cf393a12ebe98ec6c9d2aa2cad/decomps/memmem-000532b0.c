
void * memmem(void *__haystack,size_t __haystacklen,void *__needle,size_t __needlelen)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  size_t sVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint __n;
  uint uVar13;
  int local_2c [2];
  
  pvVar4 = __haystack;
  if (__needlelen != 0) {
    if (__haystacklen < __needlelen) {
      return (void *)0x0;
    }
    if (0x1f < __needlelen) {
      pvVar4 = (void *)two_way_long_needle();
      return pvVar4;
    }
                    /* WARNING: Load size is inaccurate */
    pvVar2 = (void *)rpl_memchr(__haystack,*__needle,__haystacklen);
    pvVar4 = pvVar2;
    if (__needlelen != 1 && pvVar2 != (void *)0x0) {
      uVar10 = __haystacklen - ((int)pvVar2 - (int)__haystack);
      pvVar4 = (void *)0x0;
      if (__needlelen <= uVar10) {
        if (__needlelen < 3) {
          __n = __needlelen - 1;
          local_2c[0] = 1;
        }
        else {
          __n = critical_factorization_part_0(__needle,__needlelen,local_2c);
        }
        iVar12 = local_2c[0];
        iVar3 = memcmp(__needle,(void *)((int)__needle + local_2c[0]),__n);
        if (iVar3 != 0) {
          iVar12 = __n - 1;
          uVar5 = __needlelen - __n;
          if (__needlelen - __n < __n) {
            uVar5 = __n;
          }
          uVar13 = 0;
          do {
            if (__n < __needlelen) {
              pcVar7 = (char *)(__n + uVar13 + (int)pvVar2);
              sVar9 = __n;
              pcVar6 = (char *)((int)__needle + __n);
              if (*(char *)((int)pvVar2 + __n + uVar13) == *(char *)((int)__needle + __n)) {
                do {
                  sVar9 = sVar9 + 1;
                  if (__needlelen == sVar9) goto LAB_0005342e;
                  pcVar6 = pcVar6 + 1;
                  pcVar7 = pcVar7 + 1;
                } while (*pcVar6 == *pcVar7);
              }
              uVar13 = uVar13 + (1 - __n) + sVar9;
            }
            else {
LAB_0005342e:
              if (iVar12 == -1) {
LAB_00053458:
                return (void *)((int)pvVar2 + uVar13);
              }
              pcVar7 = (char *)(iVar12 + uVar13 + (int)pvVar2);
              pcVar6 = (char *)((int)__needle + iVar12);
              if (*(char *)((int)pvVar2 + iVar12 + uVar13) == *(char *)((int)__needle + iVar12)) {
                do {
                  if (pcVar6 == (char *)__needle) goto LAB_00053458;
                  pcVar6 = pcVar6 + -1;
                  pcVar7 = pcVar7 + -1;
                } while (*pcVar6 == *pcVar7);
              }
              uVar13 = uVar13 + uVar5 + 1;
            }
            if (uVar10 - __needlelen < uVar13) {
              return (void *)0x0;
            }
          } while( true );
        }
        uVar11 = __n - 1;
        uVar5 = 0;
        uVar13 = 0;
        do {
          uVar8 = __n;
          if (__n < uVar13) {
            uVar8 = uVar13;
          }
          if (uVar8 < __needlelen) {
            pcVar6 = (char *)((int)__needle + uVar8);
            pcVar7 = (char *)(uVar8 + uVar5 + (int)pvVar2);
            if (*(char *)((int)__needle + uVar8) == *(char *)((int)pvVar2 + uVar8 + uVar5)) {
              do {
                uVar8 = uVar8 + 1;
                if (__needlelen == uVar8) goto LAB_00053360;
                pcVar6 = pcVar6 + 1;
                pcVar7 = pcVar7 + 1;
              } while (*pcVar6 == *pcVar7);
            }
            uVar5 = uVar5 + (1 - __n) + uVar8;
            uVar13 = 0;
          }
          else {
LAB_00053360:
            uVar8 = __n;
            if ((uVar13 < __n) &&
               (pcVar6 = (char *)(uVar11 + uVar5 + (int)pvVar2),
               *(char *)((int)pvVar2 + uVar11 + uVar5) == *(char *)((int)__needle + uVar11))) {
              uVar1 = uVar11;
              pcVar7 = (char *)((int)__needle + uVar11);
              do {
                uVar8 = uVar1;
                if (uVar8 - 1 == uVar13 - 1) break;
                pcVar7 = pcVar7 + -1;
                pcVar6 = pcVar6 + -1;
                uVar1 = uVar8 - 1;
              } while (*pcVar7 == *pcVar6);
            }
            if (uVar8 < uVar13 + 1) {
              return (void *)(uVar5 + (int)pvVar2);
            }
            uVar5 = uVar5 + iVar12;
            uVar13 = __needlelen - iVar12;
          }
          if (uVar10 - __needlelen < uVar5) {
            return (void *)0x0;
          }
        } while( true );
      }
    }
  }
  return pvVar4;
}

