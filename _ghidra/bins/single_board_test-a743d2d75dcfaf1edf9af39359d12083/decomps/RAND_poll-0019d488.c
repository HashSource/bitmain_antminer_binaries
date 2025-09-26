
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

int RAND_poll(void)

{
  __uid_t _Var1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ssize_t sVar5;
  __ino_t *p_Var6;
  undefined4 *puVar7;
  size_t len;
  char *pcVar8;
  uint uVar9;
  __uid_t local_15c;
  pollfd local_158;
  uchar auStack_150 [32];
  stat local_130 [3];
  
  len = 0;
  pcVar8 = "ded";
  uVar9 = 0;
  _Var1 = getpid();
  memset(local_130,0,0x108);
  do {
    pcVar8 = pcVar8 + 4;
    iVar2 = open(*(char **)pcVar8,0x900);
    if (-1 < iVar2) {
      iVar3 = __fxstat(3,iVar2,local_130 + uVar9);
      if (iVar3 == 0) {
        if (uVar9 != 0) {
          p_Var6 = &local_130[0].st_ino;
          uVar4 = 0;
          do {
            if ((*p_Var6 == local_130[uVar9].st_ino) &&
               (p_Var6[-2] == *(__ino_t *)((int)&local_130[uVar9].st_dev + 4) &&
                (__ino_t)((stat *)(p_Var6 + -3))->st_dev == (__ino_t)local_130[uVar9].st_dev)) {
              if (uVar4 < uVar9) goto LAB_0019d51a;
              break;
            }
            uVar4 = uVar4 + 1;
            p_Var6 = p_Var6 + 0x16;
          } while (uVar4 != uVar9);
        }
        local_158.events = 1;
        local_158.revents = 0;
        local_158.fd = iVar2;
        iVar3 = poll(&local_158,1,10);
        if (((-1 < iVar3) && ((int)((uint)(ushort)local_158.revents << 0x1f) < 0)) &&
           (sVar5 = read(iVar2,auStack_150 + len,0x20 - len), 0 < sVar5)) {
          len = len + sVar5;
        }
      }
LAB_0019d51a:
      close(iVar2);
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 3 && (int)len < 0x20);
  puVar7 = &egdsockets_11711;
  pcVar8 = egdsockets_11711;
  while (pcVar8 != (char *)0x0) {
    if (0x1f < (int)len) goto LAB_0019d5e8;
    iVar2 = RAND_query_egd_bytes(pcVar8,auStack_150 + len,0x20 - len);
    if (0 < iVar2) {
      len = len + iVar2;
    }
    puVar7 = puVar7 + 1;
    pcVar8 = (char *)*puVar7;
  }
  if (len != 0) {
LAB_0019d5e8:
    RAND_add(auStack_150,0x20,(double)(longlong)(int)len);
    OPENSSL_cleanse(auStack_150,len);
  }
  local_15c = _Var1;
  RAND_add(&local_15c,4,0.0);
  local_15c = getuid();
  RAND_add(&local_15c,4,0.0);
  local_15c = time((time_t *)0x0);
  RAND_add(&local_15c,4,0.0);
  return 1;
}

