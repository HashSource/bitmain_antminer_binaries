
int * add_pool(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_820;
  undefined4 uStack_81c;
  undefined4 uStack_818;
  undefined4 uStack_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  
  uVar1 = DAT_00020d48;
  piVar2 = (int *)_cgcalloc(0x738,1,"cgminer.c",DAT_00020d48,0x2e4);
  uVar5 = pools;
  iVar3 = total_pools;
  iVar4 = total_pools + 2;
  piVar2[1] = total_pools;
  *piVar2 = iVar3;
  *(undefined *)(piVar2 + 0xa1) = 0;
  pools = _cgrealloc(uVar5,iVar4 * 4,"cgminer.c",uVar1,0x2f0);
  iVar3 = total_pools * 4;
  total_pools = total_pools + 1;
  *(int **)(pools + iVar3) = piVar2;
  iVar3 = pthread_mutex_init((pthread_mutex_t *)(piVar2 + 0x2f),(pthread_mutexattr_t *)0x0);
  if (iVar3 == 0) {
    iVar3 = pthread_cond_init((pthread_cond_t *)(piVar2 + 0x4a),(pthread_condattr_t *)0x0);
    if (iVar3 != 0) {
      local_820._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[0];
      local_820._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[1];
      local_820._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[2];
      local_820._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[3];
      uStack_81c._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[4];
      uStack_81c._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[5];
      uStack_81c._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[6];
      uStack_81c._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[7];
      uStack_818._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[8];
      uStack_818._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[9];
      uStack_818._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[10];
      uStack_818._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[11];
      uStack_814._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[12];
      uStack_814._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[13];
      uStack_814._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[14];
      uStack_814._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[15];
      local_810._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[16];
      local_810._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[17];
      local_810._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[18];
      local_810._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[19];
      uStack_80c._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[20];
      uStack_80c._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[21];
      uStack_80c._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[22];
      uStack_80c._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[23];
      uStack_808._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[24];
      uStack_808._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[25];
      uStack_808._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[26];
      uStack_808._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[27];
      uStack_804._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[28];
      uStack_804._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[29];
      uStack_804._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[30];
      uStack_804._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[31];
      local_800._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[32];
      local_800._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[33];
      local_800._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[34];
      local_800._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[35];
      uStack_7fc._0_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[36];
      uStack_7fc._1_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[37];
      uStack_7fc._2_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[38];
      uStack_7fc._3_1_ = s_Failed_to_pthread_cond_init_in_a_0005d3cc[39];
      goto LAB_00020cc0;
    }
    iVar3 = pthread_mutex_init((pthread_mutex_t *)(piVar2 + 0x35),(pthread_mutexattr_t *)0x0);
    if (iVar3 == 0) {
      iVar3 = pthread_rwlock_init((pthread_rwlock_t *)(piVar2 + 0x3b),(pthread_rwlockattr_t *)0x0);
      if (iVar3 != 0) {
        piVar2 = __errno_location();
        iVar3 = *piVar2;
        uVar5 = 0x2fa;
LAB_00020d10:
        snprintf((char *)&local_820,0x800,"Failed to pthread_rwlock_init errno=%d in %s %s():%d",
                 iVar3,"cgminer.c",uVar1,uVar5);
        goto LAB_00020cc0;
      }
      iVar3 = pthread_mutex_init((pthread_mutex_t *)(piVar2 + 0xb0),(pthread_mutexattr_t *)0x0);
      if (iVar3 == 0) {
        iVar3 = pthread_mutex_init((pthread_mutex_t *)(piVar2 + 0xb9),(pthread_mutexattr_t *)0x0);
        if (iVar3 == 0) {
          iVar3 = pthread_rwlock_init((pthread_rwlock_t *)(piVar2 + 0xbf),
                                      (pthread_rwlockattr_t *)0x0);
          if (iVar3 == 0) {
            piVar2[0x22] = -1;
            piVar2[0x2e] = 0;
            piVar2[0x28] = (int)"{\"method\": \"getwork\", \"params\": [], \"id\":0}\n";
            piVar2[0x56] = (int)(piVar2 + 0x56);
            piVar2[0x57] = (int)(piVar2 + 0x56);
            piVar2[0xe] = 1;
            adjust_quota_gcd();
            *(undefined *)(piVar2 + 0x91) = 0;
            return piVar2;
          }
          piVar2 = __errno_location();
          uVar5 = 0x2fc;
          iVar3 = *piVar2;
          goto LAB_00020d10;
        }
        piVar2 = __errno_location();
        iVar3 = *piVar2;
        uVar5 = 0x2fc;
      }
      else {
        piVar2 = __errno_location();
        uVar5 = 0x2fb;
        iVar3 = *piVar2;
      }
    }
    else {
      piVar2 = __errno_location();
      uVar5 = 0x2fa;
      iVar3 = *piVar2;
    }
  }
  else {
    piVar2 = __errno_location();
    uVar5 = 0x2f3;
    iVar3 = *piVar2;
  }
  snprintf((char *)&local_820,0x800,"Failed to pthread_mutex_init errno=%d in %s %s():%d",iVar3,
           "cgminer.c",uVar1,uVar5);
LAB_00020cc0:
  _applog(3,&local_820,1);
                    /* WARNING: Subroutine does not return */
  __quit(1);
}

