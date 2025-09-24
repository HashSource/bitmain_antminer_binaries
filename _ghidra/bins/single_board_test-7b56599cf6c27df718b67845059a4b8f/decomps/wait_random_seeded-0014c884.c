
int wait_random_seeded(void)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  long lVar4;
  uint __fd;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  char cVar8;
  undefined1 uStack_221;
  fd_set fStack_220;
  utsname uStack_1a0;
  
  if (seeded_15576 != 0) {
    return seeded_15576;
  }
  iVar1 = shmget(0x72,1,0);
  if (iVar1 == -1) {
    iVar1 = uname(&uStack_1a0);
    if (iVar1 == 0) {
      lVar2 = strtol(uStack_1a0.release,(char **)0x0,10);
      pcVar3 = strchr(uStack_1a0.release,0x2e);
      if (pcVar3 == (char *)0x0) {
        if (4 < lVar2) {
          return 0;
        }
      }
      else {
        lVar4 = strtol(pcVar3 + 1,(char **)0x0,10);
        if (4 < lVar2) {
          return 0;
        }
        if (lVar2 == 4 && 7 < lVar4) {
          return 0;
        }
      }
    }
    __fd = open("/dev/random",0);
    if (__fd == 0xffffffff) {
      return seeded_15576;
    }
    cVar8 = 0x3ff < __fd;
    if ((int)__fd < 0x400) {
      memset(&fStack_220,0,0x80);
      uVar5 = __fd & 0x1f;
      uVar7 = __fd + 0x1f & (int)__fd >> 0x20;
      if (cVar8 == '\0') {
        uVar7 = __fd;
      }
      if ((int)__fd < 1) {
        uVar5 = -(-__fd & 0x1f);
      }
      fStack_220.fds_bits[(int)uVar7 >> 5] =
           fStack_220.fds_bits[(int)uVar7 >> 5] | 1 << (uVar5 & 0xff);
      do {
        iVar1 = select(__fd + 1,&fStack_220,(fd_set *)0x0,(fd_set *)0x0,(timeval *)0x0);
        if (-1 < iVar1) goto LAB_0014c9b0;
        piVar6 = __errno_location();
      } while (*piVar6 == 4);
    }
    else {
      do {
        iVar1 = read(__fd,&uStack_221,1);
        if (-1 < iVar1) goto LAB_0014c9b0;
        piVar6 = __errno_location();
      } while (*piVar6 == 4);
    }
    close(__fd);
    return seeded_15576;
  }
LAB_0014c8ac:
  seeded_15576 = 1;
  shm_addr = shmat(iVar1,(void *)0x0,0x1000);
  if (shm_addr == (void *)0xffffffff) {
    return 1;
  }
  OPENSSL_atexit(0x14c875);
  return seeded_15576;
LAB_0014c9b0:
  close(__fd);
  if (iVar1 != 1) {
    return seeded_15576;
  }
  seeded_15576 = iVar1;
  iVar1 = shmget(0x72,1,0x324);
  if (iVar1 == -1) {
    return 1;
  }
  goto LAB_0014c8ac;
}

