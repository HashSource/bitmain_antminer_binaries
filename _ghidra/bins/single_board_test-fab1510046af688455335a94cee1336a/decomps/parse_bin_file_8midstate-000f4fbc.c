
int parse_bin_file_8midstate(FILE **fp,int asic,int core,int count)

{
  size_t sVar1;
  work *pwVar2;
  int count_local;
  int core_local;
  int asic_local;
  FILE **fp_local;
  char time_stamp [48];
  char tmp1 [2048];
  pattern_struct_in_file work_in_file;
  test_pattern *new_pattern;
  work *new_work;
  int ret;
  uint32_t subid;
  
  subid = 0;
  while( true ) {
    if ((uint)count <= subid) {
      return subid;
    }
    sVar1 = fread(&work_in_file,1,0x30,(FILE *)*fp);
    if (sVar1 != 0x30) break;
    pwVar2 = pattern_info.works[asic] + subid + count * core;
    pwVar2->id = (uint16_t)subid;
    (pwVar2->pattern).nonce = work_in_file.nonce;
    *(undefined4 *)(pwVar2->pattern).midstate = work_in_file.midstate._0_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 4) = work_in_file.midstate._4_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 8) = work_in_file.midstate._8_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 0xc) = work_in_file.midstate._12_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 0x10) = work_in_file.midstate._16_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 0x14) = work_in_file.midstate._20_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 0x18) = work_in_file.midstate._24_4_;
    *(undefined4 *)((pwVar2->pattern).midstate + 0x1c) = work_in_file.midstate._28_4_;
    *(undefined4 *)(pwVar2->pattern).data = work_in_file.data._0_4_;
    *(undefined4 *)((pwVar2->pattern).data + 4) = work_in_file.data._4_4_;
    *(undefined4 *)((pwVar2->pattern).data + 8) = work_in_file.data._8_4_;
    subid = subid + 1;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s: Load core pattern failed!\n\n","parse_bin_file_8midstate");
  builtin_strncpy(tmp1,"Load core pattern failed",0x18);
  tmp1[0x18] = '!';
  tmp1[0x19] = '\n';
  tmp1[0x1a] = '\0';
  log_to_file(tmp1,time_stamp);
  return subid;
}

