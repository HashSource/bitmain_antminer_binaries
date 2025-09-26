
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void flush_binfile(void)

{
  FILE *__s;
  pattern_struct_in_file work;
  FILE *output_fp;
  int i;
  
  __s = fopen("/mnt/card/pattern_1midstate_super.bin","w");
  for (i = 0; (uint)i < (Local_Config_Information->Hash_Board).Big_Core_Num; i = i + 1) {
    memset(&work,0,0x30);
    work.data._0_4_ = *(undefined4 *)g_asic_unique_nonce[i].data;
    work.data._4_4_ = *(undefined4 *)(g_asic_unique_nonce[i].data + 4);
    work.data._8_4_ = *(undefined4 *)(g_asic_unique_nonce[i].data + 8);
    work.midstate._0_4_ = *(undefined4 *)g_asic_unique_nonce[i].midstate;
    work.midstate._4_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 4);
    work.midstate._8_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 8);
    work.midstate._12_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 0xc);
    work.midstate._16_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 0x10);
    work.midstate._20_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 0x14);
    work.midstate._24_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 0x18);
    work.midstate._28_4_ = *(undefined4 *)(g_asic_unique_nonce[i].midstate + 0x1c);
    work.nonce = g_asic_unique_nonce[i].nonce;
    fwrite(&work,1,0x30,__s);
  }
  return;
}

