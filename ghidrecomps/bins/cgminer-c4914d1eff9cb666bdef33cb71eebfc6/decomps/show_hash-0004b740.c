
void show_hash(work *work,char *hashshow)

{
  uint uVar1;
  undefined4 in_stack_ffffff88;
  uint in_stack_ffffff8c;
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
  round((double)CONCAT44(in_stack_ffffff8c,in_stack_ffffff88));
  __fixunsdfdi((DFtype)CONCAT44(in_stack_ffffff8c,in_stack_ffffff88));
  suffix_string((ulonglong)in_stack_ffffff8c << 0x20,*(char **)&work->share_diff,
                *(size_t *)((int)&work->share_diff + 4),(int)diffdisp);
  snprintf(hashshow,0x40,"%08lx Diff %s/%llu%s",uVar1,diffdisp);
  return;
}

