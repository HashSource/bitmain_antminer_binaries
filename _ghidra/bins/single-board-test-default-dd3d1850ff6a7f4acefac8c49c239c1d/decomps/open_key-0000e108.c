
int open_key(void)

{
  key_fd = open("/sys/class/gpio/gpio943/value",0x800);
  if (key_fd < 0) {
    puts("open key failed!!!");
  }
  return key_fd;
}

