
int main(void)

{
  undefined auStack_50 [64];
  ssize_t local_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  memset(auStack_50,0,0x40);
  local_10 = cgpu_init();
  if (local_10 < 0) {
    return local_10;
  }
  display_arguments();
  do {
    lseek(key_fd,0,0);
    local_10 = read(key_fd,auStack_50,0x40);
    if (0 < local_10) {
      puts("\nBegin singleAsicTest_BM1740\n");
      singleBoardTest_V9_BM1740();
    }
    sleep(1);
  } while( true );
}

