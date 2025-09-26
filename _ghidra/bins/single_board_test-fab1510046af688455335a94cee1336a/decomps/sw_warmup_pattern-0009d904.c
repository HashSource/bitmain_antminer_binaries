
int sw_warmup_pattern(char *pattern_file_path,int pattern_num,int asic_small_cores,int asics)

{
  pattern_work *ppVar1;
  int iVar2;
  int asics_local;
  int asic_small_cores_local;
  int pattern_num_local;
  char *pattern_file_path_local;
  char tmp42 [256];
  FILE *fp;
  uint32_t work_count_target;
  uint32_t work_count_of_asic;
  uint32_t core;
  uint32_t asic;
  int ret;
  
  ret = 0;
  snprintf(tmp42,0x100,"open file %s\n",pattern_file_path);
  puts(tmp42);
  fp = (FILE *)fopen(pattern_file_path,"r");
  if (fp == (FILE *)0x0) {
    snprintf(tmp42,0x100,"Fail to open pattern file %s.\n",pattern_file_path);
    puts(tmp42);
    ret = 7;
  }
  else {
    work_count_target = asic_small_cores * pattern_num;
    for (asic = 0; asic < (uint)asics; asic = asic + 1) {
      work_count_of_asic = 0;
      ppVar1 = (pattern_work *)calloc(0x38,work_count_target);
      g_works[asic] = ppVar1;
      if (g_works[asic] == (pattern_work *)0x0) {
        snprintf(tmp42,0x100,"malloc pattern buffer fail for asic %d",asic);
        puts(tmp42);
        fclose((FILE *)fp);
        return 8;
      }
      for (core = 0; core < 0x500; core = core + 1) {
        iVar2 = parse_8midstate_file_sf(&fp,asic,core,pattern_num);
        work_count_of_asic = work_count_of_asic + iVar2;
      }
      if (work_count_of_asic < work_count_target) {
        snprintf(tmp42,0x100,"No enough work, asic = %d, work_count = %d, work_count_target = %d.\n"
                 ,asic,work_count_of_asic,work_count_target);
        puts(tmp42);
        ret = 9;
        break;
      }
    }
    builtin_strncpy(tmp42,"sweep warmup pattern file ok",0x1c);
    tmp42[0x1c] = '\0';
    puts(tmp42);
    fclose((FILE *)fp);
  }
  return ret;
}

