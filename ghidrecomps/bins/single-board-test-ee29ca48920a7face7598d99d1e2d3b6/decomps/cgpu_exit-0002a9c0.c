
void cgpu_exit(void)

{
  bitmain_axi_close();
  close_green_led();
  close_red_led();
  close_key();
  close_lcd();
  patten_info_destory();
  return;
}

