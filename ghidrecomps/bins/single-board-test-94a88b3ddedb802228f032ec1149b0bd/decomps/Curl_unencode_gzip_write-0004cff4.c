
undefined4 Curl_unencode_gzip_write(undefined4 param_1,int param_2,size_t param_3)

{
  code **ppcVar1;
  undefined4 uVar2;
  char *pcVar3;
  void *__dest;
  int iVar4;
  size_t sVar5;
  void *__s;
  int local_1c;
  
  ppcVar1 = DAT_0004d1dc;
  iVar4 = *(int *)(param_2 + 0x90);
  __s = (void *)(param_2 + 0x94);
  if (iVar4 == 0) {
    memset(__s,0,0x38);
    uVar2 = DAT_0004d1e4;
    *(undefined4 *)(param_2 + 0xb4) = DAT_0004d1e0;
    *(undefined4 *)(param_2 + 0xb8) = uVar2;
    pcVar3 = (char *)zlibVersion();
    iVar4 = strcmp(pcVar3,DAT_0004d1e8);
    if (iVar4 < 0) {
      iVar4 = inflateInit2_(__s,0xfffffff1,DAT_0004d1ec,0x38);
      if (iVar4 == 0) {
        *(undefined4 *)(param_2 + 0x90) = 1;
        goto LAB_0004d0da;
      }
    }
    else {
      iVar4 = inflateInit2_(__s,0x2f,DAT_0004d1ec,0x38);
      if (iVar4 == 0) {
        *(undefined4 *)(param_2 + 0x90) = 4;
        goto LAB_0004d0b0;
      }
    }
    uVar2 = process_zlib_error(param_1,__s);
  }
  else {
    if (iVar4 != 4) {
      if (iVar4 != 1) {
        if (iVar4 != 2) {
          *(size_t *)(param_2 + 0x98) = param_3;
          *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x5c);
          sVar5 = param_3;
          goto LAB_0004d024;
        }
        uVar2 = *(undefined4 *)(param_2 + 0x94);
        *(size_t *)(param_2 + 0x98) = param_3 + *(int *)(param_2 + 0x98);
        iVar4 = (**ppcVar1)(uVar2);
        *(int *)(param_2 + 0x94) = iVar4;
        if (iVar4 == 0) {
          (**DAT_0004d1f4)(uVar2);
          inflateEnd(__s);
          *(undefined4 *)(param_2 + 0x90) = 0;
          return 0x1b;
        }
        memcpy((void *)(iVar4 + (*(int *)(param_2 + 0x98) - param_3)),*(void **)(param_2 + 0x5c),
               param_3);
        pcVar3 = *(char **)(param_2 + 0x94);
        if (*(int *)(param_2 + 0x98) < 10) {
          return 0;
        }
        if ((*pcVar3 == '\x1f') && (pcVar3[1] == -0x75)) {
          iVar4 = check_gzip_header_part_0(pcVar3,*(int *)(param_2 + 0x98),&local_1c);
          if (iVar4 == 0) {
            (**DAT_0004d1f4)(*(undefined4 *)(param_2 + 0x94));
            iVar4 = *(int *)(param_2 + 0x98);
            *(undefined4 *)(param_2 + 0x90) = 3;
            sVar5 = iVar4 - local_1c;
            *(size_t *)(param_2 + 0x98) = sVar5;
            *(size_t *)(param_2 + 0x94) = *(int *)(param_2 + 0x5c) + (local_1c - iVar4) + param_3;
            goto LAB_0004d024;
          }
          if (iVar4 == 2) {
            return 0;
          }
          pcVar3 = *(char **)(param_2 + 0x94);
        }
        (**DAT_0004d1f4)(pcVar3);
        goto LAB_0004d110;
      }
LAB_0004d0da:
      pcVar3 = *(char **)(param_2 + 0x5c);
      if ((int)param_3 < 10) {
LAB_0004d0e0:
        ppcVar1 = DAT_0004d1f0;
        *(size_t *)(param_2 + 0x98) = param_3;
        __dest = (void *)(**ppcVar1)(param_3);
        *(void **)(param_2 + 0x94) = __dest;
        if (__dest == (void *)0x0) {
          inflateEnd(__s);
          *(undefined4 *)(param_2 + 0x90) = 0;
          return 0x1b;
        }
        memcpy(__dest,*(void **)(param_2 + 0x5c),*(size_t *)(param_2 + 0x98));
        *(undefined4 *)(param_2 + 0x90) = 2;
        return 0;
      }
      if ((*pcVar3 == '\x1f') && (pcVar3[1] == -0x75)) {
        iVar4 = check_gzip_header_part_0(pcVar3,param_3,&local_1c);
        if (iVar4 == 0) {
          *(undefined4 *)(param_2 + 0x90) = 3;
          sVar5 = param_3 - local_1c;
          *(size_t *)(param_2 + 0x98) = sVar5;
          *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x5c) + local_1c;
LAB_0004d024:
          if (sVar5 != 0) {
            uVar2 = inflate_stream(param_1,param_2);
            return uVar2;
          }
          return 0;
        }
        if (iVar4 == 2) goto LAB_0004d0e0;
      }
LAB_0004d110:
      uVar2 = process_zlib_error(param_1,__s);
      inflateEnd(__s);
      *(undefined4 *)(param_2 + 0x90) = 0;
      return uVar2;
    }
LAB_0004d0b0:
    *(size_t *)(param_2 + 0x98) = param_3;
    *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x5c);
    uVar2 = inflate_stream(param_1,param_2);
  }
  return uVar2;
}

