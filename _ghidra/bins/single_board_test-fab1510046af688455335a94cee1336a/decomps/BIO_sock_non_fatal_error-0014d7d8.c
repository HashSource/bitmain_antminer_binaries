
int BIO_sock_non_fatal_error(int error)

{
  if (error != 0x47) {
    if (error < 0x48) {
      if ((error != 4) && (error != 0xb)) {
        return 0;
      }
    }
    else if ((error != 0x6b) && ((error < 0x6b || (1 < error - 0x72U)))) {
      return 0;
    }
  }
  return 1;
}

