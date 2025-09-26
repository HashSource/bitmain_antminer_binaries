
int parse_8midstate_file(FILE **fp,int asic,int core,int count)

{
  size_t sVar1;
  pattern_work *ppVar2;
  int count_local;
  int core_local;
  int asic_local;
  FILE **fp_local;
  char tmp42 [256];
  pattern_struct_in_file work_in_file;
  pattern_bin *new_pattern;
  pattern_work *new_work;
  int ret;
  uint32_t subid;
  
  subid = 0;
  while( true ) {
    if ((uint)count <= subid) {
      return subid;
    }
    sVar1 = fread(&work_in_file,1,0x30,(FILE *)*fp);
    if (sVar1 != 0x30) break;
    ppVar2 = g_works[asic] + count * core + subid;
    ppVar2->id = (uint16_t)subid;
    (ppVar2->pattern).nonce = work_in_file.nonce;
    *(undefined4 *)(ppVar2->pattern).midstate = work_in_file.midstate._0_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 4) = work_in_file.midstate._4_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 8) = work_in_file.midstate._8_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 0xc) = work_in_file.midstate._12_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 0x10) = work_in_file.midstate._16_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 0x14) = work_in_file.midstate._20_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 0x18) = work_in_file.midstate._24_4_;
    *(undefined4 *)((ppVar2->pattern).midstate + 0x1c) = work_in_file.midstate._28_4_;
    *(undefined4 *)(ppVar2->pattern).data = work_in_file.data._0_4_;
    *(undefined4 *)((ppVar2->pattern).data + 4) = work_in_file.data._4_4_;
    *(undefined4 *)((ppVar2->pattern).data + 8) = work_in_file.data._8_4_;
    subid = subid + 1;
  }
  builtin_strncpy(tmp42,"Load core pattern failed",0x18);
  tmp42[0x18] = '!';
  tmp42[0x19] = '\n';
  tmp42[0x1a] = '\0';
  puts(tmp42);
  return subid;
}

