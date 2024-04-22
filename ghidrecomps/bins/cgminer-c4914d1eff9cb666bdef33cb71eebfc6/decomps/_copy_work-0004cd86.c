
void _copy_work(work *work,work *base_work,int noffset)

{
  char *pcVar1;
  uint uVar2;
  uint32_t uVar3;
  int noffset_local;
  work *base_work_local;
  work *work_local;
  uint32_t ntime;
  uint32_t *work_ntime;
  uint32_t ntime_1;
  uint32_t *work_ntime_1;
  uint32_t id;
  
  uVar3 = work->id;
  clean_work(work);
  _cg_memcpy(work,base_work,0x1c0,"cgminer.c","_copy_work",0x1344);
  work->id = uVar3;
  if (base_work->job_id != (char *)0x0) {
    pcVar1 = strdup(base_work->job_id);
    work->job_id = pcVar1;
  }
  if (base_work->nonce1 != (char *)0x0) {
    pcVar1 = strdup(base_work->nonce1);
    work->nonce1 = pcVar1;
  }
  if (base_work->ntime == (char *)0x0) {
    if (noffset != 0) {
      uVar2 = __bswap_32(*(uint *)(work->data + 0x44));
      uVar2 = __bswap_32(noffset + uVar2);
      *(uint *)(work->data + 0x44) = uVar2;
    }
  }
  else if (noffset == 0) {
    pcVar1 = strdup(base_work->ntime);
    work->ntime = pcVar1;
  }
  else {
    uVar2 = __bswap_32(*(uint *)(work->data + 0x44));
    uVar2 = __bswap_32(noffset + uVar2);
    *(uint *)(work->data + 0x44) = uVar2;
    pcVar1 = offset_ntime(base_work->ntime,noffset);
    work->ntime = pcVar1;
  }
  if (base_work->coinbase != (char *)0x0) {
    pcVar1 = strdup(base_work->coinbase);
    work->coinbase = pcVar1;
  }
  work->version = base_work->version;
  return;
}

