
/* WARNING: Unknown calling convention */

int main(void)

{
  int iVar1;
  int ret;
  ssize_t sVar2;
  char command;
  
  puts("--- version:");
  puts("last commit version: 4e0ba0e commit time: 2019-05-06 17:16:11 build: 2019-08-17 11:22:48");
  iVar1 = cgpu_init();
  if ((-1 < iVar1) && (iVar1 = configMiner(), -1 < iVar1)) {
    display_arguments();
    puts("\n\nReady begin test\n");
    do {
      do {
        do {
          sVar2 = read_key(&command);
        } while (sVar2 < 1);
      } while (command != '0');
      hash_board_test();
      puts("\nPress \'test\' key to continue");
    } while( true );
  }
  return iVar1;
}

