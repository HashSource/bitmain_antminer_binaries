
/* WARNING: Unknown calling convention */

void copy_pool_stratum(pool *pool_stratum,pool *pool)

{
  int iVar1;
  uchar *puVar2;
  uchar **ppuVar3;
  int *piVar4;
  char *in_r2;
  uint uVar5;
  char *func;
  undefined4 *puVar6;
  char *pcVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  pthread_rwlock_t *__rwlock;
  size_t __nmemb;
  size_t coinbase_len;
  uint uVar10;
  int merkles;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  double dVar14;
  char tmp42 [2048];
  
  pcVar7 = (pool->swork).job_id;
  iVar11 = pool->merkles;
  __nmemb = pool->coinbase_len;
  if (pcVar7 != (char *)0x0) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool_stratum->data_lock);
    if (iVar1 != 0) {
      _mutex_lock((pthread_mutex_t *)DAT_0002aee4,(char *)0x2cc2,in_r2,(int)pcVar7);
    }
    __rwlock = &(pool_stratum->data_lock).rwlock;
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
    if (iVar1 != 0) {
      piVar4 = __errno_location();
      snprintf(tmp42,0x800,DAT_0002aee8,*piVar4,DAT_0002aee0,DAT_0002aee4,0x2cc2);
      _applog(3,tmp42,true);
      _quit(1);
    }
    free((pool_stratum->swork).job_id);
    free(pool_stratum->nonce1);
    free(pool_stratum->coinbase);
    if ((__nmemb & 3) != 0) {
      __nmemb = (__nmemb & 0xfffffffc) + 4;
    }
    puVar2 = (uchar *)calloc(__nmemb,1);
    pool_stratum->coinbase = puVar2;
    if (puVar2 == (uchar *)0x0) {
      tmp42._0_4_ = *DAT_0002aef0;
      tmp42._4_4_ = DAT_0002aef0[1];
      tmp42._8_4_ = DAT_0002aef0[2];
      tmp42._12_4_ = DAT_0002aef0[3];
      tmp42._16_4_ = DAT_0002aef0[4];
      tmp42._20_4_ = DAT_0002aef0[5];
      tmp42._24_4_ = DAT_0002aef0[6];
      tmp42._28_4_ = DAT_0002aef0[7];
      tmp42._32_4_ = DAT_0002aef0[8];
      tmp42._36_4_ = DAT_0002aef0[9];
      tmp42._40_4_ = DAT_0002aef0[10];
      tmp42[44] = (char)DAT_0002aef0[0xb];
      _applog(3,tmp42,true);
      _quit(1);
      puVar2 = pool_stratum->coinbase;
    }
    memcpy(puVar2,pool->coinbase,__nmemb);
    if (0 < pool_stratum->merkles) {
      iVar1 = 0;
      do {
        ppuVar3 = (pool_stratum->swork).merkle_bin + iVar1;
        iVar1 = iVar1 + 1;
        free(*ppuVar3);
      } while (iVar1 < pool_stratum->merkles);
    }
    if (iVar11 != 0) {
      ppuVar3 = (uchar **)realloc((pool_stratum->swork).merkle_bin,iVar11 * 4 + 1);
      (pool_stratum->swork).merkle_bin = ppuVar3;
      if (0 < iVar11) {
        iVar1 = 0;
        while( true ) {
          puVar2 = (uchar *)malloc(0x20);
          ppuVar3[iVar1] = puVar2;
          puVar8 = (undefined4 *)(pool_stratum->swork).merkle_bin[iVar1];
          if (puVar8 == (undefined4 *)0x0) {
            tmp42._0_4_ = *DAT_0002aeec;
            tmp42._4_4_ = DAT_0002aeec[1];
            tmp42._8_4_ = DAT_0002aeec[2];
            tmp42._12_4_ = DAT_0002aeec[3];
            tmp42._16_4_ = DAT_0002aeec[4];
            tmp42._20_4_ = DAT_0002aeec[5];
            tmp42._24_4_ = DAT_0002aeec[6];
            tmp42._28_4_ = DAT_0002aeec[7];
            tmp42._32_4_ = DAT_0002aeec[8];
            tmp42._36_4_ = DAT_0002aeec[9];
            tmp42._40_4_ = DAT_0002aeec[10];
            tmp42._44_2_ = (undefined2)DAT_0002aeec[0xb];
            tmp42[46] = (char)((uint)DAT_0002aeec[0xb] >> 0x10);
            _applog(3,tmp42,true);
            _quit(1);
            puVar8 = (undefined4 *)(pool_stratum->swork).merkle_bin[iVar1];
          }
          puVar6 = (undefined4 *)(pool->swork).merkle_bin[iVar1];
          uVar13 = puVar6[1];
          uVar9 = puVar6[2];
          uVar12 = puVar6[3];
          *puVar8 = *puVar6;
          puVar8[1] = uVar13;
          puVar8[2] = uVar9;
          puVar8[3] = uVar12;
          uVar13 = puVar6[5];
          uVar9 = puVar6[6];
          uVar12 = puVar6[7];
          puVar8[4] = puVar6[4];
          puVar8[5] = uVar13;
          puVar8[6] = uVar9;
          puVar8[7] = uVar12;
          if (iVar1 + 1 == iVar11) break;
          ppuVar3 = (pool_stratum->swork).merkle_bin;
          iVar1 = iVar1 + 1;
        }
      }
    }
    iVar11 = pool->nonce2_offset;
    uVar5 = pool->n2size;
    dVar14 = pool->sdiff;
    uVar10 = pool->coinbase_len;
    pool_stratum->pool_no = pool->pool_no;
    iVar1 = pool->merkles;
    pool_stratum->sdiff = dVar14;
    pool_stratum->nonce2_offset = iVar11;
    pool_stratum->n2size = uVar5;
    pool_stratum->merkles = iVar1;
    pool_stratum->coinbase_len = uVar10;
    pcVar7 = (char *)__strdup((pool->swork).job_id);
    (pool_stratum->swork).job_id = pcVar7;
    pcVar7 = (char *)__strdup(pool->nonce1);
    uVar12 = *(undefined4 *)pool->ntime;
    iVar1 = *(int *)(pool->ntime + 8);
    uVar9 = *(undefined4 *)(pool->ntime + 4);
    func = (char *)0x80;
    pool_stratum->nonce1 = pcVar7;
    *(undefined4 *)pool_stratum->ntime = uVar12;
    *(undefined4 *)(pool_stratum->ntime + 4) = uVar9;
    *(int *)(pool_stratum->ntime + 8) = iVar1;
    memcpy(pool_stratum->header_bin,pool->header_bin,0x80);
    iVar11 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
    if (iVar11 != 0) {
      _rw_unlock(DAT_0002aee4,(char *)0x2ce8,func,iVar1);
    }
    iVar11 = pthread_mutex_unlock((pthread_mutex_t *)&pool_stratum->data_lock);
    if (iVar11 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)DAT_0002aee4,(char *)0x2ce8,func,iVar1);
    }
    (**DAT_0002aedc)();
  }
  return;
}

