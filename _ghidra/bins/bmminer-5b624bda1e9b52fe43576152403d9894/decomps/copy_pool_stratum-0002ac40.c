
/* WARNING: Unknown calling convention */

void copy_pool_stratum(pool *pool_stratum,pool *pool)

{
  int iVar1;
  uchar *puVar2;
  char *pcVar3;
  uchar **ppuVar4;
  int *piVar5;
  char *func;
  uint uVar6;
  char *func_00;
  char *func_01;
  uchar *puVar7;
  int line;
  undefined4 uVar8;
  int line_00;
  int line_01;
  undefined4 uVar9;
  pthread_rwlock_t *__rwlock;
  size_t __nmemb;
  uint uVar10;
  int merkles;
  int iVar11;
  undefined4 uVar12;
  double dVar13;
  char tmp42 [2048];
  
  iVar11 = pool->merkles;
  __nmemb = pool->coinbase_len;
  if ((pool->swork).job_id != (char *)0x0) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&pool_stratum->data_lock);
    if (iVar1 != 0) {
      _mutex_lock((pthread_mutex_t *)"copy_pool_stratum",(char *)0x2cc2,func,line);
    }
    __rwlock = &(pool_stratum->data_lock).rwlock;
    iVar1 = pthread_rwlock_wrlock((pthread_rwlock_t *)__rwlock);
    if (iVar1 != 0) {
      piVar5 = __errno_location();
      snprintf(tmp42,0x800,"WTF WRLOCK ERROR ON LOCK! errno=%d in %s %s():%d",*piVar5,
               "driver-btm-c5.c","copy_pool_stratum",0x2cc2);
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
      builtin_strncpy(tmp42,"Failed to calloc pool_stratum coinbase in c5",0x2c);
      tmp42._44_2_ = tmp42._44_2_ & 0xff00;
      _applog(3,tmp42,true);
      _quit(1);
      puVar2 = pool_stratum->coinbase;
    }
    memcpy(puVar2,pool->coinbase,__nmemb);
    if (0 < pool_stratum->merkles) {
      iVar1 = 0;
      do {
        ppuVar4 = (pool_stratum->swork).merkle_bin + iVar1;
        iVar1 = iVar1 + 1;
        free(*ppuVar4);
      } while (iVar1 < pool_stratum->merkles);
    }
    if (iVar11 != 0) {
      ppuVar4 = (uchar **)realloc((pool_stratum->swork).merkle_bin,iVar11 * 4 + 1);
      (pool_stratum->swork).merkle_bin = ppuVar4;
      if (0 < iVar11) {
        iVar1 = 0;
        while( true ) {
          puVar2 = (uchar *)malloc(0x20);
          ppuVar4[iVar1] = puVar2;
          puVar2 = (pool_stratum->swork).merkle_bin[iVar1];
          if (puVar2 == (uchar *)0x0) {
            builtin_strncpy(tmp42,"Failed to malloc pool_stratum swork merkle_b",0x2c);
            tmp42[0x2c] = 'i';
            tmp42[0x2d] = 'n';
            tmp42[0x2e] = '\0';
            _applog(3,tmp42,true);
            _quit(1);
            puVar2 = (pool_stratum->swork).merkle_bin[iVar1];
          }
          puVar7 = (pool->swork).merkle_bin[iVar1];
          uVar12 = *(undefined4 *)(puVar7 + 4);
          uVar8 = *(undefined4 *)(puVar7 + 8);
          uVar9 = *(undefined4 *)(puVar7 + 0xc);
          *(undefined4 *)puVar2 = *(undefined4 *)puVar7;
          *(undefined4 *)(puVar2 + 4) = uVar12;
          *(undefined4 *)(puVar2 + 8) = uVar8;
          *(undefined4 *)(puVar2 + 0xc) = uVar9;
          uVar12 = *(undefined4 *)(puVar7 + 0x14);
          uVar8 = *(undefined4 *)(puVar7 + 0x18);
          uVar9 = *(undefined4 *)(puVar7 + 0x1c);
          *(undefined4 *)(puVar2 + 0x10) = *(undefined4 *)(puVar7 + 0x10);
          *(undefined4 *)(puVar2 + 0x14) = uVar12;
          *(undefined4 *)(puVar2 + 0x18) = uVar8;
          *(undefined4 *)(puVar2 + 0x1c) = uVar9;
          if (iVar1 + 1 == iVar11) break;
          ppuVar4 = (pool_stratum->swork).merkle_bin;
          iVar1 = iVar1 + 1;
        }
      }
    }
    iVar11 = pool->nonce2_offset;
    uVar6 = pool->n2size;
    dVar13 = pool->sdiff;
    uVar10 = pool->coinbase_len;
    pool_stratum->pool_no = pool->pool_no;
    iVar1 = pool->merkles;
    pool_stratum->sdiff = dVar13;
    pool_stratum->nonce2_offset = iVar11;
    pool_stratum->n2size = uVar6;
    pool_stratum->merkles = iVar1;
    pool_stratum->coinbase_len = uVar10;
    pcVar3 = (char *)__strdup((pool->swork).job_id);
    (pool_stratum->swork).job_id = pcVar3;
    pcVar3 = (char *)__strdup(pool->nonce1);
    uVar12 = *(undefined4 *)pool->ntime;
    uVar8 = *(undefined4 *)(pool->ntime + 8);
    uVar9 = *(undefined4 *)(pool->ntime + 4);
    pool_stratum->nonce1 = pcVar3;
    *(undefined4 *)pool_stratum->ntime = uVar12;
    *(undefined4 *)(pool_stratum->ntime + 4) = uVar9;
    *(undefined4 *)(pool_stratum->ntime + 8) = uVar8;
    memcpy(pool_stratum->header_bin,pool->header_bin,0x80);
    iVar11 = pthread_rwlock_unlock((pthread_rwlock_t *)__rwlock);
    if (iVar11 != 0) {
      _rw_unlock((pthread_rwlock_t *)"copy_pool_stratum",(char *)0x2ce8,func_00,line_00);
    }
    iVar11 = pthread_mutex_unlock((pthread_mutex_t *)&pool_stratum->data_lock);
    if (iVar11 != 0) {
      _mutex_unlock_noyield((pthread_mutex_t *)"copy_pool_stratum",(char *)0x2ce8,func_01,line_01);
    }
    (*selective_yield)();
  }
  return;
}

