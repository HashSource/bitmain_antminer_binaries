
int ssl2_part_read(int param_1,int param_2,int param_3)

{
  int reason;
  size_t __n;
  uint uVar1;
  char *__dest;
  
  if (-1 < param_3) {
    param_3 = param_3 + *(int *)(param_1 + 0x44);
    *(int *)(param_1 + 0x44) = param_3;
    if ((2 < param_3) && (__dest = *(char **)(*(int *)(param_1 + 0x3c) + 4), *__dest == '\0')) {
      uVar1 = CONCAT11(__dest[1],__dest[2]) - 1;
      if (uVar1 < 6) {
        reason = *(int *)(DAT_00065968 + uVar1 * 4);
      }
      else {
        reason = 0xfd;
      }
      ERR_put_error(0x14,param_2,reason,DAT_0006596c,0x295);
      __n = *(int *)(param_1 + 0x44) - 3;
      *(size_t *)(param_1 + 0x44) = __n;
      if (0 < (int)__n) {
        memmove(__dest,__dest + 3,__n);
      }
    }
    param_3 = 0;
  }
  return param_3;
}

