
undefined4 parse_tagging(char *param_1,int param_2,ulong *param_3,undefined4 *param_4)

{
  ulong uVar1;
  char local_20;
  undefined local_1f;
  char *local_1c;
  
  if ((param_1 != (char *)0x0) &&
     (((uVar1 = strtoul(param_1,&local_1c,10), local_1c == (char *)0x0 || (*local_1c == '\0')) ||
      (local_1c <= param_1 + param_2)))) {
    if (-1 < (int)uVar1) {
      *param_3 = uVar1;
      if ((local_1c != (char *)0x0) && (param_1 + (param_2 - (int)local_1c) != (char *)0x0)) {
        local_20 = *local_1c;
        switch(local_20) {
        case 'A':
          *param_4 = 0x40;
          return 1;
        default:
          local_1f = 0;
          ERR_put_error(0xd,0xb6,0xba,DAT_001097fc,0x1bb);
          ERR_add_error_data(2,DAT_00109800,&local_20);
          return 0;
        case 'C':
          *param_4 = 0x80;
          return 1;
        case 'P':
          *param_4 = 0xc0;
          return 1;
        case 'U':
          *param_4 = 0;
          return 1;
        }
      }
      *param_4 = 0x80;
      return 1;
    }
    ERR_put_error(0xd,0xb6,0xbb,DAT_001097fc,0x19c);
  }
  return 0;
}

