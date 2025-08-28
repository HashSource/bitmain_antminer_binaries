
int * add_pool(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char local_820 [4];
  char acStack_81c [4];
  char acStack_818 [4];
  char acStack_814 [4];
  char local_810 [4];
  char acStack_80c [4];
  char acStack_808 [4];
  char acStack_804 [4];
  char local_800 [4];
  char acStack_7fc [2016];
  
  piVar1 = (int *)_cgcalloc(0x738,1,"cgminer.c","add_pool",0x2e4);
  uVar4 = pools;
  iVar2 = total_pools;
  iVar3 = total_pools + 2;
  piVar1[1] = total_pools;
  *piVar1 = iVar2;
  *(undefined1 *)(piVar1 + 0xa1) = 0;
  pools = _cgrealloc(uVar4,iVar3 * 4,"cgminer.c","add_pool",0x2f0);
  iVar2 = total_pools * 4;
  total_pools = total_pools + 1;
  *(int **)(pools + iVar2) = piVar1;
  iVar2 = pthread_mutex_init((pthread_mutex_t *)(piVar1 + 0x2f),(pthread_mutexattr_t *)0x0);
  if (iVar2 == 0) {
    iVar2 = pthread_cond_init((pthread_cond_t *)(piVar1 + 0x4a),(pthread_condattr_t *)0x0);
    if (iVar2 != 0) {
      local_820[0] = 'F';
      local_820[1] = 'a';
      local_820[2] = 'i';
      local_820[3] = 'l';
      acStack_81c[0] = 'e';
      acStack_81c[1] = 'd';
      acStack_81c[2] = ' ';
      acStack_81c[3] = 't';
      acStack_818[0] = 'o';
      acStack_818[1] = ' ';
      acStack_818[2] = 'p';
      acStack_818[3] = 't';
      acStack_814[0] = 'h';
      acStack_814[1] = 'r';
      acStack_814[2] = 'e';
      acStack_814[3] = 'a';
      local_810[0] = 'd';
      local_810[1] = '_';
      local_810[2] = 'c';
      local_810[3] = 'o';
      acStack_80c[0] = 'n';
      acStack_80c[1] = 'd';
      acStack_80c[2] = '_';
      acStack_80c[3] = 'i';
      acStack_808[0] = 'n';
      acStack_808[1] = 'i';
      acStack_808[2] = 't';
      acStack_808[3] = ' ';
      acStack_804[0] = 'i';
      acStack_804[1] = 'n';
      acStack_804[2] = ' ';
      acStack_804[3] = 'a';
      local_800[0] = 'd';
      local_800[1] = 'd';
      local_800[2] = '_';
      local_800[3] = 'p';
      acStack_7fc[0] = 'o';
      acStack_7fc[1] = 'o';
      acStack_7fc[2] = 'l';
      acStack_7fc[3] = '\0';
      goto LAB_00020cc0;
    }
    iVar2 = pthread_mutex_init((pthread_mutex_t *)(piVar1 + 0x35),(pthread_mutexattr_t *)0x0);
    if (iVar2 == 0) {
      iVar2 = pthread_rwlock_init((pthread_rwlock_t *)(piVar1 + 0x3b),(pthread_rwlockattr_t *)0x0);
      if (iVar2 != 0) {
        piVar1 = __errno_location();
        iVar2 = *piVar1;
        uVar4 = 0x2fa;
LAB_00020d10:
        snprintf(local_820,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",iVar2,
                 "cgminer.c","add_pool",uVar4);
        goto LAB_00020cc0;
      }
      iVar2 = pthread_mutex_init((pthread_mutex_t *)(piVar1 + 0xb0),(pthread_mutexattr_t *)0x0);
      if (iVar2 == 0) {
        iVar2 = pthread_mutex_init((pthread_mutex_t *)(piVar1 + 0xb9),(pthread_mutexattr_t *)0x0);
        if (iVar2 == 0) {
          iVar2 = pthread_rwlock_init((pthread_rwlock_t *)(piVar1 + 0xbf),
                                      (pthread_rwlockattr_t *)0x0);
          if (iVar2 == 0) {
            piVar1[0x22] = -1;
            piVar1[0x2e] = 0;
            piVar1[0x28] = (int)"{\"method\": \"getwork\", \"params\": [], \"id\":0}\n";
            piVar1[0x56] = (int)(piVar1 + 0x56);
            piVar1[0x57] = (int)(piVar1 + 0x56);
            piVar1[0xe] = 1;
            adjust_quota_gcd();
            *(undefined1 *)(piVar1 + 0x91) = 0;
            return piVar1;
          }
          piVar1 = __errno_location();
          uVar4 = 0x2fc;
          iVar2 = *piVar1;
          goto LAB_00020d10;
        }
        piVar1 = __errno_location();
        iVar2 = *piVar1;
        uVar4 = 0x2fc;
      }
      else {
        piVar1 = __errno_location();
        uVar4 = 0x2fb;
        iVar2 = *piVar1;
      }
    }
    else {
      piVar1 = __errno_location();
      uVar4 = 0x2fa;
      iVar2 = *piVar1;
    }
  }
  else {
    piVar1 = __errno_location();
    uVar4 = 0x2f3;
    iVar2 = *piVar1;
  }
  snprintf(local_820,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",iVar2,"cgminer.c",
           "add_pool",uVar4);
LAB_00020cc0:
  _applog(3,local_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

