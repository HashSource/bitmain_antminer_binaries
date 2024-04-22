
void platform_dump_capability(uint *param_1)

{
  uint local_10;
  uint local_c;
  
  if (param_1 != (uint *)0x0) {
    printf("%s:%d","platform_dump_capability",0x20);
    puts("==========================capability start==========================");
    printf("%s:%d","platform_dump_capability",0x21);
    printf("board num = %d\n",*param_1);
    for (local_c = 0; local_c < *param_1; local_c = local_c + 1) {
      printf("%s:%d","platform_dump_capability",0x23);
      printf("board id = %d, chain num = %d\n",param_1[local_c * 0x12 + 1],
             param_1[local_c * 0x12 + 2]);
      for (local_10 = 0; local_10 < param_1[local_c * 0x12 + 2]; local_10 = local_10 + 1) {
        printf("%s:%d","platform_dump_capability",0x25);
        printf("\tchain id = %d\n",param_1[local_c * 0x12 + local_10 + 3]);
      }
    }
    printf("%s:%d","platform_dump_capability",0x29);
    puts("==========================capability end============================");
  }
  return;
}

