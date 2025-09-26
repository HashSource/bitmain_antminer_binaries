
void do_all_md_fn(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  if (*(int *)(param_1 + 4) == 0) {
    (*(code *)param_2[1])
              (*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 8),0,*param_2,param_4);
    return;
  }
  (*(code *)param_2[1])
            (0,*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),*param_2,param_4);
  return;
}

