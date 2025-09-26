
/* WARNING: Unknown calling convention */

int check_unbalance(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [2048];
  int32_t is_unbalance;
  
  if ((g_rt.config)->is_super == false) {
    iVar1 = (*g_rt.pt_ops.is_unbalance_happen)((g_rt.config)->chain);
    if (iVar1 != 0) {
      print_time_stamp(time_stamp,0x30);
      printf("%s ",time_stamp);
      printf("%s: has is_unbalance, can not to rise freq more!!!\n","check_unbalance");
      builtin_strncpy(tmp1,"has is_unbalance, can not to rise freq more!",0x2c);
      tmp1[0x2c] = '!';
      tmp1[0x2d] = '!';
      tmp1[0x2e] = '\0';
      log_to_file(tmp1,time_stamp);
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

