
/* WARNING: Unknown calling convention */

void _copy_work(work *work,work *base_work,int noffset)

{
  char *pcVar1;
  uint *be32;
  uint id;
  uint uVar2;
  uchar bin [4];
  
  uVar2 = work->id;
  clean_work(work);
  _cg_memcpy(work,base_work,0x1c0,DAT_0001ed4c,DAT_0001ed48,0x12f3);
  pcVar1 = base_work->job_id;
  work->id = uVar2;
  if (pcVar1 != (char *)0x0) {
    pcVar1 = (char *)__strdup();
    work->job_id = pcVar1;
  }
  if (base_work->nonce1 != (char *)0x0) {
    pcVar1 = (char *)__strdup();
    work->nonce1 = pcVar1;
  }
  pcVar1 = base_work->ntime;
  if (pcVar1 == (char *)0x0) {
    if (noffset != 0) {
      uVar2 = *(uint *)(work->data + 0x44);
      uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18) + noffset;
      *(uint *)(work->data + 0x44) =
           uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
           uVar2 >> 0x18;
    }
  }
  else if (noffset == 0) {
    pcVar1 = (char *)__strdup(pcVar1);
    work->ntime = pcVar1;
  }
  else {
    uVar2 = *(uint *)(work->data + 0x44);
    uVar2 = (uVar2 << 0x18 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
            uVar2 >> 0x18) + noffset;
    *(uint *)(work->data + 0x44) =
         uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
         uVar2 >> 0x18;
    hex2bin(bin,pcVar1,4);
    uVar2 = ((int)bin << 0x18 | ((uint)bin >> 8 & 0xff) << 0x10 | ((uint)bin >> 0x10 & 0xff) << 8 |
            (uint)bin >> 0x18) + noffset;
    bin = (uchar  [4])
          (uVar2 * 0x1000000 | (uVar2 >> 8 & 0xff) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
          uVar2 >> 0x18);
    pcVar1 = bin2hex(bin,4);
    work->ntime = pcVar1;
  }
  if (base_work->coinbase != (char *)0x0) {
    pcVar1 = (char *)__strdup();
    work->coinbase = pcVar1;
  }
  work->version = base_work->version;
  return;
}

