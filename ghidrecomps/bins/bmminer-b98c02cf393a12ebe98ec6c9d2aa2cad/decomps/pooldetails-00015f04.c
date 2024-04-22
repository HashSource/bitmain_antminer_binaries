
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 pooldetails(char *param_1,void **param_2,void **param_3,void **param_4)

{
  size_t sVar1;
  void *__ptr;
  char *local_824 [2];
  void *local_81c;
  undefined4 local_818;
  undefined4 uStack_814;
  undefined4 uStack_810;
  undefined4 uStack_80c;
  undefined4 local_808;
  undefined4 uStack_804;
  undefined4 uStack_800;
  undefined4 uStack_7fc;
  undefined local_7f8;
  
  local_824[0] = param_1;
  sVar1 = strlen(param_1);
  __ptr = malloc(sVar1 + 1);
  local_81c = __ptr;
  if (__ptr == (void *)0x0) {
    local_818._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[0];
    local_818._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[1];
    local_818._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[2];
    local_818._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[3];
    uStack_814._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[4];
    uStack_814._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[5];
    uStack_814._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[6];
    uStack_814._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[7];
    uStack_810._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[8];
    uStack_810._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[9];
    uStack_810._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[10];
    uStack_810._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[11];
    uStack_80c._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[12];
    uStack_80c._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[13];
    uStack_80c._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[14];
    uStack_80c._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[15];
    local_808._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[16];
    local_808._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[17];
    local_808._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[18];
    local_808._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[19];
    uStack_804._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[20];
    uStack_804._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[21];
    uStack_804._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[22];
    uStack_804._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[23];
    uStack_800._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[24];
    uStack_800._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[25];
    uStack_800._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[26];
    uStack_800._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[27];
    uStack_7fc._0_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[28];
    uStack_7fc._1_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[29];
    uStack_7fc._2_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[30];
    uStack_7fc._3_1_ = s_Failed_to_malloc_pooldetails_buf_00057e3c[31];
    local_7f8 = (undefined)ram0x00057e5c;
    _applog(3,&local_818,1);
    _quit(1);
  }
  *param_2 = local_81c;
  copyadvanceafter_constprop_20(local_824,&local_81c);
  if (*local_824[0] != '\0') {
    *param_3 = local_81c;
    copyadvanceafter_constprop_20(local_824,&local_81c);
    if (*local_824[0] != '\0') {
      *param_4 = local_81c;
      copyadvanceafter_constprop_20(local_824,&local_81c);
      return 1;
    }
  }
  free(__ptr);
  return 0;
}

