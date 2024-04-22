
void gen_stratum_work(pool *pool,work *work)

{
  char *pcVar1;
  char *__ptr;
  time_t tVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 in_stack_fffff758;
  char *pcVar6;
  undefined4 in_stack_fffff75c;
  undefined4 uVar7;
  work *work_local;
  pool *pool_local;
  char tmp42 [2048];
  uint64_t nonce2le;
  uchar merkle_sha [64];
  uchar merkle_root [32];
  char *merkle_hash;
  char *header;
  uint32_t *swap32;
  uint32_t *data32;
  int i;
  
  _cg_wlock(&pool->data_lock,"cgminer.c","gen_stratum_work",0x2081);
  nonce2le = __uint64_identity(CONCAT44(in_stack_fffff75c,in_stack_fffff758));
  _cg_memcpy(pool->coinbase + pool->nonce2_offset,&nonce2le,pool->n2size,"cgminer.c",
             "gen_stratum_work",0x2086);
  uVar3 = *(uint *)&pool->nonce2;
  iVar4 = *(int *)((int)&pool->nonce2 + 4);
  *(uint *)&pool->nonce2 = uVar3 + 1;
  *(uint *)((int)&pool->nonce2 + 4) = iVar4 + (uint)(0xfffffffe < uVar3);
  *(uint *)&work->nonce2 = uVar3;
  *(int *)((int)&work->nonce2 + 4) = iVar4;
  work->nonce2_len = pool->n2size;
  _cg_dwlock(&pool->data_lock,"cgminer.c","gen_stratum_work",0x208c);
  gen_hash(pool->coinbase,merkle_root,pool->coinbase_len);
  _cg_memcpy(merkle_sha,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x2090);
  for (i = 0; i < pool->merkles; i = i + 1) {
    _cg_memcpy(merkle_sha + 0x20,(pool->swork).merkle_bin[i],0x20,"cgminer.c","gen_stratum_work",
               0x2094);
    gen_hash(merkle_sha,merkle_root,0x40);
    _cg_memcpy(merkle_sha,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x2096);
  }
  flip32(merkle_root,merkle_sha);
  _cg_memcpy(work,pool->header_bin,0x70,"cgminer.c","gen_stratum_work",0x209f);
  uVar7 = 0x20a0;
  pcVar6 = "gen_stratum_work";
  _cg_memcpy(work->data + 0x24,merkle_root,0x20,"cgminer.c","gen_stratum_work",0x20a0);
  uVar5 = *(undefined4 *)((int)&pool->sdiff + 4);
  *(undefined4 *)&work->sdiff = *(undefined4 *)&pool->sdiff;
  *(undefined4 *)((int)&work->sdiff + 4) = uVar5;
  pcVar1 = strdup((pool->swork).job_id);
  work->job_id = pcVar1;
  pcVar1 = strdup(pool->nonce1);
  work->nonce1 = pcVar1;
  pcVar1 = strdup(pool->ntime);
  work->ntime = pcVar1;
  _cg_runlock(&pool->data_lock,"cgminer.c","gen_stratum_work",0x20ab);
  if (opt_debug != false) {
    pcVar1 = bin2hex(work->data,0x70);
    __ptr = bin2hex(merkle_root,0x20);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated stratum merkle %s",__ptr);
      _applog(7,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"Generated stratum header %s",pcVar1);
      _applog(7,tmp42,false);
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      pcVar6 = *(char **)&work->nonce2;
      uVar7 = *(undefined4 *)((int)&work->nonce2 + 4);
      snprintf(tmp42,0x800,"Work job_id %s nonce2 %llu ntime %s",work->job_id,pcVar6,uVar7,
               work->ntime);
      _applog(7,tmp42,false);
    }
    free(pcVar1);
    free(__ptr);
  }
  calc_midstate(work);
  set_target(work->target,(double)CONCAT44(uVar7,pcVar6));
  local_work = local_work + 1;
  tVar2 = time((time_t *)0x0);
  if (5 < tVar2 - local_work_lasttime) {
    local_work_lasttime = time((time_t *)0x0);
    local_work_last = local_work;
  }
  work->pool = pool;
  work->stratum = true;
  work->nonce = 0;
  work->longpoll = false;
  work->getwork_mode = 'S';
  work->work_block = work_block;
  work->drv_rolllimit = 0x3c;
  calc_diff(work,(double)CONCAT44(uVar7,pcVar6));
  cgtime(&work->tv_staged);
  return;
}

