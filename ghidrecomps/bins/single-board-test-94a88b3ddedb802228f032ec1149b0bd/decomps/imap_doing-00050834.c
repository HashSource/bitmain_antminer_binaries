
int imap_doing(int *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = imap_multi_statemach();
  if (((iVar1 == 0) && (*param_2 != '\0')) && (**(int **)(*param_1 + 0x14c) != 0)) {
    imap_dophase_done_isra_4_part_5(param_1);
  }
  return iVar1;
}

