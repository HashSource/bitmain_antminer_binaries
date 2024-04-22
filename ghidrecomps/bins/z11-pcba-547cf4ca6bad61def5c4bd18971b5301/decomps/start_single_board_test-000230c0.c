
void start_single_board_test(void)

{
  bm1744_app_init();
  bm1744_hashboard_init();
  pcba_test();
  bm1744_app_exit();
  return;
}

