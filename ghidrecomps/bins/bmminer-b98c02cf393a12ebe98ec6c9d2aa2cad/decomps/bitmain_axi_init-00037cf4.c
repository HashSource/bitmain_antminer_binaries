
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bitmain_axi_init(void)

{
  char cVar1;
  int iVar2;
  FILE *__stream;
  undefined4 local_814;
  undefined4 local_810;
  undefined4 uStack_80c;
  undefined4 uStack_808;
  undefined4 uStack_804;
  undefined4 local_800;
  undefined4 uStack_7fc;
  undefined2 local_7f8;
  
  iVar2 = znyq7010_axi_init(&local_814);
  if (iVar2 == 0) {
    dev = (undefined4 *)calloc(0x5470,1);
    cVar1 = opt_debug;
    if (dev != (undefined4 *)0x0) {
      *dev = local_814;
      if (cVar1 == '\0') {
        return 0;
      }
      if (((use_syslog == '\0') && (opt_log_output == '\0')) && (opt_log_level < 7)) {
        return 0;
      }
      local_810._0_1_ = s_kmalloc_for_dev_success__00063b50[0];
      local_810._1_1_ = s_kmalloc_for_dev_success__00063b50[1];
      local_810._2_1_ = s_kmalloc_for_dev_success__00063b50[2];
      local_810._3_1_ = s_kmalloc_for_dev_success__00063b50[3];
      uStack_80c._0_1_ = s_kmalloc_for_dev_success__00063b50[4];
      uStack_80c._1_1_ = s_kmalloc_for_dev_success__00063b50[5];
      uStack_80c._2_1_ = s_kmalloc_for_dev_success__00063b50[6];
      uStack_80c._3_1_ = s_kmalloc_for_dev_success__00063b50[7];
      uStack_808._0_1_ = s_kmalloc_for_dev_success__00063b50[8];
      uStack_808._1_1_ = s_kmalloc_for_dev_success__00063b50[9];
      uStack_808._2_1_ = s_kmalloc_for_dev_success__00063b50[10];
      uStack_808._3_1_ = s_kmalloc_for_dev_success__00063b50[11];
      uStack_804._0_1_ = s_kmalloc_for_dev_success__00063b50[12];
      uStack_804._1_1_ = s_kmalloc_for_dev_success__00063b50[13];
      uStack_804._2_1_ = s_kmalloc_for_dev_success__00063b50[14];
      uStack_804._3_1_ = s_kmalloc_for_dev_success__00063b50[15];
      local_800._0_1_ = s_kmalloc_for_dev_success__00063b50[16];
      local_800._1_1_ = s_kmalloc_for_dev_success__00063b50[17];
      local_800._2_1_ = s_kmalloc_for_dev_success__00063b50[18];
      local_800._3_1_ = s_kmalloc_for_dev_success__00063b50[19];
      uStack_7fc._0_1_ = s_kmalloc_for_dev_success__00063b50[20];
      uStack_7fc._1_1_ = s_kmalloc_for_dev_success__00063b50[21];
      uStack_7fc._2_1_ = s_kmalloc_for_dev_success__00063b50[22];
      uStack_7fc._3_1_ = s_kmalloc_for_dev_success__00063b50[23];
      local_7f8 = (undefined2)ram0x00063b68;
      _applog(7,&local_810,0);
      return 0;
    }
    if ((opt_debug == '\0') ||
       (((use_syslog == '\0' && (opt_log_output == '\0')) && (opt_log_level < 7)))) {
      iVar2 = -1;
    }
    else {
      local_810._0_1_ = s_kmalloc_for_dev_failed__00063b34[0];
      local_810._1_1_ = s_kmalloc_for_dev_failed__00063b34[1];
      local_810._2_1_ = s_kmalloc_for_dev_failed__00063b34[2];
      local_810._3_1_ = s_kmalloc_for_dev_failed__00063b34[3];
      uStack_80c._0_1_ = s_kmalloc_for_dev_failed__00063b34[4];
      uStack_80c._1_1_ = s_kmalloc_for_dev_failed__00063b34[5];
      uStack_80c._2_1_ = s_kmalloc_for_dev_failed__00063b34[6];
      uStack_80c._3_1_ = s_kmalloc_for_dev_failed__00063b34[7];
      uStack_808._0_1_ = s_kmalloc_for_dev_failed__00063b34[8];
      uStack_808._1_1_ = s_kmalloc_for_dev_failed__00063b34[9];
      uStack_808._2_1_ = s_kmalloc_for_dev_failed__00063b34[10];
      uStack_808._3_1_ = s_kmalloc_for_dev_failed__00063b34[11];
      uStack_804._0_1_ = s_kmalloc_for_dev_failed__00063b34[12];
      uStack_804._1_1_ = s_kmalloc_for_dev_failed__00063b34[13];
      uStack_804._2_1_ = s_kmalloc_for_dev_failed__00063b34[14];
      uStack_804._3_1_ = s_kmalloc_for_dev_failed__00063b34[15];
      local_800._0_1_ = s_kmalloc_for_dev_failed__00063b34[16];
      local_800._1_1_ = s_kmalloc_for_dev_failed__00063b34[17];
      local_800._2_1_ = s_kmalloc_for_dev_failed__00063b34[18];
      local_800._3_1_ = s_kmalloc_for_dev_failed__00063b34[19];
      uStack_7fc._0_1_ = s_kmalloc_for_dev_failed__00063b34[20];
      uStack_7fc._1_1_ = s_kmalloc_for_dev_failed__00063b34[21];
      uStack_7fc._2_1_ = s_kmalloc_for_dev_failed__00063b34[22];
      uStack_7fc._3_1_ = s_kmalloc_for_dev_failed__00063b34[23];
      local_7f8 = CONCAT11(local_7f8._1_1_,(char)ram0x00063b4c);
      _applog(7,&local_810,0);
      iVar2 = -1;
    }
  }
  else {
    if (log_level < 2) {
      return iVar2;
    }
    __stream = fopen(log_file,(char *)&DAT_0005e760);
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d:%s: znyq7010_axi_init failed.\n","driver-btm-c5.c",0x2ecc,DAT_00037e2c
             );
    }
    fclose(__stream);
  }
  return iVar2;
}

