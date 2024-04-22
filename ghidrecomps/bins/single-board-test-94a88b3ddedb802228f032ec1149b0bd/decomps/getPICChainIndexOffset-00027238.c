
void getPICChainIndexOffset(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  FILE *__stream;
  undefined4 local_10;
  undefined4 local_c;
  
  switch(param_1) {
  case 1:
    local_c = 1;
    local_10 = 0;
    break;
  case 2:
    local_c = 2;
    local_10 = 0;
    break;
  case 3:
    local_c = 3;
    local_10 = 0;
    break;
  default:
    local_c = 0;
    local_10 = 0;
    break;
  case 5:
    local_c = 0;
    local_10 = 0;
    break;
  case 6:
    local_c = 0;
    local_10 = 1;
    break;
  case 7:
    local_c = 0;
    local_10 = 2;
    break;
  case 8:
    local_c = 1;
    local_10 = 1;
    break;
  case 9:
    local_c = 1;
    local_10 = 2;
    break;
  case 10:
    local_c = 2;
    local_10 = 1;
    break;
  case 0xb:
    local_c = 2;
    local_10 = 2;
    break;
  case 0xc:
    local_c = 3;
    local_10 = 1;
    break;
  case 0xd:
    local_c = 3;
    local_10 = 2;
  }
  *param_2 = local_c;
  *param_3 = local_10;
  if (5 < log_level) {
    __stream = fopen(log_file,"a+");
    if (__stream != (FILE *)0x0) {
      fprintf(__stream,"%s:%d: chainIndex, iicIndex, chainOffset = %d, %d, %d\n","main.c",1999,
              param_1,*param_2,*param_3);
    }
    fclose(__stream);
  }
  return;
}

