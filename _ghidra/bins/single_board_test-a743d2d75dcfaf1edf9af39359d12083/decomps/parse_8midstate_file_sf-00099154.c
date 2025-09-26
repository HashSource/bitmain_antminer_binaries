
int parse_8midstate_file_sf(FILE **fp,int asic,int core,int count)

{
  size_t sVar1;
  uint32_t uVar2;
  pattern_work *ppVar3;
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
    sVar1 = fread(&work_in_file,1,0xc,(FILE *)*fp);
    if (sVar1 != 0xc) break;
    ppVar3 = g_works[asic] + count * core + subid;
    ppVar3->id = (uint16_t)subid;
    uVar2 = ntohl(work_in_file.nonce);
    (ppVar3->pattern).nonce = uVar2;
    memset((ppVar3->pattern).midstate,0,0x20);
    *(undefined4 *)((ppVar3->pattern).midstate + 0x18) = work_in_file.midstate._0_4_;
    *(undefined4 *)((ppVar3->pattern).midstate + 0x1c) = work_in_file.midstate._4_4_;
    memset((ppVar3->pattern).data,0,0xc);
    subid = subid + 1;
  }
  builtin_strncpy(tmp42,"Load core pattern failed",0x18);
  tmp42[0x18] = '!';
  tmp42[0x19] = '\n';
  tmp42[0x1a] = '\0';
  puts(tmp42);
  return subid;
}

