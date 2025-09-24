
int parse_bin_file_16midstate_sf(FILE **fp,int asic,int core,int count)

{
  size_t sVar1;
  uint32_t uVar2;
  work_new *pwVar3;
  int iVar4;
  int count_local;
  int core_local;
  int asic_local;
  FILE **fp_local;
  char time_stamp [48];
  char tmp1 [256];
  pattern_struct_in_file work_in_file;
  test_pattern_new *new_pattern;
  work_new *new_work;
  int ret;
  uint32_t subid;
  
  subid = 0;
  while( true ) {
    if ((uint)count <= subid) {
      return subid;
    }
    sVar1 = fread(&work_in_file,1,0xc,(FILE *)*fp);
    if (sVar1 != 0xc) break;
    pwVar3 = pattern_info_new.works[asic];
    iVar4 = subid + count * core;
    uVar2 = ntohl(work_in_file.nonce);
    pwVar3[iVar4].pattern.nonce = uVar2;
    *(undefined4 *)pwVar3[iVar4].pattern.midstate = work_in_file.midstate._0_4_;
    *(undefined4 *)(pwVar3[iVar4].pattern.midstate + 4) = work_in_file.midstate._4_4_;
    subid = subid + 1;
  }
  print_time_stamp(time_stamp,0x30);
  printf("%s ",time_stamp);
  printf("%s : Load core pattern failed!\n\n","parse_bin_file_16midstate_sf");
  builtin_strncpy(tmp1,"Load core pattern failed",0x18);
  tmp1[0x18] = '!';
  tmp1[0x19] = '\n';
  tmp1[0x1a] = '\0';
  log_to_file(tmp1,time_stamp);
  return subid;
}

