
int32_t sw_pt_init(char *pattern_file_path)

{
  pattern_work *ppVar1;
  int iVar2;
  int32_t iVar3;
  char *pattern_file_path_local;
  char tmp42 [256];
  FILE *fp;
  uint32_t work_count_target;
  uint32_t work_count_of_asic;
  uint32_t core;
  uint32_t asic;
  
  snprintf(tmp42,0x100,"open file %s\n",pattern_file_path);
  puts(tmp42);
  fp = (FILE *)fopen(pattern_file_path,"r");
  if (fp == (FILE *)0x0) {
    snprintf(tmp42,0x100,"Fail to open pattern file %s.\n",pattern_file_path);
    puts(tmp42);
    iVar3 = 7;
  }
  else {
    work_count_target = (g_rt.config)->asic_small_cores * (g_rt.config)->patter_num;
    for (asic = 0; asic < (uint)(g_rt.config)->asics; asic = asic + 1) {
      work_count_of_asic = 0;
      ppVar1 = (pattern_work *)calloc(0x38,work_count_target);
      g_rt.works[asic] = ppVar1;
      if (g_rt.works[asic] == (pattern_work *)0x0) {
        snprintf(tmp42,0x100,"malloc pattern buffer fail for asic %d",asic);
        puts(tmp42);
        fclose((FILE *)fp);
        return 8;
      }
      for (core = 0; core < (uint)(g_rt.config)->asic_small_cores; core = core + 1) {
        iVar2 = parse_8midstate_file(&fp,asic,core,(g_rt.config)->patter_num);
        work_count_of_asic = work_count_of_asic + iVar2;
      }
      if (work_count_of_asic < work_count_target) {
        snprintf(tmp42,0x100,"No enough work, asic = %d, work_count = %d, work_count_target = %d.\n"
                 ,asic,work_count_of_asic,work_count_target);
        puts(tmp42);
        fclose((FILE *)fp);
        return 9;
      }
    }
    builtin_strncpy(tmp42,"sw_pt_init o",0xc);
    tmp42[0xc] = 'k';
    tmp42[0xd] = '\0';
    puts(tmp42);
    fclose((FILE *)fp);
    iVar3 = 0;
  }
  return iVar3;
}

