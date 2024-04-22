
/* WARNING: Unknown calling convention */

int configMiner(void)

{
  int iVar1;
  int ret;
  int iVar2;
  
  iVar2 = DAT_00017cb8;
  read_config();
  puts(DAT_00017cbc);
  printf(DAT_00017cc0,*(undefined4 *)(iVar2 + 0xee4));
  printf(DAT_00017cc4,*(undefined4 *)(iVar2 + 0xee8));
  printf(DAT_00017cc8,*(undefined4 *)(iVar2 + 0xeec));
  printf(DAT_00017ccc,*(undefined4 *)(iVar2 + 0xef0));
  printf(DAT_00017cd0,*(undefined4 *)(iVar2 + 0xef4));
  printf(DAT_00017cd4,*(undefined4 *)(iVar2 + 0xef8));
  printf(DAT_00017cd8,*(undefined4 *)(iVar2 + 0xf54));
  printf(DAT_00017cdc,*(undefined4 *)(iVar2 + 0xf58));
  printf(DAT_00017ce0,*(undefined4 *)(iVar2 + 0xf0c));
  printf(DAT_00017ce4,*(undefined4 *)(iVar2 + 0xf90));
  printf(DAT_00017ce8,*(undefined4 *)(iVar2 + 0xf10));
  printf(DAT_00017cec,*(undefined4 *)(iVar2 + 0xf18));
  printf(DAT_00017cf0,*(undefined4 *)(iVar2 + 0xf1c));
  printf(DAT_00017cf4,*(undefined4 *)(iVar2 + 0xf20));
  printf(DAT_00017cf8,*(undefined4 *)(iVar2 + 0xf24));
  printf(DAT_00017cfc,*(undefined4 *)(iVar2 + 0xf28));
  printf(DAT_00017d00,*(undefined4 *)(iVar2 + 0xf2c));
  printf(DAT_00017d04,*(undefined4 *)(iVar2 + 0xf30));
  printf(DAT_00017d08,*(undefined4 *)(iVar2 + 0xf34));
  printf(DAT_00017d0c,*(undefined4 *)(iVar2 + 0xf5c));
  printf(DAT_00017d10,*(undefined4 *)(iVar2 + 0xf70));
  printf(DAT_00017d14,*(undefined4 *)(iVar2 + 0xf38));
  printf(DAT_00017d18,*(undefined4 *)(iVar2 + 0xf3c));
  printf(DAT_00017d1c,*(undefined4 *)(iVar2 + 0xf40));
  printf(DAT_00017d20,*(undefined4 *)(iVar2 + 0xf60),*(undefined4 *)(iVar2 + 0xf60));
  printf(DAT_00017d24,*(undefined4 *)(iVar2 + 0xf64),*(undefined4 *)(iVar2 + 0xf64));
  printf(DAT_00017d28,*(undefined4 *)(iVar2 + 0xf68),*(undefined4 *)(iVar2 + 0xf68));
  printf(DAT_00017d2c,*(undefined4 *)(iVar2 + 0xf6c),*(undefined4 *)(iVar2 + 0xf6c));
  printf(DAT_00017d30,*(undefined4 *)(iVar2 + 0xf74));
  printf(DAT_00017d34,*(undefined4 *)(iVar2 + 0xf78));
  printf(DAT_00017d38,*(undefined4 *)(iVar2 + 0xf7c));
  printf(DAT_00017d3c,*(undefined4 *)(iVar2 + 0xf80));
  printf(DAT_00017d40,*(undefined4 *)(iVar2 + 0xf84));
  printf(DAT_00017d44,*(undefined4 *)(iVar2 + 0xf88));
  printf(DAT_00017d48,(int)*(char *)(iVar2 + 0xf8c));
  printf(DAT_00017d4c,*(undefined4 *)(iVar2 + 0xfa8));
  printf(DAT_00017d50,*(undefined4 *)(iVar2 + 0xfac));
  printf(DAT_00017d54,*(undefined4 *)(iVar2 + 0xfb0));
  printf(DAT_00017d58,*(undefined4 *)(iVar2 + 0xfb4));
  printf(DAT_00017d5c,*(undefined4 *)(iVar2 + 0xfb8));
  printf(DAT_00017d60,*(undefined4 *)(iVar2 + 0xfbc));
  printf(DAT_00017d64,*(undefined4 *)(iVar2 + 0xfc0));
  printf(DAT_00017d68,*(undefined4 *)(iVar2 + 0xfc4));
  puts(DAT_00017d6c);
  iVar1 = process_config();
  iVar2 = DAT_00017d70;
  if (-1 < iVar1) {
    puts(DAT_00017d74);
    printf(DAT_00017cc0,*(undefined4 *)(iVar2 + 0xd2c));
    printf(DAT_00017cc4,*(undefined4 *)(iVar2 + 0xd30));
    printf(DAT_00017cc8,*(undefined4 *)(iVar2 + 0xd34));
    printf(DAT_00017ccc,*(undefined4 *)(iVar2 + 0xd38));
    printf(DAT_00017cd0,*(undefined4 *)(iVar2 + 0xd40));
    printf(DAT_00017cd4,*(undefined4 *)(iVar2 + 0xd44));
    printf(DAT_00017cd8,*(undefined4 *)(iVar2 + 0xd84));
    printf(DAT_00017cdc,*(undefined4 *)(iVar2 + 0xd88));
    printf(DAT_00017ce0,*(undefined4 *)(iVar2 + 0xd3c));
    printf(DAT_00017ce8,*(undefined4 *)(iVar2 + 0xd58));
    printf(DAT_00017cec,*(undefined4 *)(iVar2 + 0xd5c));
    printf(DAT_00017cf4,*(undefined4 *)(iVar2 + 0xd60));
    printf(DAT_00017cf8,*(undefined4 *)(iVar2 + 0xd64));
    printf(DAT_00017cfc,*(undefined4 *)(iVar2 + 0xd68));
    printf(DAT_00017d00,*(undefined4 *)(iVar2 + 0xd6c));
    printf(DAT_00017d04,*(undefined4 *)(iVar2 + 0xd70));
    printf(DAT_00017d08,*(undefined4 *)(iVar2 + 0xd74));
    printf(DAT_00017d0c,*(undefined4 *)(iVar2 + 0xd8c));
    printf(DAT_00017d78,*(undefined4 *)(iVar2 + 0xda8));
    printf(DAT_00017d14,*(undefined4 *)(iVar2 + 0xd78));
    printf(DAT_00017d18,*(undefined4 *)(iVar2 + 0xd7c));
    printf(DAT_00017d1c,*(undefined4 *)(iVar2 + 0xd80));
    printf(DAT_00017d20,*(undefined4 *)(iVar2 + 0xd98),*(undefined4 *)(iVar2 + 0xd98));
    printf(DAT_00017d24,*(undefined4 *)(iVar2 + 0xd9c),*(undefined4 *)(iVar2 + 0xd9c));
    printf(DAT_00017d28,*(undefined4 *)(iVar2 + 0xda0),*(undefined4 *)(iVar2 + 0xda0));
    printf(DAT_00017d2c,*(undefined4 *)(iVar2 + 0xda4),*(undefined4 *)(iVar2 + 0xda4));
    printf(DAT_00017d30,*(undefined4 *)(iVar2 + 0xdac));
    printf(DAT_00017d34,*(undefined4 *)(iVar2 + 0xdb0));
    printf(DAT_00017d38,(uint)*(byte *)(iVar2 + 0xdb4));
    printf(DAT_00017d3c,(uint)*(byte *)(iVar2 + 0xdb5));
    printf(DAT_00017d40,(uint)*(byte *)(iVar2 + 0xdb6));
    printf(DAT_00017d44,(uint)*(byte *)(iVar2 + 0xdb7));
    printf(DAT_00017d48,(int)*(char *)(iVar2 + 0xdb8));
    printf(DAT_00017d4c,(uint)*(byte *)(iVar2 + 0xdd4));
    printf(DAT_00017d50,(int)*(char *)(iVar2 + 0xdd5));
    printf(DAT_00017dcc,*(undefined4 *)(iVar2 + 0xdd8));
    printf(DAT_00017dd0,*(undefined4 *)(iVar2 + 0xddc));
    printf(DAT_00017dd4,*(undefined4 *)(iVar2 + 0xde0));
    printf(DAT_00017dd8,*(undefined4 *)(iVar2 + 0xde4));
    printf(DAT_00017ddc,*(undefined4 *)(iVar2 + 0xde8));
    printf(DAT_00017de0,*(undefined4 *)(iVar2 + 0xdec));
    puts(DAT_00017de4);
    iVar2 = get_works();
    if (-1 < iVar2) {
      return 0;
    }
  }
  return -0xe;
}

