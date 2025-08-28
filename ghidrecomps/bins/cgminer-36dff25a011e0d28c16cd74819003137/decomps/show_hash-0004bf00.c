
void show_hash(work *work,char *hashshow)

{
  uint uVar1;
  double dVar2;
  char *hashshow_local;
  work *work_local;
  char diffdisp [16];
  uchar rhash [32];
  uint64_t uintdiff;
  ulong h32;
  uint32_t *hash32;
  int ofs;
  
  swab256(rhash,work->hash);
  for (ofs = 0; (ofs < 0x1d && (rhash[ofs] == '\0')); ofs = ofs + 1) {
  }
  uVar1 = __bswap_32(*(uint *)(rhash + ofs));
  dVar2 = round(work->work_difficulty);
  __fixunsdfdi(SUB84(dVar2,0),(int)((ulonglong)dVar2 >> 0x20));
  suffix_string(work->share_diff,diffdisp,0x10,0);
  snprintf(hashshow,0x40,"%08lx Diff %s/%llu%s",uVar1,diffdisp);
  return;
}

