
void patten_info_init(void)

{
  memset(g_patten,0,0x98);
  g_patten._0_4_ = app_conf._404_4_;
  g_patten._4_4_ = app_conf._408_4_;
  g_patten._20_4_ = app_conf._384_4_;
  g_patten[0x18] = 'p';
  g_patten[0x19] = 'a';
  g_patten[0x1a] = 't';
  g_patten[0x1b] = 't';
  g_patten._28_2_ = 0x6e65;
  g_patten[0x1e] = 0;
  g_patten._40_4_ = 0x2d63657a;
  g_patten._44_4_ = 0x31317a;
  g_patten._56_4_ = 0x63697361;
  g_patten[0x3c] = 0;
  g_patten._72_4_ = 0x65726f63;
  g_patten[0x4c] = 0;
  g_patten._8_4_ = 0x8c;
  g_patten._12_4_ = 4;
  g_patten._16_4_ = 0x540;
  g_patten._88_4_ = malloc(app_conf._384_4_ * app_conf._408_4_ * app_conf._404_4_ * 0x5d0);
  if ((void *)g_patten._88_4_ == (void *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x1c);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  g_patten._108_4_ = malloc(g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_);
  if ((void *)g_patten._108_4_ == (void *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x21);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}

