
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void patten_info_init(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  memset(g_patten,0,0x98);
  uVar2 = ram0x00036664;
  puVar1 = DAT_0002c9b4;
  g_patten._0_4_ = app_conf._404_4_;
  g_patten._4_4_ = app_conf._408_4_;
  g_patten._20_4_ = app_conf._384_4_;
  *DAT_0002c9b4 = s_patten_00036660._0_4_;
  *(short *)(puVar1 + 1) = (short)uVar2;
  *(char *)((int)puVar1 + 6) = (char)((uint)uVar2 >> 0x10);
  uVar2 = DAT_0003666c;
  puVar1 = DAT_0002c9b8;
  *DAT_0002c9b8 = DAT_00036668;
  puVar1[1] = uVar2;
  uVar2 = DAT_00036674;
  puVar1 = DAT_0002c9bc;
  *DAT_0002c9bc = DAT_00036670;
  *(char *)(puVar1 + 1) = (char)uVar2;
  uVar2 = DAT_0003667c;
  puVar1 = DAT_0002c9c0;
  *DAT_0002c9c0 = DAT_00036678;
  *(char *)(puVar1 + 1) = (char)uVar2;
  g_patten._8_4_ = 0x8c;
  g_patten._12_4_ = 4;
  g_patten._16_4_ = 0x540;
  g_patten._88_4_ = malloc(g_patten._20_4_ * g_patten._4_4_ * g_patten._0_4_ * 0x5d0);
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

