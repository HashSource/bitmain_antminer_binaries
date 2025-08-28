
undefined4 Curl_unencode_gzip_write(undefined4 param_1,int param_2,size_t param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  void *__dest;
  int iVar3;
  size_t sVar4;
  void *__s;
  int local_1c;
  
  iVar3 = *(int *)(param_2 + 0x90);
  __s = (void *)(param_2 + 0x94);
  if (iVar3 == 0) {
    memset(__s,0,0x38);
    *(undefined4 *)(param_2 + 0xb4) = 0x4cd3d;
    *(undefined4 *)(param_2 + 0xb8) = 0x4cd51;
    pcVar2 = (char *)zlibVersion();
    iVar3 = strcmp(pcVar2,"1.2.0.4");
    if (iVar3 < 0) {
      iVar3 = inflateInit2_(__s,0xfffffff1,"1.2.8",0x38);
      if (iVar3 == 0) {
        *(undefined4 *)(param_2 + 0x90) = 1;
        goto LAB_0004d0da;
      }
    }
    else {
      iVar3 = inflateInit2_(__s,0x2f,"1.2.8",0x38);
      if (iVar3 == 0) {
        *(undefined4 *)(param_2 + 0x90) = 4;
        goto LAB_0004d0b0;
      }
    }
    uVar1 = process_zlib_error(param_1,__s);
  }
  else {
    if (iVar3 != 4) {
      if (iVar3 != 1) {
        if (iVar3 != 2) {
          *(size_t *)(param_2 + 0x98) = param_3;
          *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x5c);
          sVar4 = param_3;
          goto LAB_0004d024;
        }
        uVar1 = *(undefined4 *)(param_2 + 0x94);
        *(size_t *)(param_2 + 0x98) = param_3 + *(int *)(param_2 + 0x98);
        iVar3 = (*Curl_crealloc)(uVar1);
        *(int *)(param_2 + 0x94) = iVar3;
        if (iVar3 == 0) {
          (*Curl_cfree)(uVar1);
          inflateEnd(__s);
          *(undefined4 *)(param_2 + 0x90) = 0;
          return 0x1b;
        }
        memcpy((void *)(iVar3 + (*(int *)(param_2 + 0x98) - param_3)),*(void **)(param_2 + 0x5c),
               param_3);
        pcVar2 = *(char **)(param_2 + 0x94);
        if (*(int *)(param_2 + 0x98) < 10) {
          return 0;
        }
        if ((*pcVar2 == '\x1f') && (pcVar2[1] == -0x75)) {
          iVar3 = check_gzip_header_part_0(pcVar2,*(int *)(param_2 + 0x98),&local_1c);
          if (iVar3 == 0) {
            (*Curl_cfree)(*(undefined4 *)(param_2 + 0x94));
            iVar3 = *(int *)(param_2 + 0x98);
            *(undefined4 *)(param_2 + 0x90) = 3;
            sVar4 = iVar3 - local_1c;
            *(size_t *)(param_2 + 0x98) = sVar4;
            *(size_t *)(param_2 + 0x94) = *(int *)(param_2 + 0x5c) + (local_1c - iVar3) + param_3;
            goto LAB_0004d024;
          }
          if (iVar3 == 2) {
            return 0;
          }
          pcVar2 = *(char **)(param_2 + 0x94);
        }
        (*Curl_cfree)(pcVar2);
        goto LAB_0004d110;
      }
LAB_0004d0da:
      pcVar2 = *(char **)(param_2 + 0x5c);
      if ((int)param_3 < 10) {
LAB_0004d0e0:
        *(size_t *)(param_2 + 0x98) = param_3;
        __dest = (void *)(*Curl_cmalloc)(param_3);
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
      if ((*pcVar2 == '\x1f') && (pcVar2[1] == -0x75)) {
        iVar3 = check_gzip_header_part_0(pcVar2,param_3,&local_1c);
        if (iVar3 == 0) {
          *(undefined4 *)(param_2 + 0x90) = 3;
          sVar4 = param_3 - local_1c;
          *(size_t *)(param_2 + 0x98) = sVar4;
          *(int *)(param_2 + 0x94) = *(int *)(param_2 + 0x5c) + local_1c;
LAB_0004d024:
          if (sVar4 != 0) {
            uVar1 = inflate_stream(param_1,param_2);
            return uVar1;
          }
          return 0;
        }
        if (iVar3 == 2) goto LAB_0004d0e0;
      }
LAB_0004d110:
      uVar1 = process_zlib_error(param_1,__s);
      inflateEnd(__s);
      *(undefined4 *)(param_2 + 0x90) = 0;
      return uVar1;
    }
LAB_0004d0b0:
    *(size_t *)(param_2 + 0x98) = param_3;
    *(undefined4 *)(param_2 + 0x94) = *(undefined4 *)(param_2 + 0x5c);
    uVar1 = inflate_stream(param_1,param_2);
  }
  return uVar1;
}

