
void copy_pool_stratum(pool *pool_stratum,pool *pool)

{
  uint16_t uVar1;
  uint16_t uVar2;
  size_t sVar3;
  uchar *puVar4;
  uchar **ppuVar5;
  char *pcVar6;
  int iVar7;
  size_t __n;
  undefined4 uVar8;
  pool *pool_local;
  pool *pool_stratum_local;
  ushort crc;
  int job_id_len;
  size_t coinbase_len;
  int merkles;
  int i;
  
  iVar7 = pool->merkles;
  __n = pool->coinbase_len;
  if ((pool->swork).job_id != (char *)0x0) {
    if ((pool_stratum->swork).job_id != (char *)0x0) {
      sVar3 = strlen((pool->swork).job_id);
      uVar1 = CRC16((uint8_t *)(pool->swork).job_id,(uint16_t)sVar3);
      sVar3 = strlen((pool_stratum->swork).job_id);
      uVar2 = CRC16((uint8_t *)(pool_stratum->swork).job_id,(uint16_t)sVar3);
      if (uVar1 == uVar2) {
        return;
      }
    }
    _cg_wlock(&pool_stratum->data_lock,"driver-btm-soc.c","copy_pool_stratum",0x1cb3);
    free((pool_stratum->swork).job_id);
    free(pool_stratum->nonce1);
    free(pool_stratum->coinbase);
    puVar4 = (uchar *)_cgcalloc(__n,1,"driver-btm-soc.c","copy_pool_stratum",0x1cb8);
    pool_stratum->coinbase = puVar4;
    memcpy(pool_stratum->coinbase,pool->coinbase,__n);
    for (i = 0; i < pool_stratum->merkles; i = i + 1) {
      free((pool_stratum->swork).merkle_bin[i]);
    }
    if (iVar7 != 0) {
      ppuVar5 = (uchar **)
                _cgrealloc((pool_stratum->swork).merkle_bin,iVar7 * 4 + 1,"driver-btm-soc.c",
                           "copy_pool_stratum",0x1cc0);
      (pool_stratum->swork).merkle_bin = ppuVar5;
      for (i = 0; i < iVar7; i = i + 1) {
        ppuVar5 = (pool_stratum->swork).merkle_bin;
        puVar4 = (uchar *)_cgmalloc(0x20,"driver-btm-soc.c","copy_pool_stratum",0x1cc3);
        ppuVar5[i] = puVar4;
        memcpy((pool_stratum->swork).merkle_bin[i],(pool->swork).merkle_bin[i],0x20);
      }
    }
    pool_stratum->pool_no = pool->pool_no;
    uVar8 = *(undefined4 *)((int)&pool->sdiff + 4);
    *(undefined4 *)&pool_stratum->sdiff = *(undefined4 *)&pool->sdiff;
    *(undefined4 *)((int)&pool_stratum->sdiff + 4) = uVar8;
    pool_stratum->coinbase_len = pool->coinbase_len;
    pool_stratum->nonce2_offset = pool->nonce2_offset;
    pool_stratum->n2size = pool->n2size;
    pool_stratum->merkles = pool->merkles;
    pcVar6 = strdup((pool->swork).job_id);
    (pool_stratum->swork).job_id = pcVar6;
    pcVar6 = strdup(pool->nonce1);
    pool_stratum->nonce1 = pcVar6;
    memcpy(pool_stratum->ntime,pool->ntime,0xc);
    memcpy(pool_stratum->header_bin,pool->header_bin,0x80);
    _cg_wunlock(&pool_stratum->data_lock,"driver-btm-soc.c","copy_pool_stratum",0x1cd3);
  }
  return;
}

