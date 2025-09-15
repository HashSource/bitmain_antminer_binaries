
void _copy_work(work *work,work *base_work,int noffset)

{
  char *pcVar1;
  uint uVar2;
  uint __bsx;
  int noffset_local;
  work *base_work_local;
  work *work_local;
  uint ntime_1;
  uint *work_ntime_1;
  uint ntime;
  uint *work_ntime;
  uint id;
  
  uVar2 = work->id;
  clean_work(work);
  _cg_memcpy(work,base_work,0x1c0,"cgminer.c","_copy_work",0x12fa);
  work->id = uVar2;
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
      uVar2 = *(uint *)(work->data + 0x44);
      uVar2 = (uVar2 << 0x18 | uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8) +
              noffset;
      *(uint *)(work->data + 0x44) =
           uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 * 0x1000000;
    }
  }
  else if (noffset == 0) {
    pcVar1 = strdup(base_work->ntime);
    work->ntime = pcVar1;
  }
  else {
    uVar2 = *(uint *)(work->data + 0x44);
    uVar2 = (uVar2 << 0x18 | uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8) +
            noffset;
    *(uint *)(work->data + 0x44) =
         uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 * 0x1000000;
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

