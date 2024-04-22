
/* WARNING: Unknown calling convention */

int open_key(void)

{
  key_fd = open("/sys/class/gpio/gpio943/value",0x800);
  if (-1 < key_fd) {
    return key_fd;
  }
  puts("open key failed!!!");
  return key_fd;
}

