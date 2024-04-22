
undefined4 get_works(void)

{
  void *pvVar1;
  FILE *pFVar2;
  undefined4 uVar3;
  int iVar4;
  char acStack_64 [64];
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  memset(acStack_64,0,0x40);
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  printf("%s, Conf.AsicNum %d, Conf.CoreNum %d\n","get_works",Conf._108_4_,Conf._112_4_);
  local_20 = 0;
  while( true ) {
    if ((uint)Conf._108_4_ <= local_20) {
      cgpu._1049760_4_ = cgpu._525472_4_;
      local_18 = 0;
      for (local_14 = 0; local_14 < (uint)(Conf._112_4_ * Conf._108_4_); local_14 = local_14 + 1) {
        if (*(int *)(cgpu + (local_14 + 0x20128) * 4) < (int)cgpu._1049760_4_) {
          cgpu._1049760_4_ = *(undefined4 *)(cgpu + (local_14 + 0x20128) * 4);
          local_18 = local_14;
        }
      }
      if ((uint)cgpu._1049760_4_ < (uint)Conf._64_4_) {
        write_lcd(1,"Get Less Work",0xd);
        printf("%s: cgpu.subid[%d] = %d, is the least pattern number\n","get_works",local_18,
               cgpu._1049760_4_);
        uVar3 = 0xffffffff;
      }
      else {
        uVar3 = 0;
      }
      return uVar3;
    }
    pvVar1 = malloc(Conf._112_4_ * Conf._64_4_ * 0xcc);
    *(void **)(cgpu + (local_20 + 0x20028) * 4) = pvVar1;
    if (*(int *)(cgpu + (local_20 + 0x20028) * 4) == 0) break;
    for (local_1c = 0; local_1c < (uint)Conf._112_4_; local_1c = local_1c + 1) {
      sprintf(acStack_64,"%s%02d%s%03d.txt",DAT_00012a38,local_20,DAT_00012a34,local_1c);
      iVar4 = local_20 * Conf._112_4_ + local_1c;
      pFVar2 = fopen(acStack_64,"r");
      *(FILE **)(cgpu + iVar4 * 4) = pFVar2;
      if (*(int *)(cgpu + (local_20 * Conf._112_4_ + local_1c) * 4) == 0) {
        printf("%s: Open test file %s error\n","get_works",acStack_64);
        return 0xffffffff;
      }
      iVar4 = local_20 * Conf._112_4_ + local_1c;
      uVar3 = get_work(local_20,local_1c,
                       *(undefined4 *)(cgpu + (local_20 * Conf._112_4_ + local_1c) * 4),Conf._64_4_)
      ;
      *(undefined4 *)(cgpu + (iVar4 + 0x20128) * 4) = uVar3;
      fclose(*(FILE **)(cgpu + (local_20 * Conf._112_4_ + local_1c) * 4));
    }
    local_20 = local_20 + 1;
  }
  printf("%s: malloc struct work err!\n","get_works");
  return 0xffffffff;
}

