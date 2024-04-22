
/* WARNING: Unknown calling convention */

void start_single_board_test(void)

{
  int iVar1;
  int ret;
  
  pcba_runtime_init(cgpu.runtime);
  iVar1 = bm1744_hashboard_init();
  if (iVar1 == 0) {
    start_read_temp();
    singleboard_pattern_test();
    stop_read_temp();
  }
  pcba_runtime_exit(cgpu.runtime);
  return;
}

