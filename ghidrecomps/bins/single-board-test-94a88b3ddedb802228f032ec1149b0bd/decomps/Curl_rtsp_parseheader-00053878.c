
undefined4 Curl_rtsp_parseheader(int *param_1,int param_2)

{
  int iVar1;
  ushort **ppuVar2;
  size_t __n;
  void *__dest;
  undefined4 uVar3;
  byte *pbVar4;
  uint uVar5;
  char *__s;
  byte *__s1;
  int iVar6;
  undefined4 local_1c [2];
  
  iVar6 = *param_1;
  local_1c[0] = 0;
  iVar1 = Curl_raw_nequal(DAT_00053980,param_2,5);
  if (iVar1 != 0) {
    iVar1 = __isoc99_sscanf(param_2 + 4,DAT_00053984,local_1c);
    if (iVar1 != 1) {
      Curl_failf(iVar6,DAT_00053988,param_2);
      return 0x55;
    }
    *(undefined4 *)(*(int *)(iVar6 + 0x14c) + 100) = local_1c[0];
    *(undefined4 *)(iVar6 + 0x86a8) = local_1c[0];
    return 0;
  }
  iVar1 = Curl_raw_nequal(DAT_0005398c,param_2,8);
  if (iVar1 == 0) {
    return 0;
  }
  uVar5 = (uint)*(byte *)(param_2 + 8);
  __s1 = (byte *)(param_2 + 8);
  if (uVar5 != 0) {
    ppuVar2 = __ctype_b_loc();
    do {
      if (-1 < (int)((uint)(*ppuVar2)[uVar5] << 0x12)) {
        __s = *(char **)(iVar6 + 0x3cc);
        if (__s != (char *)0x0) {
          __n = strlen(__s);
          iVar1 = strncmp((char *)__s1,__s,__n);
          if (iVar1 == 0) {
            return 0;
          }
          Curl_failf(iVar6,DAT_00053990,__s1,__s);
          return 0x56;
        }
        uVar5 = (uint)*__s1;
        iVar1 = 1;
        pbVar4 = __s1;
        if (uVar5 == 0) goto LAB_0005395a;
        goto LAB_0005392a;
      }
      __s1 = __s1 + 1;
      uVar5 = (uint)*__s1;
    } while (uVar5 != 0);
  }
  Curl_failf(iVar6,DAT_00053994);
  return 0;
LAB_0005392a:
  do {
    if ((((-1 < (int)((uint)(*ppuVar2)[uVar5] << 0x1c)) && (uVar5 != 0x2d)) && (uVar5 != 0x5f)) &&
       ((uVar5 != 0x2e && (uVar5 != 0x2b)))) {
      if ((uVar5 != 0x5c) || (pbVar4[1] != 0x24)) break;
      pbVar4 = pbVar4 + 1;
    }
    uVar5 = (uint)pbVar4[1];
    pbVar4 = pbVar4 + 1;
  } while (uVar5 != 0);
  uVar5 = (int)pbVar4 - (int)__s1;
  iVar1 = uVar5 + 1;
LAB_0005395a:
  __dest = (void *)(**DAT_00053998)(iVar1);
  *(void **)(iVar6 + 0x3cc) = __dest;
  if (__dest == (void *)0x0) {
    uVar3 = 0x1b;
  }
  else {
    memcpy(__dest,__s1,uVar5);
    uVar3 = 0;
    *(undefined *)(*(int *)(iVar6 + 0x3cc) + uVar5) = 0;
  }
  return uVar3;
}

