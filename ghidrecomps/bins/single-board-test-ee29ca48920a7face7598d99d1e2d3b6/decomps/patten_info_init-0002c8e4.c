
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void patten_info_init(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  memset(g_patten,0,0x9c);
  uVar2 = ram0x00036b3c;
  puVar1 = DAT_0002cbc8;
  g_patten._0_4_ = app_conf._404_4_;
  g_patten._4_4_ = app_conf._408_4_;
  g_patten._20_4_ = app_conf._384_4_;
  *DAT_0002cbc8 = s_patten_00036b38._0_4_;
  *(short *)(puVar1 + 1) = (short)uVar2;
  *(char *)((int)puVar1 + 6) = (char)((uint)uVar2 >> 0x10);
  uVar2 = DAT_00036b44;
  puVar1 = DAT_0002cbcc;
  *DAT_0002cbcc = DAT_00036b40;
  puVar1[1] = uVar2;
  uVar2 = DAT_00036b4c;
  puVar1 = DAT_0002cbd0;
  *DAT_0002cbd0 = DAT_00036b48;
  *(char *)(puVar1 + 1) = (char)uVar2;
  uVar2 = DAT_00036b54;
  puVar1 = DAT_0002cbd4;
  *DAT_0002cbd4 = DAT_00036b50;
  *(char *)(puVar1 + 1) = (char)uVar2;
  g_patten._8_4_ = 0x8c;
  g_patten._12_4_ = 4;
  g_patten._16_4_ = 0x540;
  g_patten._120_4_ = g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_;
  g_patten._88_4_ = malloc(g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_ * 0x5d0);
  if ((void *)g_patten._88_4_ == (void *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x1d);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset((void *)g_patten._88_4_,0,g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_ * 0x5d0);
  g_patten._108_4_ = malloc(g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_);
  if ((void *)g_patten._108_4_ == (void *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x23);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset((void *)g_patten._108_4_,0,g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_);
  g_patten._116_4_ = malloc(g_patten._0_4_ << 2);
  if ((void *)g_patten._116_4_ == (void *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x29);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset((void *)g_patten._116_4_,0,g_patten._0_4_ << 2);
  pthread_mutex_init(DAT_0002cbd8,(pthread_mutexattr_t *)0x0);
  return;
}

